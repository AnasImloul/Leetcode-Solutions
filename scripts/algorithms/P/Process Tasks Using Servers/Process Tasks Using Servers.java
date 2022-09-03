// Runtime: 421 ms (Top 69.74%) | Memory: 172.7 MB (Top 82.56%)
class Solution {
    public int[] assignTasks(int[] servers, int[] tasks) {

        PriorityQueue<int[]> availableServer = new PriorityQueue<int[]>((a, b) -> (a[1] != b[1] ? (a[1] - b[1]) : (a[0] - b[0])));
        for(int i = 0; i < servers.length; i++){
            availableServer.add(new int[]{i, servers[i]});
        }

        //int[[] arr,
        //arr[0] - server index
        //arr[1] - server weight
        //arr[2] - free time
        PriorityQueue<int[]> processingServer = new PriorityQueue<int[]>(
                (a, b) ->

                (
                    a[2] != b[2] ? a[2] - b[2] : // try to sort increasing order of free time
                    a[1] != b[1] ? a[1] - b[1] : // try to sort increasing order of server weight
                    a[0] - b[0] // sort increasing order of server index
                )
        );

        int[] result = new int[tasks.length];

        for(int i = 0; i < tasks.length; i++){

            while(!processingServer.isEmpty() && processingServer.peek()[2] <= i){
                int serverIndex = processingServer.remove()[0];
                availableServer.add(new int[]{serverIndex, servers[serverIndex]});
            }

            int currentTaskTimeRequired = tasks[i];

            int[] server;

            //when current task will free the server done
            int freeTime = currentTaskTimeRequired;

            if(!availableServer.isEmpty()){
                server = availableServer.remove();
                freeTime += i;
            }else{
                server = processingServer.remove();
                //append previous time
                freeTime += server[2];
            }

            int serverIndex = server[0];
            processingServer.add(new int[]{serverIndex, servers[serverIndex] ,freeTime});

            //assign this server to current task
            result[i] = serverIndex;
        }

        return result;

    }
}