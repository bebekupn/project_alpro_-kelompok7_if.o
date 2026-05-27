#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

struct PRODUK {
    string id;
    string stok;
    string harga;
    string nama_produk;
    string nama_rak;
};

PRODUK produk1[100];
int total_data = 0;

void input_data(){
    int jumlah;
    cout << "\nmasukkan jumlah barang yang ingin di input :";
    cin >> jumlah;

    for(int i = 0; i < jumlah; i++){
        PRODUK *ptr = &produk1[i];
        int p = total_data;
        cout << "\ndata ke -" << p+1 << endl;
        cout << "masukkan nama rak :"; getline(cin >> ws,ptr->nama_rak);
        cout << "masukkan nama produk :"; getline(cin >> ws,ptr->nama_produk);
        cout << "masukkan id produk :"; getline(cin >> ws,ptr->id);
        cout << "masukkan stok produk :"; getline(cin >> ws,ptr->stok);
        cout << "masukkan harga produk :"; getline(cin >> ws,ptr->harga);
        total_data++;
    }
} 

void BubbleSort(PRODUK arr[],int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j].nama_produk > arr[j+1].nama_produk){
                swap(arr[j],arr[j+1]);
            }
        }
    }

}

void tampilkan_data(){
    if(total_data == 0){
    cout << "\ndata maasih kosong.\n"; 
    }else{
        BubbleSort(produk1, total_data);
        for(int i = 0; i < total_data; i++){
            PRODUK *ptr = &produk1[i];
            cout << i+1 << ". nama produk :" << ptr->nama_produk << endl;
            cout << "  " << "nama rak :" << ptr->nama_rak << endl;
            cout << "  " << "id produk :" << ptr->id << endl;
            cout << "  " << "stok produk :" << ptr->stok << endl;
            cout << "  " << "harga produk :" << ptr->harga << endl;
        }
    }
}

void binnarySearch(PRODUK arr[], int n, string target){
    int kiri = 0;
    int kanan = n-1;
    bool ditemukan = false;
    BubbleSort(produk1, total_data);
    while(kiri <= kanan){
        int tengah = kiri + (kanan-kiri) /2;
        if(arr[tengah].nama_produk == target){
            cout << "data ditemukan pada urutan ke-" << tengah + 1 << ":" << endl;
            cout << "nama produk :" << arr[tengah].nama_produk << endl;
            cout << "nama rak :" << arr[tengah].nama_rak << endl;
            cout << "id produk :" << arr[tengah].id << endl;
            cout << "stok produk :" << arr[tengah].stok << endl;
            cout << "harga produk :" << arr[tengah].harga << endl;
            ditemukan = true;
            break;
        }
        if(arr[tengah].nama_produk < target){
            kiri = tengah + 1;
        }else{
            kanan = tengah - 1;
        }
    }
    if(!ditemukan){
        cout << "\ndata dengan nama" << target << "tidak ditemukan\n";
    }
}

void ubah_detail(){
    if(total_data == 0){
        cout << "\ndata masih kosong\n";
    }
    string cari;
    bool ditemukan = false;
    cout << "masukkan nama produk yang ingin diubah :";
    getline(cin >> ws, cari);

    for(int i = 0; i < total_data; i ++){
        PRODUK *ptr = &produk1[i];
        if (ptr->nama_produk == cari){
        cout << "====data ditemukan====\n";
        cout << "====masukkan data baru===";
        cout << "masukkan nama rak baru : "; getline(cin >> ws, ptr->nama_rak);
        cout << "masukkan nama produk baru : "; getline(cin >> ws, ptr->nama_produk);
        cout << "masukkan id produk baru : "; getline(cin >> ws, ptr->id);
        cout << "masukkan stok produk baru : "; getline(cin >> ws, ptr->stok);
        cout << "masukkan harga produk baru : "; getline(cin >> ws, ptr->harga);
        cout << "====data berhasil diganti====\n";
        ditemukan = true;
        break;
        }
    }
    if (!ditemukan){
        cout << "data"<< cari << "tidak ditemukan\n";
    }
}

