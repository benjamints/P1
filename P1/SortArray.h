#pragma once
#include <iostream>
using namespace std;


class STUDENT
{
private:
    string ten;
    float diem;

public:
    STUDENT();
    STUDENT(string, float);
    friend ostream& operator<<(ostream& out, STUDENT& a) {
        out << a.ten << " " << a.diem;
        return out;
    }

    bool operator<(const STUDENT& a) {
        return this->ten < a.ten ;
    }
    bool operator>(const STUDENT& a) {
        return this->ten > a.ten;
    }


};


STUDENT::STUDENT()
{
    this->ten = "";
    this->diem = 0.0;
}

STUDENT::STUDENT(string t, float d)
{
    this->ten = t;
    this->diem = d;
}


template <class T>
class SortAlgorithm
{
private:
    static SortAlgorithm* _algorithm;
    void (*currentAlgorithm)(T[], int);
    SortAlgorithm();
public:
    static SortAlgorithm<T>* getObject(void(*pAlg)(T[], int) = NULL);
    static void SelectionSort(T[], int);
    static void InsertionSort(T[], int);
    static void InterchangeSort(T[], int);
    void Sort(T[], int);
};


template <class T>
SortAlgorithm<T>* SortAlgorithm<T>::_algorithm = NULL;

template <class T>
SortAlgorithm<T>::SortAlgorithm() {
    currentAlgorithm = InsertionSort;
}

template <class T>
SortAlgorithm<T>* SortAlgorithm<T>::getObject(void (*pAlg)(T[], int)) {
    if (_algorithm == NULL) {
        _algorithm = new SortAlgorithm();
    }
    if (pAlg != NULL)
    {
        _algorithm->currentAlgorithm = pAlg;
    }
    return _algorithm;
}

template <class T>
void SortAlgorithm<T>::Sort(T a[], int n)
{
    if (currentAlgorithm != NULL) {
        currentAlgorithm(a, n);
    }
}

template <class T>
void SortAlgorithm<T>::SelectionSort(T a[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min != i) {
            T temp = a[min]; a[min] = a[i]; a[i] = temp;
        }
    }
}

template <class T>
void SortAlgorithm<T>::InsertionSort(T a[], int n) {
    T x;
    for (int i = 1; i < n; i++) {
        x = a[i];
        int pos = i;
        for (; (pos > 0) && (a[pos - 1] > x); pos--) {
            a[pos] = a[pos - 1];
        }
        a[pos] = x;
    }
}

template <class T>
void SortAlgorithm<T>::InterchangeSort(T a[], int n) {
    T temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}









