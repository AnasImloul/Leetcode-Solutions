Time: O(max(n,Log k))  Space: O(1)

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        int i=size(num)-1;
        int c=0,sum;
        while(i>=0){
            sum=num[i]+k%10+c;
            res.push_back(sum%10);
            c=sum/10;
            k/=10;i--;
        }
        while(k){
            sum=k%10+c;
            res.push_back(sum%10);
            c=sum/10;
            k/=10;
        }
        if(c)
            res.push_back(c);
        reverse(begin(res),end(res));
        return res;
    }
};

--> Approach 2 

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        int i=size(num)-1;
        int sum;
        while(i>=0){
            sum=num[i]+k;
            res.push_back(sum%10);
            k=sum/10;i--;
        }
        while(k){
            res.push_back(k%10);
            k/=10;
        }
        reverse(begin(res),end(res));
        return res;
    }
};
