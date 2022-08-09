var matchReplacement = function(s, sub, mappings) {
    let n= s.length;
    let m = sub.length;
    let map = new Array(36).fill().map(_=>new Array(36).fill(0));
    for(let i=0;i<mappings.length;i++) {
        let [o,ne] = mappings[i];
        if(isNaN(o)) {
            o = (o.toUpperCase()).charCodeAt(0)-55;
        } else {
            o = parseInt(o);
        }
        
        if(isNaN(ne)) {
            ne = (ne.toUpperCase()).charCodeAt(0)-55;
        } else {
            ne = parseInt(ne);
        }
        map[o][ne]=1;
    }
    // let map = new Map(mappings);
    for(let i=0;i<=n-m;i++) {
        let z=i;
        let j=0;
        while(j<m){
            if(s[z] !== sub[j]) {
                let ne = s[z];
                let o = sub[j];
                if(isNaN(o)) {
                    o = (o.toUpperCase()).charCodeAt(0)-55;
                } else {
                    o = parseInt(o);
                }

                if(isNaN(ne)) {
                    ne = (ne.toUpperCase()).charCodeAt(0)-55;
                } else {
                    ne = parseInt(ne);
                }
                if(map[o][ne] !== 1){
                    break;
                }
            }
            z++;
            j++;
        }
        if(j == m){
            return true
        }
    }
    return false
};
