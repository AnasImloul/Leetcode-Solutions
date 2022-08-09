class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        ios_base::sync_with_stdio(0);cin.tie(0);
        priority_queue<int,vector<int>,greater<int>>p;
        unordered_map<int,int>m;
        int ans=0;
        int i=0;
        while(p.size() || i<days.size()){
            if(i<days.size() && apples[i]!=0 && days[i]!=0){
                m[days[i]+i]=apples[i];
                p.push(days[i]+i);
            }
            while(p.size()){
                if(m[p.top()]!=0 && p.top()>i)
                    break;
                p.pop();
            }
            if(p.size()){
                ans++;
                m[p.top()]--;
            }
            ++i;
        }
        return ans;
    }
};