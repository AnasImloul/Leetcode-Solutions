// Runtime: 196 ms (Top 92.11%) | Memory: 93.10 MB (Top 73.68%)

/**
 * @param {number[]} arr
 * @return {number}
 */
var minJumps = function(arr) {
    let valuePositionsMap = getValuePositionsMap(arr);
    let mySet = new Set();
    mySet.add(0);
    let aoArray = [0];
    let counter = 0;
    while(!mySet.has(arr.length-1)){
        counter++;
        let newArray = [];
        for(let currP of aoArray){
            for(let item of findAllOptions(arr, currP, mySet, valuePositionsMap)){
                newArray.push(item);
                mySet.add(item);
                if(item == arr.length-1){
                    break;
                }
            }
            if(mySet.has(arr.length-1)){
                break;
            }
        }
        aoArray = newArray;
    }
    return counter;
};

function getValuePositionsMap(arr){
    let result = new Map();
    for(let i=arr.length-1;i>=0;i--){
        if(!result.has(arr[i])){
            result.set(arr[i], []); 
        }
        result.get(arr[i]).push(i);
    }
    return result;
}

function findAllOptions(arr, currP, mySet, valuePositionsMap){
    let result = [];
    if(currP > 0 && arr[currP-1] != arr[currP] && !mySet.has(currP-1)){
        result.push(currP-1);
    }
    if(currP < arr.length-1 && arr[currP+1] != arr[currP] && !mySet.has(currP+1)){
        result.push(currP+1);
    }
    if(valuePositionsMap.has(arr[currP])){
        for(let i of valuePositionsMap.get(arr[currP])){
            if(i != currP && !mySet.has(i)){
                result.push(i);
            }
        }
        valuePositionsMap.delete(arr[currP]);
    }
    return result;
}
