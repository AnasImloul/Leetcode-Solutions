var makeGood = function(s) {
    const sArr = []
    for(let i = 0; i < s.length; i++) {
        sArr.push(s[i])
    }
    const popper = function() {
        let counter = 0
                for(let i = 0; i < sArr.length; i++) {
            if(sArr[i] !== sArr[i + 1]) {
                if(sArr[i].toUpperCase() === sArr[i + 1] || sArr[i].toLowerCase() === sArr[i + 1]) {
                    sArr.splice(i,2)
                    counter++
                }
            }
        }
        if(counter > 0) {
            popper()
        }
    }
    popper()
  
    return sArr.join('');
};

convert string to array to allow access to splice method. iterate over array checking for eqality between i and i +1  in the array. if equal, do nothing. if not equal convert to lower/uppercase and again check for equality. if equal splice those two from the array. counter checks if anything has been removed, if it has it iterates over the array again
