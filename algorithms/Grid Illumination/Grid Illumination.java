class Solution {
    public int[] gridIllumination(int n, int[][] lamps, int[][] queries) {
        //we take 5 hashmap
        //1st hashmap for row
        HashMap<Integer, Integer> row = new HashMap<>();
        //2nd hashmap for column
        HashMap<Integer, Integer> col = new HashMap<>();
        //3rd hashmap for lower diagonal
        HashMap<Integer, Integer> d1 = new HashMap<>();
        //4th diagonal for upper diagonal
        HashMap<Integer, Integer> d2 = new HashMap<>();
        //5th diagonal for cell no meaning lamp is present at this spot
        HashMap<Integer, Integer> cellno = new HashMap<>();
        
        for(int i = 0;i<lamps.length;i++){
            //get row and column from lamps array
            int row1 = lamps[i][0];
            int col1 = lamps[i][1];
            //place row in row hashmap
            row.put(row1, row.getOrDefault(row1, 0) + 1);
            //place column in col hashmap
            col.put(col1, col.getOrDefault(col1, 0) + 1);
            //place d1 dia in d1
            d1.put((row1+col1), d1.getOrDefault((row1+col1), 0) + 1);
            //place d2 diagonal
            d2.put((row1-col1), d2.getOrDefault((row1-col1), 0) + 1);
            //place cellno in cell no hashmap
            int cell = row1*n+col1;
            cellno.put(cell, cellno.getOrDefault(cell, 0) + 1);
        }
        //direction array which travels in 8 adjacent direction
        int[][] dir = {{-1, 0},{-1, 1},{0, 1},{1, 1},{1, 0},{1, -1},{0, -1},{-1, -1}};
        int[] ans = new int[queries.length];
        //process all queries
        for(int i = 0;i<queries.length;i++){
            int row1 = queries[i][0];
            int col1 = queries[i][1];
            int cell = row1 * n + col1;
            ans[i] = (row.containsKey(row1) || col.containsKey(col1) || d1.containsKey(row1 + col1) || d2.containsKey(row1-col1) || cellno.containsKey(cell))? 1:0;
            //if query has a bulb
            if(cellno.containsKey(cell)){
                
                    int val = cellno.get(cell);
                    
                        cellno.remove(cell);
                    
                    //for row 
                    if(row.containsKey(row1)){
                        int rowval = row.get(row1);
                        rowval-=val;
                        if(rowval == 0){
                            row.remove(row1);
                        }else{
                            row.put(row1, rowval);
                        }    
                    }
                    
                    //for col
                    if(col.containsKey(col1)){
                        int colval = col.get(col1);
                        colval-=val;
                        if(colval == 0){
                            col.remove(col1);
                        }else{
                            col.put(col1, colval);
                        }    
                    }
                    
                    //for d1
                    if(d1.containsKey(row1+col1)){
                        int d1val = d1.get(row1+col1);
                        d1val-=val;
                        if(d1val == 0){
                            d1.remove(row1+col1);
                        }else{
                            row.put((row1+col1), d1val);
                        }    
                    }
                    
                    //for d2
                    if(d2.containsKey(row1 - col1)){
                        int d2val = d2.get(row1-col1);
                        d2val-=val;
                        if(d2val == 0){
                            d2.remove(row1-col1);
                        }else{
                            d2.put((row1-col1), d2val);
                        }    
                    }
            }
            //moves all 8 direction and remove the illumination 
            for(int j = 0;j<dir.length;j++){
                int rowdash = row1 + dir[j][0];
                int coldash = col1 + dir[j][1];
                int cellno1 = rowdash * n + coldash;
                if(cellno.containsKey(cellno1)){
                    int val = cellno.get(cellno1);
                    
                        cellno.remove(cellno1);
                    
                    //for row
                    if(row.containsKey(rowdash)){
                        int rowval = row.get(rowdash);
                        rowval -= val;
                        if(rowval == 0){
                            row.remove(rowdash);
                        }else{
                            row.put(rowdash, rowval);
                        }    
                    }
                    
                    //for col
                    if(col.containsKey(coldash)){
                        int colval = col.get(coldash);
                        colval-=val;
                        if(colval == 0){
                            col.remove(coldash);
                        }else{
                            col.put(coldash, colval);
                        }    
                    }
                    
                    //for d1
                    if(d1.containsKey(rowdash+coldash)){
                        int d1val = d1.get(rowdash+coldash);
                        d1val-=val;
                        if(d1val == 0){
                            d1.remove(rowdash+coldash);
                        }else{
                            row.put((rowdash+coldash), d1val);
                        }    
                    }
                    
                    //for d2
                    if(d2.containsKey(rowdash - coldash)){
                        int d2val = d2.get(rowdash-coldash);
                        d2val-=val;
                        if(d2val == 0){
                            d2.remove(rowdash-coldash);
                        }else{
                            d2.put((rowdash-coldash), d2val);
                        }    
                    }
                    
                    
                }
            }
        }
        
        return ans;
    }
}
