// Runtime: 217 ms (Top 10.77%) | Memory: 58.9 MB (Top 49.23%)
var shortestSequence = function(rolls, k)
{
    let ans=1;
    let sett=new Set();

    for(let i of rolls)
        {
            sett.add(i);
            if(sett.size===k)
                {
                    ans++;
                    sett=new Set();
                }
        }
    return ans;
};