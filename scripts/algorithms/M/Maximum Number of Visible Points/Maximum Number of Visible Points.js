// basically First i transform my points into degrees in regards to my location as the center
// I need to perform a sliding window to see how many points can fit within my window of length
// angle 
var visiblePoints = function(points, angle, location) {
    
    //Math.atan2(y,x) returns the ANGLE in RADIANS between the point (X,Y), the CENTER (0,0) and x'x
    // so Math.atan2(5,5) * (180/Math.pi) === 45 //transforms it from radians to degrees instead
    let [sx,sy]=location
    let onCenter=points.filter(([x,y])=>(x==sx&&y==sy)).length //if i m standing on a point i always count it

    points=points.filter(([x,y])=>!(x==sx&&y==sy)) //other than that i dont want it messing with my result

                 .map(([x,y])=>{
                    // i need to transform my center from (0,0) to location, hence (y-sy,x-sx)
                         return Math.atan2(y-sy,x-sx)*(180/Math.PI) //returns the degrees
                    })
                 .sort((a,b)=>a-b) 

    //I will now perform the circular array duplication trick in order to consider points from different view
    points=[...points,...points.map(d=>d+360)] 
    // so for example if a point is 340, it can go with a point that is 15
    // example : [0,60,230,250,359], angle=200
    // would become     [0,60,230,250,359,360,420,590,610,719]
    // would allow me to pick  *   *   *   *   * ,which is practically [230,250,359,0,60] 
    // (every element of my starting array), which are obviously visible with anangle fo 200 deg


    //now i will perform a sliding window that tracks the points visible from my current degree-my angle degrees
    let start=0,n=points.length,result=0
    for (let end = 0; end < n; end++) {
        while(start<end&&points[start]<points[end]-angle) //if the point of start is no bueno
            start++ // shrink the window until all the points are within angle degrees 
        result=Math.max(result,end-start+1)
    }
    return result+onCenter //the points i can see + the ones i ms tanding on

};
