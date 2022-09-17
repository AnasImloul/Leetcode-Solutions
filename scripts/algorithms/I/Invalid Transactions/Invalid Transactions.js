// Runtime: 2285 ms (Top 7.06%) | Memory: 48.4 MB (Top 63.13%)

var invalidTransactions = function(transactions) {
    const invalid = new Uint8Array(transactions.length).fill(false);

    for(let i = 0; i < transactions.length; i++){
        const [name, time, amount, city] = transactions[i].split(',');

        if(+amount > 1000) invalid[i] = true;

        for(let j = i + 1; j < transactions.length; j++){
            const [name1, time1, amount1, city1] = transactions[j].split(',');

            if(Math.abs(+time - +time1) <= 60 && name === name1 && city !== city1){
                invalid[i] = true;
                invalid[j] = true;
            }
        }
    }

    return invalid.reduce((acc, val, index) => {
        if(val) acc.push(transactions[index])
        return acc;
    }, [])
};
