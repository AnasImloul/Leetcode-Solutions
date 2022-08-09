class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
       // Initialize Prices arr with infinity & src 0
        int[] prices = new int[n];
        for(int i = 0; i < n; i++)
            prices[i] = Integer.MAX_VALUE;
        prices[src] = 0;
        
        // Build Adj list {key: src | val: dst+price}
        Map<Integer, List<int[]>> flightsMap = new HashMap<>();
        for(int[] flight : flights){
            int flightSrc = flight[0];
            int flightDst = flight[1];
            int flightPrice = flight[2];
            
            List<int[]> flightsList = flightsMap.getOrDefault(flightSrc, new ArrayList<>());
            flightsList.add(new int[]{flightDst, flightPrice});
            flightsMap.put(flightSrc, flightsList);
        }
        
        // Start Bellman ford Algo
        Queue<Integer> q = new LinkedList<>();
        q.offer(src);
        while(k >= 0 && !q.isEmpty()){
            int[] tempPrices = new int[n];                  // Temporary Prices Arr
            for(int i = 0; i < n; i++)
                tempPrices[i] = prices[i];
            
            int size = q.size();
            for(int i = 0; i < size; i++){
                int curSrc = q.poll();
                int curPrice = prices[curSrc];
                List<int[]> curFlightsList = flightsMap.getOrDefault(curSrc, new ArrayList<>());
                for(int[] flight : curFlightsList){
                    int flightDst = flight[0];
                    int flightPrice = flight[1];
                    int newPrice = curPrice + flightPrice;
                    if(newPrice < tempPrices[flightDst]){
                        tempPrices[flightDst] = newPrice;
                        q.offer(flightDst);
                    }
                }
            }
            for(int i = 0; i < n; i++)                    // Copy Temp Prices to Original Price Arr
                prices[i] = tempPrices[i];
            k--;
        }
        int totalPrice = prices[dst];
        return totalPrice == Integer.MAX_VALUE? -1 : totalPrice;
    }
}
