#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <vector>

#define watch(x) cout << "CURRENT VALUE: " << x << endl;

using namespace std;

struct edge{
    int x1, x2, y1, y2;
    bool isHorizontal() {
        return y1 == y2;
    }
};

edge createEdge(int x1, int y1, int x2, int y2){
    edge Edge;
    Edge.x1 = x1;
    Edge.x2 = x2;
    Edge.y1 = y1;
    Edge.y2 = y2;
    return Edge;
}

int level, width, x;
vector<vector<edge> > fractal;
bool shaded[82][41];

// add all the edges as necessary to the fractal from the previous level
// ensure all edges are created upwards or rightwards
void evolve(int level) {
    int length = width / pow(3, level);
    for (auto u : fractal[level - 1]) {
        edge e1, e2, e3, e4, e5;
        if (u.isHorizontal()) {
            // expand upward
            if (u.y1 == 1 and u.y2 == 1) {
                e1 = createEdge(u.x1, u.y1, u.x1 + length, u.y2); // __
                e2 = createEdge(u.x1 + length, u.y1, u.x1 + length, u.y2 + length); // __|
                e3 = createEdge(u.x1 + length, u.y1 + length, u.x1 + 2 * length, u.y2 + length); // top
                e4 = createEdge(u.x2 - length, u.y2, u.x1 + 2 * length, u.y2 + length); // __| top |
                e5 = createEdge(u.x2 - length, u.y2, u.x2, u.y2); // __ | top | __
                for (int i = u.y1; i <= u.y1 + length; i++) {
                    for (int j = u.x1 + length; j <= u.x2 - length; j++) {
                        shaded[j][i] = true;
                    }
                }
            } else {
                // expand upward
                if (shaded[(u.x1 + u.x2) / 2][u.y1 - 1]) {
                    e1 = createEdge(u.x1, u.y1, u.x1 + length, u.y2); // __
                    e2 = createEdge(u.x1 + length, u.y1, u.x1 + length, u.y2 + length); // __|
                    e3 = createEdge(u.x1 + length, u.y1 + length, u.x1 + 2 * length, u.y2 + length); // top
                    e4 = createEdge(u.x2 - length, u.y2, u.x1 + 2 * length, u.y2 + length); // __| top |
                    e5 = createEdge(u.x2 - length, u.y2, u.x2, u.y2); // __ | top | __
                    for (int i = u.y1; i <= u.y1 + length; i++) {
                        for (int j = u.x1 + length; j <= u.x2 - length; j++) {
                            shaded[j][i] = true;
                        }
                    }
                } // expand downward
                else {
                    e1 = createEdge(u.x1, u.y1, u.x1 + length, u.y2);
                    e2 = createEdge(u.x1 + length, u.y2 - length, u.x1 + length, u.y1);
                    e3 = createEdge(u.x1 + length, u.y1 - length, u.x1 + 2 * length, u.y2 - length);
                    e4 = createEdge(u.x1 + 2 * length, u.y2 - length, u.x2 - length, u.y2);
                    e5 = createEdge(u.x2 - length, u.y2, u.x2, u.y2);
                    for (int i = u.y1; i >= u.y1 - length; i--) {
                        for (int j = u.x1 + length; j <= u.x2 - length; j++) {
                            shaded[j][i] = true;
                        }
                    }
                }
            }
        } else {
            // expand to the left
            if (shaded[u.x1 + 1][(u.y1 + u.y2) / 2]) {
                e1 = createEdge(u.x1, u.y1, u.x2, u.y1 + length);
                e2 = createEdge(u.x1 - length, u.y1 + length, u.x2, u.y1 + length);
                e3 = createEdge(u.x1 - length, u.y1 + length, u.x1 - length, u.y1 + 2 * length);
                e4 = createEdge(u.x1 - length, u.y1 + 2 * length, u.x2, u.y2 - length);
                e5 = createEdge(u.x2, u.y2 - length, u.x2, u.y2);
                for (int i = u.y1 + length; i <= u.y2 - length; i++) {
                    for (int j = u.x1 - length; j <= u.x2; j++) {
                        shaded[j][i] = true;
                    }
                }
            } else { // expand to the right
                e1 = createEdge(u.x1, u.y1, u.x2, u.y1 + length);
                e2 = createEdge(u.x1, u.y1 + length, u.x2 + length, u.y1 + length);
                e3 = createEdge(u.x1 + length, u.y1 + length, u.x1 + length, u.y1 + 2 * length);
                e4 = createEdge(u.x1, u.y1 + 2 * length, u.x2 + length, u.y2 - length);
                e5 = createEdge(u.x2, u.y2 - length, u.x2, u.y2);
                for (int i = u.y1 + length; i <= u.y2 - length; i++) {
                    for (int j = u.x1; j <= u.x2 + length; j++) {
                        shaded[j][i] = true;
                    }
                }
            }
        }
        vector<edge> currentEdge;
        currentEdge.push_back(e1); currentEdge.push_back(e2); currentEdge.push_back(e3);
        currentEdge.push_back(e4); currentEdge.push_back(e5);
        fractal.push_back(currentEdge);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    cin >> level >> width >> x;
    
    for (int i = 0; i <= width; i++) {
        shaded[i][1] = true;
    }
    vector<edge> levelZero;
    edge initEdge;
    initEdge.x1 = 0; initEdge.y1 = 1;
    initEdge.x2 = width; initEdge.y2 = 1;
    levelZero.push_back(initEdge);
    fractal.push_back(levelZero);
    
    for (int i = 1; i <= level; i++) {
        evolve(i);
        for (int j = 41; j >= 0; j--) {
            for (int k = 0; k <= 81; k++) {
                if (shaded[k][j]) cout << "*";
                else cout << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}
