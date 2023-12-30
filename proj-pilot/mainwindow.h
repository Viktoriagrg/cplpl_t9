#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_action_3_triggered();

    void on_pushButton_clicked();

    void on_radioButton_toggled(bool checked);

    void on_im_toggled(bool checked);

    void on_prykm_toggled(bool checked);

    void on_zaym_toggled(bool checked);

    void on_diya_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_chysl_toggled(bool checked);

    void on_prysl_toggled(bool checked);

    void on_radioButton_16_toggled(bool checked);

    void on_radioButton_17_toggled(bool checked);

    void on_aaaa_textChanged();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_derevtse_toggled(bool checked);

    void on_action_triggered();

    void on_pushButton_3_clicked();

    void on_action_4_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
