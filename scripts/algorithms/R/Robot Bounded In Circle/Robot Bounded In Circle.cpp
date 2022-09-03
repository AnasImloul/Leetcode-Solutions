// Runtime: 0 ms (Top 100.00%) | Memory: 6.2 MB (Top 51.28%)
class Solution {
public:
    bool isRobotBounded(string instructions) {
        char direction = 'N';
        int x = 0, y = 0;
        for (char &instruction: instructions) {
            if (instruction == 'G') {
                if (direction == 'N') y++;
                else if (direction == 'S') y--;
                else if (direction == 'W') x--;
                else x++;
            } else if (instruction == 'L') {
                if (direction == 'N') direction = 'W';
                else if (direction == 'S') direction = 'E';
                else if (direction == 'W') direction = 'S';
                else direction = 'N';
            } else {
                if (direction == 'N') direction = 'E';
                else if (direction == 'S') direction = 'W';
                else if (direction == 'W') direction = 'N';
                else direction = 'S';
            }
        }
        return (x == 0 && y == 0) || direction != 'N';
    }
};