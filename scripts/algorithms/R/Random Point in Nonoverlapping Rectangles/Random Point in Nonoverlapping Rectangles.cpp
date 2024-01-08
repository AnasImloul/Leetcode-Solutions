// Runtime: 56 ms (Top 92.9%) | Memory: 67.40 MB (Top 52.26%)

class Solution {
public:
    vector<vector<int>> rect;
    vector<int> r_area;
    int total_area;
    Solution(vector<vector<int>> rects) {
        rect = rects;
        int total = 0;
        for (int i = 0; i < rects.size(); i++) {
            total += (rects[i][2] - rects[i][0]+1)*(rects[i][3] - rects[i][1]+1);
            r_area.push_back(total);
        }
        total_area = total;
    }
    
    vector<int> pick() {
        int random_area = rand()%total_area+1;
        int i = 0;
        for (; i < r_area.size(); i++) {
            if (random_area <= r_area[i]) break;
        }
        int dis_x = rand()%(rect[i][2] - rect[i][0]+1);
        int dis_y = rand()%(rect[i][3] - rect[i][1]+1);
        return {rect[i][0] + dis_x, rect[i][1] + dis_y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * vector<int> param_1 = obj.pick();
 */