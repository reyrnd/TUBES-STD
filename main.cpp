// Implementation of multi linked list procedures

#include "mll.h"

int main(){
    ListBengkel L;
    createListBengkel(L);

    adrMekanik p;
    adrPelanggan q;

    int menu = -1;

    string nama, no_telp, nama_pelanggan, motor, plat;

    do{
        cout << "\t\tBENGKEL MOTOR" << endl;
        cout << "============================" << endl;
        cout << "1. Tambah Mekanik" << endl;
        cout << "2. Tambah Pelanggan" << endl;
        cout << "3. Hapus semua pelanggan berdasarkan jenis motor" << endl;
        cout << "4. Cari pelanggan berdasarkan mekanik" << endl;
        cout << "5. Tampilkan data bengkel" << endl;
        cout << "Pilih Menu: ";
        cin >> menu;

        switch(menu) {
            case 1:
                cout << "Inputkan nama mekanik baru: ";
                cin >> nama;
                cout << "Inputkan nomor telepon mekanik baru: ";
                cin >> no_telp;

                p = createElemenMekanik(nama, no_telp);
                addMekanik(L, p);
                cout << "Mekanik berhasil ditambahkan!" << endl << endl;
                break;
            case 2:
                cout << "Inputkan nama pelanggan: ";
                cin >> nama_pelanggan;
                cout << "Inputkan jenis motor: ";
                cin >> motor;
                cout << "Inputkan plat motor: ";
                cin.ignore();
                getline(cin, plat);
                cout << "Pilih mekanik yang diinginkan (pake nomor telepon): ";
                cin >> no_telp;

                p = searchMekanik(L, no_telp);

                if(p == nullptr) {
                    cout << "Mekanik dengan nomor telepon " << no_telp << " tidak ditemukan!" << endl;
                } else {
                    q = createElemenPelanggan(nama_pelanggan, motor, plat);
                    addPelanggan(p, q);
                    cout << "Pelanggan berhasil ditambahkan!" << endl;
                }
                break;
            case 3:
                cout << "Masukkan jenis motor yang ingin dihapus: ";
                cin >> motor;

                if(!searchPelangganAll(L, motor)){
                    cout << "Motor yang kamu cari tidak ada!!!" << endl;
                } else {
                    deletePelanggan(L, motor);
                    cout << "Motor dengan jenis " << motor << " sudah DIHAPUS SEMUA" << endl;
                }

                break;
            case 4:
                cout << "Pilih mekanik yang diinginkan (pake nomor telepon): ";
                cin >> no_telp;
                cout << "Masukkan pelanggan yang ingin dicari (berdasarkan nomor plat): ";
                cin.ignore();
                getline(cin, plat);

                p = searchMekanik(L, no_telp);

                if(p != nullptr) {
                    q = searchPelangganByMekanik(p, plat);
                    if(q != nullptr) {
                        cout << "\n========Data Pelanggan yang dicari========" << endl;
                        cout << "Nama: " << q->info.nama << endl;
                        cout << "Motor: " << q->info.motor << endl;
                        cout << "Plat: " << q->info.plat << endl;
                    } else {
                        cout << "pelanggan tidak ditemukan!!!" << endl;
                    }
                } else {
                    cout << "Mekanik tidak ditemukan!!!" << endl;
                }

                break;
            case 5:
                cout << "\n\tData Bengkel" << endl;
                displayList(L);
                break;
            default:
                cout << "PILIH MENU YANG BENAR!!!!"
        }
    } while(menu != 0);
    return 0;
}
