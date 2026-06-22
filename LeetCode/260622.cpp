class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int arr[5] = {};
        for(int i=0;i<text.length();i++)
        {
            if(text[i]=='a')
            {
                arr[0]++;
            }
            else if(text[i]=='b')
            {
                arr[1]++;
            }
            else if(text[i]=='l')
            {
                arr[2]++;
            }
            else if(text[i]=='o')
            {
                arr[3]++;
            }
            else if(text[i]=='n')
            {
                arr[4]++;
            }
        }
        arr[3] /= 2;
        arr[2] /= 2;
        int ans = 1e5;
        for(int i=0;i<5;i++)
        {
            ans = min(arr[i],ans);
        }
        return ans;
    }
};
