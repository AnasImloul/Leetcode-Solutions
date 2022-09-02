// Runtime: 144 ms (Top 6.45%) | Memory: 44.9 MB (Top 6.45%)
/**
 * @param {number[]} row
 * @return {number}
 */
var minSwapsCouples = function(row) {
    let currentPositions = [];

    for(let i=0;i<row.length;i++){
        currentPositions[row[i]]=i;
    }

    let swapCount = 0;

     for(let j=0;j<row.length;j+=2) // Looping through the couches
         {

    let leftPartner = row[j];
    let correctRightPartner = getPartner(leftPartner);
        if(row[j+1] !== correctRightPartner)
        {
            console.log("unhappy");
            //Swap Positions of positions - Bring the Correct Right Partner in the Couch
            let tempValue = row[j+1];
            row[j+1]=correctRightPartner;
            let tempPosition = currentPositions[correctRightPartner];
            row[tempPosition]=tempValue;

            //Correct the Hash Table keeping the currentPositions of each Person.
            currentPositions[correctRightPartner]=j+1;
            currentPositions[tempValue]=tempPosition;

            swapCount+=1;
        }
        else
        {

        console.log("happy");
        }
    }

    console.log("currentPositions", currentPositions,"Correct Row", row);

    return swapCount;

};
function getPartner(x){
    if(x%2 ===0)
    {
        return x+1;
    }
    else
        return x-1;
}