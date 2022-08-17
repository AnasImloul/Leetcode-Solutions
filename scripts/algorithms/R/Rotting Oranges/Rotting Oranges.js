let convertAdjacentCellsToRotten = (grid, locations, rottenOranges) => {
    let didConvertAny = false;
    let newLocations = [];
    for(let i=0;i<locations.length;i++){
        let loci = locations[i][0]
        let locj = locations[i][1]
        
        if(loci+1 < grid.length && grid[loci+1][locj] === 1) {
            grid[loci+1][locj] = 2;
            newLocations.push([loci+1,locj])
            didConvertAny = true;
            rottenOranges++
        }
        if(loci-1 >= 0 && grid[loci-1][locj] === 1) {
            grid[loci-1][locj] = 2;
            newLocations.push([loci-1,locj])

            didConvertAny = true;
            rottenOranges++
        }
        if(locj+1 < grid[0].length && grid[loci][locj+1] === 1) {
            grid[loci][locj+1] = 2;
            newLocations.push([loci,locj+1])
            didConvertAny = true;
            rottenOranges++
        }
        if(locj-1 >= 0 && grid[loci][locj-1] === 1) {
            grid[loci][locj-1] = 2;
            newLocations.push([loci,locj-1])
            didConvertAny = true;
            rottenOranges++
        }
    }
    
    return {didConvertAny:didConvertAny, rottenOranges,locations:[...newLocations]}
}
var orangesRotting = function(grid) {
    let rottenLocation = [];
    let rottenOranges = 0;
    let totalOranges = 0;
    let minutes = 0;
    for(let i=0;i<grid.length;i++) {
        for(let j=0;j<grid[0].length;j++) {
            if(grid[i][j]===2) {
                rottenLocation.push([i,j])
                rottenOranges++;
            }
            if(grid[i][j]!==0) totalOranges++;
        }
    }
    
    while (1) {
        let gridConversionResult = convertAdjacentCellsToRotten(grid,rottenLocation,rottenOranges);
        if (gridConversionResult.didConvertAny) {
            rottenLocation = gridConversionResult.locations;
            minutes++;
            rottenOranges = gridConversionResult.rottenOranges;
        }
        else break
    }
    if(totalOranges===rottenOranges) return minutes;
    else return -1
    
};
