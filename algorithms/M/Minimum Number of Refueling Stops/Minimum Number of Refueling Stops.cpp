/*

The approach here used is - first cosider the stations which are possible at a particular time and then take the one with maximum fuel that can be filled this ensure that with only one fill up the vehicle will move to furthest distance.

Now there might be case where if we don't fill up from multiple stations ata paritcular time, then it will not be possible to reach end as there might not be any stations at the ending side of the target. 

To handle above case, when such situation arise then we need to take the next max fuel refill that is pissible from the already seen stations.
Like this way keep on taking fuels from stations in decreasing manner.

If at any point of time the queue is empty then, it means we do not have sufficent fuel to reach target.

=> This logic can be implemented by simply using a priority queue where the max fuel station is at top of the queue.


*/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        auto comp = [](vector<int> a, vector<int> b){ return a[1] < b[1]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        int i = 0, distance = startFuel, refillCount = 0;
        while(distance < target ){
            while(i < stations.size() && distance >= stations[i][0]){
                pq.push(stations[i++]);
            }
            if(pq.empty()) return -1;
            distance += pq.top()[1];
            refillCount++;
            pq.pop();
        }
        return refillCount;
    }
};
