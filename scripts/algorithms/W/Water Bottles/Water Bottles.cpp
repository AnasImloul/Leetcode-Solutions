class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ex=0,remain=0,res=numBottles;
        while(numBottles>=numExchange){
             remain=numBottles%numExchange;
          numBottles=numBottles/numExchange;
           res+=numBottles;
            numBottles+=remain;
          cout<<numBottles<<" ";
        }
        return res;
    }
};
