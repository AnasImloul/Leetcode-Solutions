/**
 * @param {string[]} ideas
 * @return {number}
 */
var distinctNames = function(ideas) {
    let res = 0;
    let lMap = new Map();

    for(let i=0; i<ideas.length; i++){
        let idea = ideas[i];
        // extract first letter
        let l = idea[0].charCodeAt() - 97;
        // extract substring
        let s = idea.substr(1);
        // group substring by first letter
        if(lMap.has(l)){
		    // must use map not array
            let m = lMap.get(l);
            m.set(s, 1);
            lMap.set(l, m);
        }else{
            let m = new Map();
            m.set(s, 1);
            lMap.set(l, m);
        }
    }

    for(let i=1; i<26; i++){
        for(let j=0; j<i; j++){
            // count substring with different first letter
            let m = 0;
            let m1 = lMap.has(i) ? lMap.get(i) : new Map();
            let m2 = lMap.has(j) ? lMap.get(j) : new Map();
			// both map must exist
            if(m1.size > 0 && m2.size > 0){
                let k1 = Array.from(m1.keys());
                for(let k=0; k<k1.length; k++){
                    if(m2.has(k1[k])){
                        m ++;
                    }
                }
                // the rest substring satisfy condition
                res += (m1.size - m) * (m2.size-m);
            }
        }
    }
    // double for count A + B and B + A
    res = res * 2;
    return res;    
};
