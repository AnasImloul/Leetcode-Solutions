class Solution {
    public double trimMean(int[] arr) {
        Arrays.sort(arr);
        int length = arr.length;
        int toRemove = length * 5 / 100;
        int total = 0;
        for (int number: arr) {
            total += number;
        }
        for (int i=0; i<toRemove; i++)
            total -= arr[i];
        for (int i=length-1; i>= length-toRemove; i--)
            total -= arr[i];
        length -= (2 * toRemove);
        return (double) ((double)total / (double)length);
    }
}
