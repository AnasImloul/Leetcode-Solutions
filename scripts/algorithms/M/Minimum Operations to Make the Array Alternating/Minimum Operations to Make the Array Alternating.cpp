// Runtime: 775 ms (Top 27.44%) | Memory: 140.3 MB (Top 88.77%)
class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        int totalEven = 0, totalOdd = 0;

        unordered_map<int,int> mapEven, mapOdd;

        for(int i=0;i<nums.size();i++) {
            if(i%2==0) {
                totalEven++;
                mapEven[nums[i]]++;
            }

            else {
                totalOdd++;
                mapOdd[nums[i]]++;
            }
        }

        int firstEvenCount = 0, firstEven = 0;
        int secondEvenCount = 0, secondEven = 0;

        for(auto it=mapEven.begin();it!=mapEven.end();it++) {
            int num = it->first;
            int count = it->second;

            if(count>=firstEvenCount) {
                secondEvenCount = firstEvenCount;
                secondEven = firstEven;
                firstEvenCount = count;
                firstEven = num;
            }

            else if(count >= secondEvenCount) {
                secondEvenCount = count;
                secondEven = num;
            }
        }

        int firstOddCount = 0, firstOdd = 0;
        int secondOddCount = 0, secondOdd = 0;

        for(auto it=mapOdd.begin();it!=mapOdd.end();it++) {
            int num = it->first;
            int count = it->second;

            if(count>=firstOddCount) {
                secondOddCount = firstOddCount;
                secondOdd = firstOdd;
                firstOddCount = count;
                firstOdd = num;
            }

            else if(count>=secondOddCount) {
                secondOddCount = count;
                secondOdd = num;
            }
        }

        int operationsEven = 0, operationsOdd = 0;

        operationsEven = totalEven - firstEvenCount;

        if(firstEven!=firstOdd) operationsEven += (totalOdd - firstOddCount);
        else operationsEven += (totalOdd - secondOddCount);

        operationsOdd = totalOdd - firstOddCount;
        if(firstOdd!=firstEven) operationsOdd += (totalEven - firstEvenCount);
        else operationsOdd += (totalEven - secondEvenCount);

        return min(operationsEven, operationsOdd);

    }
};