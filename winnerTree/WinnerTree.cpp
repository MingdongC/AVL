/*
by  mingdong
WinnerTree  函数一览：
    插入      WTInsert()
    查找      WTSearch()
    删除      WTDelete()
    重赛      Replay()
    判空      isEmpty()
    判整      isInteger()
    初始化     WTInitialize()
    打印整棵树   winPrint()
    排序      WTsort()
 */
#include <iostream>
#include <math.h>
#include "WinnerTree.h"
#include <limits.h>
#include <queue>
#include <ctime>
#define capacity 100
int inf = INT_MAX;
using namespace std;

//该插入函数实现的是一次插入n个值，直到size满足2^k次方
void WTInsert(WinnerT* T,int x)
{
    int *dataT=T->data,*winnerT=T->winner;              //定义两个指针指向T->data和T->winner
    int size = T->size;
    int temp = 0;
    while(temp - log(T->size)/log(2) < 0)                   //temp为大于log（size）底是2最小整数，例如size等于10，那temp就等于4
        temp++;
    T->size = pow(2,temp);
    T->data = (int *)malloc((T->size+1)*sizeof(int));       //这里重新分配大小为2^temp次方的空间
    T->winner = (int *)malloc(T->size*sizeof(int));
    for(int i=0;i<size;i++)
        T->data[i+1] = dataT[i+1];                                  //重新赋值
    for(int i=size+1;i<=T->size;i++)
        T->data[i] = x;
    free(dataT);                                                       //原来分配的空间释放
    free(winnerT);
}

//搜索函数简单实现为按data下标挨个遍历，时间复杂度为O(n)
void WTSearch(WinnerT *T,int x)
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

//判空函数
bool isEmpty(WinnerT* T)
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

//为初始参赛者进行第一轮比赛
void WTInitialize(WinnerT* T)
{
    if(isEmpty(T))
        return;
    while(!isInteger(log(T->size)/log(2)))           //若参赛选手log2之后不是整数则补齐
        WTInsert(T,inf);
    int numPlayers = T->size;

    for(int i=0;i<numPlayers-1;i++)         //初始化winner数组
        T->winner[i+1] = -1;

    int parents;
    int maxlIner;                        //maxlIner 是最底层最左端内部结点的编号
    for(maxlIner=1;2*maxlIner <= numPlayers-1;maxlIner+=maxlIner);      //maxlIner的计算方法
    int lowExt = 2*(numPlayers - maxlIner);
    int offset = 2*maxlIner - 1;

    for(int j=1;j<=numPlayers;j+=2)                     //参赛选手比赛
    {
        if(j<=lowExt)                                   //计算双亲结点编号
            parents = (j+offset)/2;
        else
            parents = (j-lowExt+numPlayers-1)/2;

        if(T->data[j] <= T->data[j+1])
            T->winner[parents] = j;
        else
            T->winner[parents] = j+1;
    }
    int left = maxlIner;                    //left和right为自底向上的赢者树的最左内部结点和最右内部结点
    int right = numPlayers-1;
    while(left != right)                    //本层的最右等于最左即为根结点，比赛结束
    {
        for(int i=left;i<right;i+=2)
        {
            if (T->data[T->winner[i]] <= T->data[T->winner[i + 1]])
                T->winner[i/2] = T->winner[i];
            else
                T->winner[i/2] = T->winner[i+1];
        }
        left /=2;                          //进入到上一层
        right /=2;
    }
    T->winner[0] = T->winner[1];            //把赢者放在T->winner[0]的位置保存
}

//打印赢者树
bool winPrint(WinnerT* T)
{
    cout <<"==========开始打印二叉树=========="<<endl;
    queue<int> q;
    int temp;
    if(isEmpty(T))
        return false;
    q.push(1);
    while(!q.empty())
    {
        static int hight = 1;                       //hight记录当前的层数
        for(int i=0;i<pow(2,hight-1);i++)          //完全二叉树当前层数和当前层结点数量的关系为n = 2^(h-1)
        {

            if (T->winner[2 * q.front()] >= 0)      //左孩子存在的话把左孩子压进去
                q.push(2 * q.front());
            if (T->winner[2 * q.front() + 1] >= 0)      //右孩子存在的话把右孩子压进去
                q.push(2 * q.front() + 1);
            temp = q.front();
            cout <<T->data[T->winner[temp]]<<" ";
            q.pop();
        }
        cout <<endl;
        hight++;
    }
    for(int k=1;k<=T->size;k++)
        cout <<T->data[k]<<" ";
    cout <<endl;
    return true;
}

