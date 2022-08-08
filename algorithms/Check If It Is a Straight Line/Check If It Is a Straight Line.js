var checkStraightLine = function(coordinates) {
    coordinates.sort((a, b) => a[1] - b[1])
    
    let slopeToCheck = (coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0])
    
    for (let i = 2; i < coordinates.length; i++) {
        let currSlope = (coordinates[i][1] - coordinates[i - 1][1]) / (coordinates[i][0] - coordinates[i - 1][0]);
        
        if (currSlope !== slopeToCheck) return false;
    }
    
    return true;
};
