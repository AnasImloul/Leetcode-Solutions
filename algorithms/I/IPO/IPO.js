var findMaximizedCapital = function(k, w, profits, capital) {
    let capitals_asc_queue = new MinPriorityQueue();
    let profits_desc_queue = new MaxPriorityQueue();
    for (let i = 0; i < capital.length; i++)
        capitals_asc_queue.enqueue([capital[i], profits[i]], capital[i]);
   
	for (let i = 0; i < k; i++)    {
        while (!capitals_asc_queue.isEmpty() && capitals_asc_queue.front().element[0] <=w ) {
            let el = capitals_asc_queue.dequeue().element;
            profits_desc_queue.enqueue(el, el[1]);
        }
        if (profits_desc_queue.isEmpty()) return w;
        w += profits_desc_queue.dequeue().element[1];
    }
    return w;
}
