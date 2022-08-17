class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int ans = 0 ;
        for(int i = 0 ; i < size(startTime); ++i )
            if(queryTime >= startTime[i] and queryTime <= endTime[i]) ++ans ;
        
        return ans ;
    }
};
