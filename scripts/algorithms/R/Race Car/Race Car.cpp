// Runtime: 27 ms (Top 58.02%) | Memory: 9.5 MB (Top 46.80%)
struct Position {
    long long int pos;
    long long int speed;
    long long int moves;

    Position(int pos, int speed, int moves) {
        this -> pos = pos;
        this -> speed = speed;
        this -> moves = moves;
    }
};

class Solution {
public:
    int racecar(int target) {
        queue<Position> q;
        Position p(0, 1, 0);
        q.push(p);

        set<pair<long long int, long long int>> s;

        while(!q.empty()) {
            Position u = q.front();
            q.pop();

            if(u.pos == target) return u.moves;

            if(s.find({u.pos, u.speed}) != s.end()) continue;
            else {
                s.insert({u.pos, u.speed});

                // only cases when you might need to move backwards
                if((u.pos + u.speed > target && u.speed > 0) ||
                   (u.pos + u.speed < target && u.speed < 0)) {
                    long long int speed = u.speed > 0 ? -1 : 1;
                    Position bkwd(u.pos, speed, u.moves + 1);
                    q.push(bkwd);
                }

                Position fwd(u.pos + u.speed, 2 * u.speed, u.moves + 1);
                q.push(fwd);
            }
        }

        return -1;
    }
};