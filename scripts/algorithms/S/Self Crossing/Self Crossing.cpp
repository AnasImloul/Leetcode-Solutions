class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        if (distance.size() <= 3) return false; //only can have intersection with more than 4 lines

        distance.insert(distance.begin(), 0); //for the edge case: line i intersect with line i-4 at (0, 0)
        for (int i = 3; i < distance.size(); i++) {
            //check line i-3
            if (distance[i - 2] <= distance[i] && distance[i - 1] <= distance[i - 3]) return true;

            //check line i-5
            if (i >= 5) {
                if (distance[i - 1] <= distance[i - 3] && distance[i - 1] >= distance[i - 3] - distance[i - 5] 
                    && distance[i - 2] >= distance[i - 4] && distance[i - 2] <= distance[i - 4] + distance[i])
                    return true;
            }
        }
        return false;
    }
};
