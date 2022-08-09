class UndergroundSystem {
    HashMap<Integer, Travel> travelMap;
    HashMap<String, Averages> avgMap;
    
    public UndergroundSystem() {
        travelMap = new HashMap();
        avgMap = new HashMap();
    }
    
    public void checkIn(int id, String stationName, int t) {
        Travel journey = new Travel(id, t, stationName);
        travelMap.put(id, journey);
    }
    
    public void checkOut(int id, String stationName, int t) {
        Travel journey = travelMap.get(id);
        
        int journeyTime = t - journey.checkIn;
        String key = journey.startStation + "," + stationName;
        
        Averages average = avgMap.containsKey(key) ? avgMap.get(key) : new Averages();
        average.updateAverage(journeyTime);
        
        avgMap.put(key, average);
    }
    
    public double getAverageTime(String startStation, String endStation) {
        String key = startStation + "," + endStation;
        Averages average = avgMap.get(key);
        
        int totalTrips = average.totalTrips;
        double totalJourneytime = average.totalTraveltime;
        double averageTime = totalJourneytime/totalTrips;
        
        return averageTime;
    }
    
    class Travel{
        int id;
        String startStation;
        int checkIn;
        
        public Travel(int id, int checkIn, String startStation)
        {
            this.id = id;
            this.checkIn = checkIn;
            this.startStation = startStation;
        }
    }
    
    class Averages{
        double totalTraveltime;
        int totalTrips;
        
        public Averages()
        {
            totalTraveltime = 0;
            totalTrips = 0;
        }
        
        private void updateAverage(int journeyTime)
        {
            totalTraveltime += journeyTime;
            totalTrips++;
        }
    }
}

