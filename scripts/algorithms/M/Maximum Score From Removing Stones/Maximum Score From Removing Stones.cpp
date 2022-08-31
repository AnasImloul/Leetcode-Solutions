// Runtime: 165 ms (Top 38.49%) | Memory: 6.1 MB (Top 38.40%)
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int f=1;
        int ans=0;
        while(f)
        {
            int f=pq.top(); pq.pop();
            int s=pq.top(); pq.pop();
            if(f==0 || s==0)
                break;
            ans++;
            f--; s--;
            pq.push(f);
            pq.push(s);
        }
        return ans;

    }
};