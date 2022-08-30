// Runtime: 71 ms (Top 95.00%) | Memory: 44.8 MB (Top 96.25%)
var minCameraCover = function(root) {
    let cam = 0;
    // 0 --> No covered
    // 1 --> covered by camera
    // 2 --> has camera
    function dfs(root) {
        if(root === null) return 1;

        const left = dfs(root.left);
        const right = dfs(root.right);

        if(left === 0 || right === 0) { // child required a camera to covered
            cam++;
            return 2;
        } else if(left === 2 || right === 2) { // child has camera so i am covered
            return 1;
        } else { // child is covered but don't have camera,So i want camera
            return 0;
        }
    }

    const ans = dfs(root);

    if(ans === 0) ++cam;

    return cam;
};