// Runtime: 101 ms (Top 5.8%) | Memory: 45.94 MB (Top 5.8%)

var twoEditWords = function(queries, dictionary) {
    var queryCorr = []
    for(var i=0;i<queries.length;i++)
    {
        var maxCorr = 0
        for(var j=0;j<dictionary.length;j++)
        {
            var corr = 0;
            for(var w=0;w<dictionary[j].length;w++)
            {
                if(dictionary[j][w] == queries[i][w])
                {
                    corr++
                }
            }  
            if(corr>maxCorr)
            {
                maxCorr = corr
            }
        }
        console.log(queries[i])
        console.log(":")
        console.log(corr)
        if(queries[i].length-maxCorr<=2)
        {
            queryCorr.push(queries[i])
        }
        
    }
    return queryCorr
    
};