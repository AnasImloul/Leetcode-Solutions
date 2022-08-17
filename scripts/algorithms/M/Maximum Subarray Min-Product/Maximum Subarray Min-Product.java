class Solution {
    public int maxSumMinProduct(int[] nums) {
        int mod=(int)Math.pow(10,9)+7;
        int n=nums.length;
        
        //next smaller on left
        int[] left=new int[n];
        Stack<Integer> st=new Stack<>();
        left[0]=-1;
        st.push(0);
        for(int i=1;i<n;i++){
            while(st.size()>0 && nums[st.peek()]>=nums[i]){
                st.pop();
            }
            
            if(st.size()==0) left[i]=-1;
            else left[i]=st.peek();
            
            st.push(i);
        }
        
        //next smaller on right
        int[] right=new int[n];
        st=new Stack<>();
        right[n-1]=n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
        while(st.size()>0 && nums[st.peek()]>=nums[i]) st.pop();
            
            if(st.size()>0) right[i]=st.peek();
            else right[i]=n;
            
            st.push(i);
        }
        
        long[] prefixSum=new long[n];
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++) prefixSum[i]=prefixSum[i-1]+nums[i];
        
      
        long max=0;
        for(int i=0;i<nums.length;i++){
            int l=left[i];
            int r=right[i]-1;
            
            max=Math.max(max,(prefixSum[r]-(l==-1?0:prefixSum[l]))*nums[i]);
        }
        return (int)(max%mod);
    }
}
