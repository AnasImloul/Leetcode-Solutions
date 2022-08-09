// Basically my intuition is sort of similar like Knapsack picking.
// We have two options : Pick Event or Don't Pick an event.
// If we "Pick event", we'll just add to our sum, then we'll find out an event whose starting time > ending time of the event that we picked and 
// we'll keep progressing like this until we hit 2. (as we can only pick at most two events)
// If we "Don't Pick the event" we'll move on
// And basically our maxvalue would be max outcome of ("Pick Event", "Don't Pick Event")

class Solution {
public:
    
    //Main Function
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        
        //Sorting because since we need to find an event that has starting time > ending time 
        //of previous event selected, so applying binary search would help there.
        sort(events.begin(),events.end());
        
        return solve(events,0,0,dp);
    }
    
    //Helper function
    int solve(vector<vector<int>>&nums,int idx,int k,vector<vector<int>>&dp)
    {
        // Base case
        if(k==2)
        {
            return 0;
        }
        if(idx>=nums.size())
        {
            return 0;
        }
        
        // Memoization check
        if(dp[idx][k]!=-1)
        {
            return dp[idx][k];
        }
        
        //Basically ending times of the events
        vector<int>ans={nums[idx][1],INT_MAX,INT_MAX};
        
        //Searching the event whose starting time > ending time of previous event selected
        int nextindex=upper_bound(begin(nums),end(nums),ans)-begin(nums);
        
        //Pick event
        int include=nums[idx][2]+solve(nums,nextindex,k+1,dp);
        
        //Don't Pick event
        int exclude=solve(nums,idx+1,k,dp);
        
        return dp[idx][k]=max(include,exclude); //Max of(Pick, Not Pick)
    }
};
