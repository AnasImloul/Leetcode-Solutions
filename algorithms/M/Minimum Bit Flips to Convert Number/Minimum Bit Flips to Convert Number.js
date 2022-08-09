var minBitFlips = function(start, goal) {
    return (start^goal).toString(2).split("0").join("").length;
};
