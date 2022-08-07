Initalise a ArrayList in which you will add all the permutations.
Start a 2d loop. First loop will be for hours and second will be for minutes.
Java as a function "Integer.bitCount". It returns the count of the number of one-bits in the two’s complement binary representation of an int value. This function is sometimes referred to as the population count. Simply add hour and minute bit count and check if it is equal to given num.
If the miute is less than 10, then add '0' before minute place in list.
Else add it directly.
Time Complexity: O(1)


class Solution {
    public List<String> readBinaryWatch(int turnedOn) {
        if(turnedOn < 0 || turnedOn>=9)
            return new ArrayList<>();
        List<String> ans = new ArrayList();
        for(int hours = 0 ;hours < 12; hours++){
            for(int min = 0; min < 60 ;min++){
                if(Integer.bitCount(hours) + Integer.bitCount(min) == turnedOn)
                    ans.add(String.format("%d:%02d" , hours ,min));
            }
        }
        return ans;
    }
}
