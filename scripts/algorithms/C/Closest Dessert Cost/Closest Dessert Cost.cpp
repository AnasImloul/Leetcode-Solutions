// Runtime: 12 ms (Top 88.73%) | Memory: 9.9 MB (Top 42.44%)
class Solution {
public:

    //ans-> store final result
    //mn -> Current minimum difference b/w target and curr_price
    int ans=INT_MAX,mn=INT_MAX;

    /*
      i-> index of tc(toppingCosts)
      curr -> current cost taken
      tar -> Target cost
    */

    void find(int i,vector<int>& tc,int curr, int tar)
    {
        /*
           if difference b/w current cost and target cost is
           less than min difference , so we have to update ans
           and min difference because we got closest to target
        */
        if(abs(curr-tar)<mn)
        {
            mn=abs(curr-tar);
            ans=curr;
        }

        /*
           if difference b/w current cost and target cost is
           equal to min difference , so we have to update ans
           and takin minimum one as condition given in problem
        */
        if(abs(curr-tar)==mn) ans=min(ans,curr);

        /*
           If we are going out of bound just return
           because we will nothing get after here
        */
        if(i>=tc.size() || curr-tar>mn) return;

        /* Main interesting thing -> How to recurse */
        /*
            Just put all the required conditions

            NOTE: We have already taken 1 baseCosts, so left that
                  We have to select from tc(toppingCosts)

            In our question we have 3 conditon
            1. Take ith toppingCosts and go for next (i+1)th toppingCost
            2. Take ith toppingCosts 2 times and go for next (i+1)th toppingCost
            3. We will not take ith toppingCosts and will select next ones
        */

        //taking ith toppingCosts and moving to (i+1)th toppingCosts
         find(i+1,tc,curr+tc[i],tar);

        //taking ith toppingCosts 2 times and moving to (i+1)th toppingCosts
         find(i+1,tc,curr+2*tc[i],tar);

        //Without taking ith toppingCosts and move to (i+1)th toppingCosts for next one
         find(i+1,tc,curr,tar);

    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {

        //take each baseCost every time
        for(auto x:baseCosts)
        {
            //taking ith baseCost and select toppingCosts
            find(0,toppingCosts,x,target);
        }

        //return closest to target answer
        return ans;

    }
};