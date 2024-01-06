// Runtime: 112 ms (Top 92.82%) | Memory: 103.30 MB (Top 60.63%)

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        int start=0;
        int end  =0;
        long long ans=1;//since, we will be starting our iteration from ist index
        
        for(end=1 ; end<n; end++){
            
            if(prices[end] == prices[end-1] - 1){
                ans += end - start + 1;
            }
            
            else{
                start=end;
                ans += end - start + 1;
            }
        }
        
        return ans;
    }
};
