//
// Created by mingdong on 2021/1/2.
//
/*
LoserTree败者树的主要函数一览：

    插入      LTInsert()
    查找      LTSearch()
    删除      LTDelete()
    重赛      Replay()
    判空      isEmpty()
    判整      isInteger()
    初始化     LTInitialize()
    打印整棵树   LosPrint()
    排序      LTSort()

*/
#include <iostream>
#include <math.h>
#include "LoserTree.h"
#include <limits.h>
#include <queue>
#include <ctime>

int inf = INT_MAX;
using namespace std;

//判空函数
bool isEmpty(LoserT* T)
{
    if(T->size == 0)
        return true;
    else
        return false;
}

//判整函数
bool isInteger(double x)
{
    if((x-floor(x))!=0 || x==0)
        return false;
    else
        return true;
}

//该插入函数实现的是一次插入n个值，直到size满足2^k次方
void LTInsert(LoserT *T,int x)
{
    int *dataT=T->data,*loserT=T->loser;              //定义两个指针指向T->data和T->loser
    int size = T->size;
    int temp = 0;
    while(temp - log(T->size)/log(2) < 0)                   //temp为大于log（size）底是2最小整数，例如size等于10，那temp就等于4
        temp++;
    T->size = pow(2,temp);
    T->data = (int *)malloc((T->size+1)*sizeof(int));       //这里重新分配大小为2^temp次方的空间
    T->loser = (int *)malloc(T->size*sizeof(int));
    for(int i=0;i<size;i++)
        T->data[i+1] = dataT[i+1];                                  //重新赋值
    for(int i=size+1;i<=T->size;i++)
        T->data[i] = x;
    free(dataT);                                                       //原来分配的空间释放
    free(loserT);
}

//查找
void LTSearch(LoserT *T,int x)
{
    int i = 1;
    if(isEmpty(T))
        return;
    while(i!=T->size+1)
    {
        if(T->data[i] == x)
            break;
        i++;
    }
    if(i == T->size+1)
        cout <<"找不到鸭！"<<endl;
    cout <<"找到了！，它的下标是："<<i<<endl;
}

//删除
void LTDelete(LoserT *T, int num)
{
    T->data[num] = inf;                 //将对应的data值置为最大，即删除，删除后再将剩余选手重赛
    Replay(T);
}

//重赛
void Replay(LoserT *T)
{
    int numPlayers = T->size;
    int parents,temp;                       //temp 用于比赛后的交换的暂存变量
    int maxlIner;                        //maxlIner 是最底层最左端内部结点的编号
    for(maxlIner=1;2*maxlIner <= numPlayers-1;maxlIner+=maxlIner);      //maxlIner的计算方法
    int lowExt = 2*(numPlayers - maxlIner);
    int offset = 2*maxlIner - 1;

    parents = (T->loser[0]<=lowExt)?(T->loser[0]+offset)/2:(T->loser[0]-lowExt+numPlayers-1)/2;  //计算双亲结点编号

    int winner;                     //winner变量暂存赢的选手的下标
    if(T->data[T->loser[0]]<=T->data[T->loser[parents]])        //被删结点与父节点比萨赢得保存在winner，输的留在父节点
    {
        winner = T->loser[0];
    }
    else
    {
        winner = T->loser[parents];
        T->loser[parents] = T->loser[0];
    }

    int k = parents/2;                              //K保存的是父亲结点的父亲结点
    while(k!=0)                                     //进行重赛直到K=0即到了根结点，退出
    {
        if(T->data[winner]>T->data[T->loser[k]])
        {
            temp = winner;
            winner = T->loser[k];
            T->loser[k] = temp;
        }
        k/=2;
    }
    T->loser[0] = winner;                    //每次都将赢者保存在T->winner[0]
}

