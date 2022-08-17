class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // <idx, count>
        vector<pair<int,int>> freqMapper;
        int civilian = 0;
        for(int i=0; i<mat.size(); ++i) {
            int degree = count(mat[i].begin(), mat[i].end(), civilian);
            freqMapper.push_back({i, degree});
        }
        sort(freqMapper.begin(), freqMapper.end(), [](pair<int,int> pair1, pair<int,int> pair2) {
        if (pair1.second > pair2.second) {
            return true;
        } else if (pair1.second == pair2.second) {
            return pair1.first < pair2.first;
        }
        return pair1.second > pair2.second;
    });
        vector<int> kWeakest;
        for(int i=0; i<k; i++) kWeakest.push_back(freqMapper[i].first);
        return kWeakest;
    }
    
};
