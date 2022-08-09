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
