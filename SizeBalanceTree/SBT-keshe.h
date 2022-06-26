//
// Created by Lenovo on 2020/12/17.
//

#ifndef UNTITLED_MAIN_H
#define UNTITLED_MAIN_H

#endif //UNTITLED_MAIN_H

#include<string>
using namespace std;

//结点定义
struct FlightInfo
{
    int qifeitime,daodatime,price;
    char hangbanhao[30];
    char qidian[30],zhongdian[30];
    int date;
    int jixing;
    FlightInfo *lchild;
    FlightInfo *rchild;
    int size;
};

void LeftRotate(FlightInfo* &T);
void RightRotate(FlightInfo* &T);
FlightInfo* InsertSBT(FlightInfo* T, int value);
int getNodeSize(FlightInfo* T);
void DeleteSBT(FlightInfo* &T,int x);
FlightInfo* get_next(FlightInfo* T,int value);
FlightInfo* FindMax(FlightInfo* T);
FlightInfo* FindMin(FlightInfo* T);
FlightInfo* FindPreNode(FlightInfo* T, int x);
FlightInfo* SearchSBT(FlightInfo* T, int value);
void Maintain(FlightInfo* &T);
FlightInfo* CreateTree(int arr[], int NodesNum);
