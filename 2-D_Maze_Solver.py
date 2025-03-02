from collections import deque

def find_shortest_path_in_maze(maze, start, end):
    rows = len(maze)
    cols = len(maze[0])
    
    if maze[start[0]][start[1]] == '#' or maze[end[0]][end[1]] == '#':
        return None  
    
    queue = deque([(start, [start])])  
    visited = {start}  

    while queue:
        (row, col), path = queue.popleft()  

        if (row, col) == end:
            return path  

        neighbors = [(row - 1, col), (row + 1, col), (row, col - 1), (row, col + 1)]
        
        for r, c in neighbors:
            if 0 <= r < rows and 0 <= c < cols and maze[r][c] == '.' and (r, c) not in visited:
                visited.add((r, c))  
                queue.append(((r, c), path + [(r, c)]))  

    return None  

maze = [
    ['.', '#', '.', '.', '.', '.'],
    ['.', '#', '.', '#', '.', '.'],
    ['.', '.', '.', '#', '.', '#'],
    ['#', '.', '#', '.', '.', '.'],
    ['.', '.', '.', '.', '#', '.'],
    ['.', '#', '.', '.', '.', '.']
]

start_point = (0, 0)
end_point = (5, 5)

shortest_path = find_shortest_path_in_maze(maze, start_point, end_point)

if shortest_path:
    print("Shortest path found:", shortest_path)
else:
    print("No path found.")
