// Runtime: 176 ms (Top 25.00%) | Memory: 49.5 MB (Top 100.00%)
var maxCandies = function(status, candies, keys, containedBoxes, initialBoxes) {
    var candyCounter = 0
    //set is like array, but does not allow duplicates and can have object references
    var ownedKeys = new Set()
    var ownedBoxes = initialBoxes
    var checkedBoxes = []
    for (let i=0; i<ownedBoxes.length; i++){
        let curBox = ownedBoxes[i]
        //checks if the box being checked is open or you have a key, then adds contents of the box to my data structures
        //Set.prototype.has is like Array.prototype.includes
        if (ownedKeys.has(curBox) || status[curBox]){
            candyCounter += candies[curBox]
            //clears checked boxes so keys can be re-referenced
            checkedBoxes = []
            for (let j=0; j<keys[curBox].length; j++){
                //add is like push, but for sets
                ownedKeys.add(keys[curBox][j])
            }
            for (let j=0; j<containedBoxes[curBox].length; j++){
                ownedBoxes.push(containedBoxes[curBox][j])
            }
        }
        //Prevents infinite looping by maintaining a ledger of checked boxes, which is cleared upon a successful opening
        else if (!checkedBoxes.includes(curBox)) {
            //takes the box being checked and moves it to the end of the array, and marks it as checked
            ownedBoxes.push(curBox)
            checkedBoxes.push(curBox)
            ownedBoxes.splice(i, 1)
            //de-iterate i to account for the removal of this number at its previous index
            i--
        }
    }
    return candyCounter
};