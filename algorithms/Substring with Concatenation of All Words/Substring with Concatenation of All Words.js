/**
 * @param {string} s
 * @param {string[]} words
 * @return {number[]}
 */
var findSubstring = function(s, words) {
   const lengthWords = words.length;
   const lengthSingleWord = words[0].length;
   const lengthS = s.length;
   let indexI = 0;
   const stringLengthForValidation = lengthWords * lengthSingleWord;
   const aryIndex = [];
   while(indexI + stringLengthForValidation <= lengthS){
      let strSet = s.substr(indexI, stringLengthForValidation);
      let indexJ = 0;
      let isWordMatching = false;
      let aryWordsMatch = [...words];
      while(strSet !== ""){
        const strWord = strSet.substr(indexJ, lengthSingleWord);

        const indexFind = aryWordsMatch.findIndex(val => val === strWord);
        if(indexFind > -1) aryWordsMatch.splice(indexFind,1);
       
        if(aryWordsMatch.length === lengthWords) break; // if word is not present, skip
        strSet =  strSet.substr(indexJ+lengthSingleWord)
      }
      if (aryWordsMatch.length === 0) aryIndex.push(indexI);

      indexI++
   }
   
   return aryIndex;
};
