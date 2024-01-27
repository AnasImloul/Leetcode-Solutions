// Runtime: 0 ms (Top 100.0%) | Memory: 41.80 MB (Top 5.91%)

class Solution {
    public int minimumSwap(String s1, String s2) {
        
        int count = 0;
        int cnt_1 = 0;
        int cnt_2 = 0;
        char[] a = s1.toCharArray();
        char[] b = s2.toCharArray();
        
        for(int i=0;i<a.length;i++){
            if(a[i] != b[i]){
                count++;
                if(a[i] == 'x') cnt_1++;
                else cnt_2++;
            }
        }
        
        if(count%2 == 1)
            return -1;
        else return cnt_1/2+cnt_2/2+(cnt_1%2)*2;
    }
}
