var lastRemaining = function(n) {
    let sum=1;  let num=1;  let bool=true;
    while(n>1){       
        if(bool){sum+=num; bool=false;}
        else{if(n%2){sum+=num;} bool=true;}
        num*=2; n=Math.floor(n/2);
    }
    return sum;
}; 
