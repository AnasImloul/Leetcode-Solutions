var nearestPalindromic = function(n) {

    //special case return immediately
    if(n.length === 1){
        return String(n-1)
    }
    
    const gen99=(len)=>{
        return "9".repeat(len)
    } 
    const gen101=(len)=>{
        return "1" + "0".repeat(len-1) + "1"
    } 
    
    let case1 = gen99(n.length-1)
    let case2 = gen101(n.length-1)
    let case3 = gen99(n.length)
    let case4 = gen101(n.length)
    
    let tempPalindrome = ''
    let tempPalindromeRev = ''
    let startCode = 0
    let endCode = n.length - 1
    while(endCode-startCode > 1){
        tempPalindrome = tempPalindrome + n[startCode]
        tempPalindromeRev = n[startCode] + tempPalindromeRev
        startCode += 1
        endCode -= 1
    }       
    const addCenterStr=(add)=> {
        if(n.length%2 !== 0){
            return tempPalindrome + (Number(n[startCode]) + add)
        } else {
            return tempPalindrome + (Number(n[startCode]) + add) + (Number(n[startCode]) + add)
        }
    }
    let case5 = addCenterStr(0) + tempPalindromeRev
    let case6 = addCenterStr(-1) + tempPalindromeRev
    let case7 = addCenterStr(1) + tempPalindromeRev
    
    //Find smallest difference ans
    const list = [case1,case2,case3,case4,case5,case6,case7]
    let tempDiff = null
    let ans = ''
    for (let i of list){
       if (i != n){
           let diff = Math.abs(n-i)
            if(diff == tempDiff && Number(i) < Number(ans)){
                ans = i
            }
           if(diff < tempDiff || !tempDiff){
                tempDiff = diff
                ans = i
           }
       }
   }
    return String(ans)
}; 
