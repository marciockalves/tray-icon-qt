#include "settingswidget.h"
// #include "ui_settingswidget.h"
#include <QMessageBox>
SettingsWidget::SettingsWidget(QWidget *parent)
    : QWidget(parent)
    // , ui(new Ui::SettingsWidget)
{
    // ui->setupUi(this);

    setWindowTitle("Configurações");
    setFixedSize(300, 150);

    textField = new QLineEdit(this);
    saveButton = new QPushButton("Salvar",this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(textField);
    layout->addWidget(saveButton);


    connect(saveButton, &QPushButton::clicked, this, &SettingsWidget::saveSettings);

}

void SettingsWidget::saveSettings(){
    QString text = textField->text();
    QMessageBox::information(this, "Informação", "Texto salvo" + text);
}
SettingsWidget::~SettingsWidget()
{
    delete this;
}
