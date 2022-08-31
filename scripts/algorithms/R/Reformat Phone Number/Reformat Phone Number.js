// Runtime: 86 ms (Top 60.00%) | Memory: 42.6 MB (Top 25.38%)
var reformatNumber = function(number) {
    let numArr = number.replace(/-/g,'').replace(/ /g,'').split('')
    let res = ''
    while(numArr.length >= 4){
        numArr.length == 4 ?
            res += numArr.splice(0,2).join('') +'-'+numArr.splice(0,2).join('') :
            res += numArr.splice(0,3).join('') + '-'
    }
    res += numArr.join('')
    return res
};