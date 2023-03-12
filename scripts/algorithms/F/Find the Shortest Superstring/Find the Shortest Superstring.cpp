vector<vector<int> > dp,pre,par;

bool startWith(string s, string t)
{
// returns true if string s starts with string t
    int i;
    for(i=0; i<s.length()&&i<t.length(); i++)
    {
        if(s[i]==t[i])
            continue;
        else
            return false;
    }
    if(i==t.length())
        return true;
    else
        return false;
}

int calc(string A, string B)
{
 // calculate the number of extra characters required to be appended to A
 // if A is followed by B
 // for eg. calc("abcd","cdef") = 2
 
    int a=A.length(),b=B.length();
    for(int i=0; i<a; i++)
    {
        if(a-i<=b&&startWith(B,A.substr(i)))
        {
            return b-(a-i); 
        }
    }
    return b;
}

int finalMask,n;

int helper(int mask, int last)
{
 // returns the minimum length of string required if last string appended was A[last] 
 // the sets bit in mask represents the strings that were already appended to the final string
 
    if(mask==finalMask)  // all strings are appended in final string
        return 0;

    if(dp[mask][last]!=-1) // memoization
        return dp[mask][last];
        
    int mn=INT_MAX;
    int p;
    for(int i=0; i<n; i++)
    {
        if(mask&(1<<i))
            continue;
        int cost=pre[last][i]+helper(mask|(1<<i),i);  // extra characters need to be appended
        if(cost<mn)
        {
            mn=cost;
            p=i;
        }
    }
    par[mask][last]=p;  // store parent, so that it is easy to traceback and find the final result
    return dp[mask][last]=mn; // store result in DP table
}



class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
    n=A.size();
    pre.assign(n,vector<int>(n));  // for pre-computing calc(a,b) for all pairs of strings
    par.assign(1<<n,vector<int>(n,-1));    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(j==i)
                continue;
            pre[i][j]=calc(A[i],A[j]);
        }
    }
    finalMask=(1<<n)-1;  
    dp.assign(1<<n,vector<int>(n,-1));
    int len=INT_MAX;  // len will contain minimum length of required string
    int ind;
    for(int i=0; i<n; i++)
    {
        int prev=len;
        len=min(len, (int)A[i].length()+helper(1<<i,i));
        if(len!=prev)
        {
            ind=i;
        }
    }

 // Now traceback to find the final answer
    string ans=A[ind];
    int msk=1<<ind;
    int prev_ind=ind;
    ind=par[msk][ind];
    while(ind!=-1)
    {
        len=pre[prev_ind][ind];
        int alen=A[ind].length();
        ans+=A[ind].substr(alen-len,len);            
        msk=msk^(1<<ind);
        prev_ind=ind;
        ind=par[msk][ind];  
    }
        return ans;
    }
};