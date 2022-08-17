class Cashier {
    private Map<Integer, Integer> catalogue;
    
    private int n;
    private double discount;
    private int orderNumber;
    
    public Cashier(int n, int discount, int[] products, int[] prices) {
        this.catalogue = new HashMap<>();
        
        for (int i = 0; i < prices.length; i++) {
            this.catalogue.put(products[i], prices[i]);
        }
        
        this.n = n;
        this.discount = ((double) 100 - discount)/100;
        this.orderNumber = 0;
    }
    
    public double getBill(int[] product, int[] amount) {
        this.orderNumber++;
        
        double bill = 0.0;
        for (int i = 0; i < amount.length; i++) {
            int p = product[i];
            int price = this.catalogue.get(p);
            bill += price*amount[i];
        }
        
        if (this.orderNumber % n == 0)
            bill *= this.discount;
        
        return bill;
    }
}

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj.getBill(product,amount);
 */
