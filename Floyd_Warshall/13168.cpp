#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,R,K,city;
unordered_map <string,int> m;
vector<int> v;

int board1[105][105];
int board2[105][105];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> R;
    R *= 2;
    for(int i=1;i<=N;i++)
    {
        string s;
        cin >> s;
        auto it = m.find(s);
        if(it == m.end())
        {
            m[s] = city;
            city++; 
        }
    }
    for(int i=0;i<m.size();i++)
    {
        for(int j=0;j<m.size();j++)
        {
            if(i==j)
            {
                board1[i][j] = 0;
                board2[i][j] = 0;
            }
            else
            {
                board1[i][j] = 100000000;
                board2[i][j] = 100000000;
            }
        }
    }
    cin >> M;
    for(int i=0;i<M;i++)
    {
        string s;
        cin >> s;
        v.push_back(m[s]);
    }
    cin >> K;
    for(int i=0;i<K;i++)
    {
        string a,b,c;
        int price;
        cin >> a >> b >> c >> price;
        price *= 2;
        int x = m[b];
        int y = m[c];
        board1[x][y] = min(price,board1[x][y]);
        board1[y][x] = board1[x][y];

        if(a == "Mugunghwa" || a=="ITX-Saemaeul" || a == "ITX-Cheongchun")
        {
            price = 0;
        }
        else if(a == "S-Train" || a== "V-Train")
        {
            price /= 2;
        }
        price = min(board2[x][y],price);
        board2[x][y] = price;
        board2[y][x] = price;
    }

    for(int k=0;k<city;k++)
    {
        for(int i=0;i<city;i++)
        {
            for(int j=0;j<city;j++)
            {
                board1[i][j] = min(board1[i][j],board1[i][k]+board1[k][j]);
                board2[i][j] = min(board2[i][j],board2[i][k]+board2[k][j]);
            }
        }
    }
    for(int i=1;i<v.size();i++)
    {
        int x = v[i-1];
        int y = v[i];
        R = R + board2[x][y] - board1[x][y];
    }
    if(R < 0)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }



}
