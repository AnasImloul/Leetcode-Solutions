/*
So in the question we want to find out the 
number of difference of bits between each pair 
so in the brute force we will iterate over the vector 
and for every pair we will calculate the Hamming  distance 
the Hamming distance will be calculated by taking XOR  between the two elements
and then finding out the number of ones in the XOR of those two elements 
the intuition behind this method is that XOR will contain 1's at those places 
where the corresponding bits of  elements x & y are different 
therefore we will add this count
to our answer
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int XOR=x^y;
        
        int count=0;
        while(XOR){
            if(XOR&1)
                count++;
            
            XOR=XOR>>1;
        }
        return count;
    }
    
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                ans+=hammingDistance(nums[i],nums[j]);
            }
        }
        
        return ans;
    }
};
