// Runtime: 12 ms (Top 74.68%) | Memory: 51.9 MB (Top 43.97%)
class Solution {
    public int minFlipsMonoIncr(String s) {
        int count1 =0;
        int delete_count =0;
        for(char ch: s.toCharArray()){
            if(ch=='1'){
                if(count1<=0){
                    count1=1;
                }
                else{
                    count1++;
                }
            }
            else if(count1>0){
                delete_count++;
                count1--;
            }
        }
        return delete_count;
    }
}