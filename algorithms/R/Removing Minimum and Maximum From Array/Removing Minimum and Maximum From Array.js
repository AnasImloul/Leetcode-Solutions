var minimumDeletions = function(nums) {
    if(nums.length===1)return 1
    let min=Math.min()
    let max=Math.max()
    
	// finding min and max
    for(let n of nums){
        min=Math.min(n,min)
        max=Math.max(n,max)
    };
    
	// obj to store no. of elements to remove if we start from left and if we start from right
    const obj={
        left:[],
        right:[]
    }
	// left[0]-> no. of elements upto min element if we start from left
	// left[1]-> no. of elements upto max element if we start from left
	// right[0]-> no. of elements upto min element if we start from right
	// right[1]-> no. of elements upto max element if we start from right
    for(let i=0;i<nums.length;i++){
        if(nums[i]===max){
            obj['left'][1]=i+1
            obj['right'][1]=nums.length-i
        }
        if(nums[i]===min){
            obj['left'][0]=i+1
            obj['right'][0]=nums.length-i
        }
    }
    let total=0
    const set = new Set();
	// if no. of elements to remove min element from left is less than right 
    if(obj['left'][0]<obj['right'][0]){
        set.add('left');
        total+=obj['left'][0]
    }else{
		// vice versa
        set.add('right');
        total+=obj['right'][0]
    }
	// if no. of elements to remove max element from right is less than left 
     if(obj['left'][1]<obj['right'][1]){
        set.add('left');
         total+=obj['left'][1]
    }else{
		// vice versa
        set.add('right');
        total+=obj['right'][1]
    }
	
	// if both elements are to be removed from diff direction inorder to remove lesser element
	// we have 3 cases: 
	// one from left and one from right(total), min/max element lies after max/min ele from left,min/max element lies after max/min ele from right
    if(set.size===2)return Math.min(total,Math.max(...obj['left']),Math.max(...obj['right']));
    else{
	   // if both elements can be removed from same direction(ie. either left or right)
        return Math.max(...obj[set.values().next().value])
    }
    
};
