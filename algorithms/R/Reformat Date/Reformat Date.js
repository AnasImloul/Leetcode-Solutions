var reformatDate = function(date) {
       const ans = [];
       const month = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"];
        
        const [inputDate,inputMonth,inputYear] = date.split(' ');
        ans.push(inputYear);
        ans.push("-");
    
        const monthIndex = month.findIndex(mon => mon === inputMonth);
        const formatedMonth = String(monthIndex + 1).padStart(2,'0');
        ans.push(formatedMonth);
        ans.push("-");
    
        const slicedDate = inputDate.slice(0,2);
        if(+slicedDate >= 10){
            ans.push(slicedDate);
        }else{
            const formatedDate = inputDate.slice(0,1).padStart(2,'0');
            ans.push(formatedDate)
        }
          
       return ans.join('');
};
