// Runtime: 3 ms (Top 72.70%) | Memory: 42.6 MB (Top 56.41%)
class Solution {
    public int secondHighest(String s) {
        int[] arr = new int[10];
        for(int i = 0;i<s.length();i++){
            if(s.charAt(i) - '0' <=9 & s.charAt(i)-'0' >=0){
                arr[s.charAt(i)-'0']++;
            }
        }
        boolean first = false;
        for(int i = 9;i>=0;i--){
            if(arr[i] !=0){
                if(first)
                    return i;
                else first = true;
            }
        }

        return -1;
    }
}