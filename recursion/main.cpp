#include <iostream>
#include<cstring>

using namespace std;

void subsequences(string input,string output)
{
    if(input.length()==0)
    {
        cout<<output<<endl;
        return;
    }

    subsequences(input.substr(1),output);
    subsequences(input.substr(1),output+input[0]);
}

/*    IN JAVA

public static String []subsequences(String str)
{
    if(str.length()==0)
    {
        string ans[]={""};
        return ans;
    }
    String[] smallAns=subsequences(str.substring(1));
    String []ans=new String[2*(smallAns.length()];
    for(int i=0;i<smallAns.length();i++)
    {
        ans[i]=smallAns[i];
    }
    for(int i=0;i<smallAns.length();i++)
    {
        ans[i + smallAns.length()]=str.charAt(0)+smallAns[i];
    }
    return ans;
}


*/
int firstIndex(int a[],int n,int num)
{
    if(n==0)
        return -1;
    if(a[0]==num)
        return 0;
    else
    {
        int ans=firstIndex(a+1,n-1,num);
        if(ans==-1)
            return -1;
        else
            return ans+1;
    }
}

int sumArray(int a[],int n)
{
    if(n==0)
        return 0;
    int ans=sumArray(a+1,n-1);
    return a[0]+ans;
}

bool checkno(int a[],int n,int num)
{
    if(n==0)
        return false;
    if(a[0]==num)
        return true;
    else
    {
        bool ans=checkno(a+1,n-1,num);
        return ans;
    }

}


int main()
{
    //int a[]={1,2,3,2,5,6};
    //cout<<"SUm "<<sumArray(a,6);
    //bool ans=checkno(a,6,1);
    //cout<<ans;
    //cout<<firstIndex(a,6,2);
    /*string input="abc";
    string output="";
    subsequences(input,output);
    */
    return 0;
}
