var countOrders = function(n) {
    let ans = 1; //for n=1, there will only be one valid pickup and delivery
    for(let i = 2; i<=n; i++){
        let validSlots = 2 * i -1; //calculating number of valid slots of new pickup in (n-1)th order
        validSlots =  (validSlots * (validSlots+1))/2; 
        ans = (ans * validSlots)%1000000007; //multiplying the ans of (n-1)th order to current order's valid slots
    }
    return ans;
};
