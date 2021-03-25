import heapq

my_graph = {
    'A': {'B': 8, 'C': 1, 'D': 2},
    'B': {},
    'C': {'B': 5, 'D': 2},
    'D': {'E': 3, 'F': 5},
    'E': {'F': 1},
    'F': {'A': 5}
}

heap=[]
distance={node: float('inf') for node in my_graph}

def dijkstra(graph,start):
    distance[start]=0
    for k,v in graph[start].items():
        distance[k]=v
        heapq.heappush(heap, [v, k])
        
    while heap:
        weight, node = heapq.heappop(heap)
        # print(weight, node)
        for k,v in graph[node].items():
            print(node,'=', k, v, '//', distance)
            if distance[node]+v < distance[k]:
                distance[k] = distance[node]+v
                heapq.heappush(heap, [v,k])
            
            
        
dijkstra(my_graph, 'A')
for k,v in distance.items():
    print(k, v, end=' ')
#print(distance, heap)
