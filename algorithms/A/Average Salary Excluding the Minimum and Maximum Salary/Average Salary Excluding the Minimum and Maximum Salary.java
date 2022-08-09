class Solution {
    public double average(int[] salary) {
        int n = salary.length-2;
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        int sum = 0;
        for(int i=0;i<n+2;i++){
            sum += salary[i];
            max = Math.max(max,salary[i]);
            min = Math.min(min,salary[i]);
        }
        return (double)(sum-max-min)/n;
    }
}