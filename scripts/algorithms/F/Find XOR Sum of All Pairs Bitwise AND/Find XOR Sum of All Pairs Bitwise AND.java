class Solution {

    public int getXORSum(int[] arr1, int[] arr2) {
        int[] x = (arr1.length < arr2.length ? arr2 : arr1);
        int[] y = (arr1.length < arr2.length ? arr1 : arr2);
        int xorSumX = 0;
        for (int xi : x) {
            xorSumX ^= xi;
        }
        int answer = 0;
        for (int yj : y) {
            answer ^= (yj & xorSumX);
        }
        return answer;
    }

}
