class Cashier {
public:
    int nn = 0;
    double dis = 0;
    vector<int> pro;
    vector<int> pri;
    int currCustomer = 0; //Declaring these variables here to use it in other fxns as well
    
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        nn = n;
        dis = discount;
        pro = products;
        pri = prices; //Assigning given values to our created variables
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        currCustomer++; //Increasing customer count
        double bill = 0; //Bill anount set to 0
        for(int i = 0; i < product.size(); i++){ //Iterating over every product
            int proId = 0; 
            
            while(pro[proId] != product[i]) proId++; //Finding product ID index
            
            bill = bill + (amount[i]*pri[proId]); //Adding total amount to bill
        }
        
        if(currCustomer == nn){ //Checking if the customer is eligible for discount
            bill = bill * (1 - dis/100); //Giving discount
            currCustomer = 0; //Setting customer count to 0 so next third person can have discount
        }
        return bill; //Returning final bill amount
    }
};

