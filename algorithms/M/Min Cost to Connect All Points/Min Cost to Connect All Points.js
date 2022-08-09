/**
 * @param {number[][]} points
 * @return {number}
 */
//By Kruskal Approach
let union_find,mapping_arr,count,maxCost,rank
const find=(root)=>{
    if(union_find[root]===root)return root;
    return union_find[root]= find(union_find[root]);
}
const union=([src,dst,d])=>{
    let rootX=find(src);
    let rootY=find(dst);
    if(rootX!=rootY){
        if(rank[rootX]<rank[rootY]){
            union_find[rootX]=rootY;
        }else if(rank[rootX]>rank[rootY]){
            union_find[rootY]=rootX;
        }else{
            union_find[rootY]=rootX;
            rank[rootX]++;
        }
        count--;
        maxCost+=d;
    }
    
    
}
var minCostConnectPoints = function(points) {
    let edges=[];
    union_find=[];
    rank=[];
    maxCost=0;
    count=points.length;
    for(let i=0;i<points.length;i++){
        union_find[i]=i;
        rank[i]=1
        let src=points[i];
        for(let j=i+1;j<points.length;j++){
            let dst=points[j];
            let d= Math.abs(src[0]-dst[0])+Math.abs(src[1]-dst[1])
            edges.push([i,j,d]);
        }
    }
    edges.sort((a,b)=>a[2]-b[2])
    for(let i=0;i<edges.length;i++){
        if(count>1)
        union(edges[i]);
    }

    return maxCost;
    
};
