// Runtime: 14 ms (Top 42.88%) | Memory: 13.1 MB (Top 59.50%)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0,currMin=prices[0];
        for(int i=1;i<n;i++){
            while(i<n && prices[i]>prices[i-1]){
                i++;
            }
            ans+=(prices[i-1]-currMin);
            currMin=prices[i];
        }
        return ans;
    }
};