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

    void on_Growth_clicked();

    void on_Reduction_clicked();

    void on_Growth_m_clicked();

    void on_Reduction_m_clicked();

    void on_Chaos_clicked();

    void on_Bubble_clicked();

    void on_Quick_clicked();

    void on_Selecting_clicked();

    void on_Merge_clicked();

    void on_Start_clicked();

    void on_Random_clicked();

    void on_Raiting_clicked();

    void on_Clear_clicked();

    void on_Shell_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
