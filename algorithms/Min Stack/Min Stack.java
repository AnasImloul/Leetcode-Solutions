//Just check the ind value that's it
class MinStack {
    int ind=-1;
    private ArrayList<Integer> arr;
    public MinStack() {
        arr=new ArrayList();
    }
    
    public void push(int val) {
        arr.add(val);
        ind++;
    }
    
    public void pop() {
            arr.remove(ind);
            ind--;
    }
    
    public int top() {
        return arr.get(ind);
    }
    
    public int getMin() {
        int mini=Integer.MAX_VALUE;
        for(int i=0;i<arr.size();i++){
            int val=arr.get(i);
            if(val<mini){
                mini=val;
            }
        }
        return mini;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */