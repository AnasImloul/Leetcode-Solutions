// Runtime: 1 ms (Top 89.57%) | Memory: 42.40 MB (Top 48.82%)

class Solution {
    public int[] prisonAfterNDays(int[] cells, int N) {
        if(N==0) return cells;
        int[][] mem=new int[14][8];            // Repeat pattern after day 14, so Day 1 and Day 15 is equal
        mem[0][0]=0;
        mem[0][7]=0;
        for(int i=1;i<7;i++){                    // calculating Day 1 and insert at 0th position in mem
            if(cells[i-1]==cells[i+1])
                mem[0][i]=1;
            else
                mem[0][i]=0;
        }
        
        for(int j=1;j<14;j++){                    // calculating Day 2 to 14 and inserting at position 1 to 13 in mem.
            for(int i=1;i<7;i++){
                if(mem[j-1][i-1]==mem[j-1][i+1])
                    mem[j][i]=1;
                else
                    mem[j][i]=0;
            }
        }
        return mem[(N-1)%14];                //return the day modulo 14
    }
}
