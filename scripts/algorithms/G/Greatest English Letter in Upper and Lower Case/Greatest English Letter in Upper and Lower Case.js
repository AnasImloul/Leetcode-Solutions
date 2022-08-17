var greatestLetter = function(s) {
    let set=new Set(s.split(""));
	// ASCII(A-Z, a-z)=(65-90, 97-122).
    for(let i=90; i>=65; i--){
        if(set.has(String.fromCharCode(i)) && set.has(String.fromCharCode(i+32))){
            return String.fromCharCode(i);
        }
    }
    return "";
};
