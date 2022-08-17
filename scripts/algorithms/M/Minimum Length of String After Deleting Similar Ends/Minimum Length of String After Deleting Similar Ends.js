var minimumLength = function(s) {
    const n = s.length;
    
    let left = 0;
    let right = n - 1;
    
    while (left < right) {
        if (s.charAt(left) != s.charAt(right)) break;
        
        left++;
        right--;
        
        while (left <= right && s.charAt(left - 1) == s.charAt(left)) left++;
        while (left <= right && s.charAt(right) == s.charAt(right + 1)) right--;
    }
    
    return right - left + 1;
};
