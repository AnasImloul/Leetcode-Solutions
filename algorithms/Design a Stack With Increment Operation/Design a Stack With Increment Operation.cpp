class CustomStack {
    int *data;
    int nextIndex;
    int capacity;
public:
    CustomStack(int maxSize) {
        data = new int[maxSize];
        nextIndex = 0;
        capacity = maxSize;
    }
    
    void push(int x) {
        if(nextIndex == capacity){
            return;
        }
        data[nextIndex] = x;
        nextIndex++;
    }
    
    int pop() {
        if(nextIndex == 0){
            return -1;
        }
        int temp = data[nextIndex-1];
        nextIndex--;
        return temp;
    }
    
    void increment(int k, int val) {
		//loop will run upto nextIndex if k >= nextIndex else runt upto k only
        int n = (k >= nextIndex) ? nextIndex : k;
        for(int i = 0; i < n; i++){
            data[i]  = data[i] + val;
        }
    }
};
