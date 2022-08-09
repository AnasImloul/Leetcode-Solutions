class TrieNode {
public:
    int numOfIndex;
    int sumOfIndex;
    TrieNode* child[2];
    
    TrieNode() : numOfIndex(0), sumOfIndex(0) {
        child[0] = NULL;
        child[1] = NULL;
    }
};
class Solution {
public:
    void addNumber(TrieNode* root, int num, int idx){
        for( int i = 31; i >= 0; i--){
       
            int bit = 1 & (num >> i) ;
        
            if ( root->child[bit] == NULL){
                root->child[bit] = new TrieNode();
            }
            root = root->child[bit];
        }
        root->sumOfIndex += idx;
        root->numOfIndex++;
    }
    int calculateIndexPair(TrieNode* root, int num, int idx){
        for( int i = 31; i >= 0; i--){
            int bit = 1 & (num >> i);
        
            if (root->child[bit] == NULL){
                return 0;
            }
            root = root->child[bit];
        }
        return (((root->numOfIndex) * idx) - (root->sumOfIndex));
    }
    int countTriplets(vector<int>& arr) {
        long long ans=0;
        int XOR = 0;
        TrieNode* root = new TrieNode();
    
        for ( int i = 0 ; i < arr.size(); i++){
            addNumber(root, XOR, i);
            XOR ^= arr[i];
            ans = (ans + calculateIndexPair(root, XOR, i)) % 1000000007;
        }
        return ans;
    }
};
