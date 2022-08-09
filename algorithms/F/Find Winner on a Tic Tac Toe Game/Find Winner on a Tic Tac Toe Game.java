/**
Here is my solution : 

Time Complexity O(M) 
Space Complaexity O(1)
*/

class Solution {
    public String tictactoe(int[][] moves) {
        
        int [][] rcd = new int[3][3]; // rcd[0] --> rows , rcd[1] --> columns , rcd[2] --> diagonals
          
        for(int turn =0 ; turn < moves.length ; turn++){
            
			int AorB =-1;
            if(turn%2==0){AorB=1;}
            
            rcd[0][moves[turn][0]]+= AorB; 
            rcd[1][moves[turn][1]]+= AorB; 
            
            if(moves[turn][0]== moves[turn][1]){rcd[2][0]+=AorB;}     // first diagonal
            if(moves[turn][0]+moves[turn][1]-2 == 0){rcd[2][1]+=AorB;} //2nd diagonal                
            
            if( Math.abs(rcd[0][moves[turn][0]]) == 3 || Math.abs(rcd[1][moves[turn][1]]) == 3 
               ||Math.abs(rcd[2][0]) ==3 || Math.abs(rcd[2][1]) ==3  ){
             
			 return AorB == 1 ? "A" : "B"; }
                                                         } 
        
        return moves.length == 9 ? "Draw" : "Pending";
        
    }
}

