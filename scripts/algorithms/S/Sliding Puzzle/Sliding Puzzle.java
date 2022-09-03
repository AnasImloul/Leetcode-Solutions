// Runtime: 22 ms (Top 35.42%) | Memory: 44.4 MB (Top 46.82%)
class Solution {
    int [][] dir={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
    public int slidingPuzzle(int[][] board) {

        String tar="123450";

        String src="";

        for(int i =0;i<board.length;i++){
            for(int j=0;j<board[i].length;j++){
                src+=board[i][j];
            }
        }

       HashSet<String> visited=new HashSet<>();

        visited.add(src);
        int level=0;
        ArrayDeque<String> q=new ArrayDeque<>();
        q.add(src);
        while(q.size()!=0){
            int t=q.size();

            while(t-->0){
                String rem=q.remove();

                if(rem.equals(tar)){
                    return level;
                }

                int idx=-1;

                for(int i=0;i<rem.length();i++){
                    if(rem.charAt(i)=='0'){
                        idx=i;
                        break;
                    }
                }

                for(int i =0;i<dir[idx].length;i++){
                    String str=swapEle(rem,idx,dir[idx][i]);

                    if(!visited.contains(str)){
                        q.add(str);
                        visited.add(str);
                    }
                }
            }
            level++;
        }

        return -1;
    }

    public String swapEle(String rem,int i,int j){
        StringBuilder sb=new StringBuilder(rem);

        sb.setCharAt(i,rem.charAt(j));
        sb.setCharAt(j,rem.charAt(i));

        return sb.toString();
    }
}