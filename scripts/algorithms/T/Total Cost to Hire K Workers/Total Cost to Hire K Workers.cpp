// Runtime: 123 ms (Top 76.96%) | Memory: 73.10 MB (Top 65.06%)

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0,i,j,end,start,n;
        
        n = costs.size();
        
        priority_queue<int,vector<int>,greater<int>> s,e;
        
        for(i=0;i<candidates;i++){
            s.push(costs[i]);
        }
        
        for(i = n-1;i>=candidates&& i >= n-candidates;i--){
            e.push(costs[i]);
        }
        
        start = candidates;
        end = n- candidates-1;
        
        while(k > 0){
            if(s.empty() == false && e.empty() == false)
            {
                if(s.top() <= e.top())
                {
                    ans= ans + s.top();
                    s.pop();
                    
                    if(start <= end){
                        s.push(costs[start]);
                        start++;
                    }
                }
                else
                {
                    ans=ans+e.top();
                e.pop();
                
                if(start<=end){
                    e.push(costs[end]);
                    end--;
                }
              }
            }
            else if(s.empty() == false){
                ans = ans + s.top();
                s.pop();
            }
            else if(e.empty() == false)
            {
                ans = ans + e.top();
                e.pop();
            }
               k--; 
            }
        return ans;
        }
    
};
