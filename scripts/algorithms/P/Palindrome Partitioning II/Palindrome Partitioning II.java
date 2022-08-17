class Solution {
int dp[];

 public boolean pali(int i,int j,String s){
    
   // int j=s.length()-1,i=0;
    
    while(i<=j){
        
        if(s.charAt(i)!=s.charAt(j))return false;
            
            i++;j--;
        
    }
    
    return true;
    
}
public int cut(String s,int i,int n,int dp[]){
    
    if(i==n)return 0;
    if(dp[i]!=-1)return dp[i];
    
    int min=Integer.MAX_VALUE;
    
    for(int j=i;j<n;j++){
        
        if(pali(i,j,s)){
            
            int cost=1+cut(s,j+1,n,dp);
            min=Math.min(min,cost);
            
      } 
    }
   return  dp[i]=min;
       
public int minCut(String s) {
    int n=s.length();
    dp=new int[n];
    Arrays.fill(dp,-1);
    return cut(s,0,n,dp)-1;       
}
