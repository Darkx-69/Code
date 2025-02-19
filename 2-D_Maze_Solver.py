from collections import deque

def find_shortest_path_in_maze(maze, start, end):
    rows = len(maze)
    cols = len(maze[0])
    queue = deque([(start, [start])])  # Initialize queue with start and its path
    visited = {start}  # Initialize visited set
    while queue:
        (row, col), path = queue.popleft()  # Dequeue a cell and its path
        if (row, col) == end:
            return path  # Return path if end is reached
        neighbors = [(row - 1, col), (row + 1, col), (row, col - 1), (row, col + 1)]  # Get neighbors
        for r, c in neighbors:
            if 0 <= r < rows and 0 <= c < cols and maze[r][c] == '.' and (r, c) not in visited:  # Check valid neighbor
                visited.add((r, c))  # Mark neighbor as visited
                queue.append(((r, c), path + [(r, c)]))  # Enqueue neighbor with updated path
    return None  # Return None if no path is found

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

