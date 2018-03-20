#include <iostream>
#include<cstring>
#include<climits>

using namespace std;

int sumArray(int a[],int n)
            {
                if(n==0)
                    return 0;
                int smallAns=sumArray(a+1,n-1);
                return a[0]+smallAns;

            }

static int n=0;
int stringToNumber(char input[]) {
    // Write your code here
	int dig=(input[0]-48);
  	n=n*10+dig;
  	if(input[0]!='\0')
  		stringToNumber(input+1);
  	else
  		return n;
}

int length(char ch[])
{
  int len=0;
  for(int i=0;ch[i]!='\0';i++)
    len++;
return len;
}

void rotateStringByNChars(char ch[], int n) {
   // Write your code here
  int len=length(ch);
    int count=0;
  while(count<n)
  {
    char c=ch[len-1];
    for(int i=len-1;i>0;i--)
    {
      ch[i]=ch[i-1];
    }
    ch[0]=c;
    count++;
  }
}

void reverse(char input[]) {
    // Write your code here
int i=0,count=0;
  while(input[i]!='\0')
{
    while(input[i]!=' ')
    {
      i++;
    }

    for(int k=count;k<i/2;k++)
    {
      char c=input[k];
      input[k]=input[i-k-1];
      input[i-k-1]=c;
    }

    count=++i;

}

}

bool nprime(int n)
{
    if(n==1)
        return false;
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            return false;
        }

    }
    return true;

}

void prime(int n)
{

    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            cout<<"Not Prime";
            return;
        }
    }
        cout<<"Prime";
}
void demo(int arr[])
{
    cout<<"Size of array in demo "<<sizeof(arr)<<endl;
}


void towerofHanoi(int n,char source,char aux,char dest)
{
    if(n==0)
        return;
    towerofHanoi(n-1,source,dest,aux);
    cout<<source<<" "<<dest<<endl;
    towerofHanoi(n-1,aux,source,dest);
}

int subsequences(string str,string output[])
{
    if(str.length()==0)
    {
        output[0]=" ";
        return 1;
    }

    string smallOutput[1000];
    int smallOutputsize=subsequences(str.substr(1),smallOutput);

    for(int i=0;i<smallOutputsize;i++)
    {
         output[i]=smallOutput[i];
        //output[i]=str[0]+smallOutput[i];

    }

    for(int i=0;i<smallOutputsize;i++)
    {
        output[smallOutputsize+i]=str[0]+smallOutput[i];
    //output[smallOutputsize+i]=smallOutput[i];
    }

    return 2*smallOutputsize;
}

class Polynomial {
    // Complete this class

  public:
static int dcount;
static int ccount;
 int dArray[1000];
int cArray[1000];
    Polynomial()
    {
           dcount=0;
           ccount=0;


    }


  void setCoefficient(int d,int c)
  {
   dArray[dcount]=d;
    cArray[dcount]=c;
    for(int i=0;i<dcount;i++)
    {
      for(int j=0;j<dcount;j++)
      {
        if(dArray[i]==dArray[j] && j!=i)
        {
          cArray[i]=cArray[j];

        }
      }
    }
    dcount++;

  }

  void multiply(Polynomial p)
  {


  }

	void add(Polynomial p)
    {
      for(int i=0;i<dcount;i++)
    {
      for(int j=0;j<dcount;j++)
      {
        if(dArray[i]==p.dArray[j] && j!=i)
        {
          cArray[i]+=p.cArray[j];

        }
      }
    }
    }

  void print()
  {
    for(int i=0;i<dcount;i++)
    {
      cout<<cArray[i]<<"x"<<dArray[i]<<" ";
    }
    cout<<endl;
  }

};


class Student{
public:
int roll;
char name;
Student(int r)
{
    roll=r;
}

void print()
{
    cout<<roll;
}

};

