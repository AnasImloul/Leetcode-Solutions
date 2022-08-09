var validTicTacToe = function(board) {
    let playerX = 0 , playerO = 0;
    let horizontal = [0,0,0];
    let vertical = [0,0,0];
    let diagnol = [0, 0];
    
    const transformConfig=(row,col,val)=>{
        horizontal[row] +=val; 
        vertical[col]+=val;
        if(row ===col ){
           diagnol[0]+=val; 
            if(row+col == board.length-1){
             diagnol[1]+=val; 
            }
        }else if(row+col == board.length-1){
             diagnol[1]+=val; 
        }
    }
    
    board.forEach((data,row)=>{
        data.split("").forEach((turn,col)=>{
            if(turn == 'X'){
                playerX++
                transformConfig(row,col,1)
            }else if(turn == 'O'){
                playerO++;
                transformConfig(row,col,-1);
            }
        });
    });
    if(playerX<playerO ||playerX-playerO>1 ) return false;
    if(horizontal.includes(3)&&playerX<= playerO)return false;
    if(vertical.includes(3)&&playerX <= playerO)return false;
    if(diagnol.includes(3)&&playerX <=playerO)return false;
    if(horizontal.includes(-3)&&playerX> playerO)return false;
    if(vertical.includes(-3)&&playerX> playerO)return false;
    if(diagnol.includes(-3)&&playerX>playerO)return false;
    
    return true;
};
