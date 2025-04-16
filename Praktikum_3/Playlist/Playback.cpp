#include "Playback.hpp"

void Playback::addToQueue(const Song &song){
    playbackQueue.push(song);
}

void Playback::addToQueue(const Playlist &playlist){
    for (auto it = playlist.getSongs().begin(); it !=playlist.getSongs().end(); it++){
        playbackQueue.push(*it);
    }
}

void Playback::next(){
    if (playbackQueue.empty()){
        cout << "Antrian kosong" << endl;
        return;
    }
    cout << "Memutar: " << playbackQueue.front()<< endl;
    playbackQueue.pop();
}

void Playback::playAll(){
    while (!playbackQueue.empty()){
        this->next();
    }
}


void Playback::skip(){
    if (playbackQueue.empty()){
        cout << "Antrian kosong" << endl;
        return;
    }
    playbackQueue.pop();
}

void Playback::clearQueue(){
    while (!playbackQueue.empty()){
        playbackQueue.pop();
    }
}

bool Playback::isEmpty() const{
    return (playbackQueue.empty());
}

size_t Playback::queueSize() const{
    return playbackQueue.size();
}