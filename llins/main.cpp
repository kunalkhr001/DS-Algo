#include <iostream>
#include<climits>

using namespace std;

int min(int a,int b)
{
    if(a>b)
        return b;
    else
        return a;
}

int main()
{
    /*   //char input
    char ch;
    cin.get(ch);
    cout<<ch<<endl;
    */

    /*    //decimal to binary
    int n,i=1;
    cin>>n;
    long b=0;
    while(n>0)
    {
        int rem=n%2;
        b+=rem*i;
        n/=2;
        i*=10;
    }
    cout<<b;
    */


    /*    //largest & second largest of nos.
    int n;
    cin>>n;
    int i=0,l=INT_MIN,sl=INT_MIN;
    while(i<n)
    {
        int num;
        cin>>num;
        if(num>l)
        {
            sl=l;
            l=num;
        }
        else if(num>sl && num!=l)
            sl=num;

        i++;
    }
    cout<<"Largest "<<l<<endl<<"Second largest "<<sl;
    */

    /*   //gcd of two nos.
    int gcd=1;
    int a,b;
    cin>>a>>b;
    int small=min(a,b);
    for(int i=2;i<=small;i++)
    {
        if(a%i==0 && b%i==0)
            gcd=i;
    }
    cout<<gcd;
    */

    /*        //lcm of two nos.
    int i=2,gcd=1;
    int a,b;
    cin>>a>>b;
    int small=min(a,b);
    for(int i=2;i<=small;i++)
    {
        if(a%i==0 && b%i==0)
            gcd=i;
    }
    cout<<a*b/gcd;
    */
    return 0;
}
