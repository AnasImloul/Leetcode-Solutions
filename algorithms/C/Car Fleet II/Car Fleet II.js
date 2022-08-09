var getCollisionTimes = function(cars) {
    // create a stack to hold all the indicies of the cars that can be hit
    const possibleCarsToHit = [];
    const result = new Array(cars.length).fill(-1);
	
    for (let i = cars.length - 1; i >= 0; i--) {
	
	    // if there are cars to hit, check if the current car will hit the car before or after hitting
		// the car in front of them
		// you can also think of this as if the current car will hit the car before or after being absorbed by
		// the slower car in front.
        while (possibleCarsToHit.length && result[possibleCarsToHit[possibleCarsToHit.length - 1]] >= 0) {
            const nextCarIndex = possibleCarsToHit[possibleCarsToHit.length - 1];
            const timeToCatchNextCar = 
                getTimeToCatchNextCar(cars[i], cars[nextCarIndex]);
            const timeToCatchNextNextCar = result[nextCarIndex];
            if (timeToCatchNextCar > 0 && 
                timeToCatchNextCar <= timeToCatchNextNextCar) {
				break;
			}
			
			// pop off the stack because the car was absorbed by the next car
			// before getting hit by the current car
            possibleCarsToHit.pop();
        }
        if (possibleCarsToHit.length) {
            const nextCarIndex = possibleCarsToHit[possibleCarsToHit.length - 1];
            result[i] = getTimeToCatchNextCar(cars[i], cars[nextCarIndex]);
        }
        possibleCarsToHit.push(i);
    }
    return result;
};
    
    
function getTimeToCatchNextCar(leftCar, rightCar) {
    const [leftCarPosition, leftCarSpeed] = leftCar
    const [rightCarPosition, rightCarSpeed] = rightCar;
    const distanceToCatchCar = rightCarPosition - leftCarPosition;
    const differenceInSpeed = leftCarSpeed - rightCarSpeed;
    return differenceInSpeed > 0 ? distanceToCatchCar / differenceInSpeed : -1;
}
