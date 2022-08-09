var angleClock = function(hour, minutes) {
    const angle = Math.abs((hour * 30) - 5.5 * minutes)
    return angle > 180 ? 360 - angle : angle
};
