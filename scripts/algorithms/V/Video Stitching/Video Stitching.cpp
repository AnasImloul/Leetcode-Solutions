// Runtime: 16 ms (Top 23.82%) | Memory: 9 MB (Top 5.98%)
class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        if(a[0]<b[0]) return true;
        else if(a[0]==b[0]) return a[1]>b[1];
        return false;
    }

    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end(), comp);
        vector<vector<int>> res;
        //check if 0 is present or not
        if(clips[0][0] != 0) return -1;
        res.push_back(clips[0]);
        //if 1. First check if the required interval is already covered or not
        //if 2. If the first value of the already inserted element in res is equal, then the next value if obviously smaller interval because of custom sorting so, we should skip it
        //if 3. Cover every value by checking if the interval is required or not (already present?) if required then insert it
        //if 3.1. Check if the interval to be inserted covers the interval at the back for example [0,4], [2,6], now if we were to insert the interval [4, 7], then [2,6] is no more requried, then pop_back.
    for(int i=1; i<clips.size(); i++){
            if(res.back()[1]>=time) break;
            if(clips[i][0]==res.back()[0]) continue;
            if(clips[i][1]>res.back()[1]){
                if(res.size()>1 and res[res.size()-2][1]>=clips[i][0]) res.pop_back();
                res.push_back(clips[i]);
            }
        }
        //Check if the compelete range from 0 to time is covered or not
        int prev = res[0][1];
        for(int i=1; i<res.size(); i++){
            if(res[i][0]>prev) return -1;
            prev = res[i][1];
        }
        //check explicitly for the last value
        if(res.back()[1]<time) return -1;
        return res.size();
    }
};