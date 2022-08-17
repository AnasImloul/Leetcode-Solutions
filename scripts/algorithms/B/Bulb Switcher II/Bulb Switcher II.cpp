// Idea / Approach: simulation we need only 4 bulbs 1..4 to cover all cases.
class Solution { // _Simulation
    static unordered_set<uint8_t> simulateStep(const unordered_set<uint8_t>& states, uint8_t mask) {
        auto op1 = [](uint8_t x) { return x ^ 0x0f; };
        auto op2 = [](uint8_t x) { return x ^ 0b1010; };
        auto op3 = [](uint8_t x) { return x ^ 0b0101; };
        auto op4 = [](uint8_t x) { return x ^ 0b1001; };

        unordered_set<uint8_t> res;
        for (auto x : states) {
            res.insert(op1(x) & mask);
            res.insert(op2(x) & mask);
            res.insert(op3(x) & mask);
            res.insert(op4(x) & mask);
        }
        return res;
    }

public:
    int flipLights(int n, int presses) {
        if (presses == 0) {
            return 1;
        }

        uint8_t mask = 0x0F;
        if (n == 1) {
            mask = 1;
        } else if (n == 2) {
            mask = 0b11;
        } else if (n == 3) {
            mask = 0b111;
        }
        unordered_set<uint8_t> reached; // reached states
        reached.insert(0x0F & mask);
		// if presses > 4, then there must be p-4 presses that are cancelling each other, and not
        // creating new states.
        // so we can max it out at 4.
        for (int i = 0; i < min(4, presses); ++i) {
            reached = simulateStep(reached, mask);
        }
        return reached.size();
    }
};
