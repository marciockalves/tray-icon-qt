#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
class SettingsWidget;
}
QT_END_NAMESPACE

class SettingsWidget : public QWidget
{
    Q_OBJECT

public:
    SettingsWidget(QWidget *parent = nullptr);
    ~SettingsWidget();

// private:
//     Ui::SettingsWidget *ui;

private slots:
    void saveSettings();
private:
    QLineEdit *textField;
    QPushButton *saveButton;
};
#endif // SETTINGSWIDGET_H
