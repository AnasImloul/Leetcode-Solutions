var removePalindromeSub = function(s) {
    const isPalindrome = s == s.split('').reverse().join('');
    return isPalindrome ? 1 : 2;
};
