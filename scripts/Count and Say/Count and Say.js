var countAndSay = function(n) {
    if(n==1) return '1';
    let index = 1, num = '1';
    while(index < n){
        num = say(num);
        index++;
    }
    return num;
};

function say(num) {
    let prev = num[num.length-1], count = 0, newNum = '';
    for(let index = num.length-1; index >= 0 ; index--) {
        if(prev == num[index]) {
            count++;
        }
        else{
            newNum = ''+count + prev + newNum;
            count = 1;
            prev = num[index];
        }
    }
    if(count) {
        newNum = ''+count + prev + newNum;
    }
    return newNum;
}
