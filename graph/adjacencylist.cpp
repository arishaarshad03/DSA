#include<iostream>
using namespace std;

struct edge
{
    vertex* v;
    edge* next;
};

struct vertex
{
    char data;
    vertex* next;
    edge* edgelist;
    bool visited;
    vertex* parent = nullptr;
    int in_degree;
};
vertex* graph = nullptr;
bool isDirected = false; 

void addvertex(char val){
    vertex* temp = new vertex;
    temp ->data = val;
    temp ->next = nullptr;
    temp ->edgelist = nullptr;
    temp ->visited = false;

    if (graph == nullptr){
        graph = temp;
    }
    else {
        vertex* cur = graph;
        while (cur ->next != nullptr){
            cur = cur ->next;
        }
        cur ->next = temp;
    }
}

void addEdge(char v1, char v2)
{
    vertex* from = graph;

    while (from != nullptr)
    {
        if (from->data == v1)
        {
            vertex* to = graph;
            while (to != nullptr)
            {
                if (to->data == v2)
                { 
                    edge* temp = new edge;
                    temp->v = to;
                    temp->next = nullptr;

                    if (from->edgelist == nullptr)
                    {
                        from->edgelist = temp;
                    }
                    else
                    {
                        edge* cur = from->edgelist;
                        while (cur->next != nullptr)
                        {
                            cur = cur->next;
                        }
                        cur->next = temp;
                    }
                    if (isDirected == false)
                    {
                        edge* temp2 = new edge;
                        temp2->v = from;
                        temp2->next = nullptr;

                        if (to->edgelist == nullptr)
                        {
                            to->edgelist = temp2;
                        }
                        else
                        {
                            edge* cur2 = to->edgelist;
                            while (cur2->next != nullptr)
                            {
                                cur2 = cur2->next;
                            }
                            cur2->next = temp2;
                        }
                    }

                    cout << "Edge added successfully\n";
                    return;
                }
                to = to->next;
            }

            cout << "Second vertex not found\n";
            return;
        }

        from = from->next;
    }

    cout << "First vertex not found\n";
}
int degree(char v)
{
    vertex* temp = graph;

    while (temp != nullptr)
    {
        if (temp->data == v)
            break;
        temp = temp->next;
    }

    // if not found
    if (temp == nullptr)
        return -1;

    int count = 0;
    edge* cur = temp->edgelist;

    // count edges
    while (cur != nullptr)
    {
        count++;
        cur = cur->next;
    }

    return count;
}

int outDegree(char v)
{
    vertex* temp = graph;

    // find vertex
    while (temp != nullptr)
    {
        if (temp->data == v)
            break;
        temp = temp->next;
    }

    // if not found
    if (temp == nullptr)
        return -1;

    int count = 0;
    edge* cur = temp->edgelist;

    // count outgoing edges
    while (cur != nullptr)
    {
        count++;
        cur = cur->next;
    }

    return count;
}
int inDegree(char v)
{
    int count = 0;
    vertex* cur = graph;

    // go through all vertices
    while (cur != nullptr)
    {
        edge* e = cur->edgelist;

        // check their edges
        while (e != nullptr)
        {
            if (e->v->data == v)
                count++;

            e = e->next;
        }

        cur = cur->next;
    }

    return count;
}
void display()
{
    vertex* temp = graph;

    if (graph == nullptr)
    {
        cout << "Graph is empty\n";
        return;
    }

    cout << "\n--- Graph (Adjacency List) ---\n";

    while (temp != nullptr)
    {
        cout << temp->data << " -> ";

        edge* e = temp->edgelist;

        if (e == nullptr)
        {
            cout << "NULL";
        }
        else
        {
            while (e != nullptr)
            {
                cout << e->v->data;

                if (e->next != nullptr)
                    cout << " -> ";

                e = e->next;
            }
        }

        cout << endl;
        temp = temp->next;
    }
}

// ------ FOR BFS TRAVERSAL ------


struct queue
{
    vertex* data;
    queue* next = nullptr;
};
queue* front = nullptr;
queue* rear = nullptr;

void enQueue(vertex* val){
    queue* temp = new queue;
    temp ->data = val;
    temp ->next = nullptr;

    // inserting first node
    if(rear==nullptr){
        rear = front = temp;
        cout << "insertion successfull\n";
        return;
    }
    else{
        rear ->next = temp;
        rear = temp;
        cout << "insertion successfull\n";
        return;
    }
}

