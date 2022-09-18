// Runtime: 100 ms (Top 61.63%) | Memory: 45.3 MB (Top 21.96%)
/**
 * @param {number} n
 * @param {number} k
 * @return {number[]}
 */
var numsSameConsecDiff = function(n, k) {

  let res = [];

  const bfs=(num,i)=>{
    let queue = [];
    queue.push(i);
    while(queue.length){
        // console.log("queue is ",queue)
        i = queue.shift();
        if (i <= num)
        {
            if(i.toString().length===n){
               res.push(i);
            }
            let last_digit = i % 10;

            if (last_digit+k<10)
            {
                queue.push((i * 10) + (last_digit + k));
            }
            if(k>0 && last_digit-k >= 0)
             {
                queue.push((i * 10) + (last_digit-k));
             }

        }
    }
  }

  let num = Math.pow(10,n)-1;
  for(let i=1;i<=9 && i<num ;i++){
    bfs(num,i);
  }
  return res;

};