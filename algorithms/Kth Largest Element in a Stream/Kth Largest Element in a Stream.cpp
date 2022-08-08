class KthLargest {
    
    int k;
    priority_queue<int, vector<int>, greater<int>> minheap;
    int n;
    
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        this->n=nums.size();
        
//         push the initial elements in the heap
        for(auto x : nums){
            minheap.push(x);
        }
        
//         if the no. of elements are greater than k then remove them
        while(n>k){
            minheap.pop();
            n--;
        }
    }    
    
    int add(int val) {
        
//         if heap is empty or no. of elements are less than k then add the input
        if(minheap.empty() || n<k){
            minheap.push(val);
            this->n=n+1;
        }
//         else compare it with top
        else{
            int minn=minheap.top();
//             if the input is greater than top
            if(minn<val){
                minheap.pop();
                minheap.push(val);
            }
        }
//         at any point of time top of the heap is required ans
        return minheap.top();
        
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
