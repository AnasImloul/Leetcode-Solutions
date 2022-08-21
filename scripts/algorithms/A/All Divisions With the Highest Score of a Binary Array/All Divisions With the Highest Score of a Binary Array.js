// Runtime: 596 ms (Top 40.00%) | Memory: 82.5 MB (Top 53.33%)

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var maxScoreIndices = function(nums) {
        let n=nums.length;
        // initialize 3 arrays for counting with n+1 size
        let zeros = new Array(n+1).fill(0);
        let ones = new Array(n+1).fill(0);
        let total = new Array(n+1).fill(0);

       // count no of zeros from left to right
        for(let i=0;i<n;i++){
            if(nums[i]==0)zeros[i+1]=zeros[i]+1;
            else zeros[i+1]=zeros[i];
        }

        // count no of ones from right to left
        for(let i=n-1;i>=0;i--){
            if(nums[i]==1)ones[i]=ones[i+1]+1;
            else ones[i]=ones[i+1];
        }

        // merge left and right to total and find max element
        let max=0;
        for(let i=0;i<n+1;i++){
            total[i]=ones[i]+zeros[i];
            if(total[i]>max)max=total[i];
        }

        // Find occurrence of max elements and return those indexes
        let ans= [];
        for(let i=0;i<n+1;i++){
            if(total[i]==max)ans.push(i);
        }

        return ans;
};