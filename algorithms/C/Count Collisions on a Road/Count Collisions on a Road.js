/**
 * @param {string} directions
 * @return {number}
 */
var countCollisions = function(directions) {
            if(directions.length == 1){
            return 0;
        }
        let count =0;
        let couplet;
        let retreivedWieght;
        let convertedArr=[];
        let rightMovingCount= 0;
        let  weights= new Map();
        weights.set("LR",0);
        weights.set("RL",2);
        weights.set("LS",0);
        weights.set("SL",1);
        weights.set("SR",0);
        weights.set("RS",1);
        weights.set("LL",0);
        weights.set("RR",0);
        weights.set("SS",0);
        
        for(let i=0;i<directions.length;i++){
            convertedArr[i]=directions[i];
        }
        
        for(let i=1;i< convertedArr.length; i++){
            couplet=convertedArr[i-1]+convertedArr[i];
            retreivedWieght=weights.get(couplet);
            count=count+retreivedWieght;
            if(retreivedWieght>0){
                convertedArr[i-1]="S"; 
                convertedArr[i]="S";
                if(rightMovingCount>0){
                    count=count+rightMovingCount;
                    rightMovingCount=0;
                }
            }
            if(couplet === "RR"){
                rightMovingCount++;
            }
            
        }
        return count;
};
