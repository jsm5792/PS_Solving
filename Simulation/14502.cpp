#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int N,M;
int max_safe = 0;
int board[8][8];


int BFS()
{
    queue<pair<int,int>> Q;
    int temp_board[8][8];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            temp_board[i][j] = board[i][j];
            if(board[i][j]==2)
            {
                Q.push({i,j});
            }
        }
    }
    while(!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for(int i=0;i<4;i++)
        {
            int temp_x = x + dx[i];
            int temp_y = y + dy[i];
            if(temp_x < 0 || temp_y <0 || temp_x >= N || temp_y >= M)
            {
                continue;
            }
            if(temp_board[temp_x][temp_y]==0)
            {
                temp_board[temp_x][temp_y]=2;
                Q.push({temp_x,temp_y});
            }
        }
    }

    int count = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(temp_board[i][j]==0)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    cin >> N >> M;
    vector<pair<int,int>> safe;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> board[i][j];
            if(board[i][j]==0)
            {
                safe.push_back({i,j});
            }
        }
    }

    for(int i=0;i<safe.size();i++)
    {
        board[safe[i].first][safe[i].second] = 1;
        for(int j=i+1;j<safe.size();j++)
        {
            board[safe[j].first][safe[j].second] = 1;
            for(int k=j+1;k<safe.size();k++)
            {
                board[safe[k].first][safe[k].second] = 1;

                int temp_safe = BFS();
                if(temp_safe > max_safe)
                {
                    max_safe = temp_safe;
                }
                board[safe[k].first][safe[k].second] = 0;
            }
            board[safe[j].first][safe[j].second] = 0;
        }
        board[safe[i].first][safe[i].second] = 0;
    }
    cout << max_safe;
}
