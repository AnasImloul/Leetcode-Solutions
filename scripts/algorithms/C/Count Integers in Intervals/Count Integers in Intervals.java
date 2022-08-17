class CountIntervals {
    
    //for storing intervals
    TreeMap<Integer,Integer> map=new TreeMap<>();
    int count=0;
    public CountIntervals() {
    }
    
    public void add(int left, int right) {
        //we are taking left side as reference and calculating ans
        
        //this is the current length
        int add=right-left+1;
        
        //var is the default data type
        //lowerentry gives the value of smaller(smaller largest) entry compared to (left+1)
        //we added +1 bcz there may be a case where left is present in a map
        //lowerentry gives the  value(that is)<left+1
        var left_bound = map.lowerEntry(left + 1);
        
        
        //if there is some value present then go
        //getvalue gives the right positon
        //if current left is cover under map.right value means there is a overlap
        if(left_bound!=null && left_bound.getValue()>=left){
            //positions are map.left <= left <= min(map.right,right) <= max(map.right,right)
            
//examples:   (1)                       (2)                     (3)
//       ____________                 _________            _______________     (map)
//                ___________                  ________           ____         (our)
            
            //now, left become the smallest value which in this case is map.left
            left=left_bound.getKey();
            
            //same as right become the maximum value
            right=Math.max(left_bound.getValue(),right);
            
            //value overlap means curr answer(add) also change
            //we already calculated the map value (covered area) and added into ans variable
            //calculate/add the new uncovered value
            //    right            - map.right
            //max(right,map.right) - map.right
            //we are not adding +1 bcz that is already handled by overlaping area
            add=right-left_bound.getValue();
            
            //this is taken so we have to remove
            //at last we added the largest area (which is stored int left,right)
            map.remove(left_bound.getKey());
        }
        
        //check is right overlaping
        //if yes then take the correct values
        //higherEntry gives the largest(largest smallest) value in map
        //we are not taking left+1 bcz that condition is already been satisfied
        //eg. left=5 map contains (5,value)
        //condition is checked in left_bound
        //i.getKey()<=right means curr is beneath our map.left and covering area(overlaping)
        for(var i=map.higherEntry(left); i!=null && i.getKey()<=right; i=map.higherEntry(left)){
            //left <= map.left <= min(right,map.right) <= max(right,map.right)
            
            
//examples:   (1)                       (2)                         (3)
//            ____________                _________              _______             (map)
//     ___________                ________                 _________________         (our)
            
            
            //now we have our add which is current ans but some area is overlaping
            //so we have to subtract overlaping area
            //+1 bcz [2,5] we have 4 position (2,3,4,5) ; 5-2=>3 ; we ned to add 1
            add-=Math.min(right,i.getValue())-i.getKey()+1;
            
            //right value become the largest among them
            right=Math.max(right,i.getValue());
            
            //we have taken care this entry and calculated left and right now we don't need
            map.remove(i.getKey());
        }
        
        //we pushed the values
        //this entry can be essential for next calls
        map.put(left,right);
        
        //add the current ans
        count+=add;
        
        
    }
    
    public int count() {
        return count;
    }
}

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals obj = new CountIntervals();
 * obj.add(left,right);
 * int param_2 = obj.count();
 */
