from queue import Queue
inf = float('inf')

def BFS(graph, src):
    n = len(graph)
    visited = [False]*n
    order = []
    spath = [-1]*n
    q = Queue()

    q.put(src)
    visited[src] = True
    order.append(src)
    spath[src] = 0
    while not q.empty():
        front = q.get()
        for i in range(n):
            if graph[front][i] != inf and not visited[i]:
                q.put(i)
                spath[i] = spath[front]+1
                visited[i] = True
                order.append(i)

    print(visited)
    print(order)
    print(spath)
    return


def main():
    adj_matrix = []
    choice = int(input("User input(0) or sample graph(1): "))
    if choice == 0:
        n = int(input('Enter the number of nodes: '))
        for i in range(n):
            adj_matrix.append(list(map(int,input(f'Enter row {i+1}(space separated): ').split())))
        src = int(input("Enter the source node: "))
    else:
        n=8
        adj_matrix = [      [0,4,10,inf,inf,inf,inf,5],
                            [4,0,11,15,inf,inf,inf,inf],
                            [10,11,0,13,3,inf,inf,11],
                            [inf,15,13,0,6,5,inf,inf],
                            [inf,inf,3,6,0,2,5,inf],
                            [inf,inf,inf,5,2,0,8,inf],
                            [inf,inf,inf,inf,5,8,0,7],
                            [5,inf,11,inf,inf,inf,7,0]
                    ]
        src = 0

    # Given matrx:
    for i in range(n):
        for j in range(n):
            print(adj_matrix[i][j], end=" ")
        print("")
    
    # Call BFS:
    BFS(adj_matrix, src)

if __name__=="__main__":
    main()

'''
unweigted graph + src node --> BFS --> traversal of all nodes + shortest path distance from src to all other nodes

Algorithm:

- Visit and enqueue src
- while queue not empty:
    visit and enqueue all unvisited neigbors of front
    spath[neighbor] = spath[front]+1
    dequeue
'''