/**
 * @param {string[]} queries
 * @param {string[]} words
 * @return {number[]}
 */
var numSmallerByFrequency = function(queries, words) {
    let res=[]
    queries=queries.map(q=>countFrequency(q))//[3,2]
    words=words.map(w=>countFrequency(w))//[1,2,3,4]
  words = words.sort((a, b) => a - b)
    for(let i=0;i<queries.length;i++){
      let start=0,end=words.length-1
      while(start<=end){
          let mid=start+Math.floor((end-start)/2)
          if(queries[i]<words[mid]){
              end=mid-1
          }else{
              start=mid+1
          }
      }
      res.push(words.length-1-end)
  }
    return res
};

function countFrequency(str){
    let freq={}
    str.split('').forEach(key=>{
        freq[key]=(freq[key]||0)+1
    })
    return freq[Object.keys(freq).sort()[0]]
}
