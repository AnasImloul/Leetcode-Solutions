class Solution {
public:
    int numSplits(string s) {
        int n=s.size();
        vector<int>left(26,0);
        vector<int>right(26,0);
        int left_count=0,right_count=0;
        int splits=0;
        for(auto &it:s){
            right[it-'a']++;
            if(right[it-'a']==1)right_count++;
        }
        for(auto &it:s){
            left[it-'a']++;
            right[it-'a']--;
            if(left[it-'a']==1)left_count++;
            if(right[it-'a']==0)right_count--;
            if(left_count==right_count)
                splits++;
        }
        return splits;
    }
};