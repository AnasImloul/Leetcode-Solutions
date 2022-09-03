// Runtime: 152 ms (Top 76.44%) | Memory: 52.1 MB (Top 42.07%)
/**
 * @param {number[][]} times
 * @param {number} n
 * @param {number} k
 * @return {number}
 */

let visited,edges,dijkastra_arr,min_heap
const MAX_VALUE=Math.pow(10,6);

const dijkastra=(source)=>{
    visited[source]=true;
    min_heap.pop();
    let nei=edges[source]||[];
    // if(!nei.length)return;
    for(let i=0;i<nei.length;i++){
        let[src,dst,t]=nei[i];
        if(visited[dst])continue;
        let time_till_src=dijkastra_arr[src];
        if(time_till_src>=MAX_VALUE)continue;
        let time_till_dst=time_till_src+t;
        dijkastra_arr[dst]=Math.min(dijkastra_arr[dst],time_till_dst);
    }
    min_heap.sort((a,b)=>{
        return dijkastra_arr[b]-dijkastra_arr[a];
    });
    if(min_heap.length && dijkastra_arr[min_heap[min_heap.length-1]]<MAX_VALUE)
    dijkastra(min_heap[min_heap.length-1]);

}
var networkDelayTime = function(times, n, k) {
    visited=[];
    edges={};
    dijkastra_arr=[];
    min_heap=[];

    for(let i=0;i<times.length;i++){
        if(!edges[times[i][0]])edges[times[i][0]]=[];
        edges[times[i][0]].push(times[i]);
    }
    // console.log(edges,"edges")
    for(let i=0;i<=n;i++){
        if(i===0){//cz numbes are starting from One
            visited[i]=true;
            dijkastra_arr[i]=-1;
            min_heap[i]=i;
        }else{
                  min_heap[i]=i;
        dijkastra_arr[i]=MAX_VALUE;
        visited[i]=false;
        }

    }

    dijkastra_arr[k]=0;
    min_heap.sort((a,b)=>{
        return dijkastra_arr[b]-dijkastra_arr[a];
    });
    min_heap.pop();//For removing zeroth entry;
    dijkastra(k);
    let max_time=0;
    if(min_heap.length)return -1;
        for(let i=0;i<dijkastra_arr.length;i++){
            max_time=Math.max(dijkastra_arr[i],max_time);
    }
    return max_time;
};