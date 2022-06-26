#include<stdio.h>
#include<stdlib.h>
#include <ctime>
#include <math.h>
using namespace std;

/* 二叉排序树的节点结构定义 */
//最小波动值来衡量这种情况： 该天的最小波动值 = min{|该天以前某一天的营业额-该天营业额|}
//设置两个value值，一个为日期date一个为营业额turnover
//插入的时候同时计算波动值
typedef struct BSTNode{
    BSTNode *lchild,*rchild;
    int date,turnover,fluctuation;
}BSTNode,*BSTree;
int minFV=10000000;

bool searchBSTNode(BSTree T,int date,int turnover,BSTree p,BSTree *f) {
    //如果为空节点
    if (!T){
        *f = p;
        return false;
    } else{
        if (T->date==date){
            *f = T;
            return true;
        } else if (T->date>date){
            return searchBSTNode(T->lchild,date,turnover,T,f);
        } else{
            return searchBSTNode(T->rchild,date,turnover,T,f);
        }

    }
}

bool insertBSNode(BSTree *T,int date,int turnover){
    BSTree f=NULL;
    if (!searchBSTNode(*T,date,turnover,NULL,&f)){
        BSTree s=(BSTree)malloc(sizeof(BSTNode));
        s->date=date;
        s->turnover=turnover;
        s->lchild=NULL;
        s->rchild=NULL;
        //如果f为空,则表明该树为空树
        if(!f){
            *T=s;
        } else{
            if (f->date>date){
                f->lchild=s;
            } else{
                f->rchild=s;
            }
        }
        return true;
    }
    //如果查找成功则插入失败
    return false;
}

//求最大值，即求右子树的最右边的值
int returnMAXValue(BSTree T,BSTree p,BSTree *f){
    //如果节点为空,则返回之前访问的最后一个值
    if (!T){
        *f=p;
        return (*f)->date;
    }else{
        return returnMAXValue(T->rchild,T,f);
    }
}

//求前驱  求左子树的最大值
int returnForwardNode(BSTree T,int date){
    if (!T->lchild){
        return false;
    }
    return returnMAXValue(T->lchild,T,NULL);
}

//中序遍历
void order(BSTree t)//中序输出
{
    if (t == NULL) {
        return;
    }
    order(t->lchild);
    printf("%d ", t->turnover);
    order(t->rchild);
}

//删除函数
int Delete(BSTree *p)
{
    BSTree q, s;
    //情况 1，结点 p 本身为叶子结点，直接删除即可
    if (!(*p)->lchild && !(*p)->rchild) {
        *p = NULL;
    }
    else if (!(*p)->lchild) { //p左子树为空，只需用结点 p 的右子树根结点代替结点 p 即可；
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }
    else if (!(*p)->rchild) {//右子树为空，只需用结点 p 的左子树根结点代替结点 p 即可；
        q = *p;
        *p = (*p)->lchild;//这里不是指针 *p 指向左子树，而是将左子树存储的结点的地址赋值给指针变量 p
        free(q);
    }
    else {//左右子树均不为空，采用第 2 种方式
        q = *p;
        s = (*p)->lchild;
        //遍历，找到结点 p 的直接前驱
        while (s->rchild)
        {
            q = s;
            s = s->rchild;
        }
        //直接改变结点 p 的值
        (*p)->date = s->date;
        //判断结点 p 的左子树 s 是否有右子树，分为两种情况讨论
        if (q != *p) {
            q->rchild = s->lchild;//若有，则在删除直接前驱结点的同时，令前驱的左孩子结点改为 q 指向结点的孩子结点
        }
        else {
            q->lchild = s->lchild;//否则，直接将左子树上移即可
        }
        free(s);
    }
    return true;
}
int DeleteBST(BSTree *T, int key)
{
    if (!(*T)) {//不存在关键字等于key的数据元素
        return false;
    }
    else
    {
        if (key == (*T)->date) {
            Delete(T);
            return true;
        }
        else if (key < (*T)->date) {
            //使用递归的方式
            return DeleteBST(&(*T)->lchild, key);
        }
        else {
            return DeleteBST(&(*T)->rchild, key);
        }
    }
}

