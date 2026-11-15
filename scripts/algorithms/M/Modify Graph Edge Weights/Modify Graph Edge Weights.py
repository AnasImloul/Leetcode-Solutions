# Runtime: 457 ms (Top 41.89%) | Memory: 36.40 MB (Top 5.41%)

class Solution:
    def modifiedGraphEdges(self, n, edges, source, destination, target):
        adjacency_list = [[] for _ in range(n)]
        for i, (nodeA, nodeB, weight) in enumerate(edges):
            adjacency_list[nodeA].append((nodeB, i))
            adjacency_list[nodeB].append((nodeA, i))

        distances = [[float('inf')] * 2 for _ in range(n)]
        distances[source][0] = distances[source][1] = 0

        self.run_dijkstra(adjacency_list, edges, distances, source, 0, 0)
        difference = target - distances[destination][0]

        if difference < 0:
            return []

        self.run_dijkstra(adjacency_list, edges, distances, source, difference, 1)

        if distances[destination][1] < target:
            return []

        for edge in edges:
            if edge[2] == -1:
                edge[2] = 1

        return edges

    def run_dijkstra(self, adjacency_list, edges, distances, source, difference, run):
        n = len(adjacency_list)
        priority_queue = [(0, source)]
        distances[source][run] = 0

        while priority_queue:
            current_distance, current_node = heapq.heappop(priority_queue)
            if current_distance > distances[current_node][run]:
                continue

            for next_node, edge_index in adjacency_list[current_node]:
                weight = edges[edge_index][2]
                if weight == -1:
                    weight = 1
                if run == 1 and edges[edge_index][2] == -1:
                    new_weight = difference + distances[next_node][0] - distances[current_node][1]
                    if new_weight > weight:
                        edges[edge_index][2] = weight = new_weight

                if distances[next_node][run] > distances[current_node][run] + weight:
                    distances[next_node][run] = distances[current_node][run] + weight
                    heapq.heappush(priority_queue, (distances[next_node][run], next_node))

def main():
    input_data = sys.stdin.read().strip()
    lines = input_data.splitlines()

    num_test_cases = len(lines) // 5
    results = []

    for i in range(num_test_cases):
        n = int(lines[i*5])
        edges = json.loads(lines[i*5 + 1])
        source = int(lines[i*5 + 2])
        destination = int(lines[i*5 + 3])
        target = int(lines[i*5 + 4])

        result = Solution().modifiedGraphEdges(n, edges, source, destination, target)
        results.append(json.dumps(result))

    with open('user.out', 'w') as f:
        for result in results:
            f.write(f"{result}\n")

if __name__ == "__main__":
    main()
    exit(0)
