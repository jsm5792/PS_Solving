#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
bool isprime[1100005];
queue <int> q;

void prime()
{
    for(int i=2;i<1100005;i++)
    {
        isprime[i] = true;
    }
    for(int i=2;i*i<1100005;i++)
    {
        for(int j=i*i;j<1100005;j+=i)
        {
            if(isprime[j])
            {
                isprime[j] = false;
            }
        }
    }
    for(int i=N;i<1100005;i++)
    {
        if(isprime[i])
        {
            q.push(i);
        }
    }
}

bool check(int N)
{
    string s = to_string(N);
    int i=0;
    int j=s.length()-1;
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;    
}

void palindrome()
{
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        if(check(temp))
        {
            cout << temp;
            return;
        }
    }
    return;
}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    prime();
    palindrome();
}
