// Runtime: 178 ms (Top 77.65%) | Memory: 121.20 MB (Top 12.35%)

class Cashier {
public:
    int n;
    int dis;
    unordered_map<int,int>price;
    int idx=0;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n=n;
        this->dis=discount;
        for(int i=0;i<products.size();i++){
            price[products[i]]=prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double res=0;
        idx++;
        for(int i=0;i<product.size();i++){
            res+=(price[product[i]]*amount[i]);
        }
        if(idx%n==0){
            return (res*(100-dis))/100;
        }
        return res;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
