class Solution {
    public int[] closestDivisors(int num) {
        int ans[]=new int[2];
        double a=Math.sqrt(num+1);
        double b=Math.sqrt(num+2);
        if(num==1){
            ans[0]=1;
            ans[1]=2;
            return ans;
        }
        else if(a%1==0){
            ans[0]=(int)a;
            ans[1]=(int)b;
            return ans;
        }
        else if(b%1==0){
            ans[0]=(int)b;
            ans[1]=(int)b;
             return ans;
        }
        else{
            int m=(int)Math.sqrt(num);
       int diff1=Integer.MAX_VALUE;
       int y=0,z=0,w=0,f=0;
       for(int i=2;i<=m;i++){
           if((num+1)%i==0){
               y=i;
               z=(num+1)/y;
               int r=Math.abs(y-z);
               if(r<diff1){
                   diff1=r;
               }
           }
       }
       int diff2=Integer.MAX_VALUE;
        for(int i=2;i<=m;i++){
           if((num+2)%i==0){
               w=i;
               f=(num+2)/w;
               int r=Math.abs(w-f);
               if(r<diff2){
                   diff2=r;
               }
           }
       }
            if(diff1<diff2){
                ans[0]=y;
            ans[1]=z;
                 return ans;
            }
            else{
                ans[0]=w;
                ans[1]=f;
                 return ans;
            }
        } 
    }
}```