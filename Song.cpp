#include "Song.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>



///////////////////////////////////////////////////////////////////////////////////
////																		   ////
///////////////////////////////////////////////////////////////////////////////////

Song::Song()
{

	 songPath_[ENTRY_SZ];  
	 songName_[ENTRY_SZ];
}

char Song::songListFile_[ENTRY_SZ] = {};
char Song::currentMP3_[ENTRY_SZ] = {};

Song::Song(char* name) {

	
	strncpy(songName_, name, strlen(name) + 1);
};

void Song::SetSongPath(char* path) {

	strncpy(songPath_, path, strlen(path) + 1);

};

 const char* Song::GetSongName() {

	 return songName_;
};

 const char* Song::GetSongPath() {
 
	 return songPath_;
 
 };
 void Song::AppendToListFile() {

	fstream songFile;
	songFile.open(songListFile_, ios::app);
	if (songFile.is_open())
	{

		songFile << songPath_ <<"/"<<  songName_ << endl;
	}
	else
	{
		cout << "File failed to open. " << endl;
	}
	songFile.close();
	songFile.clear(std::ios_base::goodbit);

 };

 void Song::PlaySong() {
 
	 cout << "Currently playing " << songName_ << endl;
 };

 void Song::StopSong() {
 
 
 
 };

 void Song::PrintToConsole() {
	
	 cout << "    Name: " << songName_;

 }
