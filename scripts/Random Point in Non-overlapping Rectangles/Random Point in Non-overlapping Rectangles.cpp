class Solution {
public:
    vector<int> prefix_sum;
    vector<vector<int>> rects_vec;
    int total = 0;
    
    Solution(vector<vector<int>>& rects) {
        int cur = 0;
        for (int i = 0; i < rects.size(); ++i) {
            cur += (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
            prefix_sum.push_back(cur);
        }
        rects_vec = rects;
        total = cur;
    }
    
    vector<int> pick() {
        int l = 0, r = prefix_sum.size() - 1, mid = 0;
        int rand_num = rand();
        int target = (rand_num % total) + 1;
		
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (prefix_sum[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
 
        return {rand_num % (rects_vec[l][2] - rects_vec[l][0] + 1) + rects_vec[l][0],
                rand_num % (rects_vec[l][3] - rects_vec[l][1] + 1) + rects_vec[l][1]};
    }
};
