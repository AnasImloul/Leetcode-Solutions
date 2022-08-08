var maxArea = function(h, w, horizontalCuts, verticalCuts) {
    horizontalCuts.sort((a,b) => a-b)
    verticalCuts.sort((a,b) => a-b)
    let max_hor_dis = Math.max(horizontalCuts[0], h - horizontalCuts[horizontalCuts.length-1])
    let max_ver_dis = Math.max(verticalCuts[0], w - verticalCuts[verticalCuts.length-1])
    for(let i=1; i<horizontalCuts.length; i++){
        max_hor_dis = Math.max(max_hor_dis, horizontalCuts[i] - horizontalCuts[i-1])
    }
    for(let i=1; i<verticalCuts.length; i++){
        max_ver_dis = Math.max(max_ver_dis, verticalCuts[i] - verticalCuts[i-1])
    }
    return BigInt(max_hor_dis) * BigInt(max_ver_dis) % BigInt(1e9+7)
};
