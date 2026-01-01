#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int w,h;
char board[10][10];
int visit[10][10][10][10];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
pair <int,int> r,b;

bool finish = false;

int BFS()
{
    queue<tuple<int,int,int,int>> Q;
    Q.push({r.first,r.second,b.first,b.second});
    visit[r.first][r.second][b.first][b.second]= 0;
    while(!Q.empty())
    {
        int r_i = get<0>(Q.front());
        int r_j = get<1>(Q.front());
        int b_i = get<2>(Q.front());
        int b_j = get<3>(Q.front());
        Q.pop();
        int count = visit[r_i][r_j][b_i][b_j];

        if(count >= 10)
        {
            return -1;
        }

        for(int i=0;i<4;i++)
        {
            int temp_r_i = r_i;
            int temp_r_j = r_j;
            int temp_b_i = b_i;
            int temp_b_j = b_j;

            while(board[temp_b_i+dx[i]][temp_b_j+dy[i]]=='.')
            {
                temp_b_i += dx[i];
                temp_b_j += dy[i];
            }

            if(board[temp_b_i+dx[i]][temp_b_j+dy[i]]=='O')
            {
                continue;
            }

            while(board[temp_r_i+dx[i]][temp_r_j+dy[i]]=='.')
            {
                temp_r_i += dx[i];
                temp_r_j += dy[i];
            }

            if(board[temp_r_i+dx[i]][temp_r_j+dy[i]]=='O')
            {
                return count+1;
            }


            if((temp_r_i==temp_b_i) && (temp_r_j == temp_b_j))
            {
                if(i==0)
                {
                    if(r_i > b_i)
                    {
                        temp_b_i --;                        
                    }
                    else
                    {
                        temp_r_i --;
                    }
                }
                else if(i==1)
                {
                    if(r_j > b_j)
                    {
                        temp_b_j --;                        
                    }
                    else
                    {
                        temp_r_j --;
                    }
                }
                else if(i==2)
                {
                    if(r_i > b_i)
                    {
                        temp_r_i ++;                        
                    }
                    else
                    {
                        temp_b_i ++;
                    }
                }
                else
                {
                    if(r_j > b_j)
                    {
                        temp_r_j ++;                        
                    }
                    else
                    {
                        temp_b_j ++;
                    }
                }
            }
            if(visit[temp_r_i][temp_r_j][temp_b_i][temp_b_j] != -1)
            {
                continue;
            }
            visit[temp_r_i][temp_r_j][temp_b_i][temp_b_j] = count+1;
            Q.push({temp_r_i,temp_r_j,temp_b_i,temp_b_j});
        }

    }

    return -1;

}




int main()
{
    cin >> h >> w;

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                for(int x=0;x<10;x++)
                {
                    visit[i][j][k][x] = -1;
                }
            }
        }
    }

    for(int i=0; i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin >> board[i][j];
            if(board[i][j]=='R')
            {
                r = {i,j};
                board[i][j]='.';
            }
            else if(board[i][j]=='B')
            {
                b = {i,j};
                board[i][j]='.';
            }
        }
    }
    cout << BFS();
    
}
