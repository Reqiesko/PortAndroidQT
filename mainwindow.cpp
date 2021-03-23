    #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "sort.h"
#include "ctime"
#include "QDebug"
enum Numbers { Zero, One, Two};
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}
int MarkSort = -One;
int TypeSort = -One;
int AmountSort = Zero;
vector <double> Arry;
QString StrArry;
void MainWindow::on_Growth_clicked()
{
    MarkSort = Maximum;
}
void MainWindow::on_Reduction_clicked()
{
    MarkSort = Minimum;
}
void MainWindow::on_Growth_m_clicked()
{
    MarkSort = AbsMax;
}
void MainWindow::on_Reduction_m_clicked()
{
    MarkSort = AbsMin;
}
void MainWindow::on_Chaos_clicked()
{
    TypeSort = Chaos;
}
void MainWindow::on_Bubble_clicked()
{
   TypeSort = Bubble;
}
void MainWindow::on_Quick_clicked()
{
    TypeSort = Quick;
}
void MainWindow::on_Selecting_clicked()
{
    TypeSort = Selection;
}
void MainWindow::on_Shell_clicked()
{
    TypeSort =Shell;
}
void MainWindow::on_Merge_clicked()
{
    TypeSort = Merge;
}
void MainWindow::on_Raiting_clicked()
{
    TypeSort = Raiting;
}
void MainWindow::on_Random_clicked()
{
    bool flag = false;
    StrArry.clear();
    AmountSort = ui->spinBox->text().toInt(&flag);
    if(!flag || AmountSort <= 0){
        AmountSort = Zero;
        ui->Input->setText("Задайте кол-во элементов!");
        return;
    }
    srand(time(nullptr));
    for(int i = Zero; i < AmountSort; i++){
        double Rand = (-1000 + rand()%2001) / 10.0f;
        StrArry.push_back( QString("%1").arg(Rand));
        StrArry.push_back(' ');
    }
        ui->Input->setText(StrArry);
}
void MainWindow::on_Start_clicked(){
    Arry.clear();
    ui->Statistic->clear();
    StrArry = ui->Input->text() + " ";
    QString Element_string = "";
    double Element_double = Zero;
    for(int i = Zero; i < StrArry.size(); i++){
        if(StrArry[i]!= ' ') {
            Element_string+=StrArry[i];
        }
        else{
            bool key = false;
            Element_double = Element_string.toDouble(&key);
            if(key){
                Arry.push_back(Element_double);
            }
            key = false;
            Element_string = "";
        }
    }
    AmountSort = Arry.size();
    if(TypeSort >= Zero && TypeSort != Chaos && MarkSort >= Zero && AmountSort > Zero){
        Sort Instance(MarkSort, AmountSort, TypeSort, Arry);
        QString SortArry = Instance.ChoiseSortingMethot();
        ui->Input->setText(SortArry);
        switch (TypeSort) {
        case Bubble:
            ui->Statistic->append("Cортировка пузырьком.");
            ui->Statistic->append("Количество сравнений: " + QString::number(Instance.STAT[Bubble].Step));
            ui->Statistic->append("Количество замен: " + QString::number(Instance.STAT[Bubble].Jump));
            break;
        case Quick:
            ui->Statistic->append("Быстрая сортировка.");
            ui->Statistic->append("Количество сравнений: " + QString::number(Instance.STAT[Quick].Step));
            ui->Statistic->append("Количество замен: " + QString::number(Instance.STAT[Quick].Jump));
            break;
        case Merge:
            ui->Statistic->append("Cортировка слиянием.");
            ui->Statistic->append("Количество сравнений: " + QString::number(Instance.STAT[Merge].Step));
            ui->Statistic->append("Количество замен: " + QString::number(Instance.STAT[Merge].Jump));
            break;
        case Selection:
            ui->Statistic->append("Cортировка выбором.");
            ui->Statistic->append("Количество сравнений: " + QString::number(Instance.STAT[Selection].Step));
            ui->Statistic->append("Количество замен: " + QString::number(Instance.STAT[Selection].Jump));
            break;
        case Shell:
            ui->Statistic->append("Cортировка шелла.");
            ui->Statistic->append("Количество сравнений: " + QString::number( Instance.STAT[Shell].Step));
            ui->Statistic->append("Количество замен: " + QString::number(Instance.STAT[Shell].Jump));
            break;
        case Raiting:
            for(int i = Bubble; i < Raiting-1; i++){
                switch (Instance.STAT[i].Sort) {
                case Bubble:
                    ui->Statistic->append(QString::number(i + One) + ") Cортировка пузырьком." + QString('\n'));
                    ui->Statistic->append("Количество сравнений: " + QString::number(Instance.STAT[i].Step));
                    ui->Statistic->append("Количество замен: " + QString::number(Instance.STAT[i].Jump));
                    break;
                case Quick:
                    ui->Statistic->append(QString::number(i + One) + ") Быстрая сортировка." + QString('\n'));
                    ui->Statistic->append("Количество сравнений: " + QString::number(Instance.STAT[i].Step));
                    ui->Statistic->append("Количество замен: " + QString::number(Instance.STAT[i].Jump));
                    break;
                case Merge:
                    ui->Statistic->append(QString::number(i + One) + ") Cортировка слиянием." + QString('\n'));
                    ui->Statistic->append("Количество сравнений: " + QString::number(Instance.STAT[i].Step));
                    ui->Statistic->append("Количество замен: " + QString::number(Instance.STAT[i].Jump));
                    break;
                case Selection:
                    ui->Statistic->append(QString::number(i + One) + ") Cортировка выбором." + QString('\n'));
                    ui->Statistic->append("Количество сравнений: " + QString::number(Instance.STAT[i].Step));
                    ui->Statistic->append("Количество замен: " + QString::number(Instance.STAT[i].Jump));
                    break;
                case Shell:
                    ui->Statistic->append(QString::number(i + One) + ") Cортировка шелла." + QString('\n'));
                    ui->Statistic->append("Количество сравнений: " + QString::number(Instance.STAT[i].Step));
                    ui->Statistic->append("Количество замен: " + QString::number(Instance.STAT[i].Jump));
                    break;
                }
            }
            break;
        }
    }
    else{
        if(TypeSort == Chaos && AmountSort > Zero){
            Sort Instance(-One, AmountSort, TypeSort, Arry);
            QString SortArry = Instance.ChoiseSortingMethot();
            ui->Input->setText(SortArry);
            ui->Statistic->append("Cортировка хаосом.");
            ui->Statistic->append("Количество сравнений: " + QString::number (Instance.STAT[Chaos].Step));
            ui->Statistic->append("Количество замен: " + QString::number(Instance.STAT[Chaos].Jump));
        }
        else{
            QMessageBox::warning(this, "Внимание","Параметры сортировки заданы некорректно!");
        }
    }
}
void MainWindow::on_Clear_clicked()
{
    ui->Input->clear();
    ui->Statistic->clear();
}
