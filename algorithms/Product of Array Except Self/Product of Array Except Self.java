class Solution {
    public int[] productExceptSelf(int[] nums) {
        int size=nums.length;
        int[] prefix=new int[size];
        int[] suffix=new int[size];
        int[] answer=new int[size];
        prefix[0]=nums[0];
        suffix[size-1]=nums[size-1];
        for(int i=1;i<size;i++){
            prefix[i]=prefix[i-1]*nums[i];
        }
        for(int i=size-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i];
        }
        answer[0]=suffix[1];
        answer[size-1]=prefix[size-1-1];
        for(int i=1;i<size-1;i++){
            answer[i]=prefix[i-1]*suffix[i+1];
        }
       // System.out.println(Arrays.toString(prefix)+'\n'+Arrays.toString(suffix));
        return answer;
    }
}


