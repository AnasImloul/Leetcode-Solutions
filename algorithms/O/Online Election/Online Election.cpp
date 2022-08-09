class TopVotedCandidate {
public:
    vector<int> pref;
    vector<int> glob_times;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = times.size();
        glob_times = times;
        pref.resize(n);
        vector<int> cnt;
        int sz = persons.size();
        cnt.resize(sz+1, 0);
        cnt[persons[0]]++;
        pref[0] = persons[0];
        int maxi = 1;
        int maxi_person = persons[0];
        for(int i = 1; i < n; i++){            
            cnt[persons[i]]++;
            if(cnt[persons[i]] > maxi){
                maxi = cnt[persons[i]];
                maxi_person = persons[i];
            }
            else if(cnt[persons[i]] == maxi){
                maxi_person = persons[i];
            }
            
            pref[i] = maxi_person;
        }
    } 
    
    int q(int t) {
        
        int it = upper_bound(glob_times.begin(), glob_times.end(), t) - glob_times.begin();
        if(it == 0) it++;
        return pref[it-1];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
