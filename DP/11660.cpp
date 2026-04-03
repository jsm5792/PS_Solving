#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
int board[1030][1030];
int s[1030][1030];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> board[i][j];
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + board[i][j];
        }
    }

    while(M--)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1] << "\n";
    }

}
