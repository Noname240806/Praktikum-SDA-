#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    Mahasiswa mhs[5];

    for (int x = 0; x < 5; x++) {
        cout << "Mahasiswa ke-" << x+1 << endl;
        cout << "Nama : ";
        cin >> mhs[x].nama;
        cout << "NIM  : ";
        cin >> mhs[x].nim;
        cout << "IPK  : ";
        cin >> mhs[x].ipk;
        cout << endl;
    }

    int maxIndex = 0;
    for (int b = 1; b < 5; b++) {
        if (mhs[b].ipk > mhs[maxIndex].ipk) {
            maxIndex = b;
        }
    }

    cout << "Mahasiswa dengan IPK tertinggi:" << endl;
    cout << "Nama : " << mhs[maxIndex].nama << endl;
    cout << "NIM  : " << mhs[maxIndex].nim << endl;
    cout << "IPK  : " << mhs[maxIndex].ipk << endl;

    return 0;
}