// Runtime: 1234 ms (Top 5.88%) | Memory: 62.9 MB (Top 5.88%)
var countSubstrings = function(s, t) {
    const count1 = countAllSubstr(s);
    const count2 = countAllSubstr(t);

    let res = 0;

    for (const [substr1, freq1] of count1) {
       for (const [substr2, freq2] of count2) {

           if (differByOneChar(substr1, substr2)) {
               res += freq1 * freq2;
           }
       }
    }

    return res;

    function countAllSubstr(str) {
        const n = str.length;
        const count = new Map();

        for (let i = 0; i < n; i++) {
            let substr = "";
            for (let j = i; j < n; j++) {
                substr += str.charAt(j);

                if (!count.has(substr)) count.set(substr, 0);
                count.set(substr, count.get(substr) + 1);
            }
        }

        return count;
    }

    function differByOneChar(str1, str2) {
        if (str1.length != str2.length) return false;

        const n = str1.length;

        let missed = 0;

        for (let i = 0; i < n; i++) {
            const char1 = str1.charAt(i);
            const char2 = str2.charAt(i);

            if (char1 != char2) missed++;

            if (missed > 1) return false;
        }

        return missed === 1;
    }

};