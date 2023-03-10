/**
 * @param {string[]} words
 * @return {number}
 */
var longestStrChain = function(words) 
{
        let tiers = new Array(16);
        for(let i=0; i<tiers.length; i++)
                tiers[i] = [];
        for(let word of words)
                tiers[word.length-1].push({word,len:1});

        const isPredecessor = function(word1,word2)     // Assumes word2.length = word1.length+1
        {
                let w1p = 0, misses = 0;
                for(let w2p = 0; w2p < word2.length; w2p++)
                {
                        if(word2[w2p] !== word1[w1p])
                        {
                                if(misses === 1)
                                        return false;
                                misses = 1;
                        }
                        else
                        {
                                w1p++;
                                if(w1p === word1.length)
                                        return true;
                        }
                }
                return true;
        };
        
        
        for(let i=tiers.length-1; i>0; i--)
        {
                for(let w2=0; w2<tiers[i].length; w2++)
                {
                        for(let w1 = 0; w1 < tiers[i-1].length; w1++)
                        {
                                if(tiers[i-1][w1].len >= tiers[i][w2].len+1)
                                        continue;
                                if(isPredecessor(tiers[i-1][w1].word, tiers[i][w2].word))
                                        tiers[i-1][w1].len = tiers[i][w2].len+1;
                        }
                }
        }
        
        let max = 0;
        for(let i=0; i<tiers.length; i++)
        {
                for(let j=0; j<tiers[i].length; j++)
                        max = Math.max(max,tiers[i][j].len);
        }
        
        return max;
};