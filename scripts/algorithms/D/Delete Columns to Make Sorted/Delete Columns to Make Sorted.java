// Runtime: 9 ms (Top 91.77%) | Memory: 42.4 MB (Top 94.00%)
class Solution {
    public int minDeletionSize(String[] strs) {
        int count = 0;
        for(int i = 0; i < strs[0].length(); i++){ //strs[0].length() is used to find the length of the column
            for(int j = 0; j < strs.length-1; j++){
                if((int) strs[j].charAt(i) <= (int) strs[j+1].charAt(i)){
                    continue;
                }else{
                    count++;
                    break;
                }
            }
        }
        return count;
    }
}