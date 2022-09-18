// Runtime: 122 ms (Top 14.09%) | Memory: 44.5 MB (Top 14.09%)
/**
 * @param {string} s
 * @return {boolean}
 */
var checkValidString = function(s) {
    let map = {}
    return check(s,0,0,map);
};

function check(s,index,open,map){
    if(index == s.length){
        return open == 0;
    }

    if(open < 0){
        return false;
    }
    let string = index.toString() + "##" + open.toString();
    if(string in map){
        return map[string]
    }

    if(s[index] == '('){
        let l = check(s,index+1,open+1,map)
        map[string] = l
        return l
    }else if (s[index] == ')'){
        let r = check(s,index+1,open-1,map)
        map[string] = r;
        return r
    }else {
        let lr = check(s,index+1,open+1,map) || check(s,index+1,open-1,map)
              || check(s,index+1,open,map)
        map[string] = lr;
        return lr
    }
}