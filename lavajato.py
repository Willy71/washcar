import sys
from PyQt5.QtWidgets import QApplication, QListWidget, QMainWindow, QWidget, QPushButton, QTextEdit, QButtonGroup, QMessageBox, QVBoxLayout, QListWidgetItem, QLabel
from PyQt5.uic import loadUi
from PyQt5.QtGui import QColor, QTextDocument, QTextCursor
import pandas as pd
from datetime import datetime, timedelta
from PyQt5.QtPrintSupport import QPrinter, QPrintDialog
import os
import re
from PyQt5.QtCore import Qt, QRect


class MultiComboBox(QWidget):
    def __init__(self, items, parent=None):
        super(MultiComboBox, self).__init__(parent)

        # Utiliza el QListWidget proporcionado desde QT Designer
        self.listWidget = QListWidget(self)
        # Ajusta la altura según tus necesidades
        self.listWidget.setMaximumHeight(90)

        for item_text in items:
            item = QListWidgetItem(item_text)
            item.setFlags(item.flags() | Qt.ItemIsUserCheckable)
            item.setCheckState(Qt.Unchecked)
            self.listWidget.addItem(item)

        # Desactivar el contorno del QListWidget
        self.listWidget.setFrameShape(QListWidget.NoFrame)

        layout = QVBoxLayout(self)
        layout.addWidget(self.listWidget)

        # Inicializar lavado como un atributo de la clase MultiComboBox
        self.valor_lavado = 0

    def calcular_lavado(self):
        self.valor_lavado = 0

        for i in range(self.listWidget.count()):
            item = self.listWidget.item(i)
            if item.checkState() == Qt.Checked:
                texto = item.text()
                # Extraer el precio del texto (suponiendo que el precio está al final del texto)
                precio_str = texto.split(
                )[-1].replace('R$', '').replace(',', '.')
                self.valor_lavado += float(precio_str)

    def obtener_valor_lavado(self):
        return self.valor_lavado


