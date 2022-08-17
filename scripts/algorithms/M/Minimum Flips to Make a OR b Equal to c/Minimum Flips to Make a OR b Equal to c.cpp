class Solution {
public:
    int minFlips(int a, int b, int c) {
        int changeBits = 0;

        for(int i=0; i<32; i++){
            int lastBitA = 0;
            int lastBitB = 0;
            int lastBitC = 0;
            if(((a >> i) & 1) == 1){
                lastBitA = 1;
            }
            if (((b >> i) & 1) == 1){
                lastBitB = 1;
            }
            if (((c >> i) & 1) == 1){
                lastBitC = 1;
            }
            if(lastBitC == 1){
                if(lastBitA == 0 & lastBitB == 0){
                    changeBits++;
                }
            }
            else{
                if(lastBitA == 1 || lastBitB == 1){
                    if(lastBitA == 1){
                        changeBits++;
                    }
                    if(lastBitB == 1){
                        changeBits++;
                    }
                }
            }
        }
        return changeBits;
    }
};
