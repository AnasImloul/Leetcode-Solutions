// Runtime: 295 ms (Top 61.43%) | Memory: 73.80 MB (Top 71.43%)

var ProductOfNumbers = function() {
  this.products = [];
};

ProductOfNumbers.prototype.add = function(num) {
  if (num == 0) {
    this.products = [];
  } else {
    const N = this.products.length;
    this.products.push(N == 0 ? num : num * this.products[N - 1]);
  }
};

ProductOfNumbers.prototype.getProduct = function(k) {
  const N = this.products.length;
  if (N - k < 0) return 0;
  if (N == k) return this.products[N - 1];
  return this.products[N - 1] / this.products[N - k - 1];
};
