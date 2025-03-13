#include "Authenticator.hpp"

Authenticator::Authenticator(){
    this->secretResource = "Ini adalah data rahasia!";
    this->currentUser = nullptr;
    this->userCount = 0;
    for (int i = 0; i < MAX_USERS; i++){
        this->users[i] = nullptr;
    }
}
 
void Authenticator::registerUser(const string &username, const string &password, bool isAdmin){
    if (this->userCount == MAX_USERS){
        cout << "Gagal: Kapasitas user penuh!" << endl;
        return;
    }
    for (int i =0; i < this->userCount; i++){
        if (username == this->users[i]->getUsername()){
            cout << "Gagal: Username sudah digunakan!" << endl;
            return;
        }
    }
    if (isAdmin){
        this->users[userCount] = new AdminUser(username,password);
        this->userCount++;
    }
    else{
        this->users[userCount] = new User(username,password);
        this->userCount++;
    }

    cout << "Sukses: User " << username <<" berhasil terdaftar!" << endl;
}


void Authenticator::login(const string &username, const string &password){
    for (int i = 0; i<this->userCount; i++){
        if (username == this->users[i]->getUsername()){
            if (this->users[i]->checkPassword(password)){
                cout << "Sukses: Login berhasil! Selamat datang, "<< username << "." << endl;
                this->currentUser = this->users[i];
                return;
            }
            else{
                cout <<"Gagal: Username atau password salah!" <<endl;
                return;
            }
        }
    }
    cout <<"Gagal: Username atau password salah!" <<endl;
}

void Authenticator::logout(){
    if (this->currentUser == nullptr){
        cout << "Gagal: Tidak ada user yang sedang login!" << endl;
        return;
    }
    else{
        cout << "Sukses: User " << this->currentUser->getUsername() << " telah logout." << endl;
        this->currentUser = nullptr;
    }
}

void Authenticator::accessResource() const{
    if (this->currentUser == nullptr){
        cout <<"Akses ditolak! Silakan login terlebih dahulu." << endl;
    }
    else{
        cout << "Resource: " << this->secretResource << endl;
    }
}

void Authenticator::setResource(const string &newResource){
    if (this->currentUser == nullptr){
        cout << "Gagal: Tidak bisa mengubah resource! Silakan login terlebih dahulu."<< endl;
    }
    else{
        if ((this->currentUser->isAdmin())){
            this->secretResource = newResource;
            cout << "Sukses: Resource telah diperbarui oleh "<<this->currentUser->getUsername() <<"." << endl;
        }
        else{
            cout << "Gagal: Tidak bisa mengubah resource! Hanya admin yang dapat melakukan ini." << endl;
        }
    }
}

Authenticator::~Authenticator(){
    for (int i = 0; i < this->userCount; i++){
        delete this->users[i];
    }
}