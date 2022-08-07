var compress = function(chars) {
    for(let i = 0; i < chars.length; i++){
        let count = 1
        while(chars[i] === chars[i+count]){
            delete chars[i+count]
            count++
        }
        if(count > 1){
            let count2 = 1
            String(count).split('').forEach((a) =>{
                chars[i+count2] = a
                count2++
            })
        }
        i = i + count -1
    }
    return chars.flat().filter((x) => x).length
};