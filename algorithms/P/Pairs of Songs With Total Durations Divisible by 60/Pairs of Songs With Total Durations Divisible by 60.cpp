class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans=0;
        vector<int>rem(60,0);
        for(int i=0; i<time.size(); i++){
            rem[time[i]%60]++;
        }
        if(rem[0]>0)while(rem[0]--) 
            ans+=rem[0];
        if(rem[30]>1)while(rem[30]--) 
            ans+=rem[30];
        for(int i=1; i<30; i++){
            ans+=rem[i]*rem[60-i];
        }
        return ans;
    }
};
