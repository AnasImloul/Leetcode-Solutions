// Runtime: 89 ms (Top 60.33%) | Memory: 42.1 MB (Top 68.87%)
var isRobotBounded = function(instructions) {
        // north = 0, east = 1, south = 2, west = 3
        let directions = [[0, 1], [1, 0], [0, -1], [-1, 0]];
        // Initial position is in the center
        let x = 0, y = 0;
        // facing north
        let idx = 0;
        let movements = [...instructions];

        for (let move of movements) {
            if (move == 'L')
                idx = (idx + 3) % 4;
            else if (move == 'R')
                idx = (idx + 1) % 4;
            else {
                x += directions[idx][0];
                y += directions[idx][1];
            }
        }

        // after one cycle:
        // robot returns into initial position
        // or robot doesn't face north
        return (x == 0 && y == 0) || (idx != 0);
};