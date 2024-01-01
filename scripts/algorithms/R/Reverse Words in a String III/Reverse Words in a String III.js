// Runtime: 76 ms (Top 15.58%) | Memory: 49.70 MB (Top 6.97%)

var reverseWords = function(s){
        let chars = [...s];
        let start = 0;

        for (let i = 0; i < chars.length; i++) {
            if (chars[i] === ' ' || i === chars.length - 1) {
                let end = (i === chars.length - 1 && chars[i] !== ' ') ? i + 1 : i;
                while (start < end) {
                    [chars[start], chars[end - 1]] = [chars[end - 1], chars[start]];
                    start++;
                    end--;
                }
                start = i + 1;
            }
        }

        return chars.join('');
    }
