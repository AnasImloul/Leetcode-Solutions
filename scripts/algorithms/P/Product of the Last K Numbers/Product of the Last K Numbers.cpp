// Runtime: 164 ms (Top 94.71%) | Memory: 69.9 MB (Top 70.96%)
class ProductOfNumbers {
private:
    vector<int> prefixProduct;
public:
    ProductOfNumbers() {

    }

    void add(int num) {
        if(num == 0){
            prefixProduct.clear();
            return;
        }
        if(prefixProduct.empty()){
            prefixProduct.push_back(num);
        }else{
            int prod = prefixProduct[prefixProduct.size() - 1] * num;
            prefixProduct.push_back(prod);
        }

    }
    int getProduct(int k) {
        if(k > prefixProduct.size()){
            return 0;
        }
        int size = prefixProduct.size();
        if(k == size) return prefixProduct[size - 1];
        int prod = prefixProduct[size - 1] / prefixProduct[size - k - 1];
        return prod;

    }
};