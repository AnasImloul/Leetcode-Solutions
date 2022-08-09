class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        int n = orders.size();
        //0 - buy  , 1 - sell; 
        priority_queue<vector<int>> buyBacklog;
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> sellBacklog;
        
        for(auto order : orders) {
            if(order[2] == 0) 
                buyBacklog.push(order);
            else 
                sellBacklog.push(order);
            
            while(!buyBacklog.empty() && !sellBacklog.empty() && sellBacklog.top()[0] <= buyBacklog.top()[0])  {
                auto btop = buyBacklog.top();
                buyBacklog.pop();
                auto stop = sellBacklog.top();
                sellBacklog.pop();
                int diff = btop[1] - stop[1];
                if(diff > 0) {
                    btop[1] = diff;
                    buyBacklog.push(btop);
                }
                else if(diff<0) {
                    stop[1] = abs(diff);
                    sellBacklog.push(stop);
                }
            }
        }
        
        int ans = 0 , mod = 1e9+7;
        while(!buyBacklog.empty()){
            ans = (ans +buyBacklog.top()[1])%mod;
            buyBacklog.pop();
        }
        while(!sellBacklog.empty()){
            ans = (ans+ sellBacklog.top()[1])%mod;
            sellBacklog.pop();
        }
        return ans;
    }
};
