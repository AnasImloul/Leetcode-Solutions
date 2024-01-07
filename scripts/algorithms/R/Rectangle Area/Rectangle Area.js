// Runtime: 95 ms (Top 83.5%) | Memory: 47.80 MB (Top 20.39%)

var computeArea = function(A, B, C, D, E, F, G, H) {
    var intersectionWidth = Math.min(C,G) - Math.max(A,E);
    var intersectionHeight = Math.min(D,H) - Math.max(B,F);
    intersectionWidth = intersectionWidth > 0 ? intersectionWidth : 0;
    intersectionHeight = intersectionHeight > 0 ? intersectionHeight : 0;
    return (C - A) * (D - B) + (G - E) * (H - F) - intersectionWidth * intersectionHeight;
};