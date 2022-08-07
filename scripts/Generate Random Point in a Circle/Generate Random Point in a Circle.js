/**
 * @param {number} radius
 * @param {number} x_center
 * @param {number} y_center
 */
var Solution = function(radius, x_center, y_center) {
  this.radius = radius;
  this.x_center = x_center;
  this.y_center = y_center;
};

/**
 * @return {number[]}
 */
Solution.prototype.randPoint = function() {
  const randomX = randRange(this.x_center + this.radius, this.x_center - this.radius);
  const randomY = randRange(this.y_center + this.radius, this.y_center - this.radius);
  
  const distanceInSquares = Math.pow(randomX - this.x_center, 2) + Math.pow(randomY - this.y_center, 2);
  const isOutOfTheCircle = distanceInSquares > Math.pow(this.radius, 2);
  
  if (isOutOfTheCircle)) {
    return this.randPoint();
  }

  return [randomX, randomY];
};

/** 
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(radius, x_center, y_center)
 * var param_1 = obj.randPoint()
 */

function randRange(maximum, minimum) {
  return Math.random() * (maximum - minimum) + minimum;
}
