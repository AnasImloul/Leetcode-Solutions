class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        
        int n = asteroids.size();
        sort(begin(asteroids), end(asteroids));
        
        long long planetMass = mass;
        
        for(auto& asteroid : asteroids) {
            if(planetMass < asteroid) return false; 
			planetMass += asteroid;
        }
        return true;
    }
};
