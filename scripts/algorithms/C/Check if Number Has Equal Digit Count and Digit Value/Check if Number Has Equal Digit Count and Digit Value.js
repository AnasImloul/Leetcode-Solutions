var digitCount = function(num) {    
    const res = [...num].filter((element, index) => {
        const reg = new RegExp(index, "g");
        const count = (num.match(reg) || []).length;
        
        return Number(element) === count
    })
    
    return res.length === num.length    
};
