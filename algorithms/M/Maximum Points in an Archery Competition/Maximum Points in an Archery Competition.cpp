class Solution {
public:
    int maxscore; 
    vector<int> ans;
    
    void helper(vector<int> &bob, int i, vector<int>& alice, int remarrows, int score)
    {
        if(i == -1  or  remarrows <= 0)
        {
            if(score >= maxscore)
            {
                maxscore = score; 
                ans = bob; 
            }
            return; 
        }
        
        helper(bob, i-1, alice, remarrows, score);
        if(remarrows > alice[i])
        {
            bob[i] = alice[i] + 1;
            remarrows -= (alice[i] + 1);
            score += i; 
            helper(bob, i-1, alice, remarrows, score);
            bob[i] = 0;
        } 
    }
    
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> bob(12, 0);
        maxscore = INT_MIN; 
        helper(bob, 11, aliceArrows, numArrows, 0);
        
        int arrows_used = 0; 
        for(int a : ans)
            arrows_used += a; 
        if(arrows_used < numArrows)
            ans[0] += (numArrows - arrows_used);
        return ans; 
    }
};
