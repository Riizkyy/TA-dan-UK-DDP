#include <iostream>
using namespace std;

// Fungsi untuk menampilkan papan permainan
void tampilkanPapan(char papan[][5]) {
    cout << "  0 1 2 3 4\n";
    for (int i = 0; i < 5; ++i) {
        cout << i << " ";
        for (int j = 0; j < 5; ++j) {
            cout << papan[i][j] << " ";
        }
        cout << "\n";
    }
}

// Fungsi untuk mengecek apakah ada pemenang atau seri
char cekPemenang(char papan[][5]) {
    // Cek baris dan kolom
    for (int i = 0; i < 5; ++i) {
        if (papan[i][0] == papan[i][1] && papan[i][1] == papan[i][2] && papan[i][2] == papan[i][3] && papan[i][3] == papan[i][4]) {
            return papan[i][0];
        }
        if (papan[0][i] == papan[1][i] && papan[1][i] == papan[2][i] && papan[2][i] == papan[3][i] && papan[3][i] == papan[4][i]) {
            return papan[0][i];
        }
    }

    // Cek diagonal
    if (papan[0][0] == papan[1][1] && papan[1][1] == papan[2][2] && papan[2][2] == papan[3][3] && papan[3][3] == papan[4][4]) {
        return papan[0][0];
    }
    if (papan[0][4] == papan[1][3] && papan[1][3] == papan[2][2] && papan[2][2] == papan[3][1] && papan[3][1] == papan[4][0]) {
        return papan[0][4];
    }

    // Cek seri
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (papan[i][j] == ' ') {
                return ' ';
            }
        }
    }

    return 'S'; // Seri
}

int main() {
    char papan[5][5] = { {' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' '} };
    int baris, kolom;
    char pemain = 'X';

    do {
        // Tampilkan papan permainan
        tampilkanPapan(papan);

        // Input baris dan kolom
        cout << "Pemain " << pemain << ", masukkan baris (0-4): ";
        cin >> baris;
        cout << "Pemain " << pemain << ", masukkan kolom (0-4): ";
        cin >> kolom;

        // Periksa apakah langkah valid
        if (baris >= 0 && baris < 5 && kolom >= 0 && kolom < 5 && papan[baris][kolom] == ' ') {
            papan[baris][kolom] = pemain;

            // Ganti pemain
            pemain = (pemain == 'X') ? 'O' : 'X';
        } else {
            cout << "Langkah tidak valid. Silakan coba lagi.\n";
        }

        // Periksa apakah ada pemenang atau seri
        char status = cekPemenang(papan);

        if (status == 'X' || status == 'O') {
            tampilkanPapan(papan);
            cout << "Pemain " << status << " menang! Selamat!\n";
            break;
        } else if (status == 'S') {
            tampilkanPapan(papan);
            cout << "Permainan seri. Silakan coba lagi.\n";
            break;
        }

    } while (true);

    return 0;
}

