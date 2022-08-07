class Solution {
public:
    //basically if we store the digits of the number in an array, then the question boils down to 
    //finding the next lexicographically larger permutation of the digits.
    int nextGreaterElement(int n) {
        vector<int>digits;
        int number=n;
        while(number){
            digits.push_back(number%10);
            number/=10;
        }
        reverse(digits.begin(),digits.end());
        next_permutation(digits.begin(),digits.end());
        long ans=0;
        for(int i=0;i<digits.size();i++){
            ans*=10;
            ans+=digits[i];
        }
        if(ans>(long)INT_MAX or ans<=n){
            return -1;
        } else {
            return (int)ans;
        }
    }
};