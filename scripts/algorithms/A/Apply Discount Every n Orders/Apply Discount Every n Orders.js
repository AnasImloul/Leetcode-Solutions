// Runtime: 324 ms (Top 7.14%) | Memory: 58.2 MB (Top 21.43%)
var Cashier = function(n, discount, products, prices) {
    this.n = n;
    this.cc = 0;
    this.discount = (100 - discount) / 100;
    this.products = new Map();
    const len = products.length;
    for(let i = 0; i < len; i++) {
        this.products.set(products[i], prices[i]);
    }
};

Cashier.prototype.getBill = function(product, amount) {
    let total = 0, len = product.length;
    for(let i = 0; i < len; i++) {
        total += amount[i] * this.products.get(product[i]);
    }
    this.cc++;
    if(this.cc % this.n == 0) {
        total = total * this.discount;
        this.cc = 0;
    }
    return total;
};