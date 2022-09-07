// Runtime: 26 ms (Top 23.48%) | Memory: 82.1 MB (Top 8.82%)
class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        char[] arr = s.toCharArray();
        int[] arr1 = new int[shifts.length];
        arr1[arr1.length-1] = (shifts[shifts.length-1])%26;
        for(int i =shifts.length -2 ;i>=0 ;i--){
            arr1[i] = (shifts[i] + arr1[i+1])%26;
        }
        for(int i =0; i<arr.length ; i++ ){
            int c = (int)(arr[i]);
            int n = c+arr1[i];
            if(n>122){
                    int m = arr1[i] -(122-c);
                    n = m+96;
                }
            char ch = (char)n;
            arr[i] = ch;

        }
        String string = new String(arr);
        return string;

    }
}