//
// Created by Lenovo on 2021/1/3.
//

#ifndef LOSERTREE_LOSERTRES_H
#define LOSERTREE_LOSERTRES_H

#endif //LOSERTREE_LOSERTRES_H

struct LoserT
{
    int *loser;
    int *data;
    int size;
};

bool isEmpty(LoserT *T);
bool isInteger(double x);
bool LTPrint(LoserT *T);
void LTInsert(LoserT *T,int x);
void LTSearch(LoserT *T,int x);
void LTInitialize(LoserT *T);
void LTDelete(LoserT *T, int num);
void Replay(LoserT *T);
int* LTsort(LoserT *T, int num);