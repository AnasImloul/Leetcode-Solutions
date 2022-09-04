// Runtime: 258 ms (Top 54.35%) | Memory: 69.1 MB (Top 14.13%)
/**
 * @param {number} n
 * @param {number[][]} paths
 * @return {number[]}
 */
var gardenNoAdj = function(n, paths) {
    //if n is less than or equal to four just return an array of size n from 1 to n
    if(n <= 4){
        let arr = []
        let count = 1
        while(arr.length < n){
            arr.push(count)
            count++
        }
        return arr
    }
    //if there are no gardens connecting to each other then just return an array of size n with ones
    if(paths.length === 0)return new Array(n).fill(1)

    //because we have three possible paths connecting to gardens and 4 flowers we know that this problems is possible because our graph is of degree 3 and we have D + 1 flowers
    //to solve
    let adjList = {}
    // create an array filled with ones so if there is a garden with no path just fill with one
    let result = new Array(n).fill(1)
    let garden = new Set([1,2,3,4])

    //create adj list from the paths
    paths.forEach(path => {
        let first = path[0];
        let second = path[1];

        if(first in adjList )adjList[first].neighbors.add(second)
        else {adjList[first] = new Fnode(second)}

        if(second in adjList)adjList[second].neighbors.add(first)
        else {adjList[second] = new Fnode(first)}

    })

    for(let node in adjList){
        //every node
        let current = adjList[node]

        //create a set of invalid flowers, flowers you can't use because they are part of
        //the other gardens this one is connected to.
        let invalidFlower = new Set();

        //iterate over the neighbors to find what type of flower they have and if it is not
        //null included in the invalid flowers set
        current.neighbors.forEach(neighbor => {
            if(adjList[neighbor]['flower'] !== null){
                invalidFlower.add(adjList[neighbor]['flower'])
            }
        })

        //create our possible value or better said our value because we will use the first one
        //we obtain.
        let possibleFlower;

        //we iterate over over our garden {1,2,3,4}
        for(let flower of garden) {
            //and if our flower is not part of the invalid flowers;
            if(!invalidFlower.has(flower)){
                //we have found a possible flower we can use
                possibleFlower = flower
                //we break because this is the only one we need
                break;
            }
        }
        // we add our flower to current so that we dont use it in the future
        current.flower = possibleFlower

        //and update our result
        result[node - 1] = possibleFlower
    }
    //we return our result
    return result

};

//create a Flower class just for simplicity
class Fnode{
    constructor(neighbor){
        this.flower = null
        this.neighbors = new Set([neighbor])
    }
}