class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int c = 0; // count
        priority_queue<int,vector<int>,greater<int>> pq; /// min heap
        int op = numsDivide[0];
        int n = numsDivide.size();
        for(int i = 1;i < n;i++){
            op = __gcd(op,numsDivide[i]); // as it will be the maximum number that will divide all the numbers 
        }
        for(auto&i : nums){
            pq.push(i); // pushing all elements in the heap
        } 
        while(!pq.empty()){ 
            int temp = pq.top();
            pq.pop();
            if(op%temp == 0){ // if the minimum element divides the gcd return count at that time
                return c;
            }
            if(temp > op){ // if pq top become bigger than the find gcd then it returns -1
                return -1;
            }
            c++;
            
        }
        return -1; // means the heap got empty and no element divide the numsDivide array
    }
};