var beautifulArray = function(n) {
    const EVEN = 1;
    const ODD = 2;
    let helper = (arr, flag) => {
        if (arr.length <= 2)
            return arr;
        let even, odd;
        if (flag == ODD)
            arr = arr.map(el=>(el+1)/2);
        else if (flag == EVEN)
            arr = arr.map(el=>el/2);
        even = helper(arr.filter(el=>el%2 === 0), EVEN);
        odd = helper(arr.filter(el=>el%2 !== 0), ODD);
        arr = even.concat(odd);
        if (flag == ODD)
            arr = arr.map(el=>el*2-1);
        else if (flag == EVEN)
            arr = arr.map(el=>el*2);
        return arr;
    };
    let arr = new Array(n);
    for (let i = 0; i<n; i++)
        arr[i] = i+1;
    return helper(arr);
};
