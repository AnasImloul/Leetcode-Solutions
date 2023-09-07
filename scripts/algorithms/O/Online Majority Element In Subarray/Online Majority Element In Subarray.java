// Runtime: 79 ms (Top 91.4%) | Memory: 61.43 MB (Top 12.7%)

class MajorityChecker {
    
    private final int digits=15;
    private int[][]presum;
    private ArrayList<Integer>[]pos;
    
    public MajorityChecker(int[] arr) {
        int len=arr.length;
        presum=new int[len+1][digits];
        pos=new ArrayList[20001];
        
        for(int i=0;i<len;i++){
            int n=arr[i];
            if(pos[n]==null)pos[n]=new ArrayList();
            pos[n].add(i);
            
            for(int j=0;j<digits;j++){
                presum[i+1][j]=presum[i][j]+(n&1);
                n>>=1;
            }
        }
    }
    
    public int query(int left, int right, int threshold) {
        int ans=0;
        for(int i=digits-1;i>=0;i--){
            int cnt=presum[right+1][i]-presum[left][i];
            int b=1;
            if(cnt>=threshold)b=1;
            else if(right-left+1-cnt>=threshold)b=0;
            else return -1;
            ans=(ans<<1)+b;
        }
        
        // check
        ArrayList<Integer>list=pos[ans];
        if(list==null)return -1;
        int L=floor(list,left-1);
        int R=floor(list,right);
        if(R-L>=threshold)return ans;
        return -1;
    }
    
    private int floor(ArrayList<Integer>list,int n){
        int left=0, right=list.size()-1, mid;
        while(left<=right){
            mid=left+(right-left)/2;
            int index=list.get(mid);
            if(index==n)return mid;
            else if(index<n)left=mid+1;
            else right=mid-1;
        }
        return right;
    }
    
}