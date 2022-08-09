class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> s;
        for(int i=0;i<arr.size();i++){
            int j=i-1;
            int a=0,b=arr[i];
            s.insert(b);
            int k=0;
            while(j>=0 and a!=b){
                a|=arr[j];
                b|=arr[j];
                s.insert(b);
                j--;
               
            }
        }
        return s.size();
    }
};
