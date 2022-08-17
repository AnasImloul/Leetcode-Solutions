class Solution {
public:
bool canFit(int n,long timeSpan,vector<int>batteries)
{
    long currBatSum=0;
	long targetBatSum=n*timeSpan; 
    for(auto it:batteries)
    {
        if(it<timeSpan)
            currBatSum+=it;
        else
            currBatSum+=timeSpan;
        
        if(currBatSum>=targetBatSum)
            return true;  
    }
    
    return false;
 }

long long maxRunTime(int n, vector<int>& batteries) {
  long totalSum=0;
  long low=*min_element(batteries.begin(),batteries.end());
  
    for(auto it:batteries)
    {
        totalSum+=it;  
    }
    
    long high = totalSum/n;
    long ans=-1;
    
    while(low<=high)
    {
     
      long mid = low+(high-low)/2;    
     if(canFit(n,mid,batteries))
     {
         ans=mid;
         low=mid+1;
     }
     else
     {
         high=mid-1;
     }
           
    }  
   return ans;       
}
