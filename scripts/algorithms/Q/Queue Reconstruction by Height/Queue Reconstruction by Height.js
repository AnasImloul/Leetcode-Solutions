// Runtime: 205 ms (Top 17.71%) | Memory: 48 MB (Top 33.33%)
var reconstructQueue = function(people) {
    var queue = new Array(people.length);
    people = people.sort((a,b) => (a[0]-b[0]));
    for(let i =0;i<people.length;i++){
        let count = 0;
        for(let j= 0;j<queue.length;j++){
            if(!queue[j]){
                if(count == people[i][1]){
                    queue[j] = people[i];
                    break;
                }
                count++;
            }
            else if( queue[j][0] >= people[i][0]){
                count++;
            }
        }
    }
    return queue;
};