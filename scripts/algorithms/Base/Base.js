/**
 * @param {number} num
 * @return {string}
 */
var convertToBase7 = function(num) {
    
      let str = "", sign
      if(num<0){
          sign =-1;
          num*=-1;
      }
    
      while(num>= 7){
          str+= num%7;
          num = Math.floor(num/7);
      }
      str+=num;
      if(sign<0) str+='-'  
    
    return str.split("").reverse().join("")
};
