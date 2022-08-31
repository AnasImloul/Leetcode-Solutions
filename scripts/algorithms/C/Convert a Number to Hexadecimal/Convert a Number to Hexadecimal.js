// Runtime: 97 ms (Top 34.09%) | Memory: 42.1 MB (Top 50.91%)
 var toHex = function(num) {
    let hexSymbols = ["0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"];
    if (num >= 0) {
        let hex = "";
        do {
            let reminder = num % 16;
            num = Math.floor(num/16);
            hex = hexSymbols[reminder] + hex;
        } while (num > 0)
        return hex;
    } else {
        num = -num;
        let invertedHex = ""; //FFFFFFFF - hex
        let needToCarry1 = true; //adding + 1 initially and carrying it on if needed
        while (num > 0) {
            let reminder = num % 16;
            let invertedReminder = 15 - reminder; //inverting
            if (needToCarry1) { //adding 1 for 2's complement
                invertedReminder += 1;
                if (invertedReminder === 16) { //overflow, carrying 1 to the left
                    invertedReminder = 0;
                    needToCarry1 = true;
                } else {
                    needToCarry1 = false;
                }
            }
            num = Math.floor(num/16);
            invertedHex = hexSymbols[invertedReminder] + invertedHex;
        }
        //formatting as "FFFFFFFF"
        while (invertedHex.length < 8) {
            invertedHex = "f" + invertedHex;
        }
        return invertedHex;
    }
};