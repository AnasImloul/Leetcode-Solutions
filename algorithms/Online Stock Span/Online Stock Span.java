class Pair{
    int stock;
    int span;
    
    public Pair(int stock, int span){
        this.stock = stock;
        this.span = span;
    }
    
}
class StockSpanner {
    Stack<Pair> stack;
    public StockSpanner() {
        stack = new Stack<>();
    }
    
    public int next(int price) {
        int span = 1;
        while(!stack.isEmpty() && stack.peek().stock <= price){
           Pair pStock = stack.pop();
           span += pStock.span ;
        }
        stack.push(new Pair(price, span));
        return span;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
