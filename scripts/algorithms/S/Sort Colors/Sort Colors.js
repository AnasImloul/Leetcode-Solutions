// Runtime: 47 ms (Top 86.98%) | Memory: 41.70 MB (Top 76.34%)

var sortColors = function(arr) {
    
    let one=0, zero=0, two=0
    

    // step1 
    for(let elem of arr){
        if(elem == 0) zero++
        else if ( elem == 1) one ++
        else two ++
    }




    // step2
    arr.length=0




    // step3
    for(let i=0;i<zero;i++) arr.push(0)
    for(let i=0;i<one;i++) arr.push(1)
    for(let i=0;i<two;i++) arr.push(2)    
    

};
