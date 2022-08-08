var isBoomerang = function(points) {
    
 // if any two of the three points are the same point return false;
 
 if (points[0][0] == points[1][0] && points[0][1] == points[1][1]) return false;
 if (points[0][0] == points[2][0] && points[0][1] == points[2][1]) return false;
 if (points[2][0] == points[1][0] && points[2][1] == points[1][1]) return false;
 
 // if the points are in a straight line return false;
 
 let slope1 = (points[0][1] - points[1][1]) / (points[0][0] - points[1][0]);
 let slope2 = (points[1][1] - points[2][1]) / (points[1][0] - points[2][0]);
 if (points[0][0] == points[1][0] && points[0][0] === points[2][0]) return false;
 if (points[0][1] == points[1][1] && points[0][1] === points[2][1]) return false;
 
 if (slope1 === slope2) return false;
 
 return true;
 
};
