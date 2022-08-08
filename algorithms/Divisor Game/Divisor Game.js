var divisorGame = function(n) {
    let count = 0;
    while(true){
        let flag = true;
        for(let i = 1;i<n;i++){
if(n%i==0){
    flag = false;
    n = n-i;
    break;
}
            
        }
        if(flag){
if(count %2==0) return false;
            else return true;
}
        count++;
    }
};
