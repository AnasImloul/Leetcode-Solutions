// Runtime: 238 ms (Top 80.0%) | Memory: 58.10 MB (Top 20.0%)

/**
* @param {number[]} balls
* @return {number}
*/
var getProbability = function(balls) 
{
       var k = balls.length;
       var halfUsed = balls.reduce((acc,val)=>acc+val,0)/2;
       var startArray = new Array(k);
       startArray.fill(0);
       
       const perm = function(b1,b2)
       {
               var p1, p2, s1, s2;
               
               s1 =  b1.reduce((acc,val)=>acc+val,0);
               s2 =  b2.reduce((acc,val)=>acc+val,0);
               
               const fact = function(n)
               {
                       var f=1;
                       for(let i=2; i<=n; i++)
                               f *= i;
                       return  f;
               };
               
               p1 = fact(s1);
               p2 = fact(s2);
               
               b1.forEach(val=>{if(val>1)p1/=fact(val);});
               b2.forEach(val=>{if(val>1)p2/=fact(val);});

               return p1*p2;
       };
       
       const getValidCombos = function(ballsUsed,colorNum=0)
       {
               var box1Used = ballsUsed.reduce((acc,val)=>acc+val,0);
               var matches = {good:0,total:0}, thisColorMax = halfUsed - box1Used;

               if(colorNum === k-1)
               {
                       /* 
                               Last ball color - adjust # of balls of this color to equal half
                               (if possible).  Then count # of different balls in each box.
                       */
                       if(thisColorMax > balls[colorNum])
                               return {good:0,total:0};

                       ballsUsed[colorNum] = thisColorMax;
                       let ballsLeft = [];
                       let colorsUsed = [0,0];
                       for(let i=0; i<k; i++)
                       {
                               ballsLeft[i] = balls[i] - ballsUsed[i];
                               if(ballsUsed[i] > 0)
                                       colorsUsed[0]++;
                               if(ballsLeft[i] > 0)
                                       colorsUsed[1]++;
                       }
                       
                       /* Count the # of permutations for the boxes represented by this 1 combination. */
                       let permutations = perm(ballsUsed,ballsLeft,k);
                       return {good:(colorsUsed[1] === colorsUsed[0]) ? permutations : 0, total:permutations};
               }

               thisColorMax = Math.min(thisColorMax,balls[colorNum]);
               for(let i=0; i<=thisColorMax; i++)
               {
                       let match = getValidCombos([...ballsUsed], colorNum+1);
                       matches = {good:matches.good+match.good, total:matches.total+match.total};
                       ballsUsed[colorNum]++;
               }
               return matches;
       }
   
       /* Probability = (total # of permutations with equal # of balls) / (permutations with same # of unique balls) */
       let res = getValidCombos(startArray);
       return res.good/res.total;
};
