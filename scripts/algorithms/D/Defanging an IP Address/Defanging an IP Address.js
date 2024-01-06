// Runtime: 45 ms (Top 87.3%) | Memory: 41.80 MB (Top 53.19%)

/**
 * @param {string} address
 * @return {string}
 */
var defangIPaddr = function(address) {
    var result="";
    
    for(var i=0;i<address.length;i++) {
        if(address[i] === ".")
            result += "[.]";
        else
            result += address[i];
    }
    
    return result;    
};
