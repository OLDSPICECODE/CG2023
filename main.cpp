#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int tam = 96;

class cubito {
public:
    vector<vector<float>> vectores;
    vector<int> camera;
    cubito();

    vector<vector<float>> refresh(vector<int> camera);
    vector<vector<char>> print();
};

cubito::cubito() {
    camera = { 2, 3, 5 };
    vectores = { {1,1,1}, {-1,1,1},{1,-1,1} ,{-1,-1,1} ,{1,1,-1},{-1,1,-1},{1,-1,-1},{-1,-1,-1} };
    //vectores = A,B,C,D,E,F,G,H;
}
vector<vector<float>> cubito::refresh(vector<int> camera) {
    vector<vector<float>> nuev;
    vector<float> v;
    for (int i = 0; i < vectores.size(); i++) {
        v = { camera[0] - vectores[i][0], camera[1] - vectores[i][1],
             camera[2] - vectores[i][2] };
        if (v[2] != 0) {
            v = { (v[0] / v[2]), (v[1] / v[2])};
        }
        else {
            return nuev;
        }
        nuev.push_back(v);
    }
    return nuev;
}

vector<vector<char>> cubito::print() {
    vector<vector<char>> plano;
    vector<char> punt;
    for (float i = 0; i <= tam; i++) {
        for (float j = 0; j <= tam; j++) {
            punt.push_back('.');
        }
        plano.push_back(punt);
        punt.clear();
    }
    return plano;
}

void dibu_linea(vector<vector<char>>& plano, int u1, int v1, int u2, int v2) {
    int dx = abs(u2 - u1);
    int dy = abs(v2 - v1);
    int sx = (u1 < u2) ? 1 : -1;
    int sy = (v1 < v2) ? 1 : -1;
    int err = dx - dy;
    while (true) {
        if (u1 == u2 && v1 == v2)
            break;
        if (((v1 + (tam / 2)) < tam || (v1 + (tam / 2)) >= 0) && ((u1 + (tam / 2)) < tam || (u1 + (tam / 2)) >= 0)) {
            plano[v1 + (tam / 2)][u1 + (tam / 2)] = '@';
        }
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            u1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            v1 += sy;
        }
    }
}
int main() {
    cubito cubito;
    vector<vector<char>> plano;
    vector<vector<char>> plano2;
    vector<vector<float>> coord2D;
    int a = 2;
    int b = 3;
    int c = 5;
    int multp = 12;
    while (true) {
        coord2D = cubito.refresh({ a, b, c });
        plano = cubito.print();
        plano2 = cubito.print();
        dibu_linea(plano, coord2D[0][0] * multp, coord2D[0][1] * multp, coord2D[1][0] * multp, coord2D[1][1] * multp);
        dibu_linea(plano, coord2D[0][0] * multp, coord2D[0][1] * multp, coord2D[2][0] * multp, coord2D[2][1] * multp);
        dibu_linea(plano, coord2D[0][0] * multp, coord2D[0][1] * multp, coord2D[4][0] * multp, coord2D[4][1] * multp);
        dibu_linea(plano, coord2D[1][0] * multp, coord2D[1][1] * multp, coord2D[3][0] * multp, coord2D[3][1] * multp);
        dibu_linea(plano, coord2D[1][0] * multp, coord2D[1][1] * multp, coord2D[5][0] * multp, coord2D[5][1] * multp);
        dibu_linea(plano, coord2D[2][0] * multp, coord2D[2][1] * multp, coord2D[3][0] * multp, coord2D[3][1] * multp);
        dibu_linea(plano, coord2D[2][0] * multp, coord2D[2][1] * multp, coord2D[6][0] * multp, coord2D[6][1] * multp);
        dibu_linea(plano, coord2D[3][0] * multp, coord2D[3][1] * multp, coord2D[7][0] * multp, coord2D[7][1] * multp);
        dibu_linea(plano, coord2D[4][0] * multp, coord2D[4][1] * multp, coord2D[6][0] * multp, coord2D[6][1] * multp);
        dibu_linea(plano, coord2D[4][0] * multp, coord2D[4][1] * multp, coord2D[5][0] * multp, coord2D[5][1] * multp);
        dibu_linea(plano, coord2D[5][0] * multp, coord2D[5][1] * multp, coord2D[7][0] * multp, coord2D[7][1] * multp);
        dibu_linea(plano, coord2D[6][0] * multp, coord2D[6][1] * multp, coord2D[7][0] * multp, coord2D[7][1] * multp);
        /*for (int n = 0; n < coord2D.size(); n++) {
            for (float i = 0; i <= tam; i++) {
                for (float j = 0; j <= tam; j++) {
                    int a = coord2D[n][0] * multp;
                    int b = coord2D[n][1] * multp;
                    if (j == a and i == b) {
                        plano[i][j] = '@';
                    }
                }
            }
        }*/
        
        cout << a << "     " << b << "      " << c << endl;
        for (float i = 40; i <= tam; i++) {
            for (float j = 20; j <= tam; j++) {
                cout << plano[j][i];
            }
            cout << endl;
        }
        char ch;
        cin >> ch;
        cout << ch;
        system("cls");
        if (ch == 'x') {
            break;
        }
        else if (ch == 'a') {
            a = a - 1;
        }
        else if (ch == 'q') {
            a = a + 1;
        }
        else if (ch == 'w') {
            b = b + 1;
        }
        else if (ch == 's') {
            b = b - 1;
        }
        else if (ch == 'e') {
            c = c + 1;
        }
        else if (ch == 'd') {
            c = c - 1;
        }
    }
}