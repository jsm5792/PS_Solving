#include <iostream>

using namespace std;

int N, L;
int board[101][101];


bool road(int line[])
{
    bool ramp[101];
    for(int i=0;i<N;i++)
    {
        ramp[i] = false;
    }

    for (int i=0;i<N-1;i++) 
    {
        if(line[i] == line[i+1])
        {
            continue;
        }
        if (abs(line[i]-line[i+1]) >= 2)
        {
            return false;
        }

        if (line[i]<line[i+1]) 
        {
            for (int j=0;j<L;j++) 
            {
                if (i-j<0 || line[i-j]!=line[i] || ramp[i-j]) 
                {
                    return false;
                }
                ramp[i-j] = true;
            }
        }

        else 
        {
            for (int j=1; j<=L;j++) 
            {
                if (i+j >= N || line[i+j] != line[i+1] || ramp[i+j]) 
                {
                    return false;
                }
                ramp[i+j] = true;
            }
        }
    }
    return true;

}


int count_road()
{
    int counter = 0;
    for(int i=0;i<N;i++)
    {
        int a[101];
        for(int j=0;j<N;j++)
        {
            a[j] = board[i][j];
        }
        if(road(a))
        {
            counter++;
        }
    }
    for(int j=0;j<N;j++)
    {
        int a[101];
        for(int i=0;i<N;i++)
        {
            a[i] = board[i][j];
        }
        if(road(a))
        {
            counter++;
        }

    }
    return counter;

}

int main()
{
    cin >> N >> L;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> board[i][j];
        }
    }

    cout << count_road();
    
    
}