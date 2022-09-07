// Runtime: 2 ms (Top 77.73%) | Memory: 42.8 MB (Top 23.55%)
class Solution {
    public int HHMMToMinutes(String s){
        return Integer.parseInt(s.substring(0,2))*60 + Integer.parseInt(s.substring(3,5)) ;
    }
    public int convertTime(String current, String correct) {
        int diff = HHMMToMinutes(correct) - HHMMToMinutes(current);
        int[] order = {60,15,5,1};
        int i = 0;
        int ops = 0;
        while(i < 4){
            ops+=(diff/order[i]);
            diff%=order[i];
            i++;
        }
        return ops;
    }
}