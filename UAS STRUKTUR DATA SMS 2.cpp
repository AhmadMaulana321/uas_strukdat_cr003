#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Untuk fungsi remove
using namespace std;

struct Baju {
    int id;
    string nama;
    string ukuran;
    string harga; // Mengubah tipe data harga menjadi string
    int stok;
};

struct Pengguna {
    string username;
    string password;
    string role;
};

const int MAX_BAJU = 100;
Baju daftarBaju[MAX_BAJU];
int jumlahBaju = 0;
vector<Pengguna> pengguna;

void registrasi() {
    Pengguna user;
    cout << "Masukkan Username: ";
    cin.ignore();
    getline(cin, user.username);
    cout << "Masukkan Password: ";
    getline(cin, user.password);
    cout << "Masukkan Role (admin/user): ";
    getline(cin, user.role);
    pengguna.push_back(user);
    cout << "Registrasi berhasil!" << endl;
}

bool login(string &role) {
    string username, password;
    cout << "Masukkan Username: ";
    cin.ignore();
    getline(cin, username);
    cout << "Masukkan Password: ";
    getline(cin, password);
    for (auto &user : pengguna) {
        if (user.username == username && user.password == password) {
            role = user.role;
            return true;
        }
    }
    return false;
}

void tambahBaju() {
    if (jumlahBaju < MAX_BAJU) {
        cout << "Masukkan ID Baju: ";
        cin >> daftarBaju[jumlahBaju].id;
        cin.ignore();
        cout << "Masukkan Nama Baju: ";
        getline(cin, daftarBaju[jumlahBaju].nama);
        cout << "Masukkan Ukuran Baju: ";
        getline(cin, daftarBaju[jumlahBaju].ukuran);
        cout << "Masukkan Harga Baju: ";
        getline(cin, daftarBaju[jumlahBaju].harga);
        cout << "Masukkan Stok Baju: ";
        cin >> daftarBaju[jumlahBaju].stok;
        jumlahBaju++;
    } else {
        cout << "Kapasitas penuh!" << endl;
    }
}

void tampilkanBaju() {
    for (int i = 0; i < jumlahBaju; i++) {
        cout << "ID: " << daftarBaju[i].id << ", Nama: " << daftarBaju[i].nama
             << ", Ukuran: " << daftarBaju[i].ukuran << ", Harga: " << daftarBaju[i].harga
             << ", Stok: " << daftarBaju[i].stok << endl;
    }
}

void updateBaju() {
    int id;
    cout << "Masukkan ID Baju yang ingin diupdate: ";
    cin >> id;
    cin.ignore();
    for (int i = 0; i < jumlahBaju; i++) {
        if (daftarBaju[i].id == id) {
            cout << "Masukkan Nama Baju baru: ";
            getline(cin, daftarBaju[i].nama);
            cout << "Masukkan Ukuran Baju baru: ";
            getline(cin, daftarBaju[i].ukuran);
            cout << "Masukkan Harga Baju baru: ";
            getline(cin, daftarBaju[i].harga);
            cout << "Masukkan Stok Baju baru: ";
            cin >> daftarBaju[i].stok;
            cin.ignore();
            return;
        }
    }
    cout << "Baju dengan ID tersebut tidak ditemukan." << endl;
}

void hapusBaju() {
    int id;
    cout << "Masukkan ID Baju yang ingin dihapus: ";
    cin >> id;
    for (int i = 0; i < jumlahBaju; i++) {
        if (daftarBaju[i].id == id) {
            for (int j = i; j < jumlahBaju - 1; j++) {
                daftarBaju[j] = daftarBaju[j + 1];
            }
            jumlahBaju--;
            return;
        }
    }
    cout << "Baju dengan ID tersebut tidak ditemukan." << endl;
}

void menuAdmin() {
    int pilihan;
    do {
        cout << "Menu Admin:\n1. Tambah Baju\n2. Tampilkan Baju\n3. Update Baju\n4. Hapus Baju\n5. Keluar\nPilih: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
            case 1: tambahBaju(); break;
            case 2: tampilkanBaju(); break;
            case 3: updateBaju(); break;
            case 4: hapusBaju(); break;
        }
    } while (pilihan != 5);
}

void menuUser() {
    cout << "Daftar Baju:\n";
    tampilkanBaju();
}

int main() {
    int pilihan;
    string role;
    do {
        cout << "Menu Utama:\n1. Registrasi\n2. Login\n3. Keluar\nPilih: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
            case 1: registrasi(); break;
            case 2: 
                if (login(role)) {
                    if (role == "admin") {
                        menuAdmin();
                    } else if (role == "user") {
                        menuUser();
                    } else {
                        cout << "Role tidak valid." << endl;
                    }
                } else {
                    cout << "Login gagal. Username atau password salah." << endl;
                }
                break;
        }
    } while (pilihan != 3);
    return 0;
}