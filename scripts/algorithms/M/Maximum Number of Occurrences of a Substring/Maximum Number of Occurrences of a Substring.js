// Runtime: 356 ms (Top 22.45%) | Memory: 54.7 MB (Top 30.61%)
var maxFreq = function(s, maxLetters, minSize, maxSize) {

    let output = 0;

    let left = 0, right = 0;

    let map = {};

    let map2 = {};

    let count = 0;

    while(right < s.length){

        if(map[s[right]] === undefined){ // adding letters to map to keep track of occurences (count)
            map[s[right]] = 1;
            count++;

        } else {
            if(map[s[right]] === 0){
                count++;
            }
            map[s[right]]++;
        }

        if(right - left + 1 > minSize) { // once over minSize removing occurence of left most letter from map and adjusting count

            map[s[left]]--;
            if(map[s[left]] < 1){
                count--;
            }
            left++;
        }

        if(right - left + 1 >= minSize && count <= maxLetters){
            map2[s.substring(left, right + 1)] = (map2[s.substring(left, right + 1)] || 0) + 1; // if subsitrng meets constraints of size and count add to map2;
        }

        right++;
    }

    Object.entries(map2).map(([key, val]) => output = Math.max(output, val)); // get largest value in map2

    return output;

};