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
