#include "mainwindow.h"
#include "QWindow"
#include <algorithm>
#include <vector>
#include <ctime>
#include "sort.h"
using namespace std;
enum Numbers { Zero, One, Two, Three, Four, Five};
void Sort::SortBubbleSort() {
    STAT[Bubble].Sort = Bubble;
    bool count = true;
    int Data_Amount = Amount - One;
    while (count) {
        count = false;
        for (int i = Zero; i < Data_Amount; i++) {
            if(SortingMark != AbsMin && SortingMark != AbsMax){
                if(SortingMark != Minimum){
                    if (Arryy[i] > Arryy[i + One]) {
                        count = true; double Element = Arryy[i];
                        Arryy[i] = Arryy[i + One]; Arryy[i + One] = Element;
                        STAT[Bubble].Jump++;
                    }
                }
                else{
                    if (Arryy[i] < Arryy[i + One]) {
                        count = true; double Element = Arryy[i];
                        Arryy[i] = Arryy[i + One]; Arryy[i + One] = Element;
                        STAT[Bubble].Jump++;
                    }
                }
            }
            else{
                if(SortingMark != AbsMin){
                    if (abs(Arryy[i]) > abs(Arryy[i + One])) {
                        count = true; double Element = Arryy[i];
                        Arryy[i] = Arryy[i + One]; Arryy[i + One] = Element;
                        STAT[Bubble].Jump++;
                    }
                }
                else{
                    if (abs(Arryy[i]) < abs(Arryy[i + One])) {
                        count = true; double Element = Arryy[i];
                        Arryy[i] = Arryy[i + One]; Arryy[i + One] = Element;
                        STAT[Bubble].Jump++;
                    }
                }
            }
            STAT[Bubble].Step++;
        }
        Data_Amount--;
    }
}
void Sort::SortQuickSort() {
    STAT[Quick].Sort = Quick;
    PartOfQuickSort1(Zero, Amount - One);

}
void Sort::PartOfQuickSort1(int eFirst, int eLast){
    int first = eFirst, last = eLast;
    double middle = Arryy[(first + last) / Two];
    do
    {
        if(SortingMark != AbsMin && SortingMark != AbsMax){
            if(SortingMark != Minimum){
                while (Arryy[first] < middle) {STAT[Quick].Step++; first++;}
                while (Arryy[last] > middle) {STAT[Quick].Step++; last--;}
            }
            else{
                while (Arryy[first] > middle){ STAT[Quick].Step++; first++;}
                while (Arryy[last] < middle) {STAT[Quick].Step++; last--;}
            }
        }
        else{
            if(SortingMark != AbsMin){
                while (abs(Arryy[first]) < abs(middle)) {STAT[Quick].Step++; first++;}
                while (abs(Arryy[last]) > abs(middle)) {STAT[Quick].Step++; last--;}
            }
            else{
                while (abs(Arryy[first]) > abs(middle)) {STAT[Quick].Step++; first++;}
                while (abs(Arryy[last]) < abs(middle)) {STAT[Quick].Step++; last--;}
            }
        }
        if (first <= last)
        {
            if (first != last && Arryy[first] != Arryy[last])
            {
                swap(Arryy[first], Arryy[last]);
                STAT[Quick].Jump++;
            }
            first++;
            last--;
        }
         STAT[Quick].Step++;
    } while (first < last);
    if (eFirst < last) {PartOfQuickSort1(eFirst, last);}
    if (first < eLast) {PartOfQuickSort1(first, eLast);}
}
void Sort::PartOfMergeSort1(vector <double> *Part, int Step) {
    bool count = true;
    Step--;
    int STEP = Step;
    while (count) {
        count = false;
        for (int i = Zero; i < STEP; i++) {
            if(SortingMark != AbsMin && SortingMark != AbsMax){
                if(SortingMark != Minimum){
                    if ((*Part)[i] > (*Part)[i + One]) {
                        count = true; double Element = (*Part)[i];
                        (*Part)[i] = (*Part)[i + One]; (*Part)[i + One] = Element;
                        STAT[Merge].Jump++;
                    }
                }
                else{
                    if ((*Part)[i] < (*Part)[i + One]) {
                        count = true; double Element = (*Part)[i];
                        (*Part)[i] = (*Part)[i + One]; (*Part)[i + One] = Element;
                        STAT[Merge].Jump++;
                    }
                }
            }
            else{
                if(SortingMark != AbsMin){
                    if (abs((*Part)[i]) > abs((*Part)[i + One])) {
                        count = true; double Element = (*Part)[i];
                        (*Part)[i] = (*Part)[i + One]; (*Part)[i + One] = Element;
                        STAT[Merge].Jump++;
                    }
                }
                else{
                    if (abs((*Part)[i]) < abs((*Part)[i + One])) {
                        count = true; double Element = (*Part)[i];
                        (*Part)[i] = (*Part)[i + One]; (*Part)[i + One] = Element;
                        STAT[Merge].Jump++;
                    }
                }
            }
        }
        STEP--;
        STAT[Merge].Step++;
    }
}
void Sort::SortMergeSort() {
    STAT[Merge].Sort = Merge;
    int Mid = Amount / Two;
    if (Amount % Two != Zero){
        Mid++;
    }
    int Step = Two;
    int count = Zero;
    int j = Mid;
    vector <double> Part;
    vector <double> Merge_;
    while (Step < Amount) {
        for (int i = Zero; i < Mid; i++) {
            if (count != Step) {
                Part.push_back(Arryy[i]);
                count++;
                if (j < Amount) {
                    Part.push_back(Arryy[j]);
                    count++;
                }
            }
            if (count == Step) {
                count = Zero;
                PartOfMergeSort1(&Part, Step);
                for (int index = Zero; index < Step; index++) {
                    Merge_.push_back(Part[index]);
                }
                Part.clear();

            }
            j++;
            STAT[Merge].Step++;
        }
        j = Mid;
        count = Zero;
        int size = Merge_.size();
        int ost = Amount - size;
        if (size != Amount) {
            PartOfMergeSort1(&Part, ost);
            for (int index = Zero; index < ost; index++) {
                Merge_.push_back(Part[index]);
                STAT[Merge].Step++;
            }
        }
        Part.clear();
        Arryy = Merge_;
        Merge_.clear();
        Step *=Two;
    }
    Merge_ = Arryy;
    PartOfMergeSort1(&Merge_, Amount);
    Arryy = Merge_;
    Merge_.clear();
}
void Sort::SortSelectionSort() {
    STAT[Selection].Sort = Selection;
    double Search;
    double Cup;
    int Key = Zero;
    int Counter = Zero;
    while (Counter < Amount) {
        Search = Arryy[Counter];
        for (int i = Counter + One; i < Amount; i++) {
            if(SortingMark != AbsMin && SortingMark != AbsMax){
                if(SortingMark != Minimum){
                    if (Search > Arryy[i]) {
                        Search = Arryy[i]; Key = i;
                    }
                }
                else{
                    if (Search < Arryy[i]) {
                        Search = Arryy[i]; Key = i;
                    }
                }
            }
            else{
                if(SortingMark != AbsMin){
                    if (abs(Search) > abs(Arryy[i])) {
                        Search = Arryy[i]; Key = i;
                    }
                }
                else{
                    if (abs(Search) < abs(Arryy[i])) {
                        Search = Arryy[i]; Key = i;
                    }
                }
            }
            STAT[Selection].Step++;
        }
        if (Key != (Counter)) {
            Cup = Arryy[Counter];
            Arryy[Counter] = Arryy[Key];
            Arryy[Key] = Cup;
            STAT[Selection].Jump++;
        }
        Counter++;
        Key = Counter;
    }
}
void Sort::SortShellSort() {
    STAT[Shell].Sort = Shell;
    int Size = static_cast<int>(Amount / 1.2);
    while (Size > Zero) {
        for (int i = Zero; i < Amount; i++) {
            int size = i + Size;
            if (size < Amount) {
                if(SortingMark != AbsMin && SortingMark != AbsMax){
                    if(SortingMark != Minimum){
                        if (Arryy[size] < Arryy[i]) {
                            double Element = Arryy[i]; Arryy[i] = Arryy[size];
                            Arryy[size] = Element; STAT[Shell].Jump++;
                        }
                    }
                    else{
                        if (Arryy[size] > Arryy[i]) {
                            double Element = Arryy[i]; Arryy[i] = Arryy[size];
                            Arryy[size] = Element; STAT[Shell].Jump++;
                        }
                    }
                }
                else{
                    if(SortingMark != AbsMin){
                        if (abs(Arryy[size]) < abs(Arryy[i])) {
                            double Element = Arryy[i]; Arryy[i] = Arryy[size];
                            Arryy[size] = Element; STAT[Shell].Jump++;
                        }
                    }
                    else{
                        if (abs(Arryy[size]) > abs(Arryy[i])) {
                            double Element = Arryy[i]; Arryy[i] = Arryy[size];
                            Arryy[size] = Element; STAT[Shell].Jump++;
                        }
                    }
                }
            }
            STAT[Shell].Step++;
        }
        Size = static_cast<int>(Size / 1.2);
    }
}
void Sort::SortChaosSort(){
    srand(time(NULL));
    int Size = Amount/2;
    for (int i = Zero; i < Size; i++) {
        double Element = Arryy[i];
        double Rand = rand() % Amount;
        Arryy[i] = Arryy[Rand];
        Arryy[Rand] = Element;
        STAT[Chaos].Step++;
        STAT[Chaos].Jump++;
    }
}
QString Sort::ChoiseSortingMethot(){
    QString ArryyStr = "";
    vector<double> CopyArry;
    switch (SortingType) {
    case Bubble:
        SortBubbleSort();
        break;
    case Quick:
        SortQuickSort();
        break;
    case Merge:
        SortMergeSort();
        break;
    case Selection:
        SortSelectionSort();
        break;
    case Shell:
        SortShellSort();
        break;
    case Chaos:
        SortChaosSort();
        break;
    case Raiting:
        bool key = true;
        CopyArry = Arryy;
        SortBubbleSort();
        Arryy = CopyArry;
        SortQuickSort();
        Arryy = CopyArry;
        SortMergeSort();
        Arryy = CopyArry;
        SortSelectionSort();
        Arryy = CopyArry;
        SortShellSort();
        while(key){
            key = false;
            int Chaos_ = Chaos - 1;
            for (int i = Bubble; i < Chaos_; i++){
                if((STAT[i].Jump + STAT[i].Step) > (STAT[i + One].Jump + STAT[i + One].Step)){
                    key = true; Stat Element = STAT[i];
                    STAT[i] = STAT[i + One];
                    STAT[i + One] = Element;
                }
            }
            Chaos_--;
        }
    }
    for(int i = Zero; i < Amount; i++){
        ArryyStr.push_back(QString::number(Arryy[i]) + " ");
    }
    Arryy.clear();
    return ArryyStr;
}

