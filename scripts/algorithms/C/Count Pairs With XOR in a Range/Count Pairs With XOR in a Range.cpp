// Runtime: 517 ms (Top 29.80%) | Memory: 71.3 MB (Top 76.82%)
struct Node {
    Node* arr[2];
    int count = 0;

    bool contains(int bitNo) {
        return arr[bitNo] != NULL;
    }

    void put(int bitNo, Node* newNode) {
        arr[bitNo] = newNode;
    }

    Node* getNext(int bitNo) {
        return arr[bitNo];
    }

    int getCount(int bitNo) {
        return arr[bitNo]->count;
    }

    void setCount(int bitNo) {
        arr[bitNo]->count++;
    }
};

class Solution {
public:

    Node* root = new Node();

    void insert(int num) {
        Node* temp = root;

        for(int bit=15; bit>=0; bit--) {
            int bitVal = (bool)(num & (1<<bit));

            if(!temp->contains(bitVal)) {
                temp->put(bitVal, new Node());
            }
            temp->setCount(bitVal);
            temp = temp->getNext(bitVal);
        }
    }

    int getPairs(int num, int k) {
        Node* temp = root;

        int cntPairs = 0;

        for(int bit=15; bit>=0 && temp; bit--) {
            int bit_num = (bool)(num & (1<<bit));
            int bit_k = (bool)(k & (1<<bit));

            if(bit_k) {
                if(temp->contains(bit_num)) {
                    cntPairs += temp->getCount(bit_num);
                }
                if(temp->contains(1 - bit_num)) {
                    temp = temp->getNext(1 - bit_num);
                }
                else break;
            }
            else if(temp->contains(bit_num)) {
                temp = temp->getNext(bit_num);
            }
            else {
                break;
            }
        }
        return cntPairs;
    }

    int countPairs(vector<int>& nums, int low, int high) {

        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++) {
            cnt += getPairs(nums[i], high+1) - getPairs(nums[i], low);
            insert(nums[i]);
        }
        return cnt;
    }
};