/**
 * @param {string} s
 * @return {boolean}
 */
var validPalindrome = function(s) {
    let left = 0, right = s.length - 1, res = true;
    while(left < right)
    {
        if(s[left] !== s[right])
        {
            res = isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            break;
        }
        
        left++;
        right--;
    }
    return res;
};

function isPalindrome(str, start, end) {
    let res = true;
    while(start < end)
    {
        if(str[start] === str[end])
        {
            start++;
            end--;
        }
        else
        {
            res = false;
            break;
        }
    }
    return res;
}
