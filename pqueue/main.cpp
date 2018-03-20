#include <iostream>
#include<vector>
#include<climits>

using namespace std;


class PriorityQueue
{
    vector<int > heap;

public:

    int size()
    {
        return heap.size();
    }

    bool isEmpty()
    {
        return heap.size()==0;
    }

    int min()
    {
        if(heap.size()==0)
            return INT_MAX;
        return heap[0];
    }


    void insert(int elem)
    {
        heap.push_back(elem);
        int childIndex=heap.size()-1;
        int parentIndex=(childIndex-1)/2;
        while(childIndex>0)
        {
            if(heap[childIndex]<heap[parentIndex])
            {
                int temp=heap[childIndex];
                heap[childIndex]=heap[parentIndex];
                heap[parentIndex]=temp;
                childIndex=parentIndex;
                parentIndex=(childIndex-1)/2;
            }
            else
                break;
        }
    }

    int removeMin()
    {
        int temp=heap[0];
        heap[0]=heap[heap.size()-1];
        heap.pop_back();

        if(heap.size()>1)
        {
            downHeapify(0);
        }

        return temp;


    }

private:
    void downHeapify(int index)
    {
        int leftchildIndex=2*index+1;
        int rightchildIndex=2*index+2;
        if(leftchildIndex>=heap.size())
            return;
        int minIndex=index;
        if(heap[leftchildIndex]<heap[minIndex])
        {

            minIndex=leftchildIndex;
        }

        if(rightchildIndex<heap.size() && heap[rightchildIndex]<heap[minIndex])
        {

            minIndex=rightchildIndex;
        }
        if(minIndex!=index)
        {
            int temp=heap[minIndex];
            heap[minIndex]=heap[index];
            heap[index]=temp;
            downHeapify(minIndex);
        }
    }

};

void insertIntoVirtualHeap(int a[],int index)
{
    int childIndex=index;
    int parentIndex=(childIndex-1)/2;
    while(childIndex>0)
        {
            if(a[childIndex]<a[parentIndex])
            {
                int temp=a[childIndex];
                a[childIndex]=a[parentIndex];
                a[parentIndex]=temp;
                childIndex=parentIndex;
                parentIndex=(childIndex-1)/2;
            }
            else
                break;
        }
}

void  downheapifySort(int index,int heapSize,int a[])
{
    int leftchildIndex=2*index+1;
        int rightchildIndex=2*index+2;
        if(leftchildIndex>=heapSize)
            return;
        int minIndex=index;
        if(a[leftchildIndex]<a[minIndex])
        {

            minIndex=leftchildIndex;
        }

        if(rightchildIndex<heapSize && a[rightchildIndex]<a[minIndex])
        {

            minIndex=rightchildIndex;
        }
        if(minIndex!=index)
        {
            int temp=a[minIndex];
            a[minIndex]=a[index];
            a[index]=temp;
            downheapifySort(minIndex,heapSize,a);
        }
}

int removeFromVirtualHeap(int a[],int heapSize)
{
    int temp=a[0];
        a[0]=a[heapSize-1];


        if(heapSize>1)
        {
            downheapifySort(0,heapSize,a);
        }

        return temp;
}

void heapSort(int a[],int size)
{
    for(int i=0;i<size;i++)
        insertIntoVirtualHeap(a,i);
    for(int i=0;i<size;i++)
        a[size-i-1]=removeFromVirtualHeap(a,size-i);
    for(int i=0;i<size;i++)
        cout<<a[i]<<endl;
}

int main()
{
    PriorityQueue pq;
    int a[]={9,2,7,3,5,1};
    /*for(int i=0;i<6;i++)
    {
        pq.insert(a[i]);
    }

    //cout<<pq.size()<<endl;
    //cout<<pq.removeMin();

    while(!pq.isEmpty())
    {
        cout<<pq.removeMin()<<endl;
    }
    */
    heapSort(a,6);
    return 0;
}
