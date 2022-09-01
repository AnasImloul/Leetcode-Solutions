// Runtime: 4 ms (Top 67.44%) | Memory: 7.6 MB (Top 66.09%)
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
            int ans =0;
            int n = tickets.size();
            int ele = tickets[k];
            for(int i=0;i< n; i++){
                    if(i<=k){
                        ans+= min(ele, tickets[i]);
                    }else{
                        ans+= min(ele-1, tickets[i]);
                    }
            }
            return ans;
    }
};