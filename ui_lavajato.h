/********************************************************************************
** Form generated from reading UI file 'lavajatoJalBtD.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef LAVAJATOJALBTD_H
#define LAVAJATOJALBTD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LavaJato
{
public:
    QWidget *centralwidget;
    QRadioButton *radioButton_entrada;
    QRadioButton *radioButton_consulta;
    QFrame *line;
    QTextEdit *textEdit_placa;
    QLabel *label;
    QTextEdit *textEdit_outro;
    QLabel *label_outro;
    QComboBox *comboBox_carro;
    QLabel *label_carro;
    QLabel *label_lavado;
    QLabel *label_cera;
    QPushButton *form_sumit_button;
    QPushButton *pushButton_imprimir;
    QTextEdit *textEdit_cliente;
    QLabel *label_cliente;
    QTextEdit *textEdit_telefone;
    QLabel *label_telefone;
    QTextEdit *textEdit_endereco;
    QLabel *label_email;
    QTextEdit *textEdit_email;
    QLabel *label_endereco;
    QPushButton *pushButton_foto_ent;
    QPushButton *pushButton_foto_sai;
    QFrame *line_2;
    QLabel *info_cliente;
    QLabel *info_placa;
    QLabel *info_carro;
    QLabel *info_cera;
    QLabel *info_data;
    QLabel *info_lavado;
    QLabel *label_titulo;
    QFrame *line_3;
    QLabel *info_custo;
    QLabel *info_telefone;
    QListWidget *listWidget;
    QComboBox *comboBox_cera;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LavaJato)
    {
        if (LavaJato->objectName().isEmpty())
            LavaJato->setObjectName(QStringLiteral("LavaJato"));
        LavaJato->resize(835, 606);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(61, 187, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(170, 230, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(115, 208, 247, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(30, 93, 120, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(40, 125, 160, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(158, 221, 247, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        LavaJato->setPalette(palette);
        centralwidget = new QWidget(LavaJato);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        radioButton_entrada = new QRadioButton(centralwidget);
        radioButton_entrada->setObjectName(QStringLiteral("radioButton_entrada"));
        radioButton_entrada->setGeometry(QRect(60, 90, 131, 17));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        radioButton_entrada->setFont(font);
        radioButton_consulta = new QRadioButton(centralwidget);
        radioButton_consulta->setObjectName(QStringLiteral("radioButton_consulta"));
        radioButton_consulta->setGeometry(QRect(60, 150, 131, 17));
        radioButton_consulta->setFont(font);
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(220, 70, 20, 351));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        textEdit_placa = new QTextEdit(centralwidget);
        textEdit_placa->setObjectName(QStringLiteral("textEdit_placa"));
        textEdit_placa->setGeometry(QRect(350, 80, 161, 31));
        textEdit_placa->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(280, 90, 51, 21));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        textEdit_outro = new QTextEdit(centralwidget);
        textEdit_outro->setObjectName(QStringLiteral("textEdit_outro"));
        textEdit_outro->setGeometry(QRect(350, 180, 161, 31));
        textEdit_outro->setFont(font);
        label_outro = new QLabel(centralwidget);
        label_outro->setObjectName(QStringLiteral("label_outro"));
        label_outro->setGeometry(QRect(280, 190, 51, 21));
        label_outro->setFont(font1);
        comboBox_carro = new QComboBox(centralwidget);
        comboBox_carro->setObjectName(QStringLiteral("comboBox_carro"));
        comboBox_carro->setGeometry(QRect(350, 130, 161, 31));
        comboBox_carro->setFont(font);
        label_carro = new QLabel(centralwidget);
        label_carro->setObjectName(QStringLiteral("label_carro"));
        label_carro->setGeometry(QRect(280, 140, 51, 21));
        label_carro->setFont(font1);
        label_lavado = new QLabel(centralwidget);
        label_lavado->setObjectName(QStringLiteral("label_lavado"));
        label_lavado->setGeometry(QRect(260, 330, 61, 21));
        label_lavado->setFont(font1);
        label_cera = new QLabel(centralwidget);
        label_cera->setObjectName(QStringLiteral("label_cera"));
        label_cera->setGeometry(QRect(290, 240, 41, 21));
        label_cera->setFont(font1);
        form_sumit_button = new QPushButton(centralwidget);
        form_sumit_button->setObjectName(QStringLiteral("form_sumit_button"));
        form_sumit_button->setGeometry(QRect(660, 310, 151, 51));
        form_sumit_button->setFont(font1);
        pushButton_imprimir = new QPushButton(centralwidget);
        pushButton_imprimir->setObjectName(QStringLiteral("pushButton_imprimir"));
        pushButton_imprimir->setGeometry(QRect(710, 480, 91, 51));
        pushButton_imprimir->setFont(font1);
        textEdit_cliente = new QTextEdit(centralwidget);
        textEdit_cliente->setObjectName(QStringLiteral("textEdit_cliente"));
        textEdit_cliente->setGeometry(QRect(620, 80, 161, 31));
        textEdit_cliente->setFont(font);
        label_cliente = new QLabel(centralwidget);
        label_cliente->setObjectName(QStringLiteral("label_cliente"));
        label_cliente->setGeometry(QRect(550, 90, 71, 21));
        label_cliente->setFont(font1);
        textEdit_telefone = new QTextEdit(centralwidget);
        textEdit_telefone->setObjectName(QStringLiteral("textEdit_telefone"));
        textEdit_telefone->setGeometry(QRect(620, 130, 161, 31));
        textEdit_telefone->setFont(font);
        label_telefone = new QLabel(centralwidget);
        label_telefone->setObjectName(QStringLiteral("label_telefone"));
        label_telefone->setGeometry(QRect(540, 140, 71, 21));
        label_telefone->setFont(font1);
        textEdit_endereco = new QTextEdit(centralwidget);
        textEdit_endereco->setObjectName(QStringLiteral("textEdit_endereco"));
        textEdit_endereco->setGeometry(QRect(620, 180, 161, 31));
        textEdit_endereco->setFont(font);
        label_email = new QLabel(centralwidget);
        label_email->setObjectName(QStringLiteral("label_email"));
        label_email->setGeometry(QRect(560, 240, 51, 21));
        label_email->setFont(font1);
        textEdit_email = new QTextEdit(centralwidget);
        textEdit_email->setObjectName(QStringLiteral("textEdit_email"));
        textEdit_email->setGeometry(QRect(620, 230, 161, 31));
        textEdit_email->setFont(font);
        label_endereco = new QLabel(centralwidget);
        label_endereco->setObjectName(QStringLiteral("label_endereco"));
        label_endereco->setGeometry(QRect(540, 190, 71, 21));
        label_endereco->setFont(font1);
        pushButton_foto_ent = new QPushButton(centralwidget);
        pushButton_foto_ent->setObjectName(QStringLiteral("pushButton_foto_ent"));
        pushButton_foto_ent->setGeometry(QRect(50, 230, 131, 51));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_foto_ent->setFont(font2);
        pushButton_foto_sai = new QPushButton(centralwidget);
        pushButton_foto_sai->setObjectName(QStringLiteral("pushButton_foto_sai"));
        pushButton_foto_sai->setGeometry(QRect(50, 310, 131, 51));
        pushButton_foto_sai->setFont(font2);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 410, 841, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        info_cliente = new QLabel(centralwidget);
        info_cliente->setObjectName(QStringLiteral("info_cliente"));
        info_cliente->setGeometry(QRect(10, 420, 361, 41));
        info_cliente->setFont(font1);
        info_placa = new QLabel(centralwidget);
        info_placa->setObjectName(QStringLiteral("info_placa"));
        info_placa->setGeometry(QRect(20, 460, 311, 41));
        info_placa->setFont(font1);
        info_carro = new QLabel(centralwidget);
        info_carro->setObjectName(QStringLiteral("info_carro"));
        info_carro->setGeometry(QRect(20, 500, 311, 41));
        info_carro->setFont(font1);
        info_cera = new QLabel(centralwidget);
        info_cera->setObjectName(QStringLiteral("info_cera"));
        info_cera->setGeometry(QRect(370, 500, 251, 41));
        info_cera->setFont(font1);
        info_data = new QLabel(centralwidget);
        info_data->setObjectName(QStringLiteral("info_data"));
        info_data->setGeometry(QRect(30, 540, 301, 41));
        info_data->setFont(font1);
        info_lavado = new QLabel(centralwidget);
        info_lavado->setObjectName(QStringLiteral("info_lavado"));
        info_lavado->setGeometry(QRect(350, 460, 271, 41));
        info_lavado->setFont(font1);
        label_titulo = new QLabel(centralwidget);
        label_titulo->setObjectName(QStringLiteral("label_titulo"));
        label_titulo->setGeometry(QRect(220, 20, 361, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("MV Boli"));
        font3.setPointSize(26);
        font3.setBold(false);
        font3.setWeight(50);
        label_titulo->setFont(font3);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(0, 60, 841, 21));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        info_custo = new QLabel(centralwidget);
        info_custo->setObjectName(QStringLiteral("info_custo"));
        info_custo->setGeometry(QRect(370, 540, 261, 41));
        info_custo->setFont(font1);
        info_telefone = new QLabel(centralwidget);
        info_telefone->setObjectName(QStringLiteral("info_telefone"));
        info_telefone->setGeometry(QRect(340, 420, 281, 41));
        info_telefone->setFont(font1);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(340, 290, 281, 101));
        comboBox_cera = new QComboBox(centralwidget);
        comboBox_cera->setObjectName(QStringLiteral("comboBox_cera"));
        comboBox_cera->setGeometry(QRect(350, 230, 161, 31));
        comboBox_cera->setFont(font);
        LavaJato->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(LavaJato);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        LavaJato->setStatusBar(statusbar);

        retranslateUi(LavaJato);

        QMetaObject::connectSlotsByName(LavaJato);
    } // setupUi

    void retranslateUi(QMainWindow *LavaJato)
    {
        LavaJato->setWindowTitle(QApplication::translate("LavaJato", "Lava-Jato Santa Rita", nullptr));
        radioButton_entrada->setText(QApplication::translate("LavaJato", "Entrada", nullptr));
        radioButton_consulta->setText(QApplication::translate("LavaJato", "Consulta", nullptr));
        label->setText(QApplication::translate("LavaJato", "Placa", nullptr));
        label_outro->setText(QApplication::translate("LavaJato", "Outro", nullptr));
        label_carro->setText(QApplication::translate("LavaJato", "Carro", nullptr));
        label_lavado->setText(QApplication::translate("LavaJato", "Lavado", nullptr));
        label_cera->setText(QApplication::translate("LavaJato", "Cera", nullptr));
        form_sumit_button->setText(QApplication::translate("LavaJato", "Aceitar", nullptr));
        pushButton_imprimir->setText(QApplication::translate("LavaJato", "Imprimir", nullptr));
        label_cliente->setText(QApplication::translate("LavaJato", "Cliente", nullptr));
        label_telefone->setText(QApplication::translate("LavaJato", "Telefone", nullptr));
        label_email->setText(QApplication::translate("LavaJato", "E-mail", nullptr));
        label_endereco->setText(QApplication::translate("LavaJato", "Endere\303\247o", nullptr));
        pushButton_foto_ent->setText(QApplication::translate("LavaJato", "Foto entrada", nullptr));
        pushButton_foto_sai->setText(QApplication::translate("LavaJato", "Foto saida", nullptr));
        info_cliente->setText(QApplication::translate("LavaJato", "Cliente:", nullptr));
        info_placa->setText(QApplication::translate("LavaJato", "Placa:", nullptr));
        info_carro->setText(QApplication::translate("LavaJato", "Carro:", nullptr));
        info_cera->setText(QApplication::translate("LavaJato", "Cera:", nullptr));
        info_data->setText(QApplication::translate("LavaJato", "Data:", nullptr));
        info_lavado->setText(QApplication::translate("LavaJato", "Lavado:", nullptr));
        label_titulo->setText(QApplication::translate("LavaJato", "Lava-Jato Santa Rita", nullptr));
        info_custo->setText(QApplication::translate("LavaJato", "Total:", nullptr));
        info_telefone->setText(QApplication::translate("LavaJato", "Telefone:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LavaJato: public Ui_LavaJato {};
} // namespace Ui

QT_END_NAMESPACE

#endif // LAVAJATOJALBTD_H
