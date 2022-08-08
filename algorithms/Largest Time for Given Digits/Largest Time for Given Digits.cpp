class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.rbegin(), arr.rend());
        used.resize(4);
        
        string ret = "";
        if(!dfs(arr,0,0)) return ret;
        else
        {
            for(int i=0;i<2;i++)
                ret.push_back(ans[i] + '0');
            
            ret.push_back(':');
            
            for(int i=2;i<4;i++)
                ret.push_back(ans[i] + '0');
        }
        return ret;
    }
    
private:
    vector<int> min = {600, 60, 10, 1};
    vector<int> ans;
    vector<int> used;
    bool dfs(const vector<int>& arr, int totalhour,int totalmin)
    {
        if(totalhour >= 24 * 60) return false;
        if(totalmin >= 60) return false;
        if(ans.size() == 4) return true;
        
        for(int i=0;i<4;i++)
        {
            if(used[i]) continue;
            used[i] = 1;
            
            int pos = ans.size();
            if(pos<2) totalhour += arr[i] * min[pos];
            else totalmin += arr[i] * min[pos];
            
            ans.push_back(arr[i]);
            
            if(dfs(arr,totalhour,totalmin)) return true;
            
            if(pos<2) totalhour -= arr[i] * min[pos];
            else totalmin -= arr[i] * min[pos];
            
            ans.pop_back();
            used[i] = 0;
        }
        
        return false;
    }
};
