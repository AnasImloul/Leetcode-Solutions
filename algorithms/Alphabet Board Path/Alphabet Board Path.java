class Solution {
    public String alphabetBoardPath(String target) {
        String ans = "";
        String[] board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
        int currR = 0 , currC=0;
        for(int i=0;i<target.length();i++){
            int positionR = 0 , positionC = 0;
            char temp = target.charAt(i);
            boolean b = false;
            if(target.charAt(i)=='z' && board[currR].charAt(currC)!='z'){
                temp = 'u';
                b = true;
            }
            for(int j=0;j<board.length;j++){
                for(int k=0;k<board[j].length();k++){
                    if(board[j].charAt(k)==temp){
                        positionR = j;
                        positionC = k;
                        break;
                    }
                }
            }
            if(board[currR].charAt(currC)=='z' && target.charAt(i)!='z'){
                currR--;
                ans+="U";
            }
            if(true){
                if(positionR>currR){
                    for(int j=1;j<=positionR-currR;j++)ans+="D";
                }
                else{
                    for(int j=1;j<=currR-positionR;j++)ans+="U";
                }
            }
            if(true){
                if(positionC>currC){
                    for(int j=1;j<=positionC-currC;j++)ans+="R";
                }
                else{
                    for(int j=1;j<=currC-positionC;j++)ans+="L";
                }
            }
            if(target.charAt(i)=='z' && board[currR].charAt(currC)!='z')ans+="D";
            ans+="!";
            if(b) positionR++;
            currR = positionR;
            currC = positionC;
        }
        return ans;
    }
}
