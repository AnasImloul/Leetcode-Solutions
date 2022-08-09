class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size();
        int z_count=0;  //count the number of zeros
        int z_index=-1; //index of the leftmost zero that is why we start iterating from the right
        for(int i=n-1;i>=0;i--) {
         if(binary[i]=='0') {
             z_count++;
             z_index = i;
             binary[i] = '1'; //changing all occurances to 1
         }
        }
        if(z_index!=-1)  //to check if there is atleast 1 zero
        {
            binary[z_index+z_count-1] = '0'; //this is the only zero present
            // -1 because the only zero is also included in zero count 
        }
        return binary;
    }
};
