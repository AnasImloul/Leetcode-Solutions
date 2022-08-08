var reformat = function(s) {
    let letter=[], digit=[];
    for(let i=0; i<s.length; i++){
        s[i]>=0 && s[i]<=9? digit.push(s[i]): letter.push(s[i]);
    }
	// impossible to reformat
    if(Math.abs(letter.length-digit.length)>=2){return ""}
    
    let i=0, output="";
    while(i<letter.length && i<digit.length){
        output=output+letter[i]+digit[i]; i++;
    }
    if(i<letter.length){output=output+letter[i]}; // add in the END
    if(i<digit.length){output=digit[i]+output}; // add in the FRONT
    return output;
};
