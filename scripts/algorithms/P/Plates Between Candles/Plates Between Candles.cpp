class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> candlesIndex;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == '|')
                candlesIndex.push_back(i);
        }
        
        vector<int> ans;
        for(auto q : queries){
            int firstCandleIndex = lower_bound(candlesIndex.begin() , candlesIndex.end() , q[0]) - candlesIndex.begin();
            int lastCandleIndex = upper_bound(candlesIndex.begin() , candlesIndex.end() , q[1]) - candlesIndex.begin() - 1;
            
            if(lastCandleIndex <= firstCandleIndex){
                ans.push_back(0);
                continue;
            }
                
            
            int tempAns = candlesIndex[lastCandleIndex] - candlesIndex[firstCandleIndex] - (lastCandleIndex - firstCandleIndex);
            
            ans.push_back(tempAns);
        }
        return ans;
    }
};
