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

#define MAX 100

Hewan antrian[MAX];
int front = -1, rear = -1;

Hewan riwayat[MAX];
int top = -1;

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
        cout << "\nID     : " << (ptr+i)->id;
        cout << "\nNama   : " << (ptr+i)->nama;
        cout << "\nJenis  : " << (ptr+i)->jenis;
        cout << "\nHarga  : " << (ptr+i)->harga;
        cout << "\n-------------------";
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
            cout << "\nID   : " << hewanData[0].id;
            cout << "\nNama : " << hewanData[0].nama << endl;

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

void enqueue() {
    if (rear == MAX - 1) {
        cout << "Antrian penuh!\n";
        return;
    }

    Hewan h;

    cout << "ID Hewan   : "; cin >> h.id;
    cin.ignore();
    cout << "Nama Hewan : "; getline(cin, h.nama);
    cout << "Jenis      : "; getline(cin, h.jenis);
    cout << "Harga      : "; cin >> h.harga;

    if (front == -1) front = 0;

    antrian[++rear] = h;
    cout << "Masuk antrian!\n";
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Antrian kosong!\n";
        return;
    }

    Hewan h = antrian[front];

    cout << "Memanggil pasien:\n";
    cout << "ID   : " << h.id << endl;
    cout << "Nama : " << h.nama << endl;

    riwayat[++top] = h;

    front++;
}

void tampilAntrian() {
    if (front == -1 || front > rear) {
        cout << "Antrian kosong!\n";
        return;
    }

    Hewan *ptr = antrian;

    cout << "\n=== ANTRIAN ===\n";
    for (int i = front; i <= rear; i++) {
        cout << (ptr+i)->id << " - " << (ptr+i)->nama << endl;
    }
}

void tampilRiwayat() {
    if (top == -1) {
        cout << "Riwayat kosong!\n";
        return;
    }

    Hewan *ptr = riwayat;

    cout << "\n=== RIWAYAT ===\n";
    for (int i = top; i >= 0; i--) {
        cout << (ptr+i)->id << " - " << (ptr+i)->nama << endl;
    }
}

void popRiwayat() {
    if (top == -1) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "Hapus riwayat: " << riwayat[top].nama << endl;
    top--;
}

void peek() {
    if (front != -1 && front <= rear)
        cout << "Antrian depan: " << antrian[front].nama << endl;
    else
        cout << "Antrian kosong\n";

    if (top != -1)
        cout << "Riwayat terakhir: " << riwayat[top].nama << endl;
    else
        cout << "Riwayat kosong\n";
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
        cout << "7. Tambah Antrian\n";
        cout << "8. Panggil Pasien\n";
        cout << "9. Tampil Antrian\n";
        cout << "10. Tampil Riwayat\n";
        cout << "11. Hapus Riwayat\n";
        cout << "12. Peek\n";
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
            case 7: enqueue(); break;
            case 8: dequeue(); break;
            case 9: tampilAntrian(); break;
            case 10: tampilRiwayat(); break;
            case 11: popRiwayat(); break;
            case 12: peek(); break;
        }

    } while (pilih != 0);

    return 0;
}