class LavaJato(QMainWindow):
    def __init__(self):
        super().__init__()

        # Carga la interfaz desde el archivo .ui
        loadUi("lavajato.ui", self)

        # Crear grupo de botones
        self.button_group = QButtonGroup()
        self.button_group.addButton(self.radioButton_entrada)
        self.button_group.addButton(self.radioButton_consulta)

        # Establecer el radioButton "entrada" como seleccionado
        self.radioButton_entrada.setChecked(True)
        self.radioButton_entrada.setStyleSheet("background-color: lightgreen")

        # Inicializar las variables
        self.user_id = None
        self.placa = ""
        self.carro_texto = ""
        self.hora_entrada = None
        self.endereco = ""
        self.lavado = ""
        self.cera = ""
        self.cliente = None
        self.telefone = None
        self.email = ''
        self.custo = 0

        # Conectar la señal clicked de los botones a funciones correspondientes
        self.radioButton_entrada.clicked.connect(self.on_entrada_clicked)
        self.radioButton_consulta.clicked.connect(self.on_consulta_clicked)

        # Conectar el evento textChanged a la función correspondiente
        self.textEdit_placa.textChanged.connect(self.placa_limite)
        # self.textEdit_email.textChanged.connect(self.validar_email)

        # Cargar la lista de carros
        self.cargar_lista_carros()
        # Cargar la lista de cera
        self.cargar_lista_cera()

        # Agregar esto en el constructor de la clase MainWindow, después de conectar otros eventos
        self.pushButton_imprimir.clicked.connect(self.imprimir_datos)

        # Utiliza el QListWidget proporcionado desde QT Designer
        opciones_lavagem = [
            "Externa (aparência)                           R$ 35,00",
            "Interna                                                 R$ 35,00",
            "Completa (interna + externa)          R$ 60,00",
            "Lavagem por baixo                            R$ 15,00"
        ]
        self.multiComboBox = MultiComboBox(opciones_lavagem, self.listWidget)
        # Ajusta las dimensiones según tus necesidades
        self.multiComboBox.setGeometry(0, 5, 280, 100)

        # Conectar la señal clicked del botón a la función correspondiente
        self.form_sumit_button.clicked.connect(self.funcion_entrada)
        self.form_sumit_button.clicked.connect(self.consultar_entrada)

        # Mostrar la ventana principal
        self.show()
        
 

    def on_entrada_clicked(self):
        self.radioButton_entrada.setStyleSheet("background-color: lightgreen")
        self.radioButton_consulta.setStyleSheet(
            "background-color: transparent")

        # Limpiar los QLabel
        self.limpiar_datos_labels()

    def on_consulta_clicked(self):
        self.radioButton_consulta.setStyleSheet("background-color: lightgreen")
        self.radioButton_entrada.setStyleSheet("background-color: transparent")

        # Limpiar los QLabel
        self.limpiar_datos_labels()

    def limpiar_datos_labels(self):
        # Restablecer el texto original en los QLabel
        self.info_cliente.setText("Cliente:")
        self.info_telefone.setText("Telefone:")
        self.info_placa.setText("Placa:")
        self.info_carro.setText("Carro:")
        self.info_data.setText("Data:")
        self.info_custo.setText("Total:")
        self.info_lavado.setText("Lavado:")
        self.info_cera.setText("Cera:")

    def funcion_entrada(self):
        global hora_entrada
        # Guarda el contenido del QPlainTextEdit en una variable diferente
        texto_placa = self.textEdit_placa.toPlainText().upper()

        # Verifica si el radio button "Entrada" está seleccionado
        if self.radioButton_entrada.isChecked():
            if len(texto_placa) != 7:
                self.mostrar_advertencia(
                    "A placa deve ter exatamente 7 caracteres.")
                return
            elif self.comboBox_carro.currentText() == "" or (self.comboBox_carro.currentText() == "Outro" and self.textEdit_outro.toPlainText().strip() == ""):
                self.mostrar_advertencia("Os campos são obrigatórios.")
                return
            else:

                # Obtener el carro seleccionado en el ComboBox
                if self.comboBox_carro.currentText() == "Outro":
                    carro_seleccionado = self.textEdit_outro.toPlainText()
                else:
                    carro_seleccionado = self.comboBox_carro.currentText()

                # Actualizar la variable carro_texto con la selección
                self.carro_texto = carro_seleccionado
                # Obtener la hora y fecha de entrada
                hora_entrada = datetime.now().strftime("%H:%M  %d/%m/%Y")
                # Asignar el contenido al QPlainTextEdit después de mostrar la información
                self.textEdit_placa.setPlainText(texto_placa)
                self.cliente = self.textEdit_cliente.toPlainText()
                self.telefone = self.textEdit_telefone.toPlainText()
                self.endereco = self.textEdit_endereco.toPlainText()
                self.email = self.textEdit_email.toPlainText()
                # Calcular el lavado y obtener su valor desde MultiComboBox
                self.multiComboBox.calcular_lavado()
                self.lavado = self.multiComboBox.obtener_valor_lavado()
                self.cera = self.comboBox_cera.currentText()
                self.calcular_cera()
                self.custo = valor_cera + self.lavado
                # Llamar a la función para verificar datos faltantes
                if not self.verificar_datos_faltantes():
                    return
                else:
                    # Establecer el texto en el QLabel label_info_placa
                    self.info_placa.setText("Placa:     " + texto_placa)
                    # Mostrar el carro seleccionado en el QLabel label_info_carro
                    self.info_carro.setText(
                        "Carro:      " + carro_seleccionado)
                    # Mostrar la hora y fecha de entrada en el QLabel label_info_entrada
                    self.info_data.setText("Data:     " + hora_entrada)
                    self.info_cliente.setText("Cliente:     " + self.cliente)
                    self.info_telefone.setText(
                        "Telefone:     " + self.telefone)
                    self.info_lavado.setText(
                        "Lavado:     $R " + format(self.lavado))
                    self.info_cera.setText(
                        "Cera:     " + self.cera + '  R$ ' + str(valor_cera))
                    self.info_custo.setText("Total:     R$ " + str(self.custo))
                    # Guardar los datos en el archivo CSV
                    self.guardar_entrada()
                    self.clear_content()

    def calcular_cera(self):
        global valor_cera
        # Calcular el valor de la cera
        valor_cera = 0
        if self.cera == "Meguiars Carnauba":
            valor_cera = 30.00
        elif self.cera == "Meguiars Ultimate":
            valor_cera = 35.00
        elif self.cera == "Turtle Wax Grafeno":
            valor_cera = 45.00
        else:
            0

    def guardar_entrada(self):
        # Generar un ID único y secuencial (puedes ajustar esto según tus necesidades)
        user_id = self.generar_user_id()

        # Crear un diccionario con los datos a guardar
        datos = {
            "user_id": int(user_id),
            "Placa": str(self.textEdit_placa.toPlainText().upper()),
            "Carro": str(self.carro_texto),
            "Data": hora_entrada,
            "Cliente": self.cliente,  # Inicializar la columna "Hora de saida" con un string vacío
            "Telefone": self.telefone,
            "Endereco": self.endereco,
            "Email": self.email,
            "Lavado": self.lavado,
            "Cera": self.cera,
            "Custo": self.custo
        }

        # Crear un DataFrame con los nuevos datos
        df_nuevo = pd.DataFrame([datos])

        # Intentar cargar el archivo CSV existente o crear uno nuevo si no existe
        try:
            df_existente = pd.read_csv("database_lava_jato.csv")
            df_actualizado = pd.concat(
                [df_existente, df_nuevo], ignore_index=True)
        except FileNotFoundError:
            df_actualizado = df_nuevo

        # Guardar el DataFrame actualizado en el archivo CSV
        df_actualizado.to_csv("database_lava_jato.csv", index=False)

    def leer_dataframe(self, df):
        file_name = 'database_lava_jato.csv'
        file_dir = os.path.dirname(os.path.abspath(__file__))
        filepath = os.path.join(file_dir, file_name)
        # Leer el DataFrame desde el archivo CSV si existe
        if os.path.exists(filepath):
            # Leer el DataFrame desde el archivo CSV usando punto y coma como delimitador
            df = pd.read_csv(filepath, delimiter=',', dtype={'Carro': str})
            # Convertir 'user_id' a tipo entero, pero solo para valores numéricos
            df['user_id'] = pd.to_numeric(
                df['user_id'], errors='coerce', downcast='integer')
            # Eliminar filas con 'user_id' no numéricos (NaN)
            df = df.dropna(subset=['user_id'])
            # Convertir 'user_id' a tipo entero (si no ha sido eliminado completamente)
            df['user_id'] = df['user_id'].astype('Int64')
        else:
            # Crear un DataFrame vacío si el archivo no existe
            df = pd.DataFrame(columns=['user_id', 'Placa', 'Carro',
                                       'Data', 'Cliente', 'Telefone',
                                       'Endereco', 'Email', 'Lavado', 'Cera', 'Custo'])
        return df

    def placa_limite(self):
        # Obtener el texto actual del QTextEdit
        current_text = self.textEdit_placa.toPlainText()

        # Verificar si el texto supera el límite de 7 caracteres alfanuméricos
        if len(current_text) > 7:
            # Si excede el límite, truncar el texto y actualizar el QTextEdit
            new_text = current_text[:7]
            self.textEdit_placa.setPlainText(new_text)

            # Mover el cursor al final del texto
            cursor = self.textEdit_placa.textCursor()
            cursor.movePosition(cursor.End)
            self.textEdit_placa.setTextCursor(cursor)

    def generar_user_id(self):
        df = pd.read_csv("database_lava_jato.csv")
        if df.empty:
            return 1
        else:
            return df['user_id'].max() + 1

    def cargar_lista_carros(self):
        # Leer la base de datos y obtener la lista de carros
        carros_df = pd.read_csv("carros_sort.csv")
        opciones_carros = carros_df["Carro"].tolist()
        # Limpiar el contenido actual del ComboBox
        self.comboBox_carro.clear()
        # Agregar las opciones al ComboBox
        self.comboBox_carro.addItems(opciones_carros)

    def cargar_lista_cera(self):
        # Leer la base de datos y obtener la lista de carros
        ceras_df = pd.read_csv("cera.csv")
        opciones_cera = ceras_df["Cera"].tolist()
        # Limpiar el contenido actual del ComboBox
        self.comboBox_cera.clear()
        # Agregar las opciones al ComboBox
        self.comboBox_cera.addItems(opciones_cera)

    def clear_content(self):
        self.textEdit_placa.clear()
        self.comboBox_carro.setCurrentIndex(-1)
        self.textEdit_outro.clear()
        self.comboBox_cera.setCurrentIndex(-1)
        self.textEdit_cliente.clear()
        self.textEdit_telefone.clear()
        self.textEdit_email.clear()
        self.textEdit_endereco.clear()
        # Desmarcar todos los elementos en el MultiComboBox (QListWidget)
        for i in range(self.multiComboBox.listWidget.count()):
            item = self.multiComboBox.listWidget.item(i)
            item.setCheckState(Qt.Unchecked)

        self.listWidget.clear()

    def mostrar_advertencia(self, mensaje):
        QMessageBox.warning(self, "Aviso", mensaje)

    def validar_email(self, email):
        # Utilizar una expresión regular para validar el formato del correo electrónico
        import re
        pattern = re.compile(r"[^@]+@[^@]+\.[^@]+")
        return bool(re.match(pattern, email))

    def validar_datos(self):
        # Validar el formato del correo electrónico
        email_valido = self.validar_email(self.textEdit_email.toPlainText())
        if not email_valido:
            self.mostrar_advertencia(
                "El formato del correo electrónico no es válido.")
            return False
        return True

    def verificar_datos_faltantes(self):
        if (
            self.textEdit_cliente.toPlainText().strip() == "" or
            self.textEdit_telefone.toPlainText().strip() == "" or
            self.textEdit_email.toPlainText().strip() == "" or
            (self.comboBox_carro.currentText() == "Outro" and self.textEdit_outro.toPlainText().strip() == "") or
            not any(item.checkState() == Qt.Checked for item in self.multiComboBox.listWidget.findItems(
                "*", Qt.MatchWildcard))
        ):
            self.mostrar_advertencia(
                "Por favor, preencha todos os campos obrigatórios.")
            return False
        return True
    
    def consultar_entrada(self):
        # Obtener la placa ingresada
        placa_consulta = self.textEdit_placa.toPlainText().upper()
        # Verifica si el radio button "Entrada" está seleccionado
        if self.radioButton_consulta.isChecked():
            if len(placa_consulta) != 7:
                self.mostrar_advertencia(
                    "A placa deve ter exatamente 7 caracteres.")
                return
            else:
                # Realizar la consulta en el archivo CSV
                ultima_entrada = self.obtener_ultima_entrada(placa_consulta)

                # Verificar si se encontraron entradas
                if ultima_entrada:
                    # Mostrar la información en los QLabel
                    self.info_placa.setText("Placa:     " + ultima_entrada["Placa"])
                    self.info_carro.setText("Carro:      " + ultima_entrada["Carro"])
                    self.info_data.setText("Data:     " + ultima_entrada["Data"])
                    self.info_cliente.setText("Cliente:     " + ultima_entrada["Cliente"])
                    self.info_telefone.setText("Telefone:     " + ultima_entrada["Telefone"])
                    self.info_lavado.setText("Lavado:     R$ " + str(ultima_entrada["Lavado"]))
                    self.info_cera.setText("Cera:     " + ultima_entrada["Cera"])
                    self.info_custo.setText("Total:     R$ " + str(ultima_entrada["Custo"]))
                else:
                    # Mostrar un mensaje de advertencia si no se encontraron entradas
                    self.mostrar_advertencia("Nenhuma entrada encontrada para a placa fornecida.")
            
    def obtener_ultima_entrada(self, placa_consulta):
        # Leer el archivo CSV
        df = pd.read_csv("database_lava_jato.csv")

        # Filtrar las entradas para la placa de consulta
        entradas_placa = df[df['Placa'] == placa_consulta]

        # Verificar si hay alguna entrada para la placa
        if not entradas_placa.empty:
            # Obtener la última entrada
            ultima_entrada = entradas_placa.iloc[-1].to_dict()
            return ultima_entrada
        else:
            return None     
    
    def imprimir_datos(self):
        printer = QPrinter()
        dialog = QPrintDialog(printer, self)

        if dialog.exec_() != QPrintDialog.Accepted:
            return

        # Crear un objeto QTextDocument con el contenido de los labels
        document = QTextDocument()

        # Crear un cursor para insertar texto en el documento
        cursor = QTextCursor(document)

        # Insertar el contenido común de los labels en el documento
        cursor.insertText(self.info_placa.text() + "\n")
        cursor.insertText(self.info_carro.text() + "\n")
        cursor.insertText(self.info_data.text() + "\n")
        cursor.insertText(self.info_cliente.text() + "\n")
        cursor.insertText(self.info_telefone.text() + "\n")
        cursor.insertText(self.info_lavado.text() + "\n")
        cursor.insertText(self.info_cera.text() + "\n")
        cursor.insertText(self.info_custo.text())

        # Imprimir el documento
        document.print_(printer)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = LavaJato()
    window.show()
    sys.exit(app.exec_())


