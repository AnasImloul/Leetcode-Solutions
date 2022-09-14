// Runtime: 748 ms (Top 53.33%) | Memory: 151.7 MB (Top 40.00%)
/**
 * @param {number[]} favorite
 * @return {number}
 */
var maximumInvitations = function(favorite) {
    let res = 0;
    let len = favorite.length;
    // count the number indegree
    let indegree = new Array(len).fill(0);
    // save the number relation
    let rMap = new Map();
    for(let i=0; i<favorite.length; i++){
        indegree[favorite[i]] ++;

        if(rMap.has(favorite[i])){
            let arr = rMap.get(favorite[i]);
            arr.push(i);
            rMap.set(favorite[i], arr);
        }else{
            rMap.set(favorite[i], [i]);
        }
    }
    // find the 0 indegree number
    let arr = [];
    for(let i=0; i<len; i++){
        if(indegree[i] === 0){
            arr.push(i);
        }
    }
    // check if the circle exist
    let search = 0;
    // the length of uncircle
    let l = 1;
    // save the number and the length of uncircle
    let lMap = new Map();
    while(arr.length > 0){
        let tmp = [];
        for(let i=0; i<arr.length; i++){
            lMap.set(arr[i], l);
            let next = favorite[arr[i]];
            indegree[next] --;
            search ++;
            if(indegree[next] === 0){
                tmp.push(next);
            }
        }
        // update the length of uncircle
        l ++;
        arr = [...tmp];
    }

    if(search === len){
        // circle not exist
    }else{
        // circle exist
        // find the not 0 indegree number
        let keys = find(indegree);
        // mark the search number in circle
        let circleMap = new Map();
        // the length of circle
        let circleLen = 1;
        // the max length of circle
        let maxCircleLen = 0;
        // sum the length of circle
        let sumCircleLen = 0;
        let cArr = [keys[0]];

        while(cArr.length > 0){
            let tmp = [];
            for(let i=0; i<cArr.length; i++){
                // not find the circle
                if(!circleMap.has(cArr[i])){
                    circleMap.set(cArr[i], circleLen);
                    tmp.push(favorite[cArr[i]]);
                // find the circle
                }else{
                    maxCircleLen = Math.max(maxCircleLen, circleLen-1);
                    // if the length equals 2 then sum the length
                    if(circleLen-1 === 2){
                        let m = calc(cArr[i], rMap, lMap) + calc(favorite[cArr[i]], rMap, lMap) + 2;
                        sumCircleLen += m;
                    }
                    // reset the length
                    circleLen = 0;
                    // find the next number not search
                    for(let i=0; i<keys.length; i++){
                        if(!circleMap.has(keys[i])){
                            tmp.push(keys[i]);
                            break;
                        }
                    }
                }
            }
            circleLen ++;
            cArr = [...tmp];
        }
        res = Math.max(res, maxCircleLen, sumCircleLen);
    }

    return res;
};

function calc(num, rMap, lMap){
    let res = 0;
    let arr = rMap.has(num) ? rMap.get(num) : [];
    if(arr.length > 0){
        for(let i=0; i<arr.length; i++){
            let l = lMap.has(arr[i]) ? lMap.get(arr[i]) : 0;
            res = Math.max(res, l);
        }
    }
    return res;
}

function find(arr){
    let res = [];
    for(let i=0; i<arr.length; i++){
        if(arr[i] > 0){
            res.push(i);
        }
    }
    return res;
}