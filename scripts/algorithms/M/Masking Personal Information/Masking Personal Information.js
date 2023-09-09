// Runtime: 39 ms (Top 100.0%) | Memory: 42.72 MB (Top 5.8%)

var maskPII = function(S) {
    if (isEmail(S)) return maskEmail(S);
    return maskPhone(S);
    
    function isEmail(str) {
       return /^[A-Za-z]{2,}@[A-Za-z]{2,}.[A-Za-z]{2,}$/.test(str);
    }
    
    function maskEmail(str) {
        let res = "";
        const [local, domain] = str.split("@");
        
        res += local.charAt(0).toLowerCase() + "*****" + local.charAt(local.length - 1).toLowerCase();
        return res + "@" + domain.toLowerCase(); 
    }
    
    function maskPhone(str) {
        const onlyDigits = str.replace(/\D/g, "");
        
        const localNum = "***-***-" + onlyDigits.substring(onlyDigits.length - 4);
        
        if (onlyDigits.length === 10) return localNum;
        
        let countryNum = "+" + "*".repeat(onlyDigits.length - 10) + "-";
        
        return countryNum + localNum;
    } 
};