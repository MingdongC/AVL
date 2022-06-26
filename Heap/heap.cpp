#include <iostream>
#include <ctime>
using namespace std;

int a[20000000];

/*
    Ŀ�꣺ɸѡ����Ϊ������iΪ�������������ҳ����������ֵ�������ŵ�����i
    ���̣�������Ϊi�Ľ�㿪ʼ���£���ϴ���ӽڵ㽻��ֵ����������ֱ�������ײ�
    a - ����������
    i - ɸѡ��ʼ�������
    len - ����Ԫ������
*/
void sift(int a[], int i, int len)
{
    int temp = a[i];
    int j = 2 * i;

    while(j <= len)
    {
        if(j < len && a[j] < a[j+1])    //ȡ�������ӽ���нϴ��
            j++;
        if(a[i] < a[j])                 //���߽����ӽڵ�ȸ��ڵ��������ֵ���ӽڵ��Ϊ�µĸ��ڵ㣬��������ɸѡ
        {
            a[i] = a[j];
            a[j] = temp;
            i = j;
            j = 2 * i;
        }
        else                            //������ڵ���ӽڵ����˵���ҵ��˸����������ֵ������ɸѡ
        {
            break;
        }
    }
    a[i] = temp;
}

/*+
�����򣨴󶥶ѣ�
a - �����������
len - ���鳤��
*/
void heapSort(int a[], int len)
{
    int temp;
    int i;

    for (i = len-1; i > 0; i--)      //������ֻ�ܴ��±�Ϊ1��ʼ�������Ҫ�������������ݺ�һ��λ���±�0�����ݲ�����
    {
        a[i] =  a[i - 1];
    }


    for (i = len/2; i >= 1; i--)     //���ѹ��̣�ʹ��ȫ���ĸ��ڵ㶼���ӽڵ��
    {
        sift(a, i, len);
    }
    for (i = len - 1; i >= 2; i--)   //������̣�ÿ�δ�����ȡֵ����ֵ��Ϊ���ֵ�����ŵ��������һ�����n�����Ѹý��������Ƴ����ظ�������̣�ֱ�������н������Ƴ����������
    {
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        sift(a, 1, i - 1);        //������ȡ�����ֵ��ȡ��β�����ŵ���������ʱ��������Ϊ���ֵ����Ҫ�ٶ���������һ��ɸѡ���̣���ȷ��������ȻΪ���ֵ
    }
}


void printArray(int a[], int length)
{
    cout << "�������ݣ�";
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
//    cout << "����ʱ�䣺" << tim << "s" <<  endl;
//    system("pause");
//    return 0;
//}