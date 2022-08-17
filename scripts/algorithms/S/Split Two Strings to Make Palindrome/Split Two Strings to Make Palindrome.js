var checkPalindromeFormation = function(a, b) {
    function isPal(str, l, r) {
        while (l < r) {
            if (str[l] === str[r]) l++, r--;
            else return false;
        } return true;
    }
    
    // aprefix + bsuffix
    let l = 0, r = b.length - 1;
    while (l < r && a[l] === b[r]) l++, r--;
    if (isPal(a, l, r) || isPal(b, l, r)) return true;
    
    // bprefix + asuffix
    l = 0, r = a.length - 1;
    while (l < r && b[l] === a[r]) l++, r--;
    if (isPal(a, l, r) || isPal(b, l, r)) return true;
    
    return false;
};