//排序函数
int* WTsort(WinnerT* T, int num)
{
    int* arr = (int *)malloc(num*sizeof(int));
    for(int i=0;i<num;i++)
    {
        arr[i] = T->data[T->winner[0]];                 //每次都将T->winner[0]对应的data值输出
        WTDelete(T,T->winner[0]);                   //输出后删除
    }
    return arr;
}


void WTDelete(WinnerT* T, int num)
{
    T->data[num] = inf;                 //将对应的data值置为最大，即删除，删除后再将剩余选手重赛
    Replay(T);
}

//重赛函数，由于参赛选手的数值发生改变，所以需要重赛。重赛选手数量不变。
void Replay(WinnerT* T)
{
    int numPlayers = T->size;
    int parents,temp;
    int maxlIner;                        //maxlIner 是最底层最左端内部结点的编号
    for(maxlIner=1;2*maxlIner <= numPlayers-1;maxlIner+=maxlIner);      //maxlIner的计算方法
    int lowExt = 2*(numPlayers - maxlIner);
    int offset = 2*maxlIner - 1;

    parents = (T->winner[0]<=lowExt)?(T->winner[0]+offset)/2:(T->winner[0]-lowExt+numPlayers-1)/2;  //计算双亲结点编号
    temp = (T->winner[0]/2 == 1)?T->winner[0]+1:T->winner[0]-1;                                     //temp保存的是被删结点的兄弟的下标

    T->winner[parents] = (T->data[T->winner[0]]>T->data[temp])?temp:T->winner[0];                   //被删结点与兄弟结点进行重赛，赢得保存在双亲结点
    int k = parents/2;                              //K保存的是父亲结点的父亲结点
    while(k!=0)                                     //进行重赛直到K=0即到了根结点，退出
    {
        T->winner[k] = (T->data[T->winner[2*k]]>T->data[T->winner[2*k+1]])?T->winner[2*k+1]:T->winner[2*k];
        parents = k;
        k = parents/2;
    }
    T->winner[0] = T->winner[1];                    //每次都将赢者保存在T->winner[0]
}

//int main()
//{
////    int a[] = {3566,2472,1180,2948,2286,4414,1207,2110,1951,4271,
////               1690,3574,4297,4232,2609,1367,3893,1693,1997,1589,
////               3140,2063,2359,3291,2699,4179,2333,3786,1458,3427};
////    WinnerT* T = (WinnerT* )malloc(sizeof (WinnerT));
////    T->size = 30;
////    T->winner = (int *)malloc(10000*sizeof(int));
////    T->data = (int *)malloc(10001*sizeof(int));
////    for(int i=0;i<T->size;i++)
////    {
////        T->data[i+1] = a[i];
////    }
//
//    //2000万个随机数取前100万个小的
//    WinnerT* T = (WinnerT* )malloc(sizeof (WinnerT));
//    int number = 20000000;
//    T->size = number;
//    T->winner = (int *)malloc(number*sizeof (int));
//    T->data = (int *)malloc((number+1)*sizeof (int));
//    int max = number,min = 1;
//    clock_t statTime,endTime;
//    for(int i=0;i<number;i++)
//    {
//        unsigned long data = rand() % max + min;
//        T->data[i+1] = data;
//    }
//
//    statTime = clock();                 //开始计时
//    WTInitialize(T);
//
//    //打印二叉树
////    if(winPrint(T))
////        cout <<"打印成功！"<<endl;
////    else
////        cout <<"打印失败！"<<endl;
//
//    int num = 1000000;                          //用赢者树进行排序
//    int* arr = WTsort(T,num);
//    endTime = clock();
//    cout <<"赢者树的排序时间为："<<(double)(endTime-statTime) / CLOCKS_PER_SEC<<"s"<<endl;
//    free(T);
//    return 0;
//}
