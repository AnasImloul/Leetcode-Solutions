class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        unordered_map<double,int> mp;
        for(int i = 0;i<n;i++){
            double ratio = rectangles[i][0]/(double)rectangles[i][1];
            mp[ratio]++;
        }
        long long count = 0;
                
        for(auto i: mp){
            long long x = i.second;
            x = (x * (x-1))/2.0;
            count += x;
        }
        return count;
    }
};
