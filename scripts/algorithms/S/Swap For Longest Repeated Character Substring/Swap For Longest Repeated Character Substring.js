// Runtime: 110 ms (Top 76.67%) | Memory: 45.7 MB (Top 13.33%)
/**
 * @param {string} text
 * @return {number}
 */

const getLast = (ar)=> ar[ar.length-1];
 var maxRepOpt1 = function(text) {

    let freq = {};

    // compute frequency map
    for(let i=0;i<text.length;i++){
        let e=text[i];
        !freq[e] && (freq[e]=0);
        freq[e]++;
    }

    let segments = [];
    segments.push({
        v:text[0],
        c:1
    });

    let max = 1;
    for(let i=1;i<text.length;i++){
        let e = text[i];
        let last = getLast(segments);

        if(last.v == e){
            last.c++;
            max = Math.max(max,last.c);
        }else{
            segments.push({v:e,c:1});
        }
    }

    for(let i=0,len=segments.length;i<len;i++){
        let {v,c} = segments[i];
        if(freq[v] > c){ // x x a , a x x , x a x
            max = Math.max(max,c+1);
        }
        if(i+2<len && v==segments[i+2].v){ // x a x a x a x a x x a x a
            let sum = c+segments[i+2].c;
            if(segments[i+1].c == 1){
                if(freq[v] > sum){
                    max = Math.max(max,1+sum);
                }else{
                    max = Math.max(max,sum);
                }
            }
        }
    }

    return max;

};
