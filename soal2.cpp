#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Deklarasi array untuk menyimpan nominal uang
    vector<int> nominal;

    // Menanyakan jumlah nominal uang yang ingin diinput
    int jumlahNominal;
    cout << "Masukkan jumlah nominal uang: ";
    cin >> jumlahNominal;

    // Loop untuk menerima input nominal uang dari user
    for (int i = 0; i < jumlahNominal; i++)
    {
        int inputAngka;
        cout << "Masukkan nominal uang ke-" << i + 1 << ": ";
        cin >> inputAngka;
        nominal.push_back(inputAngka);
    }

    // Mengurutkan nominal uang menggunakan algoritma Bubble Sort
    for (int i = 0; i < nominal.size() - 1; i++)
    {
        for (int j = 0; j < nominal.size() - i - 1; j++)
        {
            if (nominal[j] > nominal[j + 1])
            {
                swap(nominal[j], nominal[j + 1]);
            }
        }
    }

    // Menampilkan nominal uang yang sudah terurut
    cout << "\nNominal Uang yang Terurut (Kecil ke Besar):" << endl;
    for (int i = 0; i < nominal.size(); i++)
    {
        cout << nominal[i] << " ";
    }
    cout << endl;

    return 0;
}
