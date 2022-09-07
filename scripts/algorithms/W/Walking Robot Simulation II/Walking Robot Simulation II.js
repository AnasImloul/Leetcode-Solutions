// Runtime: 555 ms (Top 33.33%) | Memory: 62.5 MB (Top 46.67%)
const EAST = "East";
const NORTH = "North";
const WEST = "West";
const SOUTH = "South";

const DIRECTIONS = [EAST, NORTH, WEST, SOUTH];
const ORIGIN = [0,0];

/**
 * @param {number} width
 * @param {number} height
 */
var Robot = function(width, height) {
    this.width = width;
    this.height = height;

    this.path = []; // circular buffer of entire path of robot
    this.dirAtSquare = []; // dir robot is facing at each square
    this.currentPos = -1;

    this.preprocess();
};

/**
 * Loop around the map once and store the path into a circular buffer.
 *
 * (0,0) is set to face SOUTH. The only time it is EAST is at the beginning
 * if the robot didn't move at all.
 *
 * @return {void}
 */
Robot.prototype.preprocess = function() {
    // go right
    for (let i = 1; i < this.width; i++) {
        this.path.push([i, 0]);
        this.dirAtSquare.push(0);
    }

    // go up
    const xMax = this.width - 1;
    for (let i = 1; i < this.height; i++) {
        this.path.push([xMax, i]);
        this.dirAtSquare.push(1);
    }

    // go left
    const yMax = this.height - 1;
    for (let i = xMax - 1; i >= 0; i--) {
        this.path.push([i, yMax]);
        this.dirAtSquare.push(2);
    }

    // go down
    const xMin = 0;
    for (let i = yMax - 1; i >= 0; i--) {
        this.path.push([xMin, i]);
        this.dirAtSquare.push(3);
    }
}

/**
 * @param {number} num
 * @return {void}
 */
Robot.prototype.step = function(num) {
    this.currentPos += num;
};

/**
 * @return {number[]}
 */
Robot.prototype.getPos = function() {
    return this.currentPos === -1
        ? ORIGIN // we haven't moved
        : this.path[this.currentPos % this.path.length];
};

/**
 * @return {string}
 */
Robot.prototype.getDir = function() {
    return this.currentPos === -1
        ? DIRECTIONS[0] // we haven't moved
        : DIRECTIONS[this.dirAtSquare[this.currentPos % this.dirAtSquare.length]];
};

/**
 * Your Robot object will be instantiated and called as such:
 * var obj = new Robot(width, height)
 * obj.step(num)
 * var param_2 = obj.getPos()
 * var param_3 = obj.getDir()
 */