// Runtime: 615 ms (Top 6.03%) | Memory: 86.7 MB (Top 24.65%)
var partition = function(s) {
    let result = []
    backtrack(0, [], s, result)
    return result
};

function backtrack(i, partition, s, result){
    if(i === s.length){
        result.push([...partition])
        return
    }

    for(let j=i;j<s.length;j++){
        let str = s.slice(i,j+1)
        if(isPal(str)){
            partition.push(str)
            backtrack(j+1, partition, s, result)
            partition.pop()
        }
    }
}

function isPal(str){
    return JSON.stringify(str.split('').reverse()) === JSON.stringify(str.split(''))
}