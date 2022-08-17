class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        
        if(targetCapacity > jug1Capacity + jug2Capacity)
            return false;
        
        vector<int> dp(jug1Capacity + jug2Capacity + 1, -1);
        return helper(0, jug1Capacity, jug2Capacity, targetCapacity, dp);
    }
    
    bool helper(int tmp, int &jug1Capacity, int &jug2Capacity, int &targetCapacity, vector<int> &dp)
    {
        if(tmp < 0 || tmp > jug1Capacity + jug2Capacity)
            return false;
        
        if(tmp == targetCapacity)
            return true;
        
        if(dp[tmp] != -1)
            return dp[tmp];
        
        dp[tmp] = false;            
        if(helper(tmp + jug1Capacity, jug1Capacity, jug2Capacity, targetCapacity, dp))
            return dp[tmp] = true;
        
        if(helper(tmp - jug1Capacity, jug1Capacity, jug2Capacity, targetCapacity, dp))
            return dp[tmp] = true;
        
        if(helper(tmp + jug2Capacity, jug1Capacity, jug2Capacity, targetCapacity, dp))
            return dp[tmp] = true;
        
         if(helper(tmp - jug2Capacity, jug1Capacity, jug2Capacity, targetCapacity, dp))
            return dp[tmp] = true;
            
        return dp[tmp] = false;
    }
};
