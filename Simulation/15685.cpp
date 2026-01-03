#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
bool board[101][101];
int N;

void fill_board(int x, int y, int d, int g)
{
    vector <int> v;
    v.push_back(d);
    int generation = g;
    board[y][x] = true;
    while(generation>0)
    {
        int size = v.size();
        for(int i=size-1;i>=0;i--)
        {
            v.push_back((v[i]+1)%4);
        }
        generation--; 
    }

    for(int i=0;i<v.size();i++)
    {
        int dir = v[i];
        if(dir==0)
        {
            x++;
        }
        else if(dir==1)
        {
            y--;
        }
        else if(dir==2)
        {
            x--;
        }
        else
        {
            y++;
        }
        board[y][x]=true;
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int x,y,d,g;
        cin >> x >> y >> d >> g;
        fill_board(x,y,d,g);
    }


    int count =0;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1])
            {
                count++;
            }
        }
    }
    cout << count;

    
}