vertex* dequeue(){
    // empty queue
    if (front == nullptr){
        cout << "queue is empty\n";
        return nullptr;
    }
    queue* cur = front;
    vertex* val = front->data;
    front = front ->next;

    // if queue becomes empty
    if (front == nullptr){
        rear = nullptr;
    }
    delete cur;
    return val;
}   


void resetVertices() {
    vertex* cur = graph;
    while(cur != nullptr) {
        cur->visited = false;
        cur->parent = nullptr;
        cur = cur->next;
    }
}


void BFS(char start)
{
    vertex* cur = graph;

    // find start vertex
    while (cur != nullptr)
    {
        if (cur->data == start)
            break;
        cur = cur->next;
    }

    if (cur == nullptr)
    {
        cout << "Start vertex not found\n";
        return;
    }

    resetVertices();

    // reset queue
    front = rear = nullptr;

    enQueue(cur);
    cur->visited = true;

    cout << "BFS: ";

    while (front != nullptr)
    {
        cur = dequeue();
        cout << cur->data << " ";

        edge* e = cur->edgelist;

        while (e != nullptr)
        {
            if (!e->v->visited)
            {
                e->v->visited = true;
                enQueue(e->v);
            }
            e = e->next;
        }
    }

    cout << endl;
}

void BFS_Path(char start, char dest)
{
    vertex* cur = graph;

    // find start vertex
    while (cur != nullptr)
    {
        if (cur->data == start)
            break;
        cur = cur->next;
    }

    if (cur == nullptr)
    {
        cout << "Start vertex not found\n";
        return;
    }

    vertex* destNode = graph;

    // find destination vertex
    while (destNode != nullptr)
    {
        if (destNode->data == dest)
            break;
        destNode = destNode->next;
    }

    if (destNode == nullptr)
    {
        cout << "Destination vertex not found\n";
        return;
    }

    resetVertices();

    // reset queue
    front = rear = nullptr;

    enQueue(cur);
    cur->visited = true;

    bool found = false;

    while (front != nullptr)
    {
        cur = dequeue();

        if (cur == destNode)
        {
            found = true;
            break;
        }

        edge* e = cur->edgelist;

        while (e != nullptr)
        {
            if (!e->v->visited)
            {
                e->v->visited = true;
                e->v->parent = cur;   // store path
                enQueue(e->v);
            }
            e = e->next;
        }
    }

    if (!found)
    {
        cout << "No path found\n";
        return;
    }

    // build path
    vertex* path[100];
    int count = 0;

    cur = destNode;

    while (cur != nullptr)
    {
        path[count] = cur;
        count++;
        cur = cur->parent;
    }
    for (int i = count - 1; i >= 0; i--)
    {
        cout << path[i]->data << " ";
    }

    cout << endl;
}

// ----- for DFS traversal -----
struct stack{
    vertex* data;
    stack* next = nullptr;
};
stack* top = nullptr;

void push(vertex* val){
    stack* newnode = new stack;
    newnode ->data = val;
    newnode ->next = top;

    top = newnode;
}


vertex* pop (){
    if (top == nullptr){
        cout <<"stack underflow\n";
        return nullptr;
    }
    stack* temp = top;
    vertex* val = top->data;

    top = top->next;
    delete temp;

    return val;
}

void DFS(char start)
{
    vertex* cur = graph;

    // find start vertex
    while (cur != nullptr)
    {
        if (cur->data == start)
            break;
        cur = cur->next;
    }

    if (cur == nullptr)
    {
        cout << "Start vertex not found\n";
        return;
    }

    resetVertices();
    top = nullptr;   

    push(cur);
    cur->visited = true;

    cout << "DFS: ";

    while (top != nullptr)
    {
        cur = pop();
        cout << cur->data << " ";

        edge* e = cur->edgelist;

        while (e != nullptr)
        {
            if (!e->v->visited)
            {
                push(e->v);
                e->v->visited = true;
            }
            e = e->next;
        }
    }

    cout << endl;
}


