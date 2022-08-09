/**
 * @param {string} s
 * @param {number} k
 * @param {character} fill
 * @return {string[]}
 */
var divideString = function(s, k, fill) 
{
  var ans=[];
  for(let i=0;i<s.length;i+=k)
    {
      ans.push(s.substring(i,i+k));
    }
  let str=ans[ans.length-1];
  if(str.length==k)
    {
      return ans;
    }
  for(let i=str.length;i<k;i++)
    {
      ans[ans.length-1]+=fill;
    }
  return ans;
};
