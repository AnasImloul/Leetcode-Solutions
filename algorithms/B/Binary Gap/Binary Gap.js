var binaryGap = function(n) {
    var str = (n >>> 0).toString(2), start = 0, end = 0, diff = 0;
    for(var i=0;i<str.length;i++) {
    	if(str[i] === '1') {
      	end = i;
        diff = Math.max(diff, end - start);
        start = i;
      } 
    }
    return diff;
};
