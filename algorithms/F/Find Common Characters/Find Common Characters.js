var commonChars = function(words) {
//record the first word characters  in an array called minFreq
//iterater over the rest of the input array
    //record the characters for each word called freq
    //update the corresponding minFreq element to the smaller one between each word and the first word
//after collect all the words' freq and update the minFreq, iterate over the minReq
  //push the element to the result 
  let res = [], minFreq = new Array(26).fill(0);
  let firstWord = words[0];
  for(let i = 0; i < firstWord.length; i++){
    let index = firstWord.charCodeAt(i) - 97;
    minFreq[index]++;
  }
  for(let word of words){
    let freq = new Array(26).fill(0);
    for(let i = 0; i < word.length; i++){
      let index = word.charCodeAt(i) - 97;
      freq[index]++;
    }
    for(let i = 0; i < 26; i++){
      minFreq[i] = Math.min(minFreq[i], freq[i]);
    }
  }
  for(let i = 0; i < 26; i++){
    for(let q = 0; q < minFreq[i]; q++){
      let letter = String.fromCharCode(i + 97);
      res.push(letter);
    }
  }
  return res;
}
