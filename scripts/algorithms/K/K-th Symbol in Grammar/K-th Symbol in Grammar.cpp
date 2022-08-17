class Solution {
public:
    int kthGrammar(int n, int k) {
        int kthNode = pow(2, (n-1)) + (k - 1);
        vector<int>arr;
        while(kthNode) {
            arr.push_back(kthNode);
            kthNode /= 2;
        }
        arr[arr.size() - 1] = 0;
        for (int i = arr.size() - 2; i >= 0; i--) {
            if (arr[i] % 2 == 0) {
                arr[i] = arr[i+1];
            }
            else {
                arr[i] = 1 ^ arr[i+1];
            }
        }
        return arr[0];
    }
};
