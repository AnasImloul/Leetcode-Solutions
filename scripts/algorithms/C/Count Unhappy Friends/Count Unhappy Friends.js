// Runtime: 60 ms (Top 83.3%) | Memory: 46.06 MB (Top 50.0%)

var unhappyFriends = function(n, preferences, pairs) {
    let happyMap = new Array(n);
    for (let [i, j] of pairs) {
        happyMap[i] = preferences[i].indexOf(j);
        happyMap[j] = preferences[j].indexOf(i);
    }
    
    let unhappy = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < happyMap[i]; j++) {
            let partner = preferences[i][j];
            if (preferences[partner].indexOf(i) < happyMap[partner]) {
                unhappy++;
                break;
            }
        }
    }
    
    return unhappy;
};