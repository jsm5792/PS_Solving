#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,root,del_node;
vector<int> v[55];

int DFS(int curr)
{
    if(del_node == root)
    {
        return 0;
    }
    bool is_leaf = true;
    int ans =0;
    for(int next : v[curr])
    {
        if(next == del_node)
        {
            continue;
        }
        is_leaf = false;
        ans += DFS(next);
    }
    if(is_leaf)
    {
        return 1;
    }
    return ans;

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int x;
        cin >> x;
        if(x==-1)
        {
            root = i;
        }
        else
        {
            v[x].push_back(i);
        }
    }
    cin >> del_node;
    cout << DFS(root);
}