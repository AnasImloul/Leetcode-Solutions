var longestAwesome = function(s) {
    // freq starts with 0:0 because 9 0s is also a state and if I come across a 
    // 0 down the road, that means that the whole array up to index i is of the required type
    let firstIndex={0:0}, result=-1, curr=0
    for (let i = 0; i < s.length; i++) {
       curr^= 1<<s[i]
       // Check if you have seen curr^0=curr before, 
	   // because that would make the inbetween elements' xor = 000000000
       if(firstIndex[curr]!==undefined)
            result=Math.max(result,i-firstIndex[curr]+1)
       // Check all the other xors, because that would make 
	   // the inbetween elements of the required type (100000000,010000000,......,000000001)
       for (let j = 0; j <10; j++) {
            let ele=1<<j
            if(firstIndex[curr^ele]!==undefined)
                //i-firstIndex[curr^ele] because on freq I saved
				//the smallest index where I last met curr^ele
                result=Math.max(result,i-firstIndex[curr^ele]+1)
       }
       if(firstIndex[curr]===undefined)
		   firstIndex[curr]=i+1// +1 cos 0th place is for my 0 state
    }
 
    return result
};
