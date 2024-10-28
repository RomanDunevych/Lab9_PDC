#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

const int MAX_VERTICES = 100;
const int MAX_EDGES = 100;

int adjList[MAX_VERTICES][MAX_EDGES];
int edgeCount[MAX_VERTICES];
bool visited[MAX_VERTICES];
int bfsNumber[MAX_VERTICES];

// Ініціалізація графу
void initializeGraph() {
    for (int i = 0; i < MAX_VERTICES; ++i) {
        edgeCount[i] = 0;
        visited[i] = false;
        bfsNumber[i] = 0;
    }
}

// Додавання ребра
void addEdge(int u, int v) {
    adjList[u][edgeCount[u]++] = v;
    adjList[v][edgeCount[v]++] = u;
}

// Завантаження графу з файлу
void loadGraphFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Помилка відкриття файлу." << endl;
        return;
    }

    int u, v;
    while (file >> u >> v) {
        addEdge(u, v);
    }
    file.close();
}

// Обхід у ширину (BFS)
void BFS(int start) {
    int queue[MAX_VERTICES];
    int front = 0, back = 0;
    queue[back++] = start;
    visited[start] = true;
    int counter = 0;

    cout << "Поточна вершина\tBFS Номер\tВміст черги" << endl;
    cout << "--------------------------------------------------" << endl;

    while (front < back) {
        int current = queue[front++];
        bfsNumber[current] = ++counter;

        // Виведення поточної вершини та BFS номера
        cout << current << "\t\t" << bfsNumber[current] << "\t\t";

        // Обхід сусідніх вершин
        for (int i = 0; i < edgeCount[current]; ++i) {
            int neighbor = adjList[current][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue[back++] = neighbor;
            }
        }

        // Виведення черги
        for (int i = front; i < back; ++i) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Налаштування кодування для української мови
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    initializeGraph();

    string filename;
    int startVertex;

    cout << "Введіть назву файлу: ";
    cin >> filename;
    loadGraphFromFile(filename);

    cout << "Введіть початкову вершину: ";
    cin >> startVertex;

    BFS(startVertex);

    return 0;
}
