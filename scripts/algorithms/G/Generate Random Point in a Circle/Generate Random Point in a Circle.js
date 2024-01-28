// Runtime: 131 ms (Top 92.86%) | Memory: 68.70 MB (Top 7.14%)

var Solution = function(radius, x_center, y_center) {
    this.radius = radius;
    this.x_center = x_center;
    this.y_center = y_center;
};

Solution.prototype.randPoint = function() {
    let r = this.radius * Math.sqrt(Math.random());
    let theta = Math.random() * 2 * Math.PI;
    let x = this.x_center + r * Math.cos(theta);
    let y = this.y_center + r * Math.sin(theta);
    return [x, y];
};

