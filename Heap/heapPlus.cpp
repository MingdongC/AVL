//
// Created by Lenovo on 2021/1/6.
//

//小顶堆，未调通！！

#include <iostream>
#include <ctime>
#include<math.h>

using namespace std;

int data[20000001];


//自底向上调整
void Adjust(int arr[], int parents, int size)
{
    int temp;
    int child = 2*parents;
    while(parents <= size)
    {
        if(child<size && arr[child]>arr[child+1] )
            child++;
        if(arr[parents]>arr[child])
        {
            temp = arr[parents];
            arr[parents] = arr[child];
            arr[child] = temp;
            parents = child;
            child = 2 * parents;
        }
        else
            break;
    }

}

void buildHeap(int arr[], int size)
{
    for(int i=size/2;i>0;i--)
        Adjust(arr, i, size);
}

void heapSort(int arr[], int size, int num)
{
    int temp;
    for(int i=size;i>size-num;i--)
    {
        temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        Adjust(arr,1,i);
    }
}

int main()
{
    double tim;
    clock_t start, end;

    start = clock();
    //int a[1000000];
    for (int i = 1; i < 20000001; i++)
    {
        data[i] = int(rand() % 2000000);
    }

    int size = (sizeof(data)/sizeof(int))-1;
    buildHeap(data,size);
    //printArray(a, sizeof(a)/sizeof(int));
    heapSort(data, size, 1000000);
    //printArray(a, sizeof(a)/sizeof(int));
    end = clock();
    tim = (double)(end - start) / CLOCKS_PER_SEC;

    cout << "运行时间：" << tim << "s" <<  endl;
    system("pause");
    return 0;
}


