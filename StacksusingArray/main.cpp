#include <iostream>

using namespace std;

template<typename T>
class StackArray
{
    T* data;
    int capacity;
    int topIndex;

    public:
    StackArray()
    {
        capacity=10;
        data=new T[capacity];
        topIndex=-1;
    }

    bool isEmpty()
    {
        return topIndex==-1;
    }

    int size()
    {
        return topIndex+1;
    }

    T top()
    {
        if(topIndex==-1)    //Stack Underflow
            return 0;
        else
            return data[topIndex];
    }

    void push(T element)
    {
        if(topIndex==capacity-1)          //Stack Overflow
            return;
        else
            data[++topIndex]=element;
    }

    T pop()
    {
        if(isEmpty())        //Stack Underflow
            return 0;
        else
        {
            T temp=data[topIndex];
            topIndex--;
            return temp;
        }


    }

};

int main()
{
    StackArray<char> s ;
    s.push('a');
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<int(s.top());
    return 0;
}
