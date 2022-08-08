/**
 * @param {number[][]} grid
 * @return {number}
 */
var countNegatives = function(grid) {
  
    const m = grid.length
    const n = grid[0].length
    
    // for each row we need to find location of first negative
    // all columns past that are negative
    // also for next row search stops before
    // location of current first negative because 
    // all numbers below current are also lesser (negative) 
    
    function binSearch(start,end, arr){
        
        while(start<=end){
            let mid = start + ((end-start)>>1)
            if(arr[mid] < 0)
                end = mid - 1
            else 
                start = mid + 1
        }
        return arr[end]<0 ? end : end + 1
    }
    
    
    
    let ans = 0
    let searchTill = n-1
    for(let i=0;i<m;i++){
        
        if(searchTill<0){ 
            // last row found 0 in first column
            ans += n
            continue;
        }
        
        let firstNegative = binSearch(0,searchTill, grid[i])
        searchTill = firstNegative - 1
        ans += (n - firstNegative)
    }
    return ans
};
