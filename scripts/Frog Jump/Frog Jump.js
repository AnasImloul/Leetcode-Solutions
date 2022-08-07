var canCross = function(stones) {
    let hash = {};
    function dfs(idx = 0, jumpUnits = 0) {
        let key = `${idx}-${jumpUnits}`;
        if (key in hash) return hash[key];
		
        if (idx === stones.length - 1) return true;
        if (idx >= stones.length) return false;
		
        let minJump = jumpUnits - 1, maxJump = jumpUnits + 1;
        for (let i = idx + 1; i < stones.length; i++) {
            let jump = stones[i] - stones[idx];
            if (jump >= minJump && jump <= maxJump) {
                if (dfs(i, jump)) return hash[idx] = true;
            } else if (jump > maxJump) break;
        } return hash[key] = false;
    }
    return dfs();
};
