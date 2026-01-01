#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int board[20][20];
int min_diff = 2147483647;

int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> board[i][j];
        }
    }
    vector<int> v;
    for(int i=0;i<N/2;i++)
    {
        v.push_back(0);
    }
    for(int i=0;i<N/2;i++)
    {
        v.push_back(1);
    }
    
    do
    {
        int team_1 = 0;
        int team_2 = 0;
        int diff;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(v[i]!=v[j])
                {
                    continue;
                }
                if(v[i]==0)
                {
                    team_1 += board[i][j];
                }
                else
                {
                    team_2 += board[i][j];
                }
            }
        }

        if(team_1 >= team_2)
        {
            diff = team_1 - team_2;
        }
        else
        {
            diff = team_2 - team_1;
        }
        if(diff <= min_diff)
        {
            min_diff = diff;
        }
    } while (next_permutation(v.begin(),v.end()));
    cout << min_diff;


}
