// Runtime: 99 ms (Top 93.75%) | Memory: 76.80 MB (Top 6.6%)

class Cashier {
    private final int[] prices;
    private final int n;
    private final int discount;
    private int customerNumber;

    public Cashier(int n, int discount, int[] products, int[] prices) {
        this.prices = new int[200];

        for(int i = 0; i < products.length; ++i)
            this.prices[products[i] - 1] = prices[i];

        this.n = n;
        this.discount = discount;
        this.customerNumber = 1;
    }
    
    public double getBill(int[] product, int[] amount) {
        double sum = 0;

        for(int i = 0; i < product.length; ++i)
            sum += this.prices[product[i] - 1] * amount[i];

        if(this.customerNumber != 0 && this.customerNumber % n == 0)
            sum *= (double) (100 - this.discount) / 100;

        this.customerNumber++;

        return sum;
    }
}

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj.getBill(product,amount);
 */
