#include <iostream>

using namespace std;

#include <ctime>




void printParenthesis(int i, int j, int n,
                      int *bracket, char &name)
{

    if (i == j)
    {
        cout << name++;
        return;
    }

    cout << "(";

    printParenthesis(i, *((bracket+i*n)+j), n,
                     bracket, name);


    printParenthesis(*((bracket+i*n)+j) + 1, j,
                     n, bracket, name);
    cout << ")";
}

void matrixChainOrder(int p[], int n)
{
    int m[n][n];

    int bracket[n][n];
    for (int i=1; i<n; i++)
        m[i][i] = 0;

    // L is chain length.
    for (int L=2; L<n; L++)
    {
        for (int i=1; i<n-L+1; i++)
        {
            int j = i+L-1;
            m[i][j] = INT_MAX;
            for (int k=i; k<=j-1; k++)
            {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
                cout<<q<<" ";
            }
            cout<<endl;
        }
    }

    char name = 'A';

    cout << "Optimal Parenthesization is : ";
    printParenthesis(1, n-1, n, (int *)bracket, name);
    cout << "\nOptimal Cost is : " << m[1][n-1];
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    clock_t begin = clock();
    matrixChainOrder(arr, n);
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout<<endl<<"Time taken: "<<elapsed_secs;
    return 0;
}
