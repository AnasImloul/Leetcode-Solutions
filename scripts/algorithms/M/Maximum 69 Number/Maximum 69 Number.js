var maximum69Number  = function(num) {
  let flag=true
   num= num.toString().split('').map((x)=>{
        if(x!=='9'&&flag){
            flag=false
            return '9'
        }
        return x
    })
    return parseInt(num.join(''))
};
