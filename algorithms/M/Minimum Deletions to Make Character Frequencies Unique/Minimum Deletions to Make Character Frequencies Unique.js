var minDeletions = function(s) {
    let arr = Array(26).fill(0)
    let res = 0
    
    for(let i=0;i<s.length; i++){
        let index = s[i].charCodeAt(0) - 'a'.charCodeAt(0)
        arr[index]++
    }
    
    arr.sort((a,b)=>b-a)
    
    for(let i=1; i<26; i++){
        while(arr[i] && arr[i] >= arr[i-1]){
            arr[i]--
            res++
        }
    }
    
    return res
};
