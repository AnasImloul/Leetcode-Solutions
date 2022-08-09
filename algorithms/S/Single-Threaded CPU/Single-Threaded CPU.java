class Solution {
    public int[] getOrder(int[][] tasks) {
        int n = tasks.length;
        
        
        //minheap, store all the tosk, with there index
        //this heap helps to get the task with minimum enqueueTime
        PriorityQueue<int[]> taskQueue = new PriorityQueue<int[]>((a, b) -> (a[0] - b[0]));
        for(int i = 0; i < n; i++){
            int[] task = tasks[i];
            taskQueue.add(new int[]{task[0], task[1], i});
        }
        
        //this minheap help to get available task with minimum processingTime, if processingTime are different
        //otherwise get available task with mimimum index
        PriorityQueue<int[]> availableTask  = new PriorityQueue<int[]>((a, b) -> (a[1] != b[1] ? (a[1] - b[1]) :  (a[2] - b[2]) ));
        
        //store all Available task, with same start time from the task queue
        updateAvaiableTask(taskQueue, availableTask);
        

        
        int[] indices = new int[n];
        int i = 0;
        
        
        int endTime = availableTask.peek()[0];
        
        while(!availableTask.isEmpty() || !taskQueue.isEmpty()){
            if(availableTask.isEmpty()){
                //store all Available task, with same start time from the task queue
                updateAvaiableTask(taskQueue, availableTask);
            }
            
            //get available task with minimum processingTime, if processingTime are different
            //otherwise get available task with mimimum index
            int[] task = availableTask.remove();
            
            //add current task index
            indices[i++] = task[2];

            //append end time
            endTime += task[1];
            
            
            //store all task in Available task, with same start time is equal or less than endTime (of current task) 
            //from the task queue 
            while(!taskQueue.isEmpty() && taskQueue.peek()[0] <= endTime){
                availableTask.add(taskQueue.remove());
            }
        }
        
        
        return indices;
    }
    
    
    private void updateAvaiableTask(PriorityQueue<int[]> taskQueue, PriorityQueue<int[]> availableTask){
        //store all Available task, with same start time from the task queue
        int startTime = taskQueue.peek()[0];
        while(!taskQueue.isEmpty() && taskQueue.peek()[0] == startTime){
            availableTask.add(taskQueue.remove());
        }
    }
    

}
