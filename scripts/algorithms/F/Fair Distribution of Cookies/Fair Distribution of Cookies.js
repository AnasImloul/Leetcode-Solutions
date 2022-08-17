var distributeCookies = function(cookies, k) {
    cookies.sort((a, b) => b - a);
    if(k === cookies.length) return cookies[0];
    
    const arr = new Array(k).fill(0);
    let res = Infinity;
    
    function helper(arr, cookies, level) {
        if(level === cookies.length) {
            const max = Math.max(...arr);
            res = Math.min(res, max);
            return;
        }
        const cookie = cookies[level];
        for(let i = 0; i < arr.length; i++) {
            arr[i] += cookie;
            helper(arr, cookies, level + 1);
            arr[i] -= cookie;
        }
    }
    
    helper(arr, cookies, 0);
    
    return res;
};
