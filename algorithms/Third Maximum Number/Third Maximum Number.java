class Solution {
    public int thirdMax(int[] nums) {
        Integer first = null, second = null, third = null;
        for(Integer num: nums){
            if(num.equals(first) || num.equals(second) || num.equals(third)) continue;
            if(first == null || num > first){
                third = second;
                second = first;
                first = num;
                continue;
            } 
            if(second == null || num > second){
                third = second;
                second = num;
                continue;
            } 
            if(third == null || num > third){
                third = num;
            }
        }
        return (third != null) ? third : first;
    }
}
