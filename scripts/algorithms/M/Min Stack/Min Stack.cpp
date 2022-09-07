// Runtime: 29 ms (Top 73.41%) | Memory: 16.5 MB (Top 10.27%)
class MinStack {
public:
    stack<int> stk;
    stack<int> minstk;

    MinStack() {
      //leave empty because we don't need to initialise an object while it being created
    }

    void push(int val) {
        //---------------Push in original stack------------------------------
        stk.push(val);
        //-------Put always minimum element to MIN stack--------------
        if(minstk.size()==0)
            minstk.push(val);
        else{
            if(minstk.top()<val)
                minstk.push(minstk.top());
            else
                minstk.push(val);
        }
    }

    void pop() {
        stk.pop();
        minstk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minstk.top();
    }
};
