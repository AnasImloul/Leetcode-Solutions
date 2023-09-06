// Runtime: 603 ms (Top 88.8%) | Memory: 180.29 MB (Top 72.2%)

class Solution {
public:
    struct TrieNode {
        //trie with max 2 child, not taking any bool or 26 size value because no need
        TrieNode* one;
        TrieNode* zero;
    };
    void insert(TrieNode* root, int n) {
        TrieNode* curr = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;  //it will find 31st bit and check it is 1 or 0
            if (bit == 0) {
                if (curr->zero == nullptr) {   //if 0 then we will continue filling on zero side
                    TrieNode* newNode = new TrieNode();    
                    curr->zero = newNode;  
                }
                curr = curr->zero;   //increase cur to next zero position
            }
            else {
                //similarly if we get 1 
                if (curr->one == nullptr) {
                    TrieNode* newNode = new TrieNode();
                    curr->one = newNode;
                }
                curr = curr->one;
            }
        }
    }
     int findmax(TrieNode* root, int n) {
        TrieNode* curr = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if (bit == 1) {
                if (curr->zero != nullptr) {  //finding complement , if find 1 then we will check on zero side
                    ans += (1 << i); //push values in ans
                    curr = curr->zero;
                }
                else {
                    curr = curr->one;  //if we don't get then go to one's side
                }
            }
            else {
                //similarly on zero side if we get 0 then we will check on 1 s side
                if (curr->one != nullptr) {   
                    ans += (1 << i);
                    curr = curr->one;
                }
                else {
                    curr = curr->zero;
                }
            }
        }
        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        TrieNode* root = new TrieNode();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            insert(root, nums[i]);    //it will make trie by inserting values
        }
        for (int i = 1; i < n; i++) {
            ans = max(ans, findmax(root, nums[i]));  //find the necessary complementory values and maximum store
        }
        return ans;
    }
};