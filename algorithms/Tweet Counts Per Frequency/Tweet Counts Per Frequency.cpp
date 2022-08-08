#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

//less_equal to use it as a multiset
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class TweetCounts {
public:
    unordered_map<string, pbds> tweet;
    TweetCounts() {
        tweet.clear();
    }
    
    void recordTweet(string tweetName, int time) {
        tweet[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int interval;
        if(freq == "minute") interval = 60;
        else if(freq == "hour") interval = 3600;
        else interval = 86400;
        
        vector<int> ans;
		
        for(int i=startTime; i<=endTime; i+=interval)
        {
            int start = i, end = min(endTime, i+interval-1);
            
            //[start - end] or [start - end+1)
            auto low = tweet[tweetName].order_of_key(start);
            auto high = tweet[tweetName].order_of_key(end+1);
            
            ans.push_back(high-low);
        }
        return ans;
    }
};
