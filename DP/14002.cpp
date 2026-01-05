#include <iostream>
#include <stack>

using namespace std;

int N;
int a[1003];
int b[1003];
int c[1003];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N;
    for(int i=1;i<=N;i++)
    {
        cin >> a[i];
        b[i] = 1;
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(a[i]>a[j])
            {
                if(b[i]<b[j]+1)
                {
                    c[i] = j;
                    b[i] = b[j]+1;
                }
            }
        }
    }

    int ans = 0;
    int index= 0;
    stack <int> s;
    for(int i=1;i<=N;i++)
    {
        if(b[i]>ans)
        {
            index = i;
            ans = b[i];
        }
    }
    while(c[index]!=0)
    {
        s.push(index);
        index = c[index];
    }
    s.push(index);
    cout << ans <<'\n';
    while(!s.empty())
    {
        cout << a[s.top()] <<' ';
        s.pop(); 
    }

}
