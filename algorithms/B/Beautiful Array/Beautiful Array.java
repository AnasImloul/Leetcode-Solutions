class Solution {
    public int[] beautifulArray(int n) {
        ArrayList<Integer>ans=new ArrayList<>();
        ans.add(1);
        
        for(int i=2;i<=n;i++){
            ArrayList<Integer>temp=new ArrayList<>();
            for(Integer e:ans){
                if(2*e<=n)temp.add(e*2);
            }
            for(Integer e:ans){
                if(2*e-1<=n)temp.add(e*2-1);
            }
            
            ans=temp;
        }
        
        int []arr=new int[n];
        int k=0;
        for(Integer i:ans){
            arr[k++]=i;
        }
        return arr;
    }
}
