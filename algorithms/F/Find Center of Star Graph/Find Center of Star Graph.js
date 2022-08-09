/**
 * @param {number[][]} edges
 * @return {number}
 */
var findCenter = function(edges) {
    const [p1, p2] = edges[0]
    const [p3, p4] = edges[1]
    return p1 == p3 || p1 == p4 ? p1 : p2
};
