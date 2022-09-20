// Runtime: 911 ms (Top 7.06%) | Memory: 70.7 MB (Top 63.53%)
class Solution {
    int TIME_MAX = 200;
    int DRAW = 0;
    int MOUSE_WIN = 1;
    int CAT_WIN = 2;
    public int catMouseGame(int[][] graph) {
        return dfs(0, new int[]{1, 2}, graph, new Integer[TIME_MAX+1][graph.length][graph.length]);
    }

    private int dfs(int time, int[] p, int[][] graph, Integer[][][] memo){ // p[0] -> mouse position, p[1] -> cat position
        Integer old = memo[time][p[0]][p[1]];
        if (old != null) return old; // all the base cases here
        if (time >= TIME_MAX) return DRAW;
        if (p[0]==0) return MOUSE_WIN;
        if (p[0]==p[1]) return CAT_WIN;
        int state = 0;
        int where = p[time&1];
        int res = DRAW;
        for (int i = 0; i < graph[where].length; i++){
            if ((time&1)==0||graph[where][i]>0){ // if mouse turn or cat turn and the dest is not 0, do ...
                p[time&1]=graph[where][i];
                state |= 1 << dfs(time+1, p, graph, memo);
                if ((time&1)>0&&(state&4)>0 || (time&1)==0&&(state&2)>0) // if mouse's turn & mouse win
                    break; // or cat's turn & cat win, then we stop.
            }
        }
        p[time&1]=where; // restore p
        if (((time&1)>0 && (state & 4)>0)||((time&1)==0) && state==4){
            res = CAT_WIN; // cat win when (cat's turn & cat win) or (mouse's turn and state = cat)
        }else if (((time&1)==0 && (state & 2)>0)||(time&1)==1 && state==2){
            res = MOUSE_WIN; // mouse win when (mouse's turn and mouse win) or (cat's turn and state = mouse)
        }
        return memo[time][p[0]][p[1]]=res;
    }
}