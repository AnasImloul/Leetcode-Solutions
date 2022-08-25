// Runtime: 195 ms (Top 7.95%) | Memory: 48.1 MB (Top 21.02%)
var rankTeams = function(votes) {
     if(votes.length == 1)
        return votes[0];
    let map = new Map()
    for(let vote of votes){
        for(let i = 0; i < vote.length;i++){
            if(!(map.has(vote[i]))){
            //create all the values set as zero
                map.set(vote[i],Array(vote.length).fill(0))
            }
            let val = map.get(vote[i])
            val[i] = val[i] + 1
            map.set(vote[i], val)
        }
    }

    let obj = [...map.entries()]; //converting as array ["A",[5,0,0]]
    obj = obj.sort((a,b) => {
        for(let i = 0; i < a[1].length;i++){
            if(a[1][i] > b[1][i])
                return -1;
            else if(a[1][i] < b[1][i])
                return 1;
        }
        // if all chars are in same positon return the value charcode
        return a[0].charCodeAt(0) - b[0].charCodeAt(0);
    })
    return obj.map(item => item[0]).join('')
};