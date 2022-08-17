/** https://leetcode.com/problems/shopping-offers/
 * @param {number[]} price
 * @param {number[][]} special
 * @param {number[]} needs
 * @return {number}
 */
var shoppingOffers = function(price, special, needs) {
  // Memoization
  this.map = new Map();
  
  return shop(price,special,needs);
};

var shop = function (price, special, needs) {
  // Return memoization result
  if (this.map.has(needs) === true) {
    return this.map.get(needs);
  }
  
  // Calculate total if purchase without special offers
  let currTotal = calcTotal(price, needs);
  
  // Try every single offers
  for(let i = 0; i < special.length; i++) {
    // Check special offer can be used
    if (canUseSpecial(special[i], needs) === true) {
      // Clone the `needs` because we don't want to modify the original `needs`, update the `needs` count by calling `useSpecial()`
      let cloneNeeds = [...needs];
      cloneNeeds = useSpecial(special[i], cloneNeeds);
      
      // Count total if using special offers, basically repeat the same process with updated `needs`
      let totalUsingSpecial = special[i][needs.length] + shop(price, special, cloneNeeds);
      
      // Compare the `currTotal` with total if using special offers
      currTotal = Math.min(currTotal, totalUsingSpecial);
    }
  }
  
  // Update memoization and return result
  this.map.set(needs, currTotal);
  return currTotal;
};

var calcTotal = function (price, needs) {
  // Calculate total if purchase without special offers, basically `price[i] * needs[i]`
  let out = 0;
  
  for (let i =0 ; i < price.length; i++) {
    out += price[i] * needs[i];
  }
  
  return out;
};

var canUseSpecial = function (special, needs) {
  // Check if special offers can be used, if any of `special[i]` is more than `needs[i]`, the special can not be used, return false because we can not buy more than needed
  for (let i = 0; i < needs.length; i++) {
    if (needs[i] < special[i]) {
      return false;
    }
  }
  
  return true;
};

var useSpecial = function (special, needs) {
  // Update the `needs` count by subtracting it from `special`
  for (let i = 0; i < needs.length; i++) {
    needs[i] -= special[i];
  }
  
  return needs;
};
