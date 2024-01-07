// Runtime: 713 ms (Top 100.0%) | Memory: 51.80 MB (Top 33.33%)

/**
 * @param {string} s
 * @param {string} sub
 * @param {character[][]} mappings
 * @return {boolean}
 */
var matchReplacement = function(s, sub, mappings) {
    let duy={};
    for(let i = 0 ; i<mappings.length ; i++){
    		if(duy[mappings[i][0]] == undefined){
        		duy[mappings[i][0]] = mappings[i][1];
        }else{
        		duy[mappings[i][0]] += mappings[i][1];
        }
    }
    let vt=[];
    for(let i  = 0 ; i < s.length ; i++){
    	if(s[i] == sub[0]){
      		vt.push(i)
      }
    }
    if(duy[sub[0]]!=undefined){
      for(let i  = 0 ; i < s.length ; i++){
        if(duy[sub[0]].indexOf(s[i])>=0){
            vt.push(i)
        }
      }
    } 
    
    let lck=[],cu="";
    for(let i = 0 ; i < vt.length ; i++){
    cu=s.substr(vt[i],sub.length);
    if(cu.length ==sub.length)
    	lck.push(cu)
    }
    console.log(lck.length)

    let ck="",check=true;
    for(let i = 0 ; i< lck.length ; i++){
    	ck=lck[i];
      check=true;
    	for(let j = 0 ; j< ck.length ; j++){
      	if(ck[j] == sub[j] || (duy[sub[j]] &&duy[sub[j]].indexOf(ck[j])>=0 				)){
        	continue;
        }
        else{
        check=false;
        break;
        }
      }
      if(check){
      return true;
      }
    }
    return false;
};
