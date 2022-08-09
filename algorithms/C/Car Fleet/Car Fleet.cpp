class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();
        vector<pair<int,int>> cars;
        
        for(int i=0; i<n; i++)cars.push_back({position[i], speed[i]});
        
        sort(cars.begin(),cars.end());
        
        int start=0;
        int mid=0;
        int fleet = n;
        
        double times[n];
        
        for(int i=n-1; i>=0; i--){
            times[i] =((double) (target-cars[i].first)/cars[i].second);
            if(i<n-1)times[i] = max(times[i],times[i+1]);
        }
        
        while(mid<n){            
            double timeA = times[start];
            double timeB = times[mid];
            //cout<<timeA<<" "<<timeB<<endl;
            if(mid-start+1 == 2){
                if(timeA<=timeB)fleet--;
                start++;
            }
            mid++;
        }
        
        return fleet;
        
    }
};
