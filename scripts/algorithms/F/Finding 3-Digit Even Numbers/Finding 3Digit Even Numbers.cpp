//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Finding 3-Digit Even Numbers.
//Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Finding 3-Digit Even Numbers.
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        int A[10]={0};                                                 //Array for 10 digits (0,1,2,3...)
        
        for(auto &x:digits) A[x]++;                                    //Fill our array
        
        for(int i=100;i<999;i+=2)                                      //Look through only correct numbers
        {
            int d1=i/100,d2=i/10%10,d3=i%10;
            if(--A[d1]>=0 & --A[d2]>=0 & --A[d3]>=0) ans.push_back(i); //Here we do 2 actions at the same time(we decrease all digits from our array A and also we check if after the decreasing we have enough digits in our array)
            A[d1]++,A[d2]++,A[d3]++;                                   //Refresh our array to start position
        }
        
        return ans;
    }
};