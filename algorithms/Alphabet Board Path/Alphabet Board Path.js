var alphabetBoardPath = function(target) {
    var result = "";
    var list = "abcdefghijklmnopqrstuvwxyz";
    var curr = 0;
    for(i=0;i<target.length;i++){ 
          let next = list.indexOf(target[i]);
          if(next!==curr){   
              if(curr===25) curr-=5, result+="U";
              if(next%5!==curr%5){  
                 diff = next%5-curr%5;
                 if(diff>0) curr+=diff, result+="R".repeat(diff);
                 else curr+=diff, result+="L".repeat(-diff);  
             }
             diff = (next-curr)/5;
             if(diff>0) curr+=diff*5, result+="D".repeat(diff);
             else curr+=diff*5, result+="U".repeat(-diff);     
          }
    result+='!';
    }
    return result;
};