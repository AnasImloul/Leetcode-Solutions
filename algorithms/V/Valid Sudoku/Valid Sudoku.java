    for(int i=0; i<9; i++){
         for(int j=0; j<9; j++){
          if(board[i][j] != '.'){ 
              char currentVal = board[i][j];
               if(!(seen.add(currentVal + "found in row "+ i)) ||
                  !(seen.add(currentVal + "found in column "+ j) ) ||
                  !(seen.add(currentVal + "found in sub box "+ i/3 + "-"+ j/3)))
                   return false;
          }
      
       } 
    
    }
    return true;
}
