/**
 * @param {number[][]} edges
 * @param {number[]} patience
 * @return {number}
 */
var networkBecomesIdle = function(edges, patience) {
  /*
  Approach:
  Lets call D is the distance from node to master
  And last message sent from node is at T
  Then last message will travel till D+T and network will be idal at D+T+1
  */  
    let edgesMap={},minDistanceFromMasterArr=[],ans=0,visited={};
    for(let i=0;i<edges.length;i++){
        if(edgesMap[edges[i][0]]===undefined){
            edgesMap[edges[i][0]] = [];
        }
        edgesMap[edges[i][0]].push(edges[i][1]);
        if(edgesMap[edges[i][1]]===undefined){
            edgesMap[edges[i][1]] = [];
        }
        edgesMap[edges[i][1]].push(edges[i][0]);
    }
    
    let queue=[],node,neighbour;
    minDistanceFromMasterArr[0]=0;//Distance of source to source is 0 
    queue.push(0);
    while(queue[0]!==undefined){
        node = queue.shift();
        for(let i=0;i<edgesMap[node].length;i++){
            neighbour = edgesMap[node][i];   
            if(minDistanceFromMasterArr[neighbour]===undefined){
                minDistanceFromMasterArr[neighbour] = minDistanceFromMasterArr[node] + 1;
                queue.push(neighbour);
            }
        }
    }
    for(let i=1;i<patience.length;i++){
        let responseWillBeReceivedAt = minDistanceFromMasterArr[i]*2;
        let lastMessageSentAt;
        if(patience[i]<responseWillBeReceivedAt){
            lastMessageSentAt = Math.floor((responseWillBeReceivedAt-1)/patience[i])*patience[i];
        }else{
            lastMessageSentAt=0;
        }
        let lastMessageWillTravelTill = lastMessageSentAt + responseWillBeReceivedAt;
        let firstIdleSecond = lastMessageWillTravelTill+1;
        ans = Math.max(ans,firstIdleSecond);
    }
    
    return ans;
};
