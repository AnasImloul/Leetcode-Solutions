var reverseOnlyLetters = function(s) {
    let valid = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
    let arr = s.split('')
    
    let r = arr.length - 1;
    let l = 0;
    
    while (l < r) {
        while (!valid.includes(arr[l]) && l < r) {
            l++;
            continue;
        }
    
        while (!valid.includes(arr[r]) && l < r) {
            r--;
            continue
        }
        
        if (l >= r) break;
        
        [arr[l], arr[r]] = [arr[r], arr[l]];
        l++;
        r--;
    }
    
    
    return arr.join('')
	```