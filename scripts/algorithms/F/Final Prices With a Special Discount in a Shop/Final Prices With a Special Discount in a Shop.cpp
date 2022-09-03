// Runtime: 0 ms (Top 100.00%) | Memory: 10 MB (Top 18.49%)
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>sk;
        for(int i=0;i<prices.size();i++){
        int discount=prices[i];
            for(int j=i+1;j<prices.size();j++){
                if(prices[i]>=prices[j]){
                    discount=prices[i]-prices[j];
                    break;
                }

            }
            sk.push_back(discount);
        }
        return sk;
    }
};