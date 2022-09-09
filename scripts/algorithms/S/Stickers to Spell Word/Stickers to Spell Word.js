// Runtime: 210 ms (Top 53.57%) | Memory: 46 MB (Top 85.71%)
/**
 * @param {string[]} stickers
 * @param {string} target
 * @return {number}
 */

// Backtracking
var minStickers = function(stickers, target) {
    //* Inits *//
    let dp = new Map();

    //* Helpers *//
    const getStringDiff = (str1, str2) => {
        for(let c of str2) {
            if(str1.includes(c)) str1 = str1.replace(c, '');
        }
        return str1;
    }
    dp.set('', 0);

    //* Main *//
    function calcStickers(restStr) {
        // if(restStr === "") return 0; <-- without memoization
        if (dp.has(restStr)) return dp.get(restStr);
        let res = Infinity;

        for (let s of stickers.filter(s => s.includes(restStr[0]))) { // if current sticker does not contain the FIRST char, continue
            let str = getStringDiff(restStr, s); //aabbc - bc = aab
            res = Math.min(res, 1 + calcStickers(str)); // RECURSE.... calculate min stickers for the remaining letters.. try combination for all strings and get min
        }

        dp.set(restStr, res === Infinity || res === 0 ? -1 : res); //Memoize the result in dp;
        return dp.get(restStr);
        // return res; <-- without memoization
    }
    return calcStickers(target)
}