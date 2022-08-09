class Solution {
    public int monotoneIncreasingDigits(int n) {
        char[] arr = String.valueOf(n).toCharArray();
        int start = arr.length;
        for (int i = arr.length - 2; i >= 0; i --) {
            if (arr[i] > arr[i + 1]) {
                start = i + 1;
                arr[i] --;
            }
        }
        
        for (int i = start; i < arr.length; i ++) {
            arr[i] = '9';
        }
        
        return Integer.parseInt(String.valueOf(arr));
    }
}
