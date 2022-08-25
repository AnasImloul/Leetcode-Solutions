// Runtime: 94 ms (Top 73.77%) | Memory: 52 MB (Top 24.59%)
var unhappyFriends = function(n, preferences, pairs) {
    let assigned = {}
    let count = 0

    for(let pair of pairs){
        let [x, y] = pair
        assigned[x] = y
        assigned[y] = x
    }

    for(let x=0; x<n; x++){
        let xLimit = preferences[x].indexOf(assigned[x.toString()])
        let xPrefs = preferences[x].slice(0, xLimit)

        for(let u of xPrefs){
            let uLimit = preferences[u].indexOf(assigned[u.toString()])
            let uPrefs = preferences[u].slice(0, uLimit)

            if(uPrefs.includes(x)){
                count += 1
                break
            }
        }
    }

    return count
};