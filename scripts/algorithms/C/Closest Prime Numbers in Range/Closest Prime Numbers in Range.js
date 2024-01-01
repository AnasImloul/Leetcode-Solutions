// Runtime: 125 ms (Top 46.43%) | Memory: 52.50 MB (Top 30.36%)

/**
 * @param {number} left
 * @param {number} right
 * @return {number[]}
 */
buff = []           // global buff to store prime numbers

var closestPrimes = function(left, right) {    
    prime = []          // store result
    last_val = 0        // temp variable

    if (buff.length < 1) buff = Prime_Numbers(10 ** 6)   // calculate prime numbers and set it to buff     
    
    for (let i = 0; i < buff.length ; i++) {            // go trougth buff (from 2 to 10 ^ 6)
        if (buff[i] > right) break                      // if buff[i] more then right break loop
        
        if (buff[i] >= left) {                          // if buff[i] more then left go on
            if (prime.length >= 2) {                    // check if prime array has already 2 elements
                if (buff[i] - last_val < prime[1] - prime[0]) {     // check prime nums difference
                    prime[0] = last_val                             // rewrite prime[0] with new value
                    prime[1] = buff[i]                              // rewrite prime[1] with new value
                }
            } else {            
                prime.push(buff[i])                     // fill prime if prime has not at least 2 values
            }            
            last_val = buff[i]                          // store last value for buff[i]
        }      
    }  

    function Prime_Numbers(n) {                         // search prime numbers and return in array
        output = []        
        isPrime = new Array(n).fill(true)        
        isPrime[1] = false
        
        for (let i = 2; i * i < n; i++) {
            if (!isPrime[i]) continue
            for (let j = i * i; j < n; j += i) isPrime[j] = false
        }
        
        for (let i = 1; i < n; i++) 
            if (isPrime[i]) output.push(i)
        
        return output
    } 

    if (prime.length < 2) prime = [-1, -1]              // if prime has not at least 2 values -> [-1, -1]

    return prime                // return result array
};




