// Runtime: 100 ms (Top 33.90%) | Memory: 42.4 MB (Top 10.17%)
var numRookCaptures = function(board) {
    const r=board.length;
    const c=board[0].length;

    let res=0
    const dir=[[0,1],[0,-1],[1,0],[-1,0]]; // all the 4 possible directions
    let rook=[];

    // finding the rook's position
    for(let i=0;i<r;i++){
        for(let j=0;j<c;j++){
            if(board[i][j]==='R'){
                rook=[i,j]
                break;
            }
        }
    }

    // traversing all the 4 directions
    for(let [x,y] of dir){
        res+=helper(x,y,rook[0],rook[1])
    }

    return res;

    function helper(x,y,i,j){
        let newX=x+i
        let newY=y+j
        let attack=0
        while(newX<r&&newY<c&&newX>=0&&newY>=0){
            if(board[newX][newY]==='p'){
                attack++
                break; // break because Rook can't attack more than one pawn in same direction
            }else if(board[newX][newY]==='B'){
                break
            }
            // keep moving towards the same direction
            newX+=x
            newY+=y
        }
        return attack
    }
};