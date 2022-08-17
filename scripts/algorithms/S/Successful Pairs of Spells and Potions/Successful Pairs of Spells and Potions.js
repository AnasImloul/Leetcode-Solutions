/**
 * @param {number[]} spells
 * @param {number[]} potions
 * @param {number} success
 * @return {number[]}
 */
 var successfulPairs = function(spells, potions, success) {
    let res = [];
    potions.sort((a, b) => b-a);
    let map = new Map();
    
    for(let i=0; i<spells.length; i++){
        if(!map.has(spells[i])){
            let s = success / spells[i];
            let len = search(potions, s);
            res.push(len);
            map.set(spells[i], len);
        }else{
            let len = map.get(spells[i]);
            res.push(len);
        }
    }
    
    return res;
};

function search(potions, target){
    let res = 0;
    let left = 0;
    let right = potions.length-1;
    while(left <= right){
        let mid = Math.floor((left + right) / 2);
        if(potions[mid] < target){
            right = mid - 1;
        }else{
            left = mid + 1;
            res = mid + 1;
        }
    }

    return res;
}
