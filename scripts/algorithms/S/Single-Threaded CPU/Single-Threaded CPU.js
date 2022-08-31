// Runtime: 7002 ms (Top 5.13%) | Memory: 106.5 MB (Top 58.97%)
var getOrder = function(tasks) {
    var n = tasks.length;
    tasks = tasks.map((t,i)=>[...t, i]);
    tasks.sort((a,b)=>{
        if(a[0]===b[0])
        {
            return a[2]-b[2];
        }
        return a[0]-b[0];
    }); // sort by queue time
    var q = [];
    var time=tasks[0][0];
    var ans = [];
    var enqIndex = 0;
    while(ans.length < n)
    {
        if(q.length===0 && time < tasks[enqIndex][0])
        {
            time = tasks[enqIndex][0];
        }
        // enqueue
        var curSize = q.length;
        while(enqIndex<tasks.length && tasks[enqIndex][0]<=time)
        {
            q.push(tasks[enqIndex]);
            enqIndex++;
        }
        // sort when needed
        if(curSize < q.length) // hack way to fix TLE to mock PQ
        {
            if(q.length>0)
            {
                q.sort((a,b)=>{
                    if(a[1] === b[1])
                    {
                        return a[2]-b[2];
                    }
                    return a[1]-b[1];
                });
            }
        }
        // execute first task
        var t = q.shift();
        ans.push(t[2]);
        time += t[1];
    }
    return ans;
};