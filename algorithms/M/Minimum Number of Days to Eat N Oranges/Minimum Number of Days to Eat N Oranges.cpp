class Solution {
public:
    // approach: BFS
    int minDays(int n) {
        int cnt=0;
        queue<int>q;
        q.push(n);
        unordered_set<int>s;
        s.insert(n);
        while(!q.empty()){
            int l=q.size();
            while(l--){
                int a=q.front();
                q.pop();
                if(a==0)
                    break;
                if(s.find(a-1)==s.end()){ 
                    q.push(a-1);
                    s.insert(a-1);
                }  
                if(!(a&1) && s.find(a>>1)==s.end()){   // if divisible by 2 and a/2 not present in set
                    q.push(a>>1);
                    s.insert(a>>1);
                }
                if(a%3==0 && s.find(a/3)==s.end()){  // if divisible by 3 and a/3 not present in set
                    q.push(a/3);
                    s.insert(a/3);
                }
            }
            cnt++;
            if(s.find(0)!=s.end())
                break;
        }
        return cnt;
    }
};
