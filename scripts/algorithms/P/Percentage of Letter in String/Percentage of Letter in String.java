class Solution {
    public int percentageLetter(String s, char letter) {
        int count=0; //count acts as a counter variabe to count the give character "letter" in the string 
        
        //Traverse the string s and each time the character int the string is equal to "letter"
        //increment the count variable by 1.
        for(char ch:s.toCharArray())
        {
            if(ch==letter)
                count++;
        }
        
    //If the count is zero, then the percentage is also zero
        if(count==0) 
            return 0;
        
        
     // to find the total characters in the strings or we can say to find the length of the string   
        int total=s.length(); 
    
    // Calculate the total percentage using the standard percentage formula i.e (given*100)/total
        int per=(count*100)/total;
        return per;
    }
}
