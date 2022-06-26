#include <iostream>
#include <ctime>
#include "SBT-keshe.h"
#include<string>
using namespace std;


//建树
FlightInfo* CreateTree(int arr[], int NodesNum)
{

    FlightInfo *root = new FlightInfo;
    root = NULL;


    if (NodesNum == 0)
        return root;
    else
    {
        for (int i = 0; i < NodesNum; i++)
        {
            root = InsertSBT(root, arr[i]);
            Maintain(root);
            cout << "第"<<i<<"次调整完毕" <<endl;
        }
        return root;
    }
}

/*
//求后继
FlightInfo* get_next(FlightInfo* T,int value)
{
    if(T == NULL)
        return T;
    //输入的值比根大，寻右子树
    if(value>=T->value)
        return get_next(T->rchild,value);
    else
    {
        FlightInfo* t=get_next(T->lchild,value);
        return t->value==value?T:t;
    }
}
*/

//获取size
int getNodeSize(FlightInfo* T)
{
    if(T == NULL)
        return 0;
    return T->size;
}

//左旋
void LeftRotate(FlightInfo* &T)
{
    FlightInfo* temp = T->rchild;
    T->rchild = temp->lchild;
    temp->lchild = T;
    temp->size = getNodeSize(T);
    T->size = getNodeSize(T->lchild) + getNodeSize(T->rchild) + 1;
    T = temp;
    free(temp);
}

//右旋
void RightRotate(FlightInfo* &T)
{
    FlightInfo* temp = T->lchild;
    T->lchild = temp->rchild;
    temp->rchild = T;
    temp->size = getNodeSize(T);
    T->size = getNodeSize(T->lchild) + getNodeSize(T->rchild) + 1;
    T = temp;
    free(temp);
}

//插入
FlightInfo* InsertSBT(FlightInfo* T, int qifeitime, int daodatime, int price, string hangbanhao, string qidian, string zhongdian, int jixing, int date)
{

    if (T == NULL)
    {
        FlightInfo* node = new FlightInfo;
        node->qifeitime = qifeitime;
        node->daodatime =daodatime;
        node->price = price;
        node->hangbanhao = hangbanhao;
        node->qidian = qidian;
        node->zhongdian = zhongdian;
        node->jixing = jixing;
        node->date = date;
        node->size = 1;
        node->rchild = node->lchild = NULL;
        return node;
    }
    else
    {

        if (T->hangbanhao == hangbanhao)
        {
            cout << "该趟航班已存在，不用再添加啦！" <<endl;
        }
        else if(T->daodatime > daodatime) {     //按到达时间排序
            T->size += 1;
            T->lchild = InsertSBT(T->lchild, qifeitime, daodatime, price, hangbanhao, qidian, zhongdian, jixing, date);
        }
        else {
            T->size += 1;
            T->rchild = InsertSBT(T->rchild, qifeitime, daodatime, price, hangbanhao, qidian, zhongdian, jixing, date);
        }
        return T;

    }
}

/*
//删除
void DeleteSBT(FlightInfo* &T,int x)
{
    if (NULL == T)
    {
        return;
    }
    --T->size;
    if (x < T->value)
    {
        DeleteSBT(T->lchild,x);
        Maintain(T->lchild);
    }
    else if (T->value < x)
    {
        DeleteSBT(T->rchild,x);
        Maintain(T->rchild);
    }
    else {      //T->value == x
        if (T->lchild != NULL && T->rchild != NULL) {
            if (getNodeSize(T->lchild) < getNodeSize(T->rchild)) {
                T->value = FindMin(T->rchild)->value;       //找后继
                DeleteSBT(T->rchild, T->value);
                Maintain(T->rchild);
            } else {
                T->value = FindMax(T->lchild)->value;       //找前驱
                DeleteSBT(T->lchild, T->value);
                Maintain(T->rchild);
            }
        } else {
            FlightInfo *oldNode = T;
            T = ((T->lchild != NULL) ? T->lchild : T->rchild);
            delete oldNode;
            oldNode = NULL;
        }
    }
}
*/

//求最大值
FlightInfo* FindMax(FlightInfo* T)
{
    FlightInfo* pre;
    if (T == NULL)
        return T;
    while (T!=NULL) {
        pre = T;
        T = T->rchild;
    }
    return pre;
}

//求最小值
FlightInfo* FindMin(FlightInfo* T)
{
    FlightInfo* pre;
    if (T == NULL)
        return T;
    while (T!=NULL) {
        pre = T;
        T = T->lchild;
    }
    return pre;
}

/*
//求前驱节点
FlightInfo* FindPreNode(FlightInfo* T,int x)
{
    FlightInfo* pre;
    if (T == NULL)
        return T;
    while(T != NULL)
    {
        if (T->value == x)
            break;
        else if (T->value > x) {
            pre = T;
            T = T->lchild;
        }
        else {
            pre = T;
            T = T->rchild;
        }
    }
    return pre;
}
*/

//中序遍历打印
void midTraval(FlightInfo* T)
{
    if(T->lchild != NULL)
        midTraval(T->lchild);
    cout <<T->hangbanhao<<" "<<T->qidian<<" "<<T->zhongdian<<" "<<T->date<<" "<<T->qifeitime<<" "<<T->daodatime<<" "<<T->jixing<<" "<<T->price<<endl;
    if(T->rchild != NULL)
    {
        midTraval(T->rchild);
    }
}

//查找(按起飞时间)
FlightInfo* SearchSBT(FlightInfo* T, int qifeitime)
{
    if(T == NULL)
    {
        return T;
    }

    else if(qifeitime == T->qifeitime)
        return T;
    else if(qifeitime > T->qifeitime)
        return SearchSBT(T->rchild, qifeitime);
    else
        return SearchSBT(T->lchild,qifeitime);
}

//修复SBT
void Maintain(FlightInfo* &T)
{

    if (T->lchild != NULL)
    {
        if (getNodeSize(T->rchild) < getNodeSize(T->lchild->lchild))
        {
            RightRotate(T);
        }
        else if (getNodeSize(T->rchild) < getNodeSize(T->lchild->rchild))
        {


            LeftRotate(T->lchild);
            RightRotate(T);
        }
    }
    if (T->rchild != NULL)
    {
        if (getNodeSize(T->lchild) < getNodeSize(T->rchild->rchild))
        {
            LeftRotate(T);
        }
        else if (getNodeSize(T->lchild) < getNodeSize(T->rchild->lchild))
        {
            RightRotate(T->rchild);
            LeftRotate(T);
        }
    }
    if (T->lchild != NULL)
    {
        Maintain(T->lchild);
    }
    if (T->rchild != NULL)
    {
        Maintain(T->rchild);
    }
}



