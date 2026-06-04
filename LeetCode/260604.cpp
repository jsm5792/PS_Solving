int dp[100005];
int pref[100005];

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        if(pref[100]==0)
        {
            for(int i=100;i<100005;i++)
            {
                int d1=i%10;
                int d2=(i/10)%10;
                int d3=(i/100)%10;
                int wave=0;
                if((d2>d3 && d2>d1) || (d2<d3 && d2<d1)) wave=1;
                dp[i]=dp[i/10]+wave;
                pref[i]=pref[i-1]+dp[i];
            }
        }
        return pref[num2]-pref[num1-1];
    }
};
