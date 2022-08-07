var compareVersion = function(version1, version2) {
    const v1 = version1.split('.')
    const v2 = version2.split('.')
	
	let max=Math.max(v1.length,v2.length);
    
    for(let i=0;i<max;i++){
        if(v1[i]&&v2[i]){ // if both v1 and v2 are present
            if(+v1[i] > +v2[i])return 1
            else if(+v1[i] < +v2[i])return -1
        }else if(v1[i] && +v1[i]!==0){ // if v1 is larger than v2 but make sure those digits are not 0.
            return 1
        }else if(v2[i] && +v2[i]!==0){ // if v2 is larger than v1 but make sure those digits are not 0.
            return -1
        }
    }
    return 0
};
