class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        HashMap<Integer,Integer>hm=new HashMap<>();
        Stack<Integer>st=new Stack<>();
        for(int i=0;i<temperatures.length;i++){
            while(st.size()>0&&temperatures[i]>temperatures[st.peek()]){
                hm.put(st.pop(),i);
            }
            st.push(i);
        }
        int []ans=new int[temperatures.length];
        for(int i=0;i<temperatures.length;i++){
            if(hm.containsKey(i)){
                ans[i]=hm.get(i)-i;
            }else{
                ans[i]=0;
            }
        }
        return ans;
    }
}