#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a state (jug A, jug B)
typedef struct {
    int a;
    int b;
} State;

// Structure for queue elements (state + path)
typedef struct QueueNode {
    State state;
    State *path; // Array of states representing the path
    int path_len;
    struct QueueNode *next;
} QueueNode;

// Queue operations
QueueNode *front = NULL;
QueueNode *rear = NULL;

void enqueue(State state, State *path, int path_len) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->state = state;
    newNode->path = (State *)malloc(sizeof(State) * (path_len + 1));
    for (int i = 0; i < path_len; i++) {
        newNode->path[i] = path[i];
    }
    newNode->path[path_len] = state; // Append the current state to the path
    newNode->path_len = path_len + 1;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

State *dequeue(State *state, int *path_len) {
    if (front == NULL) {
        return NULL;
    }
    State *path = front->path;
    *state = front->state;
    *path_len = front->path_len;
    QueueNode *temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    return path;
}

bool isEmpty() {
    return front == NULL;
}

// Function to check if a state has been visited
bool isVisited(State state, State *visited, int visited_count) {
    for (int i = 0; i < visited_count; i++) {
        if (visited[i].a == state.a && visited[i].b == state.b) {
            return true;
        }
    }
    return false;
}

// Water jug problem solver using BFS
State *waterJugProblem(int capacity_a, int capacity_b, int target, int *solution_len) {
    State initialState = {0, 0};
    enqueue(initialState, NULL, 0);
    State *visited = (State *)malloc(sizeof(State) * 1000); // Adjust size as needed
    int visited_count = 0;
    while (!isEmpty()) {
        State currentState;
        int path_len;
        State *path = dequeue(&currentState, &path_len);
        if (currentState.a == target || currentState.b == target) {
            *solution_len = path_len;
            return path;
        }
        if (isVisited(currentState, visited, visited_count)) {
            free(path);
            continue;
        }
        visited[visited_count++] = currentState;
        // Possible actions
        State actions[6];
        actions[0] = (State){capacity_a, currentState.b}; // Fill A
        actions[1] = (State){currentState.a, capacity_b}; // Fill B
        actions[2] = (State){0, currentState.b}; // Empty A
        actions[3] = (State){currentState.a, 0}; // Empty B
        actions[4] = (State){
            (currentState.a + currentState.b > capacity_b) ? currentState.a + currentState.b - capacity_b : 0,
            (currentState.a + currentState.b < capacity_b) ? currentState.a + currentState.b : capacity_b
        }; // Pour A to B
        actions[5] = (State){
            (currentState.a + currentState.b < capacity_a) ? currentState.a + currentState.b : capacity_a,
            (currentState.a + currentState.b > capacity_a) ? currentState.a + currentState.b - capacity_a : 0
        }; // Pour B to A
        for (int i = 0; i < 6; i++) {
            enqueue(actions[i], path, path_len);
        }
        free(path); // Free the previous path.
    }
    free(visited);
    return NULL; // No solution found
}

int main() {
    int capacity_a = 4;
    int capacity_b = 3;
    int target = 2;
    int solution_len = 0;
    State *solution = waterJugProblem(capacity_a, capacity_b, target, &solution_len);
    if (solution != NULL) {
        printf("Solution found:\n");
        for (int i = 0; i < solution_len; i++) {
            printf("(%d, %d)\n", solution[i].a, solution[i].b);
        }
        free(solution);
    } else {
        printf("No solution found.\n");
    }
    return 0;
}