//初始化
void LTInitialize(LoserT *T)
{
    if(isEmpty(T))
        return;
    while(!isInteger(log(T->size)/log(2)))           //若参赛选手log2之后不是整数则补齐
        LTInsert(T,inf);
    int numPlayers = T->size;

    for(int i=0;i<numPlayers-1;i++)         //初始化loser数组
        T->loser[i+1] = -1;

    int parents;
    int maxlIner;                        //maxlIner 是最底层最左端内部结点的编号
    for(maxlIner=1;2*maxlIner <= numPlayers-1;maxlIner+=maxlIner);      //maxlIner的计算方法
    int lowExt = 2*(numPlayers - maxlIner);
    int offset = 2*maxlIner - 1;

    int winnerSize = T->size/2;
    int *winner = (int *)malloc(winnerSize*sizeof(int));

    int left = maxlIner;                //left和right为自底向上的败者树的最左内部结点和最右内部结点
    int right = numPlayers-1;

    int j=1;
    for(int i=0;i<=right-left;i++)              //参赛选手进行第一轮淘汰赛
    {
        parents = (j<=lowExt)?(j+offset)/2:(j-lowExt+numPlayers-1)/2;         //计算双亲结点编号

        if(T->data[j]<=T->data[j+1])
        {
            T->loser[parents] = j+1;
            winner[i] = j;
        }
        else
        {
            T->loser[parents] = j;
            winner[i] = j+1;
        }
        j+=2;
    }

    left/=2;                                //进入上一层的内部结点
    right/=2;
    while(left != right)
    {
        int k = 0;                      //k指向要比赛的选手的地址
        int it = 0;                     //it指向保存胜利的选手的地址
        for(int i=left;i<=right;i++)     //胜者相互比赛，赢得存回winner，输的放到相应得T->loser
        {
            if(T->data[winner[k]]<=T->data[winner[k+1]])
            {
                winner[it] = winner[k];
                T->loser[i] = winner[k+1];
            }
            else
            {
                winner[it] = winner[k+1];
                T->loser[i] = winner[k];
            }
            it++;
            k+=2;
        }

        left/=2;
        right/=2;
    }

    if(T->data[winner[0]]<=T->data[winner[1]])          //此时left=right,最后两个胜者比较，赢的放到T->loser[0],输的放到T->loser[1]
    {
        T->loser[0] = winner[0];
        T->loser[left] = winner[1];
    }
    else
    {
        T->loser[0] = winner[1];
        T->loser[left] = winner[0];
    }
    free(winner);
    winner = NULL;
}

//打印整棵树  !!!慎用
bool LTPrint(LoserT *T)
{
    cout <<"==========开始打印二叉树=========="<<endl;
    queue<int> q;
    int temp;
    if(isEmpty(T))
        return false;
    cout <<T->data[T->loser[0]]<<endl;
    q.push(1);

    while(!q.empty())
    {
        static int hight = 1;                       //hight记录当前的层数
        for(int i=0;i<pow(2,hight-1);i++)          //完全二叉树当前层数和当前层结点数量的关系为n = 2^(h-1)
        {

            if (T->loser[2 * q.front()] >= 0)      //左孩子存在的话把左孩子压进去
                q.push(2 * q.front());
            if (T->loser[2 * q.front() + 1] >= 0)      //右孩子存在的话把右孩子压进去
                q.push(2 * q.front() + 1);
            temp = q.front();
            cout <<T->data[T->loser[temp]]<<" ";
            q.pop();
        }
        cout <<endl;
        hight++;
        if(temp == T->size-1)
            break;
    }
    for(int k=1;k<=T->size;k++)
        cout <<T->data[k]<<" ";
    cout <<endl;
    return true;
}

//排序
int* LTSort(LoserT *T, int num)
{
    int* arr = (int *)malloc(num*sizeof(int));
    for(int i=0;i<num;i++)
    {
        arr[i] = T->data[T->loser[0]];                 //每次都将T->winner[0]对应的data值输出
        LTDelete(T,T->loser[0]);                   //输出后删除
    }
    return arr;
}

int main()
{
//    int a[] = {3566,2472,1180,2948,2286,4414,1207,2110,1951,4271,
//               1690,3574,4297,4232,2609,1367,3893,1693,1997,1589,
//               3140,2063,2359,3291,2699,4179,2333,3786,1458,3427};
//    LoserT* T = (LoserT* )malloc(sizeof (LoserT));
//    T->size = 30;
//    T->loser = (int *)malloc(T->size*sizeof(int));
//    T->data = (int *)malloc((T->size+1)*sizeof(int));
//    for(int i=0;i<T->size;i++)
//    {
//        T->data[i+1] = a[i];
//    }
//    LTInitialize(T);
//
//    //    //打印二叉树
//    if(LTPrint(T))
//        cout <<"打印成功！"<<endl;
//    else
//        cout <<"打印失败！"<<endl;

    //    //2000万个随机数取前100万个小的
    LoserT* T = (LoserT* )malloc(sizeof (LoserT));
    int number = 20000000;
    T->size = number;
    T->loser = (int *)malloc(number*sizeof (int));
    T->data = (int *)malloc((number+1)*sizeof (int));
    int max = number,min = 1;
    clock_t statTime,endTime;
    for(int i=0;i<number;i++)
    {
        unsigned long data = rand() % max + min;
        T->data[i+1] = data;
    }

    statTime = clock();                 //开始计时
    LTInitialize(T);

//    //打印二叉树
//    if(LTPrint(T))
//        cout <<"打印成功！"<<endl;
//    else
//        cout <<"打印失败！"<<endl;

    int num = 1000000;                          //用败者树进行排序
    int* arr = LTSort(T,num);

//    //打印排好序的数组
//    for(int i=0;i<num;i++)
//        cout <<arr[i]<<" ";
//    cout <<endl;

    endTime = clock();
    cout <<"败者树的排序时间为："<<(double)(endTime-statTime) / CLOCKS_PER_SEC<<"s"<<endl;
    free(T);

    return 0;
}