void cari_data(){
    string cari;
    cout << "=====binary search=====\n";
    cout << "masukkan data yang ingin dicari :";
    getline(cin >> ws, cari);
    binnarySearch(produk1, total_data, cari);
}

void exportData(PRODUK arr[], int n) {
    ofstream file("data_produk.txt");
    if (file.is_open()) {
        for (int i = 0; i < n; i++) {
            file << arr[i].nama_produk << endl;
            file << arr[i].nama_rak << endl;
            file << arr[i].id << endl;
            file << arr[i].stok << endl;
            file << arr[i].harga << endl;
        }
        file.close();
        cout << "Data berhasil diexport ke 'data_produk.txt'!\n";
    } else {
        cout << "Gagal membuka file!\n";
    }
}

void importData(PRODUK arr[], int &n) {
    ifstream file("data_produk.txt");
    if (file.is_open()) {
        n = 0; 
        while (getline(file, arr[n].nama_produk) && getline(file, arr[n].nama_rak) && getline(file, arr[n].id) && getline(file, arr[n].stok) && getline(file, arr[n].harga)) {
            n++;
        }
        file.close();
        cout << "Data berhasil diimport dari 'data_produk.txt'!\n";
    } else {
        cout << "File tidak ditemukan atau gagal dibuka!\n";
    }
}

void file(){
    int menu;
    cout << "1. export data \n";
    cout << "2. import data \n";
    cout << "pilih menu :"; cin >> menu;
    switch(menu){
        case 1 :{
            exportData(produk1, total_data);
            break;
        }
        case 2 :{
            importData(produk1, total_data);
            break;
        }

    }
}

int fibonacci(int n){
    if(n <= 1){
        return n;
    }else{
        return fibonacci(n - 1) + (n - 2);
    }
}

int long long faktorial(int n){
    if(n <= 1){
        return n;
    }else{
        return n*faktorial(n-1);
    }

}  


void rekursi(){

    int pilih;
    cout << "\n=====menu rekursi=====\n";
    cout << "1. fibonacci\n";
    cout << "2. faktorial\n";
    cout << "pilih menu :";
    cin >> pilih;
    switch(pilih){
        case 1 :{
            int deret = 0;
            cout << "berapa deret suku pertama fibonacci :";cin >> deret;
            cout << "deret fibonacci untuk " << deret << "suku pertama :\n";
            for(int i = 0; i < deret ; i++){
                cout << fibonacci(i) << " ";
            } 
            cout << endl;
            break;
        }
        case 2 :{
            int n;
            cout << "masukkan angka faktorial :";cin >> n;
            cout << "faktorial dari " << n << " :" << faktorial(n) << endl; 
            break;
        }
        default:{
            cout << "input tidak valid.\n";
            break;
        }

    }

}


int main(){

    int menu;
    while(true){
        cout << "\n== Manajemen Produk Toko ==" << endl;
        cout << "MENU UTAMA" << endl;
        cout << " 1. Input data barang" << endl;
        cout << " 2. Tampilkan data barang (sorted)" << endl;
        cout << " 3. Cari produk berdasarkan nama produk" << endl;
        cout << " 4. Ubah detail produk" << endl;
        cout << " 5. export dan import data" << endl;
        cout << " 6. rekusi" << endl;
        cout << " 7. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> menu;

        switch(menu){
            case 1 :{
                input_data();
                break;
            }
            case 2 :{
                tampilkan_data();
                break;
            }
            case 3 :{
                cari_data();
                break;
            }
            case 4 :{
                ubah_detail();
                break;
            }
            case 5 :{
                file();
                break;
            }
            case 6 :{
                rekursi();
                break;
            }
            case 7 :{
                cout << "program will be executed\n";
                return 1;
            }
            default :{
                cout << "input tidak valid\n";
                break;
            }

        }

    }



return 0;
}