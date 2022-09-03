// Runtime: 418 ms (Top 31.73%) | Memory: 49.8 MB (Top 48.21%)
class Solution {
public:
    bool canCross(vector<int>& stones) {
       unordered_map<int,bool>mp; //to see the position where stone is present
       for(int i=0;i<stones.size();i++)
       {
           mp[stones[i]]=true;
       }
       int stone=1; //current stone
       int jump=1; //jump made
       int last_stone=stones[stones.size()-1]; //last stone on which frog will land to cross river
       map<pair<int,int>,bool>dp;
       return fun(mp,stone,jump,dp,last_stone);
    }
    bool fun( unordered_map<int,bool>&mp,int stone,int jump,map<pair<int,int>,bool>&dp,int &ls)
    {
        if(stone==ls) //reached last stone
        {
            return true;
        }
        if(mp.find(stone)==mp.end()) //stone is not present
        {
            return false;
        }
        if(dp.find({stone,jump})!=dp.end())
        {
            return dp[{stone,jump}];
        }
        bool jump1=false;
        bool jump2=false;
        bool jump3=false;
        if((stone+jump-1)>stone) //can take jump of k-1 units
        {
            jump1=fun(mp,stone+jump-1,jump-1,dp,ls);
        }
        if((stone+jump)>stone) //can take jump of k units
        {
            jump2=fun(mp,stone+jump,jump,dp,ls);
        }
        if((stone+jump+1)>stone) //can take jump of k+1 units
        {
            jump3=fun(mp,stone+jump+1,jump+1,dp,ls);
        }
        dp[{stone,jump}]=jump1 or jump2 or jump3;
        return dp[{stone,jump}];
    }
};