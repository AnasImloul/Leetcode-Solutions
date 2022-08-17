const toCharCode = (char) => char.charCodeAt()

var cellsInRange = function(s) {
    const result = []
    for(let i = toCharCode(s[0]) ; i <= toCharCode(s[3]) ; i++){
        for(let j = s[1] ; j <= s[4] ; j++){
            result.push(String.fromCharCode(i) +j)
        }
    }
    return result
};
