#include <iostream>
using namespace std;

const int MAXN = 100;

struct Vertex {
    int data;
};

int n;
bool isDirected;

Vertex Graph[MAXN];
int adj_matrix[MAXN][MAXN];

// stack for finding path
int stackArr[MAXN];
int top = -1;

void push(int val) {
    if (top >= n - 1) {
        cout << "Stack overflow!\n";
        return;
    }
    stackArr[++top] = val;
}

int pop() {
    if (top < 0) {
        cout << "Stack underflow!\n";
        return -1;
    }
    return stackArr[top--];
}

void initGraph() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj_matrix[i][j] = 0;
}

void buildGraph() {
    cout << "For each pair of vertices, enter 1 if edge exists, 0 if not.\n\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == j) { adj_matrix[i][j] = 0; continue; }

            // for undirected,skip lower triangle
            if (!isDirected && j < i) {
                adj_matrix[i][j] = adj_matrix[j][i];
                continue;
            }

            int val;
            do {
                if (isDirected)
                    cout << "Edge from " << i << " -> " << j << "? (1/0): ";
                else
                    cout << "Edge between " << i << " -- " << j << "? (1/0): ";
                cin >> val;
            } while (val != 0 && val != 1);

            adj_matrix[i][j] = val;
            if (!isDirected)
                adj_matrix[j][i] = val; // mirror for undirected
        }
    }
    cout << "Graph built successfully!\n";
}
bool isValid(int v) {
    if (v < 0 || v >= n) {
        cout << "Invalid vertex!\n";
        return false;
    }
    return true;
}

void addEdge(int v1, int v2) {
    if (!isValid(v1) || !isValid(v2)) return;

    adj_matrix[v1][v2] = 1;

    if (!isDirected)
        adj_matrix[v2][v1] = 1;
}

void removeEdge(int v1, int v2) {
    if (!isValid(v1) || !isValid(v2)) return;

    adj_matrix[v1][v2] = 0;

    if (!isDirected)
        adj_matrix[v2][v1] = 0;
}

void findDegree(int v) {
    if (!isValid(v)) return;

    int indeg = 0, outdeg = 0;

    for (int i = 0; i < n; i++) {
        outdeg += adj_matrix[v][i];
        indeg  += adj_matrix[i][v];
    }
    int deg = indeg + outdeg;

    if (isDirected)
        cout << "Total Degree = " << deg<<"\n";
    else
        cout << "Degree = " << outdeg << "\n";
}

void findInDegree(int v) {
    if (!isValid(v)) return;

    int indeg = 0;

    for (int i = 0; i < n; i++)
        indeg += adj_matrix[i][v];

    cout << "In-Degree = " << indeg << "\n";
}

void findOutDegree(int v) {
    if (!isValid(v)) return;

    int outdeg = 0;

    for (int i = 0; i < n; i++)
        outdeg += adj_matrix[v][i];

    cout << "Out-Degree = " << outdeg << "\n";
}

void isAdjacent(int v1, int v2) {
    if (!isValid(v1) || !isValid(v2)) return;

    if (!isDirected){
        if (adj_matrix[v1][v2] == 1){
            cout<< v1 << " & "<<v2<<"are adjacent\n";
        }
        else{
            cout<< v1 << " & "<<v2<<"are not adjacent\n";
        }
    }
    else{
        if (adj_matrix[v1][v2] == 1){
            cout<< v1 << " & "<<v2<<"are adjacent\n";
        }
        else{
            cout<< v1 << " & "<<v2<<"are not adjacent\n";
        }
    }
}

void findNeighbours(int v) {
    if (!isValid(v)) return;

    cout << "Neighbours: ";
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (adj_matrix[v][i] == 1) {
            cout << i << " ";
            found = true;
        }
    }

    if (!found) cout << "None";
    cout << endl;
}

void outputall() {
    cout << "\nAdjacency Matrix:\n";
    cout << "    ";
    for (int i = 0; i < n; i++) cout << i << " ";
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << i << " [ ";
        for (int j = 0; j < n; j++)
            cout << adj_matrix[i][j] << " ";
        cout << "]\n";
    }
}

void findPathDFS(int src, int dest) {
    if (!isValid(src) || !isValid(dest)) return;

    bool visited[MAXN] = {false};
    int parent[MAXN];

    for (int i = 0; i < n; i++)
        parent[i] = -1;

    top = -1; // reset stack

    push(src);
    visited[src] = true;

    bool found = false;

    while (top != -1) {

        int current = pop();

        if (current == dest) {
            found = true;
            break;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (adj_matrix[current][i] == 1 && !visited[i]) {
                push(i);
                visited[i] = true;
                parent[i] = current;
            }
        }
    }

    if (!found) {
        cout << "No path exists\n";
        return;
    }

    int path[MAXN];
    int idx = 0;

    // trace from dest back to src, filling path[]
    int temp = dest;
    while (temp != -1) {
        path[idx] = temp;
        idx++;
        temp = parent[temp];
    }

    // print path
    int i = idx - 1;
    while (i >= 0) {
        cout << path[i] << " ";
        i--;
    }
}


int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Is the graph directed? (1 = Yes, 0 = No): ";
    cin >> isDirected;

    initGraph();
    buildGraph();

    int choice;

    do {
        cout << "\n------ MENU ------\n";
        cout << "1. Add Edge\n";
        cout << "2. Remove Edge\n";
        cout << "3. Check Degree\n";
        cout << "4. In-Degree\n";
        cout << "5. Out-Degree\n";
        cout << "6. Check Adjacency\n";
        cout << "7. Find Neighbours\n";
        cout << "8. Display Matrix\n";
        cout << "9. find path\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int v1, v2, v;

        switch (choice) {

        case 1:
            cout << "Enter v1 v2: ";
            cin >> v1 >> v2;
            addEdge(v1, v2);
            break;

        case 2:
            cout << "Enter v1 v2: ";
            cin >> v1 >> v2;
            removeEdge(v1, v2);
            break;

        case 3:
            cout << "Enter vertex: ";
            cin >> v;
            findDegree(v);
            break;

        case 4:
            cout << "Enter vertex: ";
            cin >> v;
            findInDegree(v);
            break;

        case 5:
            cout << "Enter vertex: ";
            cin >> v;
            findOutDegree(v);
            break;

        case 6:
            cout << "Enter v1 v2: ";
            cin >> v1 >> v2;
            isAdjacent(v1, v2);
            break;

        case 7:
            cout << "Enter vertex: ";
            cin >> v;
            findNeighbours(v);
            break;

        case 8:
            outputall();
            break;

        case 9:
            cout << "Enter source and destination: ";
            cin >> v1 >> v2;
            findPathDFS(v1, v2);
            break;
        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}