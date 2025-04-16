#include "Playlist.hpp"

Playlist::Playlist(string a){
    this->name = a;
}

const string& Playlist::getName() const{
    return this->name;
}

const vector<Song>& Playlist::getSongs() const{
    return this->songs;
}

void Playlist::addSong(const Song &song){
    for (auto it = songs.begin(); it != songs.end(); it++){
        if (song == *it){
            return;
        }
    }
    songs.push_back(song);
}

bool Playlist::removeSong(const Song &songToRemove){
    for (auto it = songs.begin(); it != songs.end(); it++){
        if (songToRemove == *it){
            songs.erase(it);
            return true;
        }
    }   
    return false;
}

void Playlist::removeSongByIndex(size_t index){
    if (index > songs.size()){
        throw out_of_range("Index out of range");
        return;
    }
    songs.erase(songs.begin() + index);
}

size_t Playlist::numberOfSongs() const{
    return songs.size();
}

ostream &operator<<(ostream &os, const Playlist &pl){
    os << "Playlist: " << pl.getName() << " (" << pl.numberOfSongs() << " lagu)" << endl;
    int idx = 1;
    for (auto it = pl.getSongs().begin(); it != pl.getSongs().end(); it++){
        os << idx << ". " << *it << endl;
        idx++;
    }
    return os;
}