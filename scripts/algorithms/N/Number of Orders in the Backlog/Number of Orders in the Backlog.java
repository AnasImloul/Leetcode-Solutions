class Solution {
    
    PriorityQueue<Order> buyBackLog;
    PriorityQueue<Order> sellBackLog;
    
    static int MOD = 1_000_000_007;
    
    
    public int getNumberOfBacklogOrders(int[][] orders) {
        
        //max heap, heapify on price
        buyBackLog = new PriorityQueue<Order>((a, b) -> (b.price - a.price));
        //min heap, heapify on price
        sellBackLog = new PriorityQueue<Order>((a, b) -> (a.price - b.price));
        
        
        //handle all order
        for(int[] order : orders){
            int price     = order[0];
            int quantity  = order[1];
            int orderType = order[2];
            
            if(orderType == 0){
                //buy order 
                handleBuyOrder(new Order(price, quantity));
                
            }else if(orderType == 1){ 
                //sell order
                handleSellOrder(new Order(price, quantity));
            }
        }
        
        long counts = 0L;
        
        //count buy backlog
        while(!buyBackLog.isEmpty()){
            counts += buyBackLog.remove().quantity; 
            counts %= MOD;
        }
        
        //count sell backlog
        while(!sellBackLog.isEmpty()){
            counts += sellBackLog.remove().quantity; 
            counts %= MOD;
        }
        
        
        return (int) (counts % MOD);
    }
    
    
    
    
    private void handleBuyOrder(Order buyOrder){
        //just add buyorder, if there is no sell back log
        if(sellBackLog.isEmpty()){
            buyBackLog.add(buyOrder);
            return;
        }
        
        
        while(!sellBackLog.isEmpty() && buyOrder.price >= sellBackLog.peek().price && buyOrder.quantity > 0){
            //selloder with minumum price
            Order sellOrder = sellBackLog.remove();
            
            if(buyOrder.quantity >= sellOrder.quantity){
                buyOrder.quantity -= sellOrder.quantity;
                sellOrder.quantity = 0;
            } else {
                //decrement sell order, add remaining sellorder
                sellOrder.quantity -= buyOrder.quantity;
                sellBackLog.add(sellOrder);
                
                buyOrder.quantity = 0;
            }
        }
        
        //add reaming buyorder
        if(buyOrder.quantity > 0){
            buyBackLog.add(buyOrder);
        }
    }
    
    
    private void handleSellOrder(Order sellOrder){
        //just add sell order, if there is no buy backlog
        if(buyBackLog.isEmpty()){
            sellBackLog.add(sellOrder);
            return;
        }
        
        
        while(!buyBackLog.isEmpty() && buyBackLog.peek().price >= sellOrder.price && sellOrder.quantity > 0){
            //buy order with maximum price
            Order buyOrder = buyBackLog.remove();
            
            if(sellOrder.quantity >= buyOrder.quantity){
                sellOrder.quantity -= buyOrder.quantity;
                buyOrder.quantity = 0;
                
            }else{
                //decrement buy order quantity, add remaining buyorder
                buyOrder.quantity -= sellOrder.quantity;
                buyBackLog.add(buyOrder);
                
                sellOrder.quantity = 0;
            }
        }
        
        //add remaining sell order
        if(sellOrder.quantity > 0){
            sellBackLog.add(sellOrder);
        }
    }
}

class Order{
    int price;
    int quantity;
    
    public Order(int price, int quantity){
        this.price = price;
        this.quantity = quantity;
    }
}
