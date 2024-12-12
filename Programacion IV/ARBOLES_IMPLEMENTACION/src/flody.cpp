#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge
{
    char init;
    char end;
    int weight;
};

vector<vector<int>> FloydWarshall(const vector<char>& vertices, const vector<Edge>& aristas)
{
    int n = int(vertices.size());
    vector<vector<int>> dist(n, vector<int>(n, numeric_limits<int>::max()));
    vector<vector<int>> next(n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i)
        dist[i][i] = 0;

    for (const auto& arista : aristas)
    {
        int u = arista.init - '1';
        int v = arista.end - '1';
        int weight = arista.weight;
        dist[u][v] = weight;
        next[u][v] = v;

    }

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][k] != numeric_limits<int>::max() && dist[k][j] != numeric_limits<int>::max() &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    return next;
}

void displayPath(vector<vector<int>> next, char init, char end)
{
    int u = init - '1';
    int v = end - '1';

    if (next[u][v] == -1)
    {
        cout << "No hay un camino entre " << init << " y " << end << endl;
        return;
    }

    cout << init;
    while (u != v)
    {
        u = next[u][v];
        cout << " -> " << static_cast<char>(u + '1');
    }
    cout << endl;
}
void test1(){
    vector<char> vertices = {'1','2','3','4','5'};
    vector<Edge> aristas =
            {{'1', '3', 6},
             {'1', '4', 3},
             {'2', '1', 3},
             {'3', '4', 2},
             {'4', '2', 1},
             {'4', '3', 1},
             {'5', '2', 4},
             {'5', '4', 2}
            };
    vector<vector<int>> tourMatrix = FloydWarshall(vertices, aristas);
    displayPath(tourMatrix, '5','1');//5->4->2->1
    displayPath(tourMatrix, '2','3');//2->1->4->3
    displayPath(tourMatrix, '5','3');//5->4->3
}

void test2(){
    vector<char> vertices = {'1','2','3','4'};
    vector<Edge> aristas =
            {{'1', '3', -2},
             {'2', '1', 4},
             {'2', '3', 3},
             {'3', '4', 2},
             {'4', '2', -1}
            };
    vector<vector<int>> tourMatrix = FloydWarshall(vertices, aristas);
    displayPath(tourMatrix, '2','3');//2->1->3
    displayPath(tourMatrix, '4','3');//4->2->1->3
    displayPath(tourMatrix, '2','4');//2->1->3->4
}
int main()
{
    test1();
    test2();

    return 0;
}
