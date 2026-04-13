#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Horse
{
    int r, c, d;
};

int N, K, ans;
int board[15][15];
vector<int> state[15][15];
Horse h[15];
int dr[5] = {0, 0, 0, -1, 1};
int dc[5] = {0, 1, -1, 0, 0};

int reverse_dir(int d)
{
    if (d == 1) return 2;
    if (d == 2) return 1;
    if (d == 3) return 4;
    return 3;
}

void solve()
{
    while (ans <= 1000)
    {
        ans++;
        for (int i = 1; i <= K; i++)
        {
            int r = h[i].r;
            int c = h[i].c;
            int d = h[i].d;

            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 1 || nr > N || nc < 1 || nc > N || board[nr][nc] == 2)
            {
                h[i].d = reverse_dir(d);
                nr = r + dr[h[i].d];
                nc = c + dc[h[i].d];

                if (nr < 1 || nr > N || nc < 1 || nc > N || board[nr][nc] == 2) continue;
            }

            vector<int> &cur_pos = state[r][c];
            vector<int> &nxt_pos = state[nr][nc];
            auto it = find(cur_pos.begin(), cur_pos.end(), i);
            vector<int> move_list(it, cur_pos.end());
            cur_pos.erase(it, cur_pos.end());

            if (board[nr][nc] == 1)
            {
                reverse(move_list.begin(), move_list.end());
            }

            for (int horse_idx : move_list)
            {
                h[horse_idx].r = nr;
                h[horse_idx].c = nc;
                nxt_pos.push_back(horse_idx);
            }

            if (nxt_pos.size() >= 4)
            {
                cout << ans;
                return;
            }
        }
    }
    cout << -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= K; i++)
    {
        cin >> h[i].r >> h[i].c >> h[i].d;
        state[h[i].r][h[i].c].push_back(i);
    }

    solve();

}
