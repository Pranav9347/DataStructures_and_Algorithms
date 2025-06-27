inf = float('inf')

def DFS(graph, src):
    n = len(graph)
    visited = [False]*n
    order = []
    stack = []

    stack.append(src)
    visited[src] = True
    order.append(src)
    while stack:
        top = stack[-1]
        for i in range(n):
            if graph[top][i] != inf and not visited[i]:
                stack.append(i)
                visited[i] = True
                order.append(i)
                break
        if top == stack[-1]:
            stack.pop()
    print(visited)
    print(order)
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
    
    # Call DFS:
    DFS(adj_matrix, src)

if __name__=="__main__":
    main()

'''
graph + src node --> DFS --> traversal of all nodes

Algorithm:
- Push and visit src
- while stack not empty:
    push and visit 1 adjacent unvisited neighbor of top
    if no such neighbor exists
        pop
'''