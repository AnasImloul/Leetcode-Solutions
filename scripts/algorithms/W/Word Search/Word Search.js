// Runtime: 744 ms (Top 49.74%) | Memory: 49.8 MB (Top 8.66%)
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */

let visited

const getNeighbours=([i,j],board)=>{
    let arr=[];
    if(i>0 && !visited[i-1][j])arr.push([i-1,j])
    if(j>0 && !visited[i][j-1])arr.push([i,j-1])
    if(i+1<board.length && !visited[i+1][j])arr.push([i+1,j])
    if(j+1<board[i].length && !visited[i][j+1])arr.push([i,j+1])
    return arr;
}
const dfs=([i,j],board, word,index)=>{
 if(word[index]!==board[i][j])return false;
 if(word.length-1===index)return true;
    visited[i][j]=true;
    let neighbours=getNeighbours([i,j],board,word,index)||[];

    for(let k=0;k<neighbours.length;k++){
        let temp_result=dfs(neighbours[k],board, word,index+1);
        if(temp_result===true)return true;
    }
    visited[i][j]=false;
    return false;

}

var exist = function(board, word) {
    visited=[];
    for(let i=0;i<board.length;i++){
        visited[i]=[];
        for(let j=0;j<board[i].length;j++){
           visited[i][j]=false;
        }
    }
   for(let i=0;i<board.length;i++){
        for(let j=0;j<board[i].length;j++){
           if(board[i][j]===word[0]){
               let result=dfs([i,j],board,word,0);
               if(result===true)return true;
           }
        }
    }

    return false;
};