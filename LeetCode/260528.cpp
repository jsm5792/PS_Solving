class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        long long base1 = 26;
        long long base2 = 29;
        long long mod1 = 1e9 + 7;
        long long mod2 = 1e9 + 9;

        unordered_map<long long, int> suffixMatches;

        int minLengthIndex = 0;
        for(int i=0;i<wordsContainer.size();i++)
        {
            if(wordsContainer[i].length() < wordsContainer[minLengthIndex].length())
            {
                minLengthIndex = i;
            }
        }

        for(int i=0;i<wordsContainer.size();i++)
        {
            string word = wordsContainer[i];
            long long hash1 = 0;
            long long hash2 = 0;

            for(int j=word.length()-1;j>=0;j--)
            {
                hash1 = (hash1 * base1) % mod1;
                hash1 = (hash1 + (word[j] - 'a' + 1)) % mod1;

                hash2 = (hash2 * base2) % mod2;
                hash2 = (hash2 + (word[j] - 'a' + 1)) % mod2;

                long long hashKey = (hash1 << 32) | hash2;

                if(suffixMatches.count(hashKey))
                {
                    int prevIndex = suffixMatches[hashKey];

                    if(wordsContainer[prevIndex].length() > word.length())
                    {
                        suffixMatches[hashKey] = i;
                    }
                }
                else
                {
                    suffixMatches[hashKey] = i;
                }
            }
        }

        vector<int> res(wordsQuery.size(), minLengthIndex);
        
        for(int i=0;i<wordsQuery.size();i++)
        {
            string query = wordsQuery[i];
            long long hash1 = 0;
            long long hash2 = 0;

            for(int j = query.length()-1;j>=0;j--)
            {
                hash1 = (hash1 * base1) % mod1;
                hash1 = (hash1 + (query[j] - 'a' + 1)) % mod1;

                hash2 = (hash2 * base2) % mod2;
                hash2 = (hash2 + (query[j] - 'a' + 1)) % mod2;

                long long hashKey = (hash1 << 32) | hash2;

                if(suffixMatches.count(hashKey))
                {
                    res[i] = suffixMatches[hashKey];
                }
                else
                {
                    break;
                }
            }
        }

        return res;
    }
};
