class Solution {
public:
vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {

    sort(bobSizes.begin(),bobSizes.end());
    sort(aliceSizes.begin(),aliceSizes.end());

    int sum1=0;
    int sum2=0;
    vector <int> ans;
    for(int i =0 ; i <aliceSizes.size(); i++)
    {
        sum1+=aliceSizes[i];
    }
    for(int i =0 ; i <bobSizes.size(); i++)
    {
        sum2+=bobSizes[i];
    }
    
    int dif = (sum1-sum2)/2;
    
    
    for(int i = 0 ; i <aliceSizes.size(); i++)
    {
        
        int st=0;
        int end = bobSizes.size()-1;
        
        while(st<=end)
        {
            int mid = (st+end)/2;
            
            if(bobSizes[mid]==aliceSizes[i]-dif)
            {
             ans.push_back(aliceSizes[i]);
             ans.push_back(bobSizes[mid]);
             return ans;
            }
            
            else if(bobSizes[mid]<aliceSizes[i]-dif)
            {
                st=mid+1;
            }
            else if(bobSizes[mid]>aliceSizes[i]-dif)
            {
                end=mid-1;
            }
              
        }    
    }
    
    return ans;
    
}
};
