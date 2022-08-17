var getTime = function(time){
    var [hrs,mins] = time.split(":");
    return parseInt(hrs)*60 + parseInt(mins);
}


var convertTime = function(current, correct) {
    var diff = getTime(correct) - getTime(current);
    var order = [60,15,5,1];
    var ops = 0;
    order.forEach(val =>{
        ops+=Math.floor((diff/val));
        diff%=val;
    })
    return ops;
};
