class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> currRow(1, poured);
		
        for(int i=0; i<=query_row; i++){ //we need to make the dp matrix only till query row. No need to do after that
            vector<double> nextRow(i+2, 0); //If we are at row 0, row 1 will have 2 glasses. So next row will have currRow number + 2 number of glasses.
            for(int j=0; j<=i; j++){ //each row will have currRow number + 1 number of glasses.
                if(currRow[j]>=1){ //if the champagne from the current glass is being overflowed.
                    nextRow[j] += (currRow[j]-1)/2.0; //fill the left glass with the overflowing champagne
                    nextRow[j+1] += (currRow[j]-1)/2.0; //fill the right glass with the overflowing champagne
                    currRow[j] = 1; //current glass will store only 1 cup of champagne
                }
            }
            if(i!=query_row) currRow = nextRow; //change the currRow for the next iteration. But if we have already reached the query_row, then the next iteration will not even take place, so the currRow is the query_row itself. So don't change as we need the currRow only.
        }
        return currRow[query_glass];
    }
};

