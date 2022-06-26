//
// Created by Lenovo on 2020/12/26.
//

#ifndef UNTITLED1_WINNERTREE_H
#define UNTITLED1_WINNERTREE_H

#endif //UNTITLED1_WINNERTREE_H

struct WinnerT
{
    int *winner;
    int *data;
    int size;
};

bool isEmpty(WinnerT* T);
bool isInteger(double x);
bool winPrint(WinnerT* T);
void WTInsert(WinnerT* T,int x);
void WTSearch(WinnerT *T,int x);
void WTInitialize(WinnerT* T);
void WTDelete(WinnerT* T, int num);
void Replay(WinnerT* T);
int* WTsort(WinnerT* T, int num);