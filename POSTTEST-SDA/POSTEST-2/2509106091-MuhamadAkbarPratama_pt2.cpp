#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    float harga;
};

Hewan hewanData[100];
int jumlah = 0;

void swapData(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void tampil() {
    if (jumlah == 0) {
        cout << "Data kosong!";
        return;
    }

    Hewan *ptr = hewanData;

    for (int i = 0; i < jumlah; i++) {
        cout << "ID     : " << (ptr+i)->id;
        cout << "Nama   : " << (ptr+i)->nama;
        cout << "Jenis  : " << (ptr+i)->jenis;
        cout << "Harga  : " << (ptr+i)->harga;
        cout << "-------------------";
    }
}

void tambah() {
    if (jumlah >= 100) {
        cout << "Data penuh!";
        return;
    }

    cout << "ID     : ";
    cin >> hewanData[jumlah].id;

    cin.ignore();
    cout << "Nama   : ";
    getline(cin, hewanData[jumlah].nama);

    cout << "Jenis  : ";
    getline(cin, hewanData[jumlah].jenis);

    cout << "Harga  : ";
    cin >> hewanData[jumlah].harga;

    jumlah++;
}

void linearSearchNama() {
    if (jumlah == 0) {
        cout << "Data kosong!";
        return;
    }

    string cari;
    cin.ignore();
    cout << "Masukkan nama: ";
    getline(cin, cari);

    bool ketemu = false;

    for (int i = 0; i < jumlah; i++) {
        if (hewanData[i].nama == cari) {
            swapData(&hewanData[0], &hewanData[i]);

            cout << "Data ditemukan:";
            cout << "ID   : " << hewanData[0].id << endl;
            cout << "Nama : " << hewanData[0].nama << endl;

            ketemu = true;
            break;
        }
    }

    if (!ketemu) cout << "Data tidak ditemukan!\n";
}

void sortID() {
    for (int i = 0; i < jumlah-1; i++) {
        for (int j = i+1; j < jumlah; j++) {
            if (hewanData[i].id > hewanData[j].id) {
                swapData(&hewanData[i], &hewanData[j]);
            }
        }
    }
}

int fibonacciSearch(int x) {
    if (jumlah == 0) return -1;

    sortID();

    int fib2 = 0, fib1 = 1, fib = fib2 + fib1;

    while (fib < jumlah) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1;

    while (fib > 1) {
        int i;
        if (offset + fib2 < jumlah - 1)
            i = offset + fib2;
        else
            i = jumlah - 1;

        if (hewanData[i].id < x) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (hewanData[i].id > x) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else {
            swapData(&hewanData[0], &hewanData[i]);
            return 0;
        }
    }

    if (offset + 1 < jumlah && hewanData[offset+1].id == x) {
        swapData(&hewanData[0], &hewanData[offset+1]);
        return 0;
    }

    return -1;
}

void bubbleSortNama() {
    for (int i = 0; i < jumlah-1; i++) {
        for (int j = 0; j < jumlah-i-1; j++) {
            if (hewanData[j].nama > hewanData[j+1].nama) {
                swapData(&hewanData[j], &hewanData[j+1]);
            }
        }
    }
    cout << "Data diurutkan berdasarkan nama\n";
}

void selectionSortHarga() {
    for (int i = 0; i < jumlah-1; i++) {
        int min = i;
        for (int j = i+1; j < jumlah; j++) {
            if (hewanData[j].harga < hewanData[min].harga) {
                min = j;
            }
        }
        swapData(&hewanData[i], &hewanData[min]);
    }
    cout << "Data diurutkan berdasarkan harga\n";
}

int main() {
    int pilih, idCari;

    do {
        cout << "\n=== PAWCARE PETSHOP ===\n";
        cout << "1. Tampil Data\n";
        cout << "2. Tambah Data\n";
        cout << "3. Cari Nama\n";
        cout << "4. Cari ID\n";
        cout << "5. Sort Nama\n";
        cout << "6. Sort Harga\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch(pilih) {
            case 1: tampil(); break;
            case 2: tambah(); break;
            case 3: linearSearchNama(); break;
            case 4:
                cout << "Masukkan ID: ";
                cin >> idCari;
                if (fibonacciSearch(idCari) != -1)
                    cout << "Data ditemukan\n";
                else
                    cout << "Tidak ditemukan\n";
                break;
            case 5: bubbleSortNama(); break;
            case 6: selectionSortHarga(); break;
        }

    } while (pilih != 0);

    return 0;
}