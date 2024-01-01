// Runtime: 76 ms (Top 21.43%) | Memory: 42.40 MB (Top 100.0%)

var maxPalindromes = function(s, k) {
   let ans = 0;
   for(let i = 0; i <= s.length - k; i++){
        if(isPalindrome(s, i, i + k-1)){
            ans++;
            i += k - 1;
            continue;
        }
        if(isPalindrome(s, i, i + k)){
            ans++;
            i += k;
            continue;
        }
   }  
  return ans;  
};

function isPalindrome(s, left, right){
    if(right >= s.length) return false;
    while(left < right){
        if(s[left++] != s[right--]) return false;
    }
  return true;
}
