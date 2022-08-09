#define ll long long
class Solution {
public:
    ll dp1[100005];
    ll dp2[100005];
    
    ll mod=1e9+7;
    
    ll func(vector<int> &nums1 , vector<int> &nums2 , unordered_map< int , int> &mp1,
 unordered_map< int , int> &mp2 , int i1 , int i2 , int n1 , int n2 , bool f1)
    {
        if(i1>=n1 || i2>=n2)
        {
            return 0;
        }
        
        ll sum1=0;
        
        ll sum2=0;
        
        ll ans=0;
        
        if(f1==true)
        {
            if(dp1[i1]!=-1)
            {
                return dp1[i1];
            }
        }
        else
        {
            if(dp2[i2]!=-1)
            {
                return dp2[i2];
            }
        }
        
        if(f1==true)
        {
            sum1=(sum1 + nums1[i1]);
            auto it=mp2.find(nums1[i1]);
            
            sum1=(sum1 + func(nums1 , nums2 , mp1 , mp2 , i1+1 , i2 , n1 , n2 , true));
            
            if(it!=mp2.end())
            {
                int idx=mp2[nums1[i1]];
                sum2=(sum2 + nums2[idx]);
                
                sum2=(sum2 + func(nums1 , nums2 , mp1 , mp2 , i1 , idx+1 , n1 , n2 , false ));
                
            }
            ans=max(sum1 , sum2);
            
            dp1[i1]=ans;
        }
        else
        {
            sum2=(sum2 + nums2[i2]);
            auto it=mp1.find(nums2[i2]);
            
            sum2=(sum2 + func(nums1 , nums2 , mp1 , mp2 , i1 , i2+1 , n1 , n2 , false));
            
            if(it!=mp1.end())
            {
                int idx=mp1[nums2[i2]];
                sum1= (sum1 + nums1[idx]);
                sum1=(sum1 + func(nums1 , nums2 , mp1 , mp2 , idx+1 , i2 , n1 , n2 , true));
            }
            ans=max(sum1 , sum2);
            dp2[i2]=ans;
        }
        
        
        return ans;
        
        
    }
    
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
         
        // at every equal value we can switch 
        
        // the elements from array1 to array2
        
        unordered_map< int , int> mp1 , mp2;
        
        int n1=nums1.size() , n2=nums2.size();
        
        for(int i=0;i<nums1.size();i++)
        {
            mp1[nums1[i]]=i;
        }
        
        for(int i=0;i<nums2.size();i++)
        {
            mp2[nums2[i]]=i;
        }
        
        // start from both array as nums1 & nums2 , nums2 & nums1
        
        memset(dp1 , -1 , sizeof(dp1));
        memset(dp2 , -1 , sizeof(dp2));
        
        bool f1=true;
        
        ll ans1=func(nums1 , nums2 , mp1 , mp2 , 0 , 0 ,n1 , n2 , f1);
        memset(dp1 , -1 , sizeof(dp1));
        memset(dp2 , -1 , sizeof(dp2));
        ll ans2=func(nums2 , nums1 , mp2 , mp1 , 0 , 0 , n2 , n1 , f1);
        
        ans1=ans1%mod;
        ans2=ans2%mod;
        
        return max(ans1 , ans2);
        
    }
