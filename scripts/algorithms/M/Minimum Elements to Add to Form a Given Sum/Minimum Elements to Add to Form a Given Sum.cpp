class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
     
        //just calculate how many limit values to be added to the array to make our currSum close to the goal
        long int currSum=0;
        for(auto ele:nums)
            currSum+=ele;
        long int remaining=abs(currSum-goal);
        if(remaining==0)
            return 0;
        long int res=(remaining/limit);
        //if remaining exists still after adding limit k times
        //ex - remaining - 7 limit -3 we have to add a 1 after adding two times of limit values (6)
        res+= (remaining%limit!=0) ? 1 : 0;
        return res;
        
    }
};
