const checkLen = (password) => password.length >= 8;

const checkSmallLetter = (password) => {
    for(let i=0;i<password.length;i++){
        const ind = password.charCodeAt(i);
        if(ind > 96 && ind < 123){
            return true;
        }
    }
    return false;
}

const checkCapitalLetter = (password) => {
    for(let i=0;i<password.length;i++){
        const ind = password.charCodeAt(i);
        if(ind > 64 && ind < 91){
            return true;
        }
    }
    return false;
}

const checkDigit = (password) => {
    for(let i=0;i<password.length;i++){
        const ind = password.charCodeAt(i);
        if(ind > 47 && ind < 58){
            return true;
        }
    }
    return false;
}

const checkSpecialChar = (password) => {
    const str = "!@#$%^&*()-+";
     for(let i=0;i<str.length;i++){
       if(password.includes(str[i])) return true;
    }
    return false;
}

const checkAdjacentMatches = (password) => {
    for(let i=1;i<password.length;i++){
        if(password[i] === password[i-1]) return false;
    }
    return true;
}


var strongPasswordCheckerII = function(password) {
    const lenValidity = checkLen(password);
    const smallLetterValidity = checkSmallLetter(password);    
    const capitalLetterValidity = checkCapitalLetter(password);
    const digitValidity = checkDigit(password);
    const specialCharValidity = checkSpecialChar(password);
    const adjacentMatchesValidity = checkAdjacentMatches(password);
        
    const passwordIsStrong = lenValidity && smallLetterValidity && capitalLetterValidity && digitValidity && specialCharValidity && adjacentMatchesValidity;
  
    return passwordIsStrong;
};
