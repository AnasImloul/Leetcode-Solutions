// Runtime: 168 ms (Top 57.53%) | Memory: 48.9 MB (Top 58.07%)
var numSplits = function(s) {
        let n = s.length;
        let preFix = new Array(n) , suFix = new Array(n);
        let preSet = new Set();
        let suSet = new Set();

        for(let i=0; i<n ; i++){
            preSet.add(s[i]);
            suSet.add(s[n-1-i]);
            preFix[i]= preSet.size;
            suFix[n-1-i]= suSet.size;
        }

        let goodWays=0;

        for(let i=0; i<n-1; i++){
            if(preFix[i]===suFix[i+1]) goodWays++;
        }

        return goodWays;
};