/**
 * @param {number[]} edges
 * @return {number}
 */
var longestCycle = function(edges) {
    let res = -1;
	// count the node indegree
    let map = new Map();
    let len = edges.length;
    for(let i=0; i<edges.length; i++){
        if(edges[i] !== -1){
            if(map.has(edges[i])){
                let c = map.get(edges[i]);
                c ++;
                map.set(edges[i], c);
            }else{
                map.set(edges[i], 1);
            }
        }
    }
	// find the node of 0 indegree
    let arr = [];
    for(let i=0; i<len; i++){
        if(!map.has(i)){
            arr.push(i);
        }
    }
    // count the search node
    let search = 0;
    while(arr.length > 0){
        let tmp = [];
        for(let i=0; i<arr.length; i++){
            search ++;
            let next = edges[arr[i]];

            if(next !== -1){
                let c = map.get(next);
                c --;
                if(c === 0){
                    tmp.push(next);
                    map.delete(next);
                }else{
                    map.set(next, c);
                }
            }
        }
        arr = [...tmp];
    }

    if(search === len){
        // no circle
    }else{
        // exist circle
		// consider there may be some circles
        let circleMap = new Map();
        let keys = Array.from(map.keys());
        let circle = [keys[0]];
        let circleLen = 0;
		// mark the max length of circle
        let max = 0;
        while(circle.length > 0){
            let tmp = [];
            for(let i=0; i<circle.length; i++){
                if(!circleMap.has(circle[i])){
				    // node not search
                    circleMap.set(circle[i], 1);
                    circleLen ++;
                    tmp.push(edges[circle[i]]);
                }else{
				    // node search
                    max = Math.max(max, circleLen);
                    circleLen = 0;
                    // find the next possible node
                    for(let j=0; j<keys.length; j++){
                        if(!circleMap.has(keys[j])){
                            tmp.push(keys[j]);
                            break;
                        }
                    }
                }
            }
            circle = [...tmp];
        }

        res = max;
    }

    return res;
};
