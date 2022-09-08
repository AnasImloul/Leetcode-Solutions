// Runtime: 223 ms (Top 56.47%) | Memory: 52.1 MB (Top 78.82%)
/**
 * @param {number} n
 * @param {number[][]} reservedSeats
 * @return {number}
 */
var maxNumberOfFamilies = function(n, reservedSeats) {
    let a,b,c,reservedMap={},ans=n*2,takenB={};
    for(let i=0;i<reservedSeats.length;i++){
        let resverd = reservedSeats[i];
        let row = resverd[0];
        if(reservedMap[row]===undefined){
            reservedMap[row]={}
        }
        if(2<=resverd[1] && resverd[1]<=3 && reservedMap[row]['a']===undefined){//a is blocked now
            ans--;
            reservedMap[row]['a']=true;
            if(reservedMap[row]['c']===true && reservedMap[row]['b']===undefined){
                takenB[resverd[0]]=true;
                ans++;//add for b
            }
        }else if(8<=resverd[1] && resverd[1]<=9 && reservedMap[row]['c']===undefined){//c is blocked now
            ans--;
            reservedMap[row]['c']=true;
            if(reservedMap[row]['a']===true && reservedMap[row]['b']===undefined){
                takenB[resverd[0]]=true;
                ans++;//add for b
            }
        }else if(4<=resverd[1] && resverd[1]<=5){//b is blocked now
            if(reservedMap[row]['a']===undefined){
                ans--;
                reservedMap[row]['a']=true;
            }
            if(takenB[resverd[0]]===true){
                ans--;//substract for b
                takenB[resverd[0]]=false;
            }
            reservedMap[row]['b']=true;
        }else if(6<=resverd[1] && resverd[1]<=7){//b is blocked now
            if(reservedMap[row]['c']===undefined){
                ans--;
                reservedMap[row]['c']=true;
            }
            if(takenB[resverd[0]]===true){
                ans--;//substract for b
                takenB[resverd[0]]=false;
            }
            reservedMap[row]['b']=true;
        }
    }
    return ans;
};