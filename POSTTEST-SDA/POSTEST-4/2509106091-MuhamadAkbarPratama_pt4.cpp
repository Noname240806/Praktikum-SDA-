#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    float harga;
    Hewan *next;
};

Hewan *headData = NULL;

// Queue
Hewan *front = NULL;
Hewan *rear = NULL;

// Stack
Hewan *top = NULL;

void swapData(Hewan *a, Hewan *b) {
    int tempId = a->id;
    string tempNama = a->nama;
    string tempJenis = a->jenis;
    float tempHarga = a->harga;

    a->id = b->id;
    a->nama = b->nama;
    a->jenis = b->jenis;
    a->harga = b->harga;

    b->id = tempId;
    b->nama = tempNama;
    b->jenis = tempJenis;
    b->harga = tempHarga;
}

void tambahNode(Hewan *&head, Hewan *baru) {
    if (head == NULL) {
        head = baru;
    } else {
        Hewan *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void tambahData() {
    Hewan *baru = new Hewan;

    cout << "ID     : ";
    cin >> baru->id;
    cin.ignore();

    cout << "Nama   : ";
    getline(cin, baru->nama);

    cout << "Jenis  : ";
    getline(cin, baru->jenis);

    cout << "Harga  : ";
    cin >> baru->harga;

    baru->next = NULL;

    tambahNode(headData, baru);

    cout << "\nData berhasil ditambahkan!\n";
}

void tampilData() {
    if (headData == NULL) {
        cout << "\nData kosong!\n";
        return;
    }

    Hewan *temp = headData;

    cout << "\n===============================================================\n";
    cout << left << setw(10) << "ID"
         << setw(20) << "Nama"
         << setw(20) << "Jenis"
         << setw(15) << "Harga" << endl;
    cout << "===============================================================\n";

    while (temp != NULL) {
        cout << left << setw(10) << temp->id
             << setw(20) << temp->nama
             << setw(20) << temp->jenis
             << setw(15) << temp->harga << endl;

        temp = temp->next;
    }

    cout << "===============================================================\n";
}

void enqueue() {
    Hewan *baru = new Hewan;

    cout << "ID Hewan   : ";
    cin >> baru->id;
    cin.ignore();

    cout << "Nama Hewan : ";
    getline(cin, baru->nama);

    cout << "Jenis      : ";
    getline(cin, baru->jenis);

    cout << "Harga      : ";
    cin >> baru->harga;

    baru->next = NULL;

    if (front == NULL) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }

    cout << "\nData berhasil masuk ke antrian!\n";
}

void dequeue() {
    if (front == NULL) {
        cout << "\nAntrian kosong! Tidak bisa dequeue.\n";
        return;
    }

    Hewan *hapus = front;

    cout << "\nData yang dipanggil:\n";
    cout << "ID    : " << hapus->id << endl;
    cout << "Nama  : " << hapus->nama << endl;
    cout << "Jenis : " << hapus->jenis << endl;
    cout << "Harga : " << hapus->harga << endl;

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    Hewan *riwayatBaru = new Hewan;
    riwayatBaru->id = hapus->id;
    riwayatBaru->nama = hapus->nama;
    riwayatBaru->jenis = hapus->jenis;
    riwayatBaru->harga = hapus->harga;

    riwayatBaru->next = top;
    top = riwayatBaru;

    delete hapus;
}

void push() {
    Hewan *baru = new Hewan;

    cout << "ID Hewan   : ";
    cin >> baru->id;
    cin.ignore();

    cout << "Nama Hewan : ";
    getline(cin, baru->nama);

    cout << "Jenis      : ";
    getline(cin, baru->jenis);

    cout << "Harga      : ";
    cin >> baru->harga;

    baru->next = top;
    top = baru;

    cout << "\nData berhasil masuk ke stack!\n";
}

void pop() {
    if (top == NULL) {
        cout << "\nStack kosong! Tidak bisa pop.\n";
        return;
    }

    Hewan *hapus = top;

    cout << "\nData yang dihapus dari stack:\n";
    cout << "ID    : " << hapus->id << endl;
    cout << "Nama  : " << hapus->nama << endl;
    cout << "Jenis : " << hapus->jenis << endl;
    cout << "Harga : " << hapus->harga << endl;

    top = top->next;
    delete hapus;
}

void peek() {
    cout << "\n=== PEEK ===\n";

    if (front != NULL) {
        cout << "Antrian Terdepan : " << front->nama << endl;
    } else {
        cout << "Antrian kosong!\n";
    }

    if (top != NULL) {
        cout << "Stack Teratas    : " << top->nama << endl;
    } else {
        cout << "Stack kosong!\n";
    }
}

void tampilAntrian() {
    if (front == NULL) {
        cout << "\nAntrian kosong!\n";
        return;
    }

    Hewan *temp = front;

    cout << "\n===================== ANTRIAN =====================\n";
    cout << left << setw(10) << "ID"
         << setw(20) << "Nama"
         << setw(20) << "Jenis"
         << setw(15) << "Harga" << endl;
    cout << "===================================================\n";

    while (temp != NULL) {
        cout << left << setw(10) << temp->id
             << setw(20) << temp->nama
             << setw(20) << temp->jenis
             << setw(15) << temp->harga << endl;

        temp = temp->next;
    }

    cout << "===================================================\n";
}

void tampilRiwayat() {
    if (top == NULL) {
        cout << "\nRiwayat kosong!\n";
        return;
    }

    Hewan *temp = top;

    cout << "\n===================== RIWAYAT =====================\n";
    cout << left << setw(10) << "ID"
         << setw(20) << "Nama"
         << setw(20) << "Jenis"
         << setw(15) << "Harga" << endl;
    cout << "===================================================\n";

    while (temp != NULL) {
        cout << left << setw(10) << temp->id
             << setw(20) << temp->nama
             << setw(20) << temp->jenis
             << setw(15) << temp->harga << endl;

        temp = temp->next;
    }

    cout << "===================================================\n";
}

int main() {
    int pilih;

    do {
        cout << "\n=========== PAWCARE PETSHOP ===========\n";
        cout << "1. Tambah Data Hewan\n";
        cout << "2. Tampil Data Hewan\n";
        cout << "3. Enqueue\n";
        cout << "4. Dequeue\n";
        cout << "5. Push\n";
        cout << "6. Pop\n";
        cout << "7. Peek\n";
        cout << "8. Tampil Antrian\n";
        cout << "9. Tampil Riwayat\n";
        cout << "0. Keluar\n";
        cout << "Pilih Menu : ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                tambahData();
                break;
            case 2:
                tampilData();
                break;
            case 3:
                enqueue();
                break;
            case 4:
                dequeue();
                break;
            case 5:
                push();
                break;
            case 6:
                pop();
                break;
            case 7:
                peek();
                break;
            case 8:
                tampilAntrian();
                break;
            case 9:
                tampilRiwayat();
                break;
            case 0:
                cout << "\nProgram selesai.\n";
                break;
            default:
                cout << "\nMenu tidak tersedia!\n";
        }

    } while (pilih != 0);

    return 0;
}