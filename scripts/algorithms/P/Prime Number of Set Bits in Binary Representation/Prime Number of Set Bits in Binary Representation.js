var countPrimeSetBits = function (left, right) {
    let count = 0;

    for (let i = left; i <= right; i++) {
        let sum = 0;
        let bytes = i.toString(2);

        for (let i = 0; i < bytes.length; i++) {
            const element = bytes[i];
            element === "1" ? sum += 1 : 0
        }
        
        checkPrime(sum) ? count++ : 0;
    }

    return count;

}


const checkPrime = (number) => {
    isPrime = true;
    if (number < 1) {
        isPrime = false;
    } else if (number === 1) {
        isPrime = false;
    } else {
        for (let i = 2; i < number; i++) {
            if (number % i == 0) {
                isPrime = false;
            }
            
        }
    }
    return isPrime;
}