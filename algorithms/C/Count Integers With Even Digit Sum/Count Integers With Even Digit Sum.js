var countEven = function(num) {
    let count=0;
    for(let i=2;i<=num;i++){
        if(isEven(i)%2==0){
            count++;
        }
    }
    return count
};

const isEven = (c) =>{
    let sum=0;
    while(c>0){
        sum+=(c%10)
        c=Math.floor(c/10)
    }
    return sum
}
