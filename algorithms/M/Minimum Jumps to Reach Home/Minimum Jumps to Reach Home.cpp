#define B_MASK 14

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        
        int g{std::gcd(a, b)};
        
        if(x % g) return -1; // No non-negative integers c1,c2 such that c1*a - c2*b == x
        int max_{x};
        std::bitset<1<<15> invalid;
        for(const auto &n: forbidden) max_ = std::max(max_, n), invalid.set(n);
        b
        int16_t stop{(int16_t)(max_+b+a)};
        
        /* Bidirectional BFS, good for when both start and end states are known, and the edge definition is "bidirectional"
		   aka for edge "a <--> b", at "a" you know you can go to "b", and at "b" you know you can come from "a".
		  The definition need not be symmetric, such as in this problem. */
        std::queue<std::pair<int16_t,int16_t>> qS, qE;
        int stepS{0}, stepE{0};
        qS.emplace(0,0), qS.emplace(-1,-1);
        qE.emplace(x,0), qE.emplace(x, 1), qE.emplace(-1,-1);
        
        std::vector<int16_t> visitedS(1<<15, -1), visitedE(1<<15, -1);
        
        bool useS{true};
        while(!qS.empty() || !qE.empty()) {
            if(useS) {
                auto [loc, bc]{qS.front()}; qS.pop();
                if(loc == -1) {
                    if(!qS.empty()) ++stepS, qS.emplace(-1,-1);
                    if(qS.empty() || qS.size() >= qE.size() && !qE.empty()) useS = false;
                    continue;
                }

                int16_t key = {(int16_t)(loc|(bc<<B_MASK))};
                if(visitedS[key] != -1) continue;
                visitedS[key] = stepS;
                if(visitedE[key] != -1) return stepS + visitedE[key];
                
                if(loc+a <= stop && !invalid[loc+a] && visitedS[(key+a)%(1<<B_MASK)] == -1) qS.emplace(loc+a, 0);
                if(!bc && loc-b > 0 && !invalid[loc-b] && visitedS[(key-b)|(1<<B_MASK)] == -1) qS.emplace(loc-b, 1);
                    
            } else {
                auto [loc, bc]{qE.front()}; qE.pop();
                if(loc == -1) {
                    if(!qE.empty()) ++stepE, qE.emplace(-1,-1);
                    if(qE.empty() || qE.size() >= qS.size() && !qS.empty()) useS = true;
                    continue;
                }
                
                int16_t key = {(int16_t)(loc|(bc<<B_MASK))};
                if(visitedE[key] != -1) continue;
                visitedE[key] = stepE;
                if(visitedS[key] != -1) return stepE + visitedS[key];

                if(loc-a >= 0 && !invalid[loc-a] && visitedE[key-a] == -1) qE.emplace(loc-a, bc);
                if(bc && loc+b <= stop && !invalid[loc+b] && visitedE[(key+b)%(1<<B_MASK)] == -1) qE.emplace(loc+b, 0);
            }
            
        }
        
        return -1; 
        
    }
};
