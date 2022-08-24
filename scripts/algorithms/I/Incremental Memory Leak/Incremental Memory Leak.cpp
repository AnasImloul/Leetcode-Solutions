// Runtime: 8 ms (Top 53.78%) | Memory: 6 MB (Top 85.78%)
class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int time = 1;
        while (max(memory1, memory2) >= time) {
            if (memory1 >= memory2) {
                memory1 -= time;
            } else {
                memory2 -= time;
            }
            ++time;
        }
        return {time, memory1, memory2};
    }
};