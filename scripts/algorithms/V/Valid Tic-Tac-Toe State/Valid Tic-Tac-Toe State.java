// Runtime: 1 ms (Top 71.13%) | Memory: 41.6 MB (Top 42.96%)
class Solution {
    public boolean validTicTacToe(String[] board) {
        //cnt number of X and O
        int x = cntNumber('X', board);
        //this check can be omitted, it can be covered in the second number check.
        if(x >5){
            return false;
        }
        int o = cntNumber('O', board);
        if(x < o || x > o + 1){
            return false;
        }
        //if(x <3 ) true, no need to see winning
        if(o >= 3){
            //if x has won, but game doesnt stop
            if(x == o && hasWon('X', board)){
                return false;
            }
            //if o has won, but game doesnt stop
            if( x > o && hasWon('O', board) ){
                return false;
            }
        }
        return true;
    }

    private int cntNumber(char target, String[] board){
        int res = 0;
        for(int i = 0; i<3; i++) {
            for(int j = 0; j<3; j++) {
                if(target == board[i].charAt(j)){
                    res++;
                }
            }
        }
        return res;
    }

    private boolean hasWon(char target, String[] board){
        String toWin = Character.toString(target).repeat(3);
        for(int i = 0; i<3; i++) {
            if(board[i].equals(toWin)){
                return true;
            }
        }
        for(int j = 0; j<3; j++) {
            boolean col = true;
            for(int i = 0; i<3; i++) {
                col = col && target == board[i].charAt(j);
                if(!col){
                    break;
                }
            }
            if(col){
                return true;
            }
        }
        //check diagonal. If center is not target, not possible to form diag win.
        if(target != board[1].charAt(1)){
            return false;
        }

        boolean diagonal1 = target == board[0].charAt(0);
        //only proceed if the first letter match. Otherwise might get false positive
        if(diagonal1){
            if(target == board[2].charAt(2)){
                return true;
            }
        }

        boolean diagonal2 = target == board[0].charAt(2);
        if(diagonal2){
            if(target == board[2].charAt(0)){
                return true;
            }
        }
        return false;
    }
}