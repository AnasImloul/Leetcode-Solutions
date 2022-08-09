 * @param {string[][]} paths
 * @return {string}
 */
var destCity = function(paths) {
    
    
    let map={}
    
    for(let city of paths){
        map[city[0]]=map[city[0]]?map[city[0]]+1:1
    }
    for(let city of paths){
        if(!map[city[1]]) return city[1]
    }
};```