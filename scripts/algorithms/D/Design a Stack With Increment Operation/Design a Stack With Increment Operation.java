// Runtime: 8 ms (Top 70.94%) | Memory: 50.6 MB (Top 37.77%)

class CustomStack {

    int[] stack;
    int top;

    public CustomStack(int maxSize) {

        //intialise the stack and the top
         stack= new int[maxSize];
        top=-1;
    }

    public void push(int x) {

        // if the stack is full just skip
        if( top==stack.length-1) return;

        //add to the stack
        top++;
        stack[top]=x;
    }

    public int pop() {

        //if stack is empty return -1
        if( top==-1) return -1;

        //remove/pop the top element
        top--;
        return stack[top+1];

    }

    public void increment(int k, int val) {

        //got to increment the min of the elements present in the stack and k
        int n= Math.min(top+1,k);

        for( int i=0; i<n ; i++){
            stack[i]+=val;
        }

    }
}