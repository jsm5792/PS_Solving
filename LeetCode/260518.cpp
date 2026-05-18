class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n <= 1)
        {
            return 0;
        }
        
        unordered_map<int, vector<int>> indicesOfValue;
        for(int i = 0; i < n; i++) {
            indicesOfValue[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();

                if (curr == n - 1)
                {
                    return steps;
                }

                vector<int>& nextIndices = indicesOfValue[arr[curr]];
                for(int nextIdx : nextIndices)
                {
                    if(!visited[nextIdx])
                    {
                        visited[nextIdx] = true;
                        q.push(nextIdx);
                    }
                }
                nextIndices.clear();

                if(curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }
                if(curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }
            }
            steps++;
        }

        return 0;
    }
};