void DFS_Path(char start, char dest)
{
    vertex* cur = graph;

    // find start vertex
    while (cur != nullptr)
    {
        if (cur->data == start)
            break;
        cur = cur->next;
    }

    if (cur == nullptr)
    {
        cout << "Start vertex not found\n";
        return;
    }

    vertex* destNode = graph;

    // find destination vertex
    while (destNode != nullptr)
    {
        if (destNode->data == dest)
            break;
        destNode = destNode->next;
    }

    if (destNode == nullptr)
    {
        cout << "Destination vertex not found\n";
        return;
    }

    resetVertices();

    // reset stack
    top = nullptr;

    push(cur);
    cur->visited = true;

    bool found = false;

    while (top != nullptr)
    {
        cur = pop();

        if (cur == destNode)
        {
            found = true;
            break;
        }

        edge* e = cur->edgelist;

        while (e != nullptr)
        {
            if (!e->v->visited)
            {
                e->v->visited = true;
                e->v->parent = cur;   // store path
                push(e->v);
            }
            e = e->next;
        }
    }

    if (!found)
    {
        cout << "No path found\n";
        return;
    }

    // build path from destination using parent
    vertex* path[100];
    int count = 0;

    cur = destNode;

    while (cur != nullptr)
    {
        path[count] = cur;
        count++;
        cur = cur->parent;
    }

    cout << "DFS Path: ";

    for (int i = count - 1; i >= 0; i--)
    {
        cout << path[i]->data << " ";
    }

    cout << endl;
}

void undirected_cycle()
{
    resetVertices();

    vertex* cur = graph;

    if (cur == nullptr)
    {
        cout << "Graph is empty\n";
        return;
    }

    while (cur != nullptr)
    {
        if (!cur->visited)
        {
            cur->visited = true;
            cur->parent = nullptr;
            enQueue(cur);

            while (front != nullptr)
            {
                cur = dequeue();

                edge* e = cur->edgelist;

                while (e != nullptr)
                {

                    if (!e->v->visited)
                    {
                        e->v->visited = true;
                        e->v->parent = cur;
                        enQueue(e->v);
                    }
                    else if (e->v->visited && e->v != cur->parent)
                    {
                        cout << "Cycle found.\n";
                        return;
                    }

                    e = e->next;
                }
            }
        }

        cur = cur->next;
    }

    cout << "No cycle.\n";
}


void directed_cycle()
{
    vertex* cur = graph;

    if (cur == nullptr)
    {
        cout << "Graph is empty\n";
        return;
    }

    int total_nodes = 0;

    // calculate in-degree and reset visited
    while (cur != nullptr)
    {
        cur->in_degree = inDegree(cur->data);
        cur->visited = false;
        total_nodes++;
        cur = cur->next;
    }

    // reset queue
    front = rear = nullptr;

    // enqueue nodes with in-degree 0
    cur = graph;
    while (cur != nullptr)
    {
        if (cur->in_degree == 0)
        {
            enQueue(cur);
            cur->visited = true;
        }
        cur = cur->next;
    }

    int processed = 0;

    // BFS processing
    while (front != nullptr)
    {
        vertex* current = dequeue();
        processed++;

        edge* e = current->edgelist;

        while (e != nullptr)
        {
            e->v->in_degree--;

            if (e->v->in_degree == 0 && !e->v->visited)
            {
                e->v->visited = true;
                enQueue(e->v);
            }

            e = e->next;
        }
    }

    // cycle check
    if (processed != total_nodes)
    {
        cout << "Cycle found\n";
    }
    else
    {
        cout << "No cycle\n";
    }
}

int main()
{
    int choice;
    char v1, v2;
    char v;
    
    cout << "Enter 1 for Directed Graph, 0 for Undirected Graph: ";
    cin >> isDirected;

    do
    {
        cout << "\n----- MENU -----\n";
        cout << "1. Add Vertex\n";
        cout << "2. Add Edge\n";
        cout << "3. Degree (Undirected)\n";
        cout << "4. In-Degree (Directed)\n";
        cout << "5. Out-Degree (Directed)\n";
        cout << "7. Display Graph\n";
        cout << "8. bfs traversal\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter vertex: ";
            cin >> v;
            addvertex(v);
            break;

        case 2:
            cout << "Enter edge (v1 v2): ";
            cin >> v1 >> v2;
            addEdge(v1, v2);
            break;

        case 3:
            if (isDirected)
            {
                cout << "Use in/out degree for directed graph\n";
            }
            else
            {
                cout << "Enter vertex: ";
                cin >> v;
                cout << "Degree = " << degree(v) << endl;
            }
            break;

        case 4:
            if (!isDirected)
            {
                cout << "Only for directed graph\n";
            }
            else
            {
                cout << "Enter vertex: ";
                cin >> v;
                cout << "In-Degree = " << inDegree(v) << endl;
            }
            break;

        case 5:
            if (!isDirected)
            {
                cout << "Only for directed graph\n";
            }
            else
            {
                cout << "Enter vertex: ";
                cin >> v;
                cout << "Out-Degree = " << outDegree(v) << endl;
            }
            break;

        case 7:
            display();
            break;
        case 8:
            cout << "Enter start vertex: ";
            cin >> v;
            BFS(v);
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