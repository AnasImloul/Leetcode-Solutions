var flipEquiv = function(root1, root2) {
    const flipEquivHelper = (r1 = root1, r2 = root2) => {
        if(!r1 && !r2) return true;
        
        if(!r1 || !r2) return false;
        
        if(r1.val != r2.val) return false;
        
        let ans = false;
        // normal
        ans = ans || (
            flipEquivHelper(r1.left, r2.left) && 
            flipEquivHelper(r1.right, r2.right)
        );
        // flip
        ans = ans || (
            flipEquivHelper(r1.right, r2.left) && 
            flipEquivHelper(r1.left, r2.right)
        );
        return ans;
    }
    return flipEquivHelper();
};
