#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP_VALUE(value1,value2) do\
{\
    int tempVaule = value1;\
    value1 = value2;\
    value2 = tempVaule;\
}while(0)

void print_value(int a[],int len)
{
    int i = 0;
    printf("升序排序结果:\n");
    for(i = 0;i < len;i++)
    {
        printf("%u ",a[i]);
    }
    printf("\n");
}


/**********************************************************************
 *                  选择排序
 * ********************************************************************/
void selectAccendingSort(int a[],int len)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    int minIndex = 0;
    for(;i < len - 1;i++)
    {
        minIndex = i;
        for(j=i+1;j < len;j++)
        {
            if(a[minIndex] > a[j])
            {
                minIndex = j;
            }
        }
        SWAP_VALUE(a[i],a[minIndex]);
    }
    print_value(a,len);

    return;
}

/**********************************************************************
 *                  冒泡排序
 * ********************************************************************/
void bubble_ascending_order(int a[],int n)
{
    int i = 0;
    int j = 0;
    for(;i < n-1;i++)
    {
        for (j=0;j<n-1-i;j++)
        {
            if(a[j] > a[j+1])
            {
                SWAP_VALUE(a[j+1],a[j]);
            }
        }
    }
    print_value(a,n);

    return;
}

/**********************************************************************
 *                  插入排序
 * ********************************************************************/
void insert_sort(int a[],int len)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    for(i = 1;i < len; i++)
    {
        temp = a[i];
        for(j=i-1;j>=0;j--)
        {
            if(temp < a[j])
            {
                a[j+1] = a[j];
            }
            else
            {
                break;
            }  
        }
        a[j+1] = temp;
    }
    print_value(a,len);

    return;
}


/**********************************************************************
 *                  希尔排序
 * ********************************************************************/
void shell_sort(int a[],int len)
{
    int i = 0;
    int j = 0;
    int h = len/2;
    int temp = 0;
    /* 设置步长因子 */
    for(;h > 0;h/=2)
    {
        for(i = h;i < len;i+=h)
        {
            temp = a[i];
            for(j=i-h;j >= 0;j-=h)
            {
                if(temp < a[j])
                {
                    a[j+h] = a[j];
                }
                else
                {
                    break;
                }
            }
            a[j+h]  = temp;
        }
    }
    print_value(a,len);

    return;
}

void _quick_sort(int a[],int left,int right)
{
    int i = left;
    int j = right;
    int temp = a[i];
    if(left >= right)
    {
        return;
    }
    while(i<j)
    {
        while(i < j && a[j] > temp)
        {
            j--;
        }
        a[i] = a[j];
        while(i < j && a[i] <= temp)
        {
            i++;
        }
        a[j] = a[i];
    }
    a[i] = temp;
    _quick_sort(a,left,i-1);
    _quick_sort(a,i+1,right);
}

void quick_sort(int a[],int len)
{
    _quick_sort(a,0,len-1);

    print_value(a,len);
}

void _merge(int a[],int b[],int left,int mid,int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= right)
    {
        b[k++] = (a[i] < a[j])?a[i++]:a[j++];
    }
    while (i <= mid)
    {
        b[k++] = a[i++];
    }
    while (j <= right)
    {
        b[k++] = a[j++];
    }

    for(i = 0;i<right-left+1;i++)
    {
        a[i+left] = b[i];
    }  
}

void _merge_sort(int a[],int b[],int left,int right)
{
    if(left < right)
    {
        int mid = (left+right) / 2;
        _merge_sort(a,b,left,mid);
        _merge_sort(a,b,mid+1,right);
        _merge(a,b,left,mid,right);
    }
}

void merge_sort(int a[],int len)
{
    int* ass = NULL;
    ass = (int*)malloc(sizeof(int) * len);
    if(NULL == ass)
    {
        return;
    }
    _merge_sort(a,ass,0,len-1);

    print_value(a,len);

    free(ass);

}

/* 对最小单元的某个节点形成的二叉树做heapify操作形成堆 */
/* 单个此结构体存在两个问题：
    1.如果第一个元素是最大值，那么会原样输出该数组
    2.因为从树中只取一个最大值和根节点进行交换，所以只能对发生交换的节点所在的子堆进行重新heapify
 */
void heapify(int a[],int max_index,int index)
{
    if(index >= max_index)
    {
        return;
    }
    /* 假设数组当前元素的编号为i，父节点编号（i-1）/2，左孩子节点：2*i+1，右孩子编号：2*i+2 */
    int left  = 2 * index + 1;
    int right = 2 * index + 2;
    /* 记录并找到该节点二叉树中最大值的节点编号 */
    int max = index;
    if(left < max_index && a[left] > a[max])
    {
        max = left;
    }
    if(right < max_index && a[right] > a[max])
    {
        max = right;
    }
    /* 从二叉树中选出最大值节点并和根节点做交换，属于交换排序类。根节点中存放的是最大值，因此该种方式又被称为大根堆 */
    if(max != index)
    {
        SWAP_VALUE(a[max],a[index]);
        /* 因为元素交换,index处存放的是最大值，已经变成了一个堆，但是对于发生交换的max节点，其值发生了改变，因此需要对交换的元素继续做heapify */
        heapify(a,max_index,max);
    }

}


void build_heap(int a[],int len)
{
    /* 获取数组的最后一个节点的父节点，从最后节点的父节点开始构建堆 */
    int max_heap = (len -1)/2;
    /* 从最后一个二叉树的父节点开始依次向前构建堆 */
    for (;max_heap >= 0;max_heap--)
    {
        heapify(a,len,max_heap);
    }
}

void heap_sort(int a[],int len)
{
    int i = 0;
    build_heap(a,len-1);
    /* 至此堆构建完成，可以保证构建出来的堆的根节点是整个的最大值
       因此可以将根节点和最后一个节点交换，这样最后一个节点就是最大值了，然后再对第一个节点做heapify */
    for (i = len - 1;i >= 0; i--)
    {
        SWAP_VALUE(a[0],a[i]);
        heapify(a,i,0);
    }

    print_value(a,len);
}