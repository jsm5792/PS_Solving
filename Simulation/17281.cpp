#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int player[52][10];
int max_score = 0;

int score_count(int a[])
{
    int score = 0;
    int inning = 1;
    int curr_player = 1;
    while(inning <= N)
    {
        int base[4] = {0,0,0,0};
        int out_count = 0;
        while(out_count<3)
        {
            int curr_hitter = a[curr_player];
            if(player[inning][curr_hitter]==1)
            {
                score += base[3];
                base[3] = base[2];
                base[2] = base[1];
                base[1] = 1;
            }
            else if(player[inning][curr_hitter]==2)
            {
                score += base[3]+base[2];
                base[3] = base[1];
                base[2] = 1;
                base[1] = 0;
            }
            else if(player[inning][curr_hitter]==3)
            {
                score += base[3]+base[2]+base[1];
                base[3] = 1;
                base[2] = 0;
                base[1] = 0;
            }
            else if(player[inning][curr_hitter]==4)
            {
                score += base[3]+base[2]+base[1]+1;
                base[3] = 0;
                base[2] = 0;
                base[1] = 0;
            }
            else
            {
                out_count++;
            }
            curr_player = (curr_player)%9 + 1;
        }
        base[3] = 0;
        base[2] = 0;
        base[1] = 0;
        inning++;
    }
    return score;
}


int main()
{
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=9;j++)
        {
            cin >> player[i][j];
        }
    }
    vector <int> v = {2,3,4,5,6,7,8,9};

    do
    {
        int a[10];
        a[4] = 1;
        for(int i=0;i<8;i++)
        {
            if(i<3)
            {
                a[i+1] = v[i];
            }
            else
            {
                a[i+2] = v[i];
            }
        }
        int score = score_count(a);
        if(max_score < score)
        {
            max_score = score;
        }
    }while((next_permutation(v.begin(),v.end())));

    cout << max_score;
    
}
