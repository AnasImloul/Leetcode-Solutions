// Runtime: 76 ms (Top 14.9%) | Memory: 6.33 MB (Top 5.0%)

class Solution {
public:
    int nextGreaterElement(int n) {
       vector<int>vec;
       int temp = n;
        while(n>0){
            int r = n%10;
            vec.push_back(r);
            n /= 10; 
        }
        sort(vec.begin(),vec.end());
        do{
            int num=0;
            long j=0;
            int s = vec.size()-1;
            long i = pow(10,s);
            while(i>0)
           {
            num += i*vec[j++];
            i /= 10;
           }
              if(num>temp)
                 return num;
    
        } while(next_permutation(vec.begin(),vec.end()));
       return -1;
    }
};