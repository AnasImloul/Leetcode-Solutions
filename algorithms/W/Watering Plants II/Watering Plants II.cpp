class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
     
        int n(plants.size()), res(0), aliceC(capacityA), bobC(capacityB), alice(0), bob(n-1);
        
        while (alice < bob)
        {
            if (alice == bob)
            {
                if (aliceC < plants[alice] and bobC < plants[bob]) res++;
                break;
            }
            if (aliceC < plants[alice]) aliceC = capacityA, res++;
            if (bobC < plants[bob]) bobC = capacityB, res++;
            aliceC -= plants[alice++];
            bobC -= plants[bob--];
        }
        return res;
    }
};
