var romanToInt = function(s) {
    let v = [];
    let romans = [{a: 'I', b: 1}, {a: 'V', b: 5}, {a: 'X', b: 10}, 
                  {a: 'L', b: 50}, {a: 'C', b: 100}, {a: 'D', b: 500}, {a: 'M', b: 1000}];
    for(let i=0; i<s.length; i++){
        for(let j=0; j<romans.length; j++){
            if(s[i] == romans[j].a){
                v.push(romans[j].b);
            }
        }
    }
    let n = 0;
    for(let i=0; i<v.length; i++){
        if(i+1 < v.length){
            if(v[i+1] <= v[i]){
                n += v[i];
            }
            else if(v[i+1] > v[i]){
                n = n + v[i+1] - v[i]
                i += 1;
                if(i >= v.length){
                    return n;
                }
            }
        }
        else{
            n += v[i]; 
        }
    }
    return n;
};
