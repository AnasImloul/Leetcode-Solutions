var slowestKey = function(releaseTimes, keysPressed) {
let maxDuration = releaseTimes[0], char=keysPressed[0];
for (let i = 1; i < releaseTimes.length; i++) {
    if (releaseTimes[i]-releaseTimes[i-1]==maxDuration && keysPressed[i]>char) char=keysPressed[i]
    else if (releaseTimes[i]-releaseTimes[i-1]>maxDuration) {
        char=keysPressed[i];
        maxDuration=releaseTimes[i]-releaseTimes[i-1];
    }
}
return char;    
};
