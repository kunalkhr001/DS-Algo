#include <bits/stdc++.h>

using namespace std;


static int config=0;

bool isSafe(int **board,int i,int j,int n)
{
    //column
    for(int row=i;row>=0;row--)
    {
        if(board[row][j]==1)
        {
            return false;
        }
    }
    
    //left diagonal
    int x=i;
    int y=j;
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y--;
    }
    
    //right diagonal
    x=i;
    y=j;
    while(x>=0 && y<n)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y++;
    }
    
    return true;
    
}

bool nQueen(int **board,int i,int n)
{
    if(i==n)
    {
        //print board
        config++;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==1)
                {
                    cout<<"Q ";
                }
                else
                {
                    cout<<"_ ";
                }
            }
            cout<<endl;
        }
        cout<<"\n\n";
        //return true; 
        //return false for all configurations
        return false;
    }
    for(int j=0;j<n;j++)
    {
        //check if i,j of board is valid
        if(isSafe(board,i,j,n))
        {
            board[i][j]=1;
            bool placeNextQueen=nQueen(board,i+1,n);
            if(placeNextQueen)
            {
                return true;
            }
            board[i][j]=0;
        }
    }
    return false;
}

int main() {
	int n;
	cin>>n;
	//int board[10][10]={0};
	int **board=new int*[n];
	for(int i=0;i<n;i++)
	{
	    board[i]=new int[n];
	    for(int j=0;j<n;j++)
	    {
	        board[i][j]=0;
	    }
	}
	nQueen(board,0,n);
	cout<<config;
	return 0;
}
