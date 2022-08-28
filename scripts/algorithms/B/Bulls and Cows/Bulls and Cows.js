// Runtime: 149 ms (Top 11.68%) | Memory: 44.9 MB (Top 52.42%)
var getHint = function(secret, guess) {
    let ACount = 0, BCount = 0;
    const secretMap = new Map(), guessMap = new Map();
    for(let i = 0; i < secret.length; i++) {
        if(secret[i] == guess[i]) {
            ACount++;
        }
        else {
            if(secretMap.has(secret[i])) {
                secretMap.set(secret[i], secretMap.get(secret[i])+1);
            }
            else {
                secretMap.set(secret[i], 1);
            }
        }
    }
    for(let i = 0; i < guess.length; i++) {
        if(secret[i] !== guess[i]) {
            if(secretMap.get(guess[i]) > 0) {
                secretMap.set(guess[i], secretMap.get(guess[i])-1);
                BCount++;
            }
        }
    }
    return ACount+'A'+BCount+'B';
};