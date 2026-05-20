class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int count = 0;
        vector<int> v(n);
        bitset<51> seen;
        for(int i=0;i<n;i++)
        {
            count += seen[A[i]];
            seen.set(A[i]);
            count += seen[B[i]];
            seen.set(B[i]);
            
            v[i] = count;
        }
        return v;
        
    }
};
