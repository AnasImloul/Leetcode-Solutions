// Runtime: 9 ms (Top 69.93%) | Memory: 44.3 MB (Top 32.60%)

class Solution {
    public String largestNumber(int[] nums) {
        String[] arr=new String[nums.length];
        for(int i=0;i<nums.length;i++){
            arr[i]=Integer.toString(nums[i]);
        }
        Arrays.sort(arr,(a,b)->(b+a).compareTo(a+b));
        if(arr[0].equals("0")) return "0";
        StringBuilder builder=new StringBuilder();
        for(String item:arr){
            builder.append(item);
        }
        return builder.toString();
    }
}