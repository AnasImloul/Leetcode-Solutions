var defangIPaddr = function(address) {
   return address.split("").map((x)=>{
        if(x=='.')
            return "[.]"
        else return x
    }).join("")
};
