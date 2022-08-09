 * @param {number[]} bills
 * @return {boolean}
 */
var lemonadeChange = function(bills) {
   let cashLocker = {
    "5": 0,
    "10": 0,
    
  }
  for (let i = 0; i < bills.length; i++) {
    if (bills[i] === 5) {
      cashLocker["5"] += 1;
    } else if (bills[i] === 10 && cashLocker["5"] > 0) {
      cashLocker["5"] -= 1;
      cashLocker["10"] += 1;

    } else if (bills[i] === 20 && cashLocker["5"] >= 1 && cashLocker["10"] >= 1) {
      cashLocker["5"] -= 1;
      cashLocker["10"] -= 1;
     
    } else if (bills[i] === 20 && cashLocker["5"] >= 3) {

      cashLocker["5"] -= 3;
     
    } else {
      return false;
    }
  }

  return true;
    
};