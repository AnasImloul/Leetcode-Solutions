var maxSizeSlices = function(slices) {
    const numSlices = slices.length / 3;
    const len = slices.length - 1;
    
    const dp = new Array(len).fill(null).map(() => new Array(numSlices + 1).fill(0));
    const getMaxTotalSlices = (pieces) => {
	    // the max for 1 piece using only the first slice is itself
        dp[0][1] = pieces[0];
		// the max for 1 piece using the first 2 slices is the max of the first and second slice
        dp[1][1] = Math.max(pieces[0], pieces[1]);
		// start the max as the max of taking 1 slice from the first 2 slices
        let max = dp[1][1];
		
		// calculate the max value for taking x number of pieces using up to that piece
        for (let i = 2; i < pieces.length; i++) {
            for (let numPieces = 1; numPieces <= numSlices; numPieces++) {
                dp[i][numPieces] = Math.max(dp[i - 1][numPieces],                    // the max for not taking this piece
				                            dp[i - 2][numPieces - 1] + pieces[i]);   // the max for taking this piece
                if (max < dp[i][numPieces]) max = dp[i][numPieces];                  // update the max if it is greater
            }
        }
        return max;
    }
    
    return Math.max(getMaxTotalSlices(slices.slice(0, slices.length - 1)),    // get max without the last slice
                    getMaxTotalSlices(slices.slice(1)));                      // get max without the first slice
};
