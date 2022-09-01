// Runtime: 10 ms (Top 30.51%) | Memory: 45.4 MB (Top 20.46%)
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        Map<Integer, Integer> destinationToPassengers = new TreeMap<>();
        for(int[] trip : trips) {
            int currPassengersAtPickup = destinationToPassengers.getOrDefault(trip[1], 0);
            int currPassengersAtDrop = destinationToPassengers.getOrDefault(trip[2], 0);
            destinationToPassengers.put(trip[1], currPassengersAtPickup + trip[0]);
            destinationToPassengers.put(trip[2], currPassengersAtDrop - trip[0]);
        }

        int currPassengers = 0;
        for(int passengers : destinationToPassengers.values()) {
            currPassengers += passengers;

            if(currPassengers > capacity) {
                return false;
            }
        }
        return true;
    }
}