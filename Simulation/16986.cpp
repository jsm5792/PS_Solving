#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, K;
int info[11][11];
int pattern[4][25];
int idx[4];
int win[4];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> info[i][j];
        }
    }
    
    for (int i = 1; i <= 20; i++) cin >> pattern[2][i];
    for (int i = 1; i <= 20; i++) cin >> pattern[3][i];

    vector<int> jiwoo;
    for (int i = 1; i <= N; i++) jiwoo.push_back(i);

    do
    {
        for (int i = 1; i <= 3; i++)
        {
            idx[i] = 1;
            win[i] = 0;
        }
        for (int i = 1; i <= N; i++) pattern[1][i] = jiwoo[i - 1];

        int p1 = 1, p2 = 2;
        bool flag = false;

        while (1)
        {
            if (win[1] == K)
            {
                flag = true;
                break;
            }
            if (win[2] == K || win[3] == K || idx[1] > N) break;
            if (idx[2] > 20 || idx[3] > 20) break;

            int p3 = 6 - (p1 + p2);
            int h1 = pattern[p1][idx[p1]++];
            int h2 = pattern[p2][idx[p2]++];

            int winner;
            if (info[h1][h2] == 2) winner = p1;
            else if (info[h1][h2] == 0) winner = p2;
            else winner = (p1 > p2 ? p1 : p2);

            win[winner]++;
            p1 = winner;
            p2 = p3;
        }

        if (flag)
        {
            cout << 1;
            return 0;
        }
    } while (next_permutation(jiwoo.begin(), jiwoo.end()));

    cout << 0;
}