//插入200w的数据
double returnInsertRunTime(BSTree *RT){
    double start, finish;
    start = clock();
    //BSTree RT=NULL;
    srand((unsigned)time(NULL));

    int arrRandom[2000000];
    //srand((int)time(0));  // 产生随机种子  把0换成NULL也行
    for (int i = 0; i < 2000000; i++)
    {
        arrRandom[i]=rand();
        insertBSNode(RT,arrRandom[i],1);
    }
    finish = clock();
    return (double)(finish - start) / CLOCKS_PER_SEC;

}

//查找200w次
//searchBSTNode(BSTree T,int date,int turnover,BSTree p,BSTree *f)
double returnFindRunTime(BSTree RT){
    double start, finish;
    start = clock();
    //BSTree RT=NULL;
    srand((unsigned)time(NULL));

    int arrRandom[2000000];
    //srand((int)time(0));  // 产生随机种子  把0换成NULL也行
    for (int i = 0; i < 2000000; i++)
    {
        arrRandom[i]=rand();
        BSTree f=NULL;
        searchBSTNode(RT,arrRandom[i],1,NULL,&f);
    }
    finish = clock();
    return (double)(finish - start) / CLOCKS_PER_SEC;

}

//删除200w次
double returnDelRunTime(BSTree *RT){
    double start, finish;
    start = clock();
    //BSTree RT=NULL;
    srand((unsigned)time(NULL));

    int arrRandom[2000000];
    for (int i = 0; i < 2000000; i++)
    {
        arrRandom[i]=rand();
        DeleteBST(RT, arrRandom[i]);
    }
    finish = clock();
    return (double)(finish - start) / CLOCKS_PER_SEC;

}

void returnMinFV(BSTree T,int turnover){
    if (T) {
        returnMinFV(T->lchild,turnover);
        if (abs(turnover-T->turnover)<minFV){
            minFV=abs(turnover-T->turnover);
        }
//        printf("%d",minFV);
//        printf("\n");
        returnMinFV(T->rchild,turnover);
    }
    return;
}

int main()
{
    BSTree T=NULL;
    int minFV_sum=0;
    //初始化数据
    int arr[]={3566, 2472, 1180, 2948, 2286, 4414, 1207, 2110, 1951, 4271,
               1690, 3574, 4297, 4232, 2609, 1367, 3893, 1693, 1997, 1589,
               3140, 2063, 2359, 3291, 2699, 4179, 2333, 3786, 1458, 3427};
    printf("显示30天营业额为：");
    for (int i = 0; i < 30; i++) {
    if(i==0){
        minFV=arr[i];
        insertBSNode(&T,i+1,arr[i]);
        minFV_sum+=minFV;
    } else{
        returnMinFV(T,arr[i]);
        minFV_sum+=minFV;

        insertBSNode(&T,i+1,arr[i]);
        minFV = 100000;
    }
        //每次插入的时候进行计算当天的波动值
    }
    printf("最小波动值之和是:%d\n", minFV_sum);
    //printf("\n");
    //order(T);
    BSTree *Temp=&T;
    printf("\n");
    //求最大值
    printf("%d",returnMAXValue(T,NULL,Temp));
    //求前驱
    //returnMAXValue(reinterpret_cast<BSTree>(&T), NULL, Temp);
    BSTree TRand=NULL;
    BSTree *Tp=&TRand;
    printf("\n");
    //插入200w数后的树
    printf("二叉排序树插入200w耗时：%f secs",returnInsertRunTime(Tp));
    printf("\n");
    //order(*Tp);
    //在树TRand中查找200w次
    printf("二叉排序树查找200w耗时：%f secs",returnFindRunTime(*Tp));
    printf("\n");
    //删除200w次的时间
    printf("二叉排序树删除200w耗时：%f secs",returnDelRunTime(Tp));
    printf("\n");

}
