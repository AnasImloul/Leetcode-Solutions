var addStrings = function(num1, num2) {
    let longer = num1.length >= num2.length ? num1 : num2;
    let shorter = num1.length < num2.length ? num1 : num2;
    let diff = (longer.length - shorter.length)
    for (let i = 0; i < diff; i++) {
      shorter = '0' + shorter;
    }
    
    let str = '';
    let remainder = 0;
    
    for (let i = (longer.length -1); i >= 0; i--) {
        let num = remainder > 0
            ? remainder + parseInt(longer[i]) + parseInt(shorter[i])
            : parseInt(longer[i]) + parseInt(shorter[i]);
        if (num > 9) {
            remainder = 1;
            num = num - 10;
        } else {
            remainder = 0;
        }
        str = num.toFixed() + str;
    }
    return !!remainder ? remainder + str : str;
};
