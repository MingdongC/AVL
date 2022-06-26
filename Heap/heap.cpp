#include <iostream>
#include <ctime>
using namespace std;

int a[20000000];

/*
    目标：筛选区域为以索引i为树根的子树，找出该子树最大值，将其存放到索引i
    过程：从索引为i的结点开始往下，与较大的子节点交换值，向下搜索直到子树底部
    a - 待排序数组
    i - 筛选起始结点索引
    len - 排序元素数量
*/
void sift(int a[], int i, int len)
{
    int temp = a[i];
    int j = 2 * i;

    while(j <= len)
    {
        if(j < len && a[j] < a[j+1])    //取两个孩子结点中较大的
            j++;
        if(a[i] < a[j])                 //如者交果子节点比父节点大，则两换值，子节点成为新的父节点，继续向下筛选
        {
            a[i] = a[j];
            a[j] = temp;
            i = j;
            j = 2 * i;
        }
        else                            //如果父节点比子节点大，则说明找到了该子树的最大值，结束筛选
        {
            break;
        }
    }
    a[i] = temp;
}

/*+
堆排序（大顶堆）
a - 待排序的数组
len - 数组长度
*/
void heapSort(int a[], int len)
{
    int temp;
    int i;

    for (i = len-1; i > 0; i--)      //堆排序只能从下标为1开始排序，因此要把数组所有数据后一移位。下标0的数据不处理
    {
        a[i] =  a[i - 1];
    }


    for (i = len/2; i >= 1; i--)     //建堆过程（使得全树的父节点都比子节点大）
    {
        sift(a, i, len);
    }
    for (i = len - 1; i >= 2; i--)   //排序过程：每次从树根取值（该值必为最大值），放到树的最后一个结点n，并把该结点从树中移除。重复排序过程，直到将所有结点从树移除，排序结束
    {
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        sift(a, 1, i - 1);        //从树根取出最大值，取最尾树结点放到树根，此时树根不再为最大值，需要再对树根进行一次筛选过程，以确保树根仍然为最大值
    }
}


void printArray(int a[], int length)
{
    cout << "数组内容：";
    for(int i = 0; i < length; i++)
    {
        if(i == 0)
            cout << a[i];
        else
            cout << "," << a[i];

    }
    cout << endl;
}

//int main()
//{
//    double tim;
//    clock_t start, end;
//
//    start = clock();
//    //int a[1000000];
//    for (int i = 0; i < 20000000; i++)
//    {
//        a[i] = int(rand() % 2000000);
//    }
//
//    //printArray(a, sizeof(a)/sizeof(int));
//    heapSort(a, sizeof(a)/sizeof(int));
//    //printArray(a, sizeof(a)/sizeof(int));
//    end = clock();
//    tim = (double)(end - start) / CLOCKS_PER_SEC;
//
//    cout << "运行时间：" << tim << "s" <<  endl;
//    system("pause");
//    return 0;
//}