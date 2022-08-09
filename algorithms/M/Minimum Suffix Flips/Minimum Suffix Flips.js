var minFlips = function(target) {
    target = "0" + target;
    let count = (target.match(/01/g) || []).length * 2;
    return target[target.length -1] ==="0" ? count : count - 1;
};
