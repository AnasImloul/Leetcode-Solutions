class Solution {
public:
    
    void fun(vector < vector < int > > & rq , vector < int > & cap , int ind , int req , int& maxRequests){ 
    
        if(ind >= rq.size()){ 
           
            for(auto a : cap){ 
              if( a != 0) return; 
            }
            maxRequests = max(maxRequests , req); 
            return; 
        }
        
        
        fun(rq , cap , ind+1 , req , maxRequests); 
        
        cap[rq[ind][0]]--; cap[rq[ind][1]]++; 
        
      fun(rq , cap , ind+1 , req+1 , maxRequests); 
        
         cap[rq[ind][0]]++; cap[rq[ind][1]]--; 
    
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
       int maxRequests = 0 ; 
        vector < int > capacity(n , 0); 
        fun(requests , capacity , 0 , 0 , maxRequests); 
        return maxRequests; 
    }
};
