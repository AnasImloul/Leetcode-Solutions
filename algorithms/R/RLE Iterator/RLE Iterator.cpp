/*
    https://leetcode.com/problems/rle-iterator/
    
    next(): TC: O(n) in total over n calls
    Idea is to use two pointers are this.
    We maintain a ptr that points to the current element bucket. For a given n
    first iterate through the buckets which have freq < n, this means they won't have the 
    last element.
    Once the iteration ends, either we will have no elements left or we will be on the bucket
    with freq >= n. Update the iteration ptr accordingly.
*/
class RLEIterator {
    vector<int> encoding;
    // Tracks the even indices
    int curr = -1;
    // Tracks the total length of array
    int len = 0;
public:
    RLEIterator(vector<int>& encoding) {
        this->encoding = encoding;
        curr = 0;
        len = encoding.size();
    }
    
    int next(int n) {
        // Skip all the number buckets which will be completely exhausted
        // and we will still have some n left i.e n > 0
        for(; curr < len && n > 0 && encoding[curr] < n; curr += 2) {
            // Skip the buckets with 0 frequency
            if(encoding[curr] == 0)
                continue;
            n -= encoding[curr];
        }
        
        int element = -1;
        //  If we still have elements left with non zero frequency then
        // the current bucket's frequency will be >= leftover n
        if(curr < len && encoding[curr] >= n) {
            // Exhaust the leftover n
            encoding[curr] -= n;
            element = encoding[curr+1];
            // If the bucket is completely exhausted, then move the iterator ptr to next element
            // for the next function call
            if(encoding[curr] == 0)
                curr += 2;
        }
        return element;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
