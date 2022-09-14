// Runtime: 287 ms (Top 34.81%) | Memory: 9.4 MB (Top 44.61%)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            int res = 0;
            for(int j = 0; j < n; j++)
            {
                if(boxes[j] == '1')
                {
                    res += abs(i-j);
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};