class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        // base case:
        // if target is less then x then we can only have values like either
        // x - (x/x)-(x/x).... or (x/x)+(x/x)+(x/x)...
        if(target<x){
            return min((x-target)*2, target*2-1);
        }
        
        if(x==target) return 0;
        
        long long int sum=x;
        int ans=0;
        
        //greedly get to the closest number such that x>target and then perform either (x/x)+(x/x)+...+(x/x) or
        // x-(x/x)-(x/x)... etc
        
        while(sum<target){
             ans++;
            sum =sum*x;
           
        }
        
        // at this point sum is either greater than target or equal to target
        if(sum==target)
            return ans;
        
        // Now we have two choice to reduce the number either we make new number
        // ---> target = sum-target (but this can only work if target>sum-target)
        // ---> target-sum/x
        int op1 = INT_MAX, op2 = INT_MAX;
        if(sum-target<target){
            op1 = leastOpsExpressTarget(x, sum-target) + ans;
        }
        op2 = leastOpsExpressTarget(x, target-sum/x) + ans-1;
        
        return min(op1,op2)+1;
    }
};