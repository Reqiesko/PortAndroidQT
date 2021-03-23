#include "mainwindow.h"
#ifndef SORT_H
#define SORT_H
#include <vector>
using namespace std;
enum Mark { Maximum, Minimum, AbsMin, AbsMax};
enum Type {Bubble, Quick, Selection, Shell, Merge, Chaos, Raiting};
class Sort
{
private:
    int SortingType;
    int SortingMark;
    int SortingAddition;
    int Amount;
    vector <double> Arryy;
public:
    Sort(int SortingMark, int Amount, int SortingType, vector <double> Arryy) {
        this->SortingMark = SortingMark;    // выбор сортировки
        this->Amount = Amount;
        this->SortingType = SortingType;    // выбор метода
        this->Arryy = Arryy;
    }
    ~Sort() {
        Arryy.clear();
    }
    struct Stat {
        int Step = 0;
        int Jump = 0;
        int Sort = 0;
    };
    Stat STAT[6];
    void SortBubbleSort();
    void SortSelectionSort();
    void SortInsertionSort();
    void SortShellSort();
    void SortQuickSort();
    void PartOfQuickSort1(int, int);
    void SortMergeSort();
    void PartOfMergeSort1(vector<double>*, int);
    void SortChaosSort();
    QString ChoiseSortingMethot();
};
#endif // SORT_H
