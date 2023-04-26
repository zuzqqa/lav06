#include <iostream>
#include <vector>

using namespace std;

bool is_cycle(vector<vector<int>> adj_matrix) {
    int n = adj_matrix.size();
    bool has_all_vertices = true;

    // Sprawdź, czy graf zawiera wszystkie wierzchołki w cyklu
    for (int i = 0; i < n; i++) {
        bool has_edge = false;
        for (int j = 0; j < n; j++) {
            if (adj_matrix[i][j] == 1) {
                has_edge = true;
                break;
            }
        }
        if (!has_edge) {
            has_all_vertices = false;
            break;
        }
    }

    // Sprawdź, czy graf zawiera cykl
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj_matrix[i][j] == 1 && adj_matrix[j][i] == 1) {
                if (has_all_vertices && i == 0 && j == n - 1) {
                    return true; // jeśli graf zawiera wszystkie wierzchołki i krawędź między pierwszym i ostatnim wierzchołkiem, to jest to cykl
                }
                else if (!has_all_vertices && i == j) {
                    return true; // jeśli graf nie zawiera wszystkich wierzchołków i istnieje pętla, to jest to cykl
                }
            }
        }
    }

    return false; // w przeciwnym razie graf nie jest cyklem
}

int main() {
    int t; // liczba grafów
    cin >> t;

    while (t--) {
        int n; // liczba wierzchołków
        cin >> n;

        vector<vector<int>> adj_matrix(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c;
                cin >> c;
                adj_matrix[i][j] = c - '0';
            }
        }

        cout << is_cycle(adj_matrix) << endl;
    }

    return 0;
}
