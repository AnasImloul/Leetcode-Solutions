var champagneTower = function(poured, query_row, query_glass) {
    
    let water = [poured];
    let hasOverflow = true;
    let row = 0;

    while(true){
        
        if (! hasOverflow) return 0   // We haven't reached query_row yet, and water ran out
        hasOverflow = false;
        
        let rowGlass = Array(water.length).fill(0);    // List of glasses at current row
        for (let i = 0; i < rowGlass.length; i++){
            let input = water[i];
            if (input <= 1){
                rowGlass[i] = input;
                water[i] = 0
            }else{
                rowGlass[i] = 1;
                water[i]--
            }
            if (row == query_row && i == query_glass){  // Return if we reach goal before water run out
                return rowGlass[i]
            }
        }
        // console.log('row,rowGlass',row,rowGlass);  // to debug
        
        let nextWater = Array(water.length + 1).fill(0);  // water poured towards next row, 
        for (let i = 0; i < rowGlass.length; i++){
            let overflow = water[i];
            
            if (overflow > 0) hasOverflow = true;
            
            nextWater[i] += overflow / 2;
            nextWater[i+1] += overflow / 2;
        }
        water = nextWater;
        row ++;
    }
};
