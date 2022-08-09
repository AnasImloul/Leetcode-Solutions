class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int rotate = 0, total = 0, money = 0, num = 0, i;
		int maxx = INT_MIN, ans = rotate;
        for(i = 0; i< customers.size(); i++){
            total += customers[i];
            rotate = i+1;
            if(total >= 4) {num += 4; total -= 4;}
            else { num += total; total = 0;}
            money = num * boardingCost - rotate * runningCost;
            if(maxx < money) {maxx = money; ans = rotate;}
        }
        while(total > 0){
            rotate = i+1;
            if(total >= 4) {num += 4; total -= 4;}
            else { num += total; total = 0;}
            money = num * boardingCost - rotate * runningCost;
            if(maxx < money) {maxx = money; ans = rotate;}
            i++;

        }
        if(maxx < 0) return -1;
        return ans;
    }
};
