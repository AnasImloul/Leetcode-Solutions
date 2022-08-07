var countSmaller = function(nums) {
    if(nums===null || nums.length == 0) return []
    
    let N = nums.length
    const result = new Array(N).fill(0)
    const numsWithIdx = new Array(N).fill(0)
    
    for(let i = 0; i < nums.length; i++) {
        const curr = nums[i]
        
        numsWithIdx[i] = {val:curr, originalIdx: i}
    }

    divideAndConqueuer(0, nums.length - 1)
    
    const resultList = []
    result.forEach(el => resultList.push(el))
    
    return resultList

    function divideAndConqueuer(left, right) {
        if(left < right) {
            const mid = Math.floor(left + (right - left)/2)
            divideAndConqueuer(left, mid)
            divideAndConqueuer(mid+1, right)
            merge(left, mid, right)
        }
    }

    function merge(left, mid, right) {
        const leftLen = mid - left + 1
        const rightLen = right - mid
        
        let rightSmallers = 0

        const leftAux = new Array(leftLen).fill(0)
        const rightAux = new Array(rightLen).fill(0)


        for(let i = 0; i < leftLen; i++) {
            leftAux[i] = numsWithIdx[left+i]
        }


        for(let i = 0; i < rightLen; i++) {
            rightAux[i] = numsWithIdx[mid+1+i]
        }


        let leftPointer = 0
        let rightPointer = 0
        let insertAtPointer = left

        while(leftPointer < leftLen && rightPointer < rightLen) {
            if(leftAux[leftPointer].val <= rightAux[rightPointer].val) {
                
                result[leftAux[leftPointer].originalIdx] += rightSmallers  
                numsWithIdx[insertAtPointer++] = leftAux[leftPointer++]
                
            } else {
                numsWithIdx[insertAtPointer++] = rightAux[rightPointer++]                
                rightSmallers++
            }
        }


        while(rightPointer < rightLen) {
                numsWithIdx[insertAtPointer++] = rightAux[rightPointer++]                            
        }
        
        while(leftPointer < leftLen) {
                result[leftAux[leftPointer].originalIdx] += rightSmallers  
                numsWithIdx[insertAtPointer++] = leftAux[leftPointer++]            
        }

    }
};
