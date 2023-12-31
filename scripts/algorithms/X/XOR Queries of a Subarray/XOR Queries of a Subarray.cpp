// Runtime: 51 ms (Top 98.57%) | Memory: 38.10 MB (Top 95.53%)

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int q = queries.size();
        vector<int> answer(q, 0);
        vector<int> prefXor(n, 0);

        prefXor[0] = arr[0];
        for(int i = 1; i < n; i++) {
            prefXor[i] = prefXor[i - 1] ^ arr[i];
        }

        for(int i = 0; i < q; i++) {
            int left = queries[i][0];
            int right = queries[i][1];
            if(left == 0) answer[i] = prefXor[right];
            else answer[i] = prefXor[right] ^ prefXor[left - 1];
        }

        return answer;
    }
};
