inf = float('inf')
graph = [
    [0,1,2,inf,inf],
    [1,0,3,inf,6],
    [2,3,0,4,inf],
    [inf,inf,4,0,5],
    [inf,6,inf,5,0]
]
n = len(graph)
edge_list = []
mst_edges = []

# union-find/ Disjoint union set data-stucture to remove cycles:
group = [i for i in range(n)]
def union(i, j):
    gi = find(i)
    gj = find(j)
    for k in range(n):
        if group[k] == gj:
            group[k] = gi

def find(i):
    return group[i]

for i in range(n-1):
    for j in range(i+1,n):
        if graph[i][j] == inf:
            continue
        edge_list.append((i,j))

# print(edge_list)

edge_list.sort(key=lambda edge: graph[edge[0]][edge[1]])
# print("After sorting", edge_list)

for edge in edge_list:
    x, y = edge
    if find(x) != find(y):
        union(x, y)
        mst_edges.append(edge)
        if len(mst_edges) == n - 1:
            break  # We have enough edges for the MST

print(mst_edges)
mst_length = 0
for edge in mst_edges:
    mst_length += graph[edge[0]][edge[1]]

print("Length of minimum spanning tree: ", mst_length)