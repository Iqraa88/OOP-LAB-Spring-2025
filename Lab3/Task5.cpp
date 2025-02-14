#include<iostream>
using namespace std;


class MusicPlayer{

string playList[50];
string currentlyPlaying;
int count;
int flag;
public:

MusicPlayer(){
    count=0;
    flag=0;
}
void addSong(int numberOfSongs){
    if(numberOfSongs<50){
        cin.ignore();
        for(int i=0; i<numberOfSongs; i++){
            cout<< "Enter Name of Song "<< i+1 << " :"<< endl;
            getline(cin, playList[i]);
            count++;

        }
    }
    else{
        cout<<" Insufficeint Storage!"<< endl;
    }

    cout<<"--------------------------------"<< endl;
}

void removeSong(int index){

    if(index>=0 && index<count){
       
        playList[index]=" ";
        for(int i=0; i<count; i++){
        playList[index]= playList[index+1];
    }

     count--;
    }
    else{
        cout<<"Invalid Index!"<< endl;
    }

    cout<<"-----------------------------"<< endl;
}

void playSong(string song){
    for(int i=0; i<count; i++){
        if(song== playList[i]){
            currentlyPlaying= song;
            flag=1;

        }
    }
    if(!flag){
        cout<< "No Song Found!"<< endl;
    }
}
void displaySongs(){
    for(int i=0; i<count; i++){
        cout<< "Song" << i+1<< " :" << playList[i]<< endl;
    }
    cout<<"----------------------------"<< endl;
}

string getCurrentlyPlaying(){
    return currentlyPlaying;
}





};


int main(){

MusicPlayer Spotify;
   int num, index;
    cout<<" How many songs do you want to add?"<< endl;
    cin>> num;

    Spotify.addSong(num);
    Spotify.displaySongs();
    Spotify.playSong("Gul");
    cout<<"You are currently listening to : "<<Spotify.getCurrentlyPlaying()<< " "<< endl;

    
    cout<<" Enter Index of song you want to remove?"<< endl;
    cin>> index;

    Spotify.removeSong(index);
    Spotify.displaySongs();

    

    return 0;
}
