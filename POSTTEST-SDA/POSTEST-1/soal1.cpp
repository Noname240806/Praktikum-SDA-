// Nama: Muhamad Akbar Pratama
// Nim : 2509106091
#include <iostream>
using namespace std;

int main() {
    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};

    int min = A[0];
    int index = 0;

    for (int i = 1; i < 8; i++) {
        if (A[i] < min) {
            min = A[i];
            index = i;
        }
    }

    cout << "Nilai minimum: " << min << endl;
    cout << "Indeks minimum: " << index << endl;

    return 0;
}

// Pseudocode:
// 1  min <- A[0]            = 1
// 2  for i <- 1 to n-1      = (n-1)
// 3     if A[i] < min       = (n-1)
// 4        min <- A[i]      = tergantung kondisi
// 5  return min             = 1

// Tmin(n) (Best Case):
// Kondisi: elemen pertama sudah minimum.
// Baris 4 tidak pernah dijalankan.
// Tmin(n) = 1 + (n-1) + (n-1) + 1
// Tmin(n) = 2n
// Big-O Best Case = O(n)

// Tmax(n) (Worst Case):
// Kondisi: setiap elemen lebih kecil dari sebelumnya.
// Baris 4 dijalankan (n-1) kali.
// Tmax(n) = 1 + (n-1) + (n-1) + (n-1) + 1
// Tmax(n) = 3n
// Big-O Worst Case = O(n)

// Kesimpulan:
// Best Case  = O(n)
// Worst Case = O(n)