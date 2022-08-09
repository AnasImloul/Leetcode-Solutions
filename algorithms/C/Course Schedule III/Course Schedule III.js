
var scheduleCourse = function(courses) {
  courses.sort((a,b)=>a[1]-b[1]);
  let pq = new PQ(), currentDay = 0;

  for(let [duration,lastDay] of courses){
    if(duration > lastDay) continue;    
 
    if(currentDay + duration <= lastDay){
      pq.offer(duration);
      currentDay += duration;
    }
    
    else if(duration < pq.peek() && pq.size())
      {
        currentDay += duration-pq.poll();
        pq.offer(duration);
      }  
  }
  return pq.size();   
};
