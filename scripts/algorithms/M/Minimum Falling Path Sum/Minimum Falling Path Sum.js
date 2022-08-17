//recursion 

var minFallingPathSum = function(matrix) {
    let n = matrix.length;
    
    let ans = Number.MAX_VALUE;
    for(let j = 0; j < n; j++){
        ans = Math.min(ans, solve(n - 1, j, n, matrix));
    }
    return ans;
};

function solve(i, j, n, arr){
    if(j < 0 || j >= n) return Number.MAX_VALUE;
    if(i == 0) return arr[0][j];
    
    let s = arr[i][j] + solve(i - 1, j, n, arr);
    let ld = arr[i][j] + solve(i - 1, j - 1, n, arr);
    let rd = arr[i][j] + solve(i - 1, j + 1, n, arr);
    
    return Math.min(s, Math.min(ld, rd));
}

// recursion to memoization

var minFallingPathSum = function(matrix) {
    let n = matrix.length;
    
    // create a dp array to store the calculated value.
    let dp = new Array(n);
    for(let i = 0; i < n; i++){
        dp[i] = new Array(n);
    }
    
    let ans = Number.MAX_VALUE;
    for(let j = 0; j < n; j++){
        //pass dp into the recursive function.
        ans = Math.min(ans, solve(n - 1, j, n, matrix, dp));
    }
    return ans;
};

function solve(i, j, n, arr, dp){
    if(j < 0 || j >= n) return Number.MAX_VALUE;
    if(i == 0) return arr[0][j];
    
    // before calculating any further recursive call check if it has been already calculated or not.
    if(dp[i][j] != undefined) return dp[i][j];
    
    let s = arr[i][j] + solve(i - 1, j, n, arr, dp);
    let ld = arr[i][j] + solve(i - 1, j - 1, n, arr, dp);
    let rd = arr[i][j] + solve(i - 1, j + 1, n, arr, dp);
    
    // in last store the calculated value in dp array.
    return dp[i][j] = Math.min(s, Math.min(ld, rd));
}

// tabulation 

var minFallingPathSum = function(matrix) {
    let n = matrix.length;
    
    let dp = new Array(n);
    for(let i = 0; i < n; i++){
        dp[i] = new Array(n);
    }
    
	// base case - here any one from the first row of matrix array can be a base case
    for(let j = 0; j < n; j++){
        dp[0][j] = matrix[0][j];
    }
    
	// go from next row and calculate value for each column
    for(let i = 1; i < n; i++){
        for(let j = 0; j < n; j++){
            
            let s = matrix[i][j] + dp[i - 1][j];
            let ld = matrix[i][j]
            if(j > 0) ld += dp[i - 1][j - 1];  // condition to restrict getting out of bound value from matrix.
            else ld = Number.MAX_VALUE;
            
            let rd = matrix[i][j];
            if(j < n - 1) rd += dp[i - 1][j + 1];
            else rd = Number.MAX_VALUE;
            
            dp[i][j] = Math.min(s, Math.min(ld, rd));
        }
    }
    
    let maxi = dp[n - 1][0];
    for(let j = 1; j < n; j++){
        maxi = Math.min(maxi, dp[n - 1][j]);
    }
    return maxi;
};

// further space optimized

var minFallingPathSum = function(matrix) {
    let n = matrix.length;
    
    // create a dp array to store the calculated value.
    let prev = new Array(n);
    
    for(let j = 0; j < n; j++){
        prev[j] = matrix[0][j];
    }
    
    for(let i = 1; i < n; i++){
        let cur = new Array(n);
        for(let j = 0; j < n; j++){
            
            let s = matrix[i][j] + prev[j];
            let ld = matrix[i][j]
            if(j > 0) ld += prev[j - 1];
            else ld = Number.MAX_VALUE;
            
            let rd = matrix[i][j];
            if(j < n - 1) rd += prev[j + 1];
            else rd = Number.MAX_VALUE;
            
            cur[j] = Math.min(s, Math.min(ld, rd));
        }
        prev = cur;
    }
    
    let maxi = prev[0];
    for(let j = 1; j < n; j++){
        maxi = Math.min(maxi, prev[j]);
    }
    return maxi;
};
