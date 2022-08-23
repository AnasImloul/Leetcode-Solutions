// Runtime: 305 ms (Top 62.11%) | Memory: 113.5 MB (Top 30.98%)
class Solution {
    public int repeatedStringMatch(String a, String b) {
        String copyA = a;
        int count =1;
        int repeat = b.length()/a.length();
        for(int i=0;i<repeat+2;i++){
            if(a.contains(b)){
                return count;
            }
            else{
                a+=copyA;
                count++;
            }
        }
        return -1;

    }
}