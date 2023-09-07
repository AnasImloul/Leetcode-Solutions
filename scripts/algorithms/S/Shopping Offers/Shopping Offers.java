// Runtime: 549 ms (Top 11.6%) | Memory: 43.58 MB (Top 33.0%)

class Solution {
    public static int fun(int index,List<Integer> price,List<List<Integer>> special, List<Integer> needs){
        // Base 
        if(index < 0){
            int addAmount = 0;
            for(int i=0;i<needs.size();i++){
                addAmount += (needs.get(i) * price.get(i));
            }
            return addAmount;
        }

        // Not Take Offer
        int notTakeOffer = 0 + fun(index-1,price,special,new ArrayList<>(needs));

        // Take Offer 
        int takeOffer = 1000000000;
        if(canTakeOffer(special.get(index),new ArrayList<>(needs))){
            List<Integer> current_special = special.get(index);
            for(int i=0;i<current_special.size()-1;i++){
                int current_need = needs.get(i);
                int update = current_special.get(i);
                needs.set(i,current_need-update);
            }
            takeOffer = current_special.get(current_special.size()-1) + fun(index,price,special,new ArrayList<>(needs));
        }
        return Math.min(notTakeOffer,takeOffer);
    }

    public static boolean canTakeOffer(List<Integer> current_special, List<Integer> needs){
        boolean canTake = true;
        for(int i=0;i<current_special.size()-1;i++){
            if(needs.get(i) < current_special.get(i)){
                canTake = false;
                break;
            }
        }
        return canTake;
    }

    public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        int items = price.size();
        int offers = special.size();
        return fun(offers-1,price,special,needs);
    }
}