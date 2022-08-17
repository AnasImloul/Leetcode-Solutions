var closeStrings = function(word1, word2) {
    if (word1.length != word2.length) return false;
    let map1 = new Map(), map2 = new Map(),freq1=new Set(),freq2=new Set();
    for (let i = 0; i < word1.length; i++) map1.set(word1[i],map1.get(word1[i])+1||1),map2.set(word2[i],map2.get(word2[i])+1||1);
    if (map1.size != map2.size) return false;
    for (const [key,value] of map1) {
      if (!map2.has(key)) return false
      freq1.add(value);
      freq2.add(map2.get(key));
    }
    if (freq1.size != freq2.size) return false;
    for (const freq of freq1) if (!freq2.has(freq)) return false
    return true;    
};
