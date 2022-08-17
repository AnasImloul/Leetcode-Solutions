class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        long long temp = 0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i - 1] - prices[i] == 1){
                temp++;
                ans += temp;
            }
            else{
                temp = 0;
            }
        }
        ans += prices.size();
        return ans;
    }
};
