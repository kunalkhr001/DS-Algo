#include<iostream>
#include<cstring>

using namespace std;


int lcsRec(string s,string t)
{
    if(s.size()==0 || t.size()==0)
        return 0;

    if(s[0]==t[0])
    {
        return 1+lcsRec(s.substr(1),t.substr(1));
    }
    else
    {
        int a=lcsRec(s.substr(1),t);
        int b=lcsRec(s,t.substr(1));
        return max(a,b);
    }
}

int main()
{
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
  cout<<lcsRec(X,Y);
  return 0;
}
