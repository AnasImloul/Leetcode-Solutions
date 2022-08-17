var numUniqueEmails = function(emails) {
    let set = new Set();
    
    for (let email of emails) {
        let curr = email.split('@');
        let currEmail = '';
        
        for (let char of curr[0]) {
            if (char === '.') continue;
            if (char === '+') break;
            currEmail += char;
        }
        
        currEmail += '@' + curr[1];
        set.add(currEmail)
    }
    
    return set.size
};
