class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();

        sort(costs.begin(),costs.end());
        
        int i=0;
        for(;i<n && coins>=costs[i];i++){
            coins-=costs[i];
        }
        
        return i;
    }
};