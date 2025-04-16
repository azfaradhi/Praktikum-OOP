#include "Gudang.hpp"
#include "Exception.hpp"
#include "BarangElektronik.hpp"
#include "BarangMakanan.hpp"
#include <iostream>
using namespace std;

Gudang::Gudang(){
    this->kapasitasTotal = DEFAULT_KAPASITAS;
    this->uang = DEFAULT_UANG;
    this->tenagaKerja = DEFAULT_TENAGA_KERJA;
    this->kapasitasTerpakai = 0;
}

Gudang::Gudang(int kapasitas, int uang, int tenagaKerja){
    this->kapasitasTotal = kapasitas;
    this->uang = uang;
    this->tenagaKerja = tenagaKerja;
    this->kapasitasTerpakai = 0;
}

Gudang::~Gudang(){
    for (auto& barang: daftarBarang){
        delete barang;
    }
    daftarBarang.clear();
}

void Gudang::simpanBarang(Barang *barang){

    try{

        BarangMakanan *x = dynamic_cast<BarangMakanan *> (barang);
        if (x != nullptr && x->getHariKedaluwarsa() <= 0){
            delete barang;
            throw BarangKedaluwarsaException();
        }
        if (kapasitasTerpakai + barang->getBerat() > kapasitasTotal){
            delete barang;
            throw KapasitasPenuhException();
        }

        if (uang < 100){
            delete barang;
            throw UangTidakCukupException();
        }

        if (tenagaKerja < 1){
            delete barang;
            throw TenagaKerjaTidakCukupException();
        }

        pakaiKapasitas(barang->getBerat());
        pakaiUang(100);
        pakaiTenagaKerja();

        daftarBarang.push_back(barang);
        cout << "Barang [" << daftarBarang.size()-1 << "] " << barang->getNama() << " berhasil disimpan" << endl;

    }
    catch (BarangKedaluwarsaException& e){
        cout << "Barang makanan sudah kedaluwarsa, buang dulu." << endl;    
    }
    catch (KapasitasPenuhException& e){
        cout << "Kapasitas gudang tidak mencukupi, perluas gudang dulu." << endl;
    }
    catch (UangTidakCukupException& e){
        cout << "Uang tidak cukup, cari pemasukan dulu." << endl;
    }
    catch (TenagaKerjaTidakCukupException& e){
        cout << "Tidak ada tenaga kerja, rekrut dulu." << endl;
    }
}

void Gudang::tambahKapasitas(int kg){
    this->kapasitasTotal += kg;
}

void Gudang::tambahTenagaKerja(int jumlah){
    this->tenagaKerja += jumlah;
}

void Gudang::tambahUang(int jumlah){
    this->uang += jumlah;
}

void Gudang::pakaiKapasitas(int kg){
    if (kapasitasTerpakai + kg > kapasitasTotal){
        throw KapasitasPenuhException();
    }
    kapasitasTerpakai += kg;
}

void Gudang::pakaiUang(int jumlah){
    if (uang < jumlah){
        throw UangTidakCukupException();
    }
    uang -= jumlah;
}

void Gudang::pakaiTenagaKerja(){
    if (tenagaKerja < 1){
        throw TenagaKerjaTidakCukupException();
    }
    tenagaKerja--;
}


void Gudang::sebutBarang(int idx){
    try{
        cout << daftarBarang.at(idx)->getNama() << " - " << daftarBarang.at(idx)->getJenis() << " - " << daftarBarang.at(idx)->getBerat() << "kg" << endl;
    }
    catch (out_of_range& e){
        cout << e.what() << endl;
    }

}
void Gudang::statusGudang() const{
    cout << "Status gudang:" <<  endl;
    cout << "  Kapasitas total: " << this->kapasitasTotal << " kg" << endl;
    cout << "  Kapasitas terpakai: " << this->kapasitasTerpakai << " kg" << endl;
    cout << "  Uang: " << this->uang << endl;
    cout << "  Tenaga kerja: " << this->tenagaKerja << endl;
    cout << "  Barang:" << endl;
    for (int i=0 ; i<daftarBarang.size(); i++){
        cout << "    [" << i << "] " << daftarBarang.at(i)->getNama() << " - " << daftarBarang.at(i)->getJenis() << " - " << daftarBarang.at(i)->getBerat() << "kg" << endl; 
    }
}
