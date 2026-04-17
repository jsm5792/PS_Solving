#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, M, T;
int board[55][55];

void rotate(int x, int d, int k)
{
    for (int i = x; i <= N; i += x)
    {
        vector<int> tmp(M);
        for (int j = 0; j < M; j++)
        {
            if (d == 0) tmp[(j + k) % M] = board[i][j];
            else tmp[(j + M - (k % M)) % M] = board[i][j];
        }
        for (int j = 0; j < M; j++) board[i][j] = tmp[j];
    }
}

bool update()
{
    bool erased = false;
    vector<pair<int, int>> targets;
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 0) continue;
            
            if (board[i][j] == board[i][(j + 1) % M])
            {
                targets.push_back({i, j});
                targets.push_back({i, (j + 1) % M});
            }
            if (i < N && board[i][j] == board[i + 1][j])
            {
                targets.push_back({i, j});
                targets.push_back({i + 1, j});
            }
        }
    }

    if (!targets.empty())
    {
        erased = true;
        for (auto p : targets) board[p.first][p.second] = 0;
    }
    else
    {
        double sum = 0;
        int cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] > 0)
                {
                    sum += board[i][j];
                    cnt++;
                }
            }
        }
        if (cnt > 0)
        {
            double avg = sum / cnt;
            for (int i = 1; i <= N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    if (board[i][j] == 0) continue;
                    if (board[i][j] > avg) board[i][j]--;
                    else if (board[i][j] < avg) board[i][j]++;
                }
            }
        }
    }
    return erased;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> T;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    while (T--)
    {
        int x, d, k;
        cin >> x >> d >> k;
        rotate(x, d, k);
        update();
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++) ans += board[i][j];
    }
    cout << ans;

}
