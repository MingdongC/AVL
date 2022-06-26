/*
 by mingdong
 2020.12.22

SizeBalanceTree框架说明：

 构建大小平衡树    BuildSBT()
 左旋            LeftRatate()
 右旋            RighRatate()
 修复SBT         Maintain()
 插入            InsertSBT()
 删除            DeleteSBT()
 求最大值         FindMax()
 求前驱           FindPreNode()
 求后继           get_next()
 查找            SearchSBT()


*/

#include <iostream>
#include <ctime>
#include "SBT.h"
using namespace std;


//建树
SBTNode* CreateTree(int arr[], int NodesNum)
{

    SBTNode *root = new SBTNode;
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

//求后继
SBTNode* get_next(SBTNode* T,int value)
{
    if(T == NULL)
        return T;
    //输入的值比根大，寻右子树
    if(value>=T->value)
        return get_next(T->rchild,value);
    else
    {
        SBTNode* t=get_next(T->lchild,value);
        return t->value==value?T:t;
    }
}

//获取size
int getNodeSize(SBTNode* T)
{
    if(T == NULL)
        return 0;
    return T->size;
}

//左旋
void LeftRotate(SBTNode* &T)
{
    SBTNode* temp = T->rchild;
    T->rchild = temp->lchild;
    temp->lchild = T;
    temp->size = getNodeSize(T);
    T->size = getNodeSize(T->lchild) + getNodeSize(T->rchild) + 1;
    T = temp;
    free(temp);
}

//右旋
void RightRotate(SBTNode* &T)
{
    SBTNode* temp = T->lchild;
    T->lchild = temp->rchild;
    temp->rchild = T;
    temp->size = getNodeSize(T);
    T->size = getNodeSize(T->lchild) + getNodeSize(T->rchild) + 1;
    T = temp;
    free(temp);
}

//插入
SBTNode* InsertSBT(SBTNode* T, int value)
{

    if (T == NULL)
    {
        SBTNode* node = new SBTNode;
        node->value = value;
        node->size = 1;
        node->rchild = node->lchild = NULL;
        return node;
    }
    else
    {

        if (T->value == value)
        {
            cout << "节点已存在" <<endl;
        }
        else if(T->value > value) {
            T->size += 1;
            T->lchild = InsertSBT(T->lchild, value);
        }
        else {
            T->size += 1;
            T->rchild = InsertSBT(T->rchild, value);
        }
        return T;

    }
}

//删除
void DeleteSBT(SBTNode* &T,int x)
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
            SBTNode *oldNode = T;
            T = ((T->lchild != NULL) ? T->lchild : T->rchild);
            delete oldNode;
            oldNode = NULL;
        }
    }
}

//求最大值
SBTNode* FindMax(SBTNode* T)
{
    SBTNode* pre;
    if (T == NULL)
        return T;
    while (T!=NULL) {
        pre = T;
        T = T->rchild;
    }
    return pre;
}

//求最小值
SBTNode* FindMin(SBTNode* T)
{
    SBTNode* pre;
    if (T == NULL)
        return T;
    while (T!=NULL) {
        pre = T;
        T = T->lchild;
    }
    return pre;
}

//求前驱节点
SBTNode* FindPreNode(SBTNode* T, int x)
{
    SBTNode* pre;
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

//查找
SBTNode* SearchSBT(SBTNode* T, int value)
{
    if(T == NULL)
    {
        return T;
    }

    else if(value == T->value)
        return T;
    else if(value > T->value)
        return SearchSBT(T->rchild, value);
    else
        return SearchSBT(T->lchild,value);
}

//修复SBT
void Maintain(SBTNode* &T)
{

    // case 1: 
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
    
    // case 2: 
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
    
    // case 3
    if (T->lchild != NULL)
    {
        Maintain(T->lchild);
    }

    // case 4
    if (T->rchild != NULL)
    {
        Maintain(T->rchild);
    }
}

/*
int main()
{

//    SBTNode* T = NULL;
//    int a[] = { 3566, 2472, 1180, 2948, 2286, 4414, 1207, 2110, 1951, 4271,
//                1690, 3574, 4297, 4232, 2609, 1367, 3893, 1693, 1997, 1589,
//                3140, 2063, 2359, 3291, 2699, 4179, 2333, 3786, 1458, 3427 };
//
//    T = InsertSBT(T,a[0]);
//
//    int temp=1, pre, next, sum=a[0];
//    int n = sizeof(a) / sizeof(int);
//    while (temp < n){
//        pre = FindPreNode(T, a[temp])->value;
//        next = get_next(T,a[temp])->value;
//        if (abs(pre-temp) >= abs(next-temp))
//            sum += abs(next-temp);
//        else
//            sum += abs(pre-temp);
//        T = InsertSBT(T,a[temp]);
//        temp++;
//    }
//    cout <<"大小平衡树"<<endl;
//    cout <<"最小波动值之和为："<<sum<<endl;

    SBTNode* root = NULL;
    SBTNode* node;
    int MAX = 2000000, MIN = 2000;
    clock_t startTime, endTime;
    startTime = clock();//计时开始
    for (int i = 0; i < 2000000; i++)
    {
        unsigned long data = rand() % (MAX - MIN + 1) + MIN;
        InsertSBT(root,data);
    }
    endTime = clock();//计时结束
    cout << "插入时间为: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    clock_t startTime1, endTime1;
    startTime1 = clock();
    for (int i = 0; i < 2000000; i++)
    {
        unsigned long data1 = rand() % (MAX - MIN + 1) + MIN;
        node = SearchSBT(root, data1);
    }
    endTime1 = clock();//计时结束
    cout << "查找时间为: " << (double)(endTime1 - startTime1) / CLOCKS_PER_SEC << "s" << endl;

    clock_t startTime2, endTime2;
    startTime2 = clock();
    for (int i = 0; i < 2000000; i++)
    {
        unsigned long data1 = rand() % (MAX - MIN + 1) + MIN;
        DeleteSBT(root, data1);
    }
    endTime2 = clock();//计时结束
    cout << "删除时间为: " << (double)(endTime2 - startTime2) / CLOCKS_PER_SEC << "s" << endl;
    getchar();
}

*/
