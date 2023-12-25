// Runtime: 243 ms (Top 80.44%) | Memory: 106.00 MB (Top 36.23%)

class Solution {
public:
    #include<map>    
    int getvalue(int n,vector<int>& mapping){
        int value=0,t=1;
        if(n==0)
            return mapping[0];
        while(n!=0){
            int temp=n%10;            
            value=mapping[temp]*t+value;
            t=t*10, n=n/10;
        }
        return value;
    }            
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {        
        multimap<int,int> m;
        for(int a:nums){            
            int temp=getvalue(a,mapping);                        
            m.insert(make_pair(temp,a));
        }        
        nums.clear();
        for(auto itr=m.begin();itr!=m.end();itr++){
            nums.push_back(itr->second);
        }
        return nums;
    }
};
