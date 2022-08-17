class Solution {
public:
    int halveArray(vector<int>& nums) {
		priority_queue<double> pq;
        double totalSum = 0;
        double requiredSum = 0;
        for(auto x: nums){
            totalSum += x;
            pq.push(x);
        }
        
        requiredSum = totalSum/2;
        int minOps = 0;
        while(totalSum > requiredSum){
            double currtop = pq.top();
            pq.pop();
            currtop = currtop/2;
            totalSum -= currtop;
            pq.push(currtop);
            minOps++;
        }
        return minOps;
	}
}
		
