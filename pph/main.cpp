#include <iostream>
#include<time.h>
#include<cmath>
using namespace std;

struct marks
{
    int p:3;
    int c:3;
    int m:2;
};

int main() {
    struct marks s={2,-6,5};
    cout<<s.p<<s.c<<s.m;
}
