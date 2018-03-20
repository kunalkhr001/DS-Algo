#include <iostream>

using namespace std;

template<typename T>
class Node
{
    public:
    T data;
    Node<T>* next;   //Node *next


    Node (T data)
    {
        this->data=data;
        next=NULL;
    }

};

template <typename T>
class StackLL {
    Node<T> *head;

    int size;		// number of elements prsent in stack

    public :


    StackLL() {
  		head=NULL;
      size=0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return head==NULL;
    }

    void push(T element) {
        size++;
      	Node<T> *newNode=new Node<T>(element);
      	newNode->next=head;
      	head=newNode;
    }

    T pop() {
        // Return 0 if stack is empty. Don't display any other message
        if(head==NULL)
            return 0;
		Node<T> *p=head;
      	head=head->next;
      	if(head==NULL)
            return 0;

      	int d=p->data;
      	delete(p);
      	size--;
      	return d;
    }

    T top() {
        // Return 0 if stack is empty. Don't display any other message
      if(head==NULL)
        return 0;
      else
      	return head->data;
    }



};


int main()
{
    StackLL <int> s;
    s.push(10);
    s.push(20);
    cout<<s.top()<<endl;
    cout<<s.getSize()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    cout<<s.getSize()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    return 0;
}
