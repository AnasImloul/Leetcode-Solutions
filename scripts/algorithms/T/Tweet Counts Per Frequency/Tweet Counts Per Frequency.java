// Runtime: 351 ms (Top 16.84%) | Memory: 93.3 MB (Top 14.74%)
class TweetCounts {
    Map<String, List<Integer>> map;
    public TweetCounts() {
        map = new HashMap<>();
    }

    public void recordTweet(String tweetName, int time) {
        map.computeIfAbsent(tweetName, v->new ArrayList<>()).add(time);
    }

    public List<Integer> getTweetCountsPerFrequency(String freq, String tweetName, int startTime, int endTime) {
        List<Integer> res = new ArrayList<>();
        if(map.containsKey(tweetName)) {
            Collections.sort(map.get(tweetName));
            while(startTime<=endTime) {
                int interval = Freq.valueOf(freq).getVal();
                int end = Math.min(startTime+interval-1, endTime); // need this to handle the last interval
                res.add(getFreq(map.get(tweetName), startTime, end));
                startTime=end+1; // ex: for minute, the interval is 60 so our end is 59. The next startTime is end+1
            }
        }
        return res;
    }

    public int getFreq(List<Integer> list, int start, int end) {
        int st = Collections.binarySearch(list, start);
        if(st<0) {
            st = (st+1)*-1; // our exact start time might not be in the list, to get the 1st timestamp greater than start
        }
        int en = Collections.binarySearch(list, end);
        if(en<0) {
            en = (en+2)*-1; // our exact end time might not be in the list, to get the last timestamp just smaller than end
        }

        return en-st+1; // the freq count
    }
}

 enum Freq {
    minute(60), hour(3600), day(86400);
    Map<Freq, Integer> map = new HashMap<>();
    Freq(int val) {
        map.put(this, val);
    }

    public int getVal() {
         return map.get(this);
     }

}

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts obj = new TweetCounts();
 * obj.recordTweet(tweetName,time);
 * List<Integer> param_2 = obj.getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
