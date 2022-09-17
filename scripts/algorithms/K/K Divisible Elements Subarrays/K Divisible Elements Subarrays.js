// Runtime: 3190 ms (Top 8.57%) | Memory: 86.8 MB (Top 45.72%)
var countDistinct = function(nums, k, p) {
    let ans = [];

    let rec = (index,k,p,nums,ans,curr) => {
        let val = nums[index];
        let check = val%p;
        let isdiv = false;
        if(check == 0) isdiv=true;

        if(index == nums.length) {
            if(curr.length>0){
                ans.push(curr.join(","));
            }
            return;
        }

        //take conditions
        if(isdiv && k==0){
          ans.push(curr.join(","));
        } else if(isdiv){
             curr.push(val)
             rec(index+1,k-1,p,nums,ans,curr);
             curr.pop()
        } else {
             curr.push(val)
             rec(index+1,k,p,nums,ans,curr);
             curr.pop()
        }

        //non take conditions
        if(curr.length == 0){
             rec(index+1,k,p,nums,ans,curr);
        } else {
            ans.push(curr.join(","));
        }

    }
    rec(0,k,p,nums,ans,[]);
    let set = new Set(ans);

    return set.size
};