// Runtime: 1084 ms (Top 15.1%) | Memory: 56.26 MB (Top 90.9%)

class Solution {
    int max = 0;
    Set<Integer> exist = new HashSet();
    public int countDifferentSubsequenceGCDs(int[] nums) {
        getMax(nums);
        for(int num : nums) exist.add(num);
        int count = 0;
        for (int i=1;i<=max;i++) if(findGCD(i)) count++;      //  <---- findGCD
        return count;
    }
    public void getMax(int[] nums){
        for(int i : nums) max = Math.max(max, i);
    }
    public int gcd(int a, int b){
        return (a == 0) ? b : gcd(b % a, a);
    }
	public boolean findGCD(int num){
        int val = 0;
        for(int i = num; i <= max; i+= num)
            if(exist.contains(i)) val = gcd(i, val);          //  <---- gcd between two number
        return (val == num);
    }
}