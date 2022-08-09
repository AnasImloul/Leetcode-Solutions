
class Solution {
    public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        // Call tryOptions with an initial cost of 0
        return tryOptions(price, special, needs, 0);
    }
    
    // Tries all special offers as well as the possibly just buying all teh remainign elements one by one. 
    private int tryOptions(List<Integer> price, List<List<Integer>> special, List<Integer> needs, int cost) {
        // Base case
        int c = 0;
        for(int i: needs) {
            if(i == 0) {
                c++;
            }
        }
        
        if(c == needs.size()) {
            return cost;
        }
        c = 0;
        for(int i: price) {
            if(i == 0) {
                c++;
            }
        }
        
        if(c == needs.size()) {
            return cost;
        }
        
        HashMap<List<Integer>, List<Integer>> offers = possibleOptions(needs, special);
        
        int min = cost;
        for(int i = 0; i < needs.size(); i++) {
            min += needs.get(i)*price.get(i);
        }
        
        if(offers.isEmpty()) {
            return min;
        }
        
        else {
            
            for(List<Integer> offer: offers.keySet()) {
                min = Integer.min(min, tryOptions(price, special, offers.get(offer), cost + offer.get(offer.size()-1)));
            }
            
            return min;
        }
    }
    
    // Checks which of the special offers can be used and returns a hashmap where the key is the offer that can be used and value is the "needs<>" list of that particular offer was used.
    // The "needs<>" is calculated here so it can be used to make the next call to the recursive function.
    private HashMap<List<Integer>, List<Integer>> possibleOptions(List<Integer> needs, List<List<Integer>> special) {
        HashMap<List<Integer>, List<Integer>> map = new HashMap<List<Integer>, List<Integer>>();
        
        for(List<Integer> offer: special) {
            boolean canUse = true;
            List<Integer> tempNeeds = new ArrayList<Integer>(needs);
            
            for(int i = 0; i < needs.size(); i++) {
                if(needs.get(i) < offer.get(i)) {
                    canUse = false;
                    break;
                }
                else {
                    tempNeeds.set(i, tempNeeds.get(i)-offer.get(i));
                }
            }
            
            if(canUse) {
                map.put(offer, tempNeeds);
            }
        }
        
        return map;
    }
}
