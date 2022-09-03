// Runtime: 196 ms (Top 22.22%) | Memory: 46.2 MB (Top 66.67%)
var findTheLongestSubstring = function(s) {
    // u o i e a
    // 0 0 0 0 0 => initial state, all are even letters
    // s = "abcab"
    // 0 0 0 0 1 => at index 0, only a is odd count
    // 0 0 0 0 1 => at index 1, max = 1
    // 0 0 0 0 1 => at index 2, max = 2
    // 0 0 0 0 0 => at index 3, max = 4
    // 0 0 0 0 0 => at index 4, max = 5

    // valid condition: same state in previous index, then it means we have a even count for all letters within the middle substring.
    var mask = 0;
    var t = "aeiou";
    var count = new Map(); // <mask, first_idx>
    count.set(0,-1);
    var res = 0;
    for(var i = 0; i<s.length; i++)
    {
        if(t.indexOf(s[i])>=0)
        {
            var j = t.indexOf(s[i]);
            mask = mask ^ (1 << j);
        }
        if(!count.has(mask))
        {
            count.set(mask,i);
        }
        else
        {
            // substring is from [prevIdx+1, i];
            res = Math.max(res, i - count.get(mask));
        }
    }
    return res;
};