class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26,-1);
        vector<int> upper(26,-1);
        for(int i=0;i<word.size();i++)
        {
            char c = word[i];
            if(c>='a' && c<='z')
            {
                lower[c-'a'] = i;                
            }
            else
            {
                if(upper[c-'A']==-1)
                {
                    upper[c-'A'] = i;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<26;i++)
        {
            if(upper[i]!=-1 && lower[i]!=-1 && upper[i] > lower[i])
            {
                ans++;
            }
        }
        return ans;
    }
};
