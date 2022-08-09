/**
 * @param {number[][]} mat
 * @return {number[][]}
 */
var diagonalSort = function(mat) {
const res=new Array(mat.length);
    
for(let i=0;i<mat.length;i++)
    res[i]=new Array(mat[i].length);

    
for(let i=0;i<mat.length;i++){
    for(let j=0;j<mat[i].length;j++){
        if(i===0 || j===0){
            const scale= i-j;
            let val=[],index=[];
            
            for(let i=0;i<mat.length;i++){
                for(let j=0;j<mat[i].length;j++){
                    if(scale===i-j){
                        val.push(mat[i][j]);    
                        index.push([i,j]);            
                    }
                }
            }
            val=val.sort((a,b)=>a-b);
            index.forEach(([x,y],id)=>res[x][y]=val[id]);
        }
    }
}
    return res;

};
