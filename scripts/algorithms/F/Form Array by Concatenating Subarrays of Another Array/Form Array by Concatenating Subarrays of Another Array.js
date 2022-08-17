/**
 * @param {number[][]} groups
 * @param {number[]} nums
 * @return {boolean}
 */
var canChoose = function(groups, nums) {
    let i=0;
    for(let start=0;i<groups.length&&groups[i].length+start<=nums.length;start++){
        
        if(search(groups[i], nums, start)){
            start+=groups[i].length-1;
            i++;
        }
    }
    return i==groups.length;
    
    function search(group, nums, start){
        for(let i =0;i<group.length;i++){
            if(group[i]!=nums[i+start]) return false;
        }
        return true;
    }
};
