var detectCapitalUse = function(word) {
      if((word.charAt(0)==word.charAt(0).toUpperCase() && word.slice(1)==word.slice(1).toLowerCase()) || (word == word.toUpperCase() 
   || word == word.toLowerCase()))
   {
      return true
   }
    else{
      return false
  }
};
