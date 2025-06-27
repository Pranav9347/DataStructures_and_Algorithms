from Kruskal_mst import graph, edge_list, mst_edges, mst_length, group, union, find

def run_test(graph, expected_edges, expected_length):
    global edge_list, mst_edges, mst_length
    n = len(graph)
    edge_list = []
    mst_edges = []
    group = [i for i in range(n)]  # Reinitialize group for each test case

    # Generate edge list
    for i in range(n-1):
        for j in range(i+1, n):
            if graph[i][j] != float('inf'):
                edge_list.append((i, j))

    # Sort edges by weight
    edge_list.sort(key=lambda edge: graph[edge[0]][edge[1]])

    # Kruskal's algorithm
    for edge in edge_list:
        x, y = edge
        if find(x, group) != find(y, group):  # Pass group explicitly
            union(x, y, group)  # Pass group explicitly
            mst_edges.append(edge)
            if len(mst_edges) == n - 1:
                break

    # Calculate MST length
    mst_length = sum(graph[edge[0]][edge[1]] for edge in mst_edges)

    # Print results
    print("Graph:", graph)
    print("MST Edges:", mst_edges)
    print("MST Length:", mst_length)
    assert mst_edges == expected_edges, f"Expected edges {expected_edges}, got {mst_edges}"
    assert mst_length == expected_length, f"Expected length {expected_length}, got {mst_length}"
    print("Test passed!\n")


# Update the find and union functions to accept the group parameter
def find(i, group):
    return group[i]

def union(i, j, group):
    gi = find(i, group)
    gj = find(j, group)
    for k in range(len(group)):
        if group[k] == gj:
            group[k] = gi


# Test Case 1
graph1 = [
    [0, 1, 2, float('inf'), float('inf')],
    [1, 0, 3, float('inf'), 6],
    [2, 3, 0, 4, float('inf')],
    [float('inf'), float('inf'), 4, 0, 5],
    [float('inf'), 6, float('inf'), 5, 0]
]
expected_edges1 = [(0, 1), (0, 2), (2, 3), (3, 4)]
expected_length1 = 12
run_test(graph1, expected_edges1, expected_length1)

# Test Case 2
graph2 = [
    [0, 2, float('inf'), 6],
    [2, 0, 3, 8],
    [float('inf'), 3, 0, float('inf')],
    [6, 8, float('inf'), 0]
]
expected_edges2 = [(0, 1), (1, 2), (0, 3)]
expected_length2 = 11
run_test(graph2, expected_edges2, expected_length2)

# Test Case 3
graph3 = [
    [0, 10, 6, 5],
    [10, 0, float('inf'), 15],
    [6, float('inf'), 0, 4],
    [5, 15, 4, 0]
]
expected_edges3 = [(2, 3), (0, 3), (0, 2)]
expected_length3 = 15
run_test(graph3, expected_edges3, expected_length3)

# Test Case 4
graph4 = [
    [0, 1, float('inf'), float('inf')],
    [1, 0, 2, float('inf')],
    [float('inf'), 2, 0, 3],
    [float('inf'), float('inf'), 3, 0]
]
expected_edges4 = [(0, 1), (1, 2), (2, 3)]
expected_length4 = 6
run_test(graph4, expected_edges4, expected_length4)