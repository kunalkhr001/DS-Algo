#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};


Node*  takeInput(){
	Node* head = NULL;
	Node* tail = NULL;
	int data;
	cin >> data;

	while(data != -1){
		Node* newNode = new Node(data);
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}else{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}

	return head;
}


Node* removeDuplicates(Node *head)
{
    Node* p=head;

    while(p!=NULL)
    {
         Node* q=p->next;
        if(q!=NULL)
        {

            while(p->data==q->data)
            {
                q=q->next;
                if(q==NULL)
                    break;
            }
        }

        p->next=q;
        p=p->next;
    }
    return head;
}

Node* insertNode(Node *head, int pos, int data) {


  Node* p=new Node(data);

    if(pos==0)
    {
  		p->next=head;
      head=p;
    }

  else
  {
      int i=1;
    Node* temp=head,*p1=NULL;
        while(temp!=NULL)
    {
      if(i==pos)
      {
        p1=temp->next;
     	temp->next=p;
        p->next=p1;
        break;
      }
      i++;
      temp=temp->next;
    }

  }


  return head;
}

Node* arrange_LinkedList(Node* head)
{
    //write your code here
  Node *e=NULL,*o=NULL,*p=head;
	while((o==NULL && e==NULL) || p!=NULL)
    {
      if(o==NULL && p->data%2!=0)
      {
        o=p;
      }
      if(e==NULL && p->data%2==0)
      {
        e=p;
      }
      p=p->next;
    }
  Node* odd=o,*ev=e;
  p=head;
  while(p!=NULL)
  {
    if(p->data%2==0 && e!=ev)
    {
      e->next=p;
      e=e->next;
    }

    if(p->data%2!=0 && o!=odd)
    {
      o->next=p;
      o=o->next;
    }

    p=p->next;
  }
  o->next=ev;

if(ev==NULL)
    return odd;
if(odd==NULL)
    return ev;

  return odd;
}


Node* deleteNode(Node *head, int i) {


  Node *p;
  if(i==0)
  {
    p=head;
    head=head->next;
    delete(p);
  }
  else
  {
    int pos=1;
    Node* temp=head;
    while(temp!=NULL)
    {
    	if(i==pos)
    	{
      p=temp->next;
      temp->next=p->next;
      delete(p);
          break;
    	}

      pos++;
      temp=temp->next;
    }

  }
    return head;
}

void print(Node *head)
{
        while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main()
{
    Node *head;
    head=takeInput();
    //head=insertNode(head,4,5);
    /*int i;
    cout<<"Delete at location ";
    cin>>i;
    head=deleteNode(head,i);
    //head=eliminate_duplicate(head);

    head=arrange_LinkedList(head);
*/

    print(head);
    Node *newhead=removeDuplicates(head);
    print(newhead);


    return 0;
}
