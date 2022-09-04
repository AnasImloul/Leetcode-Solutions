// Runtime: 1154 ms (Top 36.85%) | Memory: 229 MB (Top 24.81%)
class Solution {
public:

    vector<int>seg;

    int query(int index,int low,int high,int l,int r)
    {
        if(low>=l && high<=r)
        {
            return seg[index];
        }
        if(high<l || low>r)
            return 0;

        int mid=(low+high)/2;
        int left=query(2*index+1,low,mid,l,r);
        int right=query(2*index+2,mid+1,high,l,r);
        return right+left;

    }

    void update(int index,int low,int high,int pos)
    {
        if(low==high)
        {
            seg[index]++;
            return ;
        }
        else
        {
            int mid=(low+high)/2;
            if(pos<=mid)
            {
                update(2*index+1,low,mid,pos);
            }
            else
            {
                update(2*index+2,mid+1,high,pos);
            }
            seg[index]=seg[2*index+1]+seg[2*index+2];
        }
    }

    int createSortedArray(vector<int>& instructions) {

        // using 100001 as 1e5 is the max element value
        seg.resize(4*100001,0);
        int mod=1e9+7;
        int ans=0;
        for(int i=0;i<instructions.size();i++)
        {
            int mi=query(0,0,100001,0,instructions[i]-1); //number of elements smaller than instruction[i]
            int mx=query(0,0,100001,instructions[i]+1,100001); // number of elements greater than instruction[i]
            update(0,0,100001,instructions[i]);
            ans=(ans+min(mi,mx))%mod;
        }
        return ans;

         /*TLE approch using STL
         // 50/65 cases passed
        int m=instructions.size();
        vector<int>a;
        int mod=1e9+7;
        int ans=0;
        int mxe=INT_MIN;
        unordered_map<int,int>um;
        for(auto x:instructions)
        {
            int xx=lower_bound(a.begin(),a.end(),x)-a.begin();
            int n=a.size();
            um[x]++;
            mxe=max(mxe,x);
            if(n==0)
            {
                a.push_back(x);

            }
            else
            {
                a.insert(a.begin()+xx,x);

                int mi=xx;
                int m=a.size();
                ans=(ans+min(mi,m-mi-um[x]))%mod;

            }
        }

        return ans;*/

    }
};