int main()
{
    /*Student *s=new Student();
    s->name='A';
    s->roll=10;
    s->print();*/
    /*int a,b,rev1=0,rev2=0;
    cin>>a>>b;
    while(a>0)
    {
        int dig=a%10;
        rev1=rev1*10+dig;
        a=a/10;
    }
        while(b>0)
    {
        int dig=b%10;
        rev2=rev2*10+dig;
        b=b/10;
    }
    cout<<rev1+rev2;*/
    /*

    int n;
    cin>>n;
    int a;
    for(int i=0;i<n;i++)
    {
        a=n;
        for(int j=1;j<=n;j++)
        {
            cout<<a-i;

        }
        cout<<endl;

    }
   	int n;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
	    int i1=i-1;
	    for(int j=1;j<=i-1;j++)
	    {
	        cout<<i1<<" ";
	        if(j<i-1)
	            i1=0;
	        else
	            cout<<i-1;
	    }
	    cout<<endl;
	}
	*/
/*
	   int n,a=1,a1;
    cin>>n;
    for(int i=1;i<=n/2+1;i++)
    {
        for(int j=1;j<i;j++)
        {
            cout<<" ";

        }
        for(int k=1;k<=i;k++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=1;i<=n-n/2;i++)
    {
        for(int j=1;j<=n/2-i;j++)
        {
            cout<<" ";

        }
        for(int k=n/2;k>=i;k--)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    int n;
    cin>>n;
        for(int i=1;i<=n;i++)
    {

        for(int j=n;j>=1;j--)
        {
            if(j==i)
                cout<<"*";
            else
            {
                cout<<j;
            }


        }
        cout<<endl;
    }
    	int n;
	cin>>n;
	int n1=n;
	int sum=0;
	while(n>0)
	{
	    int dig=n%10;
	    sum+=dig*dig*dig;
	    n=n/10;
	}
	if(sum==n1)
	    cout<<"true";
	else
	    cout<<"false";

	    char ch;
	    int countd=0,counts=0,countc=0;
	    //cin>>ch;
	    cin.get(ch);
	    while(ch!='$')
        {
            //cin>>ch;

            if(ch>='0' && ch<='9')
                countd++;
            if(ch==' ' || ch=='\t' || ch=='\n')
                counts++;
            if(ch>='a' && ch<='z')
                countc++;
            cin.get(ch);
        }
        cout<<countc<<" "<<countd<<" "<<counts<<" ";
        int n,f=1,count=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            f=f*i;
        }
        cout<<f<<endl;
        int f1=f;
        int dig=f1%10;
        while(dig==0)
        {
            count++;
            f1=f1/10;
            dig=f1%10;
        }
        cout<<count;
        int n;
        cin>>n;
        cout<<nprime(n)<<endl;
        prime(n);
        long int n,f=1;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            f=f*i;
        }
        cout<<f<<endl;
            int n,f=1,count=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            f*=i;
        }
        int f1=f;
        int dig=f1%10;
        while(dig==0)
        {
            count++;
            f1=f1/10;
            dig=f1%10;
        }
        cout<<count;
        int n1,n2,size;
        cin>>n1>>n2;
        int a[n1];
        for(int i=0;i<n1;i++)
        {
            cin>>a[i];
        }
        int b[n2];
        for(int i=0;i<n2;i++)
        {
            cin>>b[i];
        }
        if(n1>n2)
            size=n1+1;
        else
            size=n2+1;
        int sum=0,carry=0,c[size];
        for(int i=size-1;i>=0;i--)
        {
            sum=a[i]+b[i];
            if(sum+carry>=10)
            {
                c[i]=sum-10;
                carry=1;
            }
            else
            {
                carry=0;
                c[i]=sum;
            }

        }
        long f1,count=0;
        cin>>f1;
while(f1%5==0)
        {
            count++;
            f1=f1/5;

        }
        cout<<count;
        int n,count=2;
        cin>>n;
        //int prev=INT_MAX,curr;
        bool isDec=true;
        int prev,curr;
        cin>>prev>>curr;
        while(count<=n)
        {
            if(prev==curr)
            {
                cout<<"false";
                return 0;
            }
            else if(prev > curr)
            {
                if(!isDec)
                {
                    cout<<"false"<<endl;
                    return 0;
                }
            }
            else
            {
                if(isDec)
                {
                    isDec=false;
                }
            }
            prev=curr;
            cin>>curr;
            count++;

        }
        cout<<true;
        int a[1000];
        int n,sum=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        int l=a[0];
        for(int i=0;i<n;i++)
        {
            if(a[i]>l)
                l=a[i];
        }
        cout<<"Sum is: "<<sum<<endl<<"Largest is: "<<l;
        int arr[200];
        demo(arr);
        cout<<"Size of array in main "<<sizeof(arr)<<endl;
        int n,count=0;
        cin>>n;
        while(n%5==0)
        {
            n=n/5;
            count++;
        }
        cout<<count;
        string s="hello";
        char ch=s[0];
        cout<<s.length();*/

        /*for(int i=0;i<=n/2;i++)
        {
            int temp=a[i];
            a[i]=a[n-i-1];
            a[n-i-1]=temp;
        }
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";

            for(int i=0;i<n-1;i++)
            {
                int min=i;
                for(int j=i+1;j<n;j++)
            {
                if(a[min]>a[j])
                {
                    min=j;
                }

            }
            int temp=a[i];
            a[i]=a[min];
            a[min]=temp;
            }

            for(int i=0;i<n;i++)
        {
            cout<<a[i];
        }
        int a[][3]={{1,2,3},{4,5,6}};
        cout<<a[1][2];
        char ch[20];
        cin.getline(ch,20);
        int i=0,count=0;
        while(ch[i]!='\0')
        {
            int len=0;
           while(ch[i]!=' ' && ch[i]!='\0')
        {
            i++;
            len++;
        }

        for(int k=count;k<(count+len)/2-1;k++)
        {
            char c=ch[k];
            ch[k]=ch[len-k-1];
            ch[len-k-1]=c;
        }

        count=++i;

        }

        for(i=0;ch[i]!='\0';i++)
        {
            cout<<ch[i];
        }
        char ch[100];
        cin.getline(ch,100);
        int nc=0,length=0,i=0;
        while(ch[i]!='\0')
        {
            length++;


            if(ch[i]!=' ')
            {
                ch[nc]=ch[i];
                nc++;
                i++;
            }

            else
                    i++;

        }
        ch[nc]='\0';
        char ch[100];
        cin.getline(ch,20);
        rotateStringByNChars(ch,5);
        for(int i=0;ch[i]!='\0';i++)
            cout<<ch[i];
            int ar[3][3];
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    cin>>ar[i][j];
                }

            }
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    cout<<ar[i][j]<<" ";
                }
                cout<<endl;
            }
           int arr[]={2,3,4,5};
           cout<<sumArray(arr,4);
           char *p="geeks";
           cout<<p;*/
       /*
           int count1,count2,choice;
    cin >> count1;

    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }

    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }

    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }

    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }

    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }

    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }

    cin >> choice;

    Polynomial result;
    switch(choice) {

    // Add
    case 1:
        result = first.add(second);
        result.print();
        break;

    // Subtract
    case 2 :
        result = first.subtract(second);
        result.print();
        break;

    // Multiply
    case 3 :
        result = first.multiply(second);
        result.print();
        break;
    }
*/
    //towerofHanoi(3,'A','B','C');
    /*string output[100];
    int n=subsequences("abcd",output);
    for(int i=0;i<n;i++)
        cout<<output[i]<<endl;
        */
        string o="12";
        char s;
        cout<<int(o[1])<<endl;
        s=o[0]+48;
        cout<<s;
    return 0;

}
