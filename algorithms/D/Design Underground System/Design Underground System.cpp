typedef pair<string, int> PSI;
typedef pair<string, string> PSS;
typedef vector<int> VI;
typedef vector<PSI> VPSI;
typedef map<PSS, VI> HPSSVI;
typedef map<int, VPSI> HIVPSI;

class UndergroundSystem {
    HPSSVI schedule;
    HIVPSI customer;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        customer[id].push_back(make_pair(stationName, t));
    }
    
    void checkOut(int id, string stationName, int t) {
        auto it=customer.find(id);
        int idx = it->second.size()-1;
        schedule[{it->second[idx].first, stationName}].push_back(t - it->second[idx].second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double sum=0.0;
        int s=schedule[{startStation,endStation}].size();
        auto it=schedule.find({startStation,endStation});
        for(int i=0;i<s;i++)
            sum += schedule[{startStation,endStation}][i];
        return sum/s;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
