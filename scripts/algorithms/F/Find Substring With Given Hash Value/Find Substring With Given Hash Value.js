let arrChar ="1abcdefghijklmnopqrstuvwxyz".split("");
var subStrHash = function(s, power, modulo, k, hashValue) {
  
    for(let i=0;i<s.length;i++){
        let subStr = s.substring(i,i+k);
        if(hash(subStr,power,modulo)==hashValue){
            return subStr;
        }
    }
};
let hash = function(str,power,m){
    let result=0;
    for(let i=0;i<str.length;i++){
        result += arrChar.indexOf(str[i])*Math.pow(power,i);
    }
    return result%m;
}
