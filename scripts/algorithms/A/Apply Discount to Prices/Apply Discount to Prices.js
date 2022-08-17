var discountPrices = function(sentence, discount) {
    let isNum = (num) => {
        if(num.length <= 1 || num[0] != '$') return false;
        for(let i = 1; i < num.length; ++i)
            if(!(num[i] >= '0' && num[i] <= '9'))
                return false;
        return true;
    };
    let x = sentence.split(' ');
    discount = 1 - (discount/100);
    for(let i = 0; i < x.length; ++i) 
        !isNum(x[i]) || (x[i] = `$${(Number(x[i].slice(1))*discount).toFixed(2)}`);
    return x.join(' ');
};
