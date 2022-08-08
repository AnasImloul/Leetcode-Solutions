var smallestSubsequence = function(s) {
    let stack = [];
  for(let i = 0; i < s.length; i++){
      if(stack.includes(s[i])) continue;
   while(stack[stack.length-1]>s[i] && s.substring(i).includes(stack[stack.length-1])) stack.pop();
      stack.push(s[i]);
  }
  return stack.join("");
};
