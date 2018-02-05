#include <bits/stdc++.h>
using namespace std;
int sud[9][9];

bool isSafe(int row, int col,  int num)
{
    // if not in row
    for(int i=0; i<9; i++)
        if(sud[row][i]==num)
            return false;

    // if not in column
    for(int i=0; i<9; i++)
        if(sud[i][col]==num)
            return false;

    // if not in the box

    int s1=row-row%3;
    int s2=col-col%3;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(sud[i+s1][j+s2]==num)
                return false;
        }
    }

    return true;
}
bool findlocation()
{
    // find unassigned location

    for( int x=0; x<9; x++)
        for(int y=0; y<9; y++)
        {
            if(sud[x][y]==0)
                return true;
        }

    return false;

}
bool solveSudoku(int x,int y)
{
    bool soln;
    if(x==9)
        return true;
    if(sud[x][y]!=0)
    {
        int temp = sud[x][y];
        sud[x][y] = 0;
        if(isSafe(x,y,sud[x][y])==false)
            return false;
        sud[x][y] = true;
        if(y<8)
            return solveSudoku(x,y+1);
        else
            return solveSudoku(x+1,y);
    }
    //Lets print
    for(int num=1; num<=9; num++)
    {
        if(isSafe(x, y, num))
        {
            sud[x][y]=num;
            if(y<8)
                soln = solveSudoku(x,y+1);
            else
                soln = solveSudoku(x+1,0);
            if(soln)
                return true;
            sud[x][y]=0;
        }
    }
    return false;
}

int main()
{

    // take input in the sudoku
    for( int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            cin>>sud[i][j];

    bool sol=solveSudoku(0,0);

    if(sol)
    {
        cout<<endl;
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
                cout<<sud[i][j]<<" ";

            cout<<endl;
        }
    }
    else
        cout<<"NO SOLUTION EXISTS!!!\n";

    return 0;
}
