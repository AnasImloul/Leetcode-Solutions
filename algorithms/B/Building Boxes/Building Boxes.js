var minimumBoxes = function(n) {
    //Binary search for the height of the biggest triangle I can create with n cubes available.
    let lo=1,hi=n,result
    let totalCubes=x=>x*(x+1)*(x+2)/6 //the total cubes of a triangle with height x 
    while(lo+1<hi){
        let mid=lo+hi>>1
        if(totalCubes(mid)<=n)
            lo=mid
        else 
            hi=mid
    }
	let f=(x)=>Math.floor(Math.sqrt(2*x)+1/2)// the i-th element of the sequence 1,2,2,3,3,3,4,4,4,4,5,...
    result=(lo)*(lo+1)/2// the base of the largest complete triangle 1+2+3+..+H
    n-=totalCubes(lo) //remove the cubes of the complete triangle
    return result+f(n)  // the base of the largest+ the extra floor cubes
};
