// Runtime: 69 ms (Top 82.47%) | Memory: 38.40 MB (Top 84.54%)

class TweetCounts {
private:
    unordered_map<string, vector<int>> mp;

public:
    TweetCounts() {
    }
    
    void recordTweet(string tweetName, int time) {
        mp[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        if(freq == "minute"){
            vector<int> ans(((endTime - startTime) / 60) + 1, 0);
            for(int time : mp[tweetName]){
                if(time >= startTime && time <= endTime){
                    int idx = (time - startTime) / 60;
                    ans[idx]++;
                }
            }
            return ans;
        }
        else if(freq == "hour"){
            vector<int> ans(((endTime - startTime) / (60 * 60)) + 1, 0);
            for(int time : mp[tweetName]){
                if(time >= startTime && time <= endTime){
                    int idx = (time - startTime) / (60 * 60);
                    ans[idx]++;
                }
            }
            return ans;
        }
        else{
            vector<int> ans(((endTime - startTime) / (3600 * 24)) + 1, 0);
            for(int time : mp[tweetName]){
                if(time >= startTime && time <= endTime){
                    int idx = (time - startTime) / (60 * 60 * 24);
                    ans[idx]++;
                }
            }
            return ans;
        }
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
