class DSU{
    vector<int> par,rank;
    int n;
    public:
    DSU(int n)
    {
        this->par.resize(n);
        this->rank.resize(n);
        this->n=n;
        for(int i=0;i<n;i++)
            par[i]=i;
    }
    int find(int x)
    {
        if(x==par[x])return x;
        return par[x]=find(par[x]);
    }
    void Union(int a, int b)
    {
        int a_par=find(a);
        int b_par=find(b);
        if(a_par==b_par)
            return;
        if(rank[a_par]<rank[b_par])
        {
            par[a_par]=b_par;
        }
        else if(rank[b_par]<rank[a_par]){
            par[b_par]=a_par;
        }
        else
        {
            par[a_par]=b_par;
            rank[b_par]+=1;
        }
    }
};

class Solution {
public:
    vector<int>spf;
    bool gcdSort(vector<int>& nums) {
        int n=nums.size();
        int max_nums=INT_MIN;
        for(int i=0;i<n;i++)
            max_nums=max(max_nums,nums[i]);
        sieve(max_nums+1);
        DSU dsu(max_nums+1);
        vector<int>sortedNums(nums);
        sort(sortedNums.begin(),sortedNums.end());
        for(int i=0;i<n;i++)
        {
            vector<int>factorsOfNumsi= getAllFactors(nums[i]);
            int numFactors=factorsOfNumsi.size();
            for(int j=0;j<numFactors;j++)
            {
                dsu.Union(nums[i],factorsOfNumsi[j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dsu.find(nums[i])!=dsu.find(sortedNums[i]))
                return false;
        }
        return true;
        
    }
    vector<int> getAllFactors(int x)
    {
        vector<int>factors;
        while(x>1)
        {
            factors.push_back(spf[x]);
            x/=spf[x];
        }
        return factors;
    }
    void sieve(int n)
    {
        spf.resize(n);
        for(int i=2;i<n;i++)
            spf[i]=i;
        for(int i=2;i*i<n;i++)
        {
            if(spf[i]==i)
            {
                for(int j=i*i;j<n;j+=i)
                {
                    if(spf[j]>i)
                        spf[j]=i;
                }
            }
        }
    }
    
};
