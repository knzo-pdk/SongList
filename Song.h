#pragma once
#include<string>

using namespace std;

const int ENTRY_SZ = 256;



class Song
{
private:
	char songPath_[ENTRY_SZ];   // Contains the full path name
	char songName_[ENTRY_SZ];   // Song name extracted from the path

public:

	// Store the path name of the song list file
	static char songListFile_[ENTRY_SZ];
	static char currentMP3_[ENTRY_SZ];

	Song();
	Song(char* name);
//	~Song();
	void SetSongPath(char* path);
	const char* GetSongName();
	const char* GetSongPath();
	void AppendToListFile();
	void PlaySong();
	void StopSong();
	void PrintToConsole();
};



