#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
#include<iomanip>
#include <ctype.h>
#include "Song.h"
#include <cstddef>
#include "LinkedList.h"

using namespace std;

LinkedList LL;
Node *nPtr;
string filepath, str, sLen;
char letter;
char sName[256], sClass[256], sMass[256], sLenn[256];
double dMass, dLen;
long a, chain;
string *sfilepath;
Song* SgPtr;


char pathmp3[ENTRY_SZ], namemp3[ENTRY_SZ];
int counterForSongObjects;

string newstring;
int i, numLines;
int *openChecker = &i;
void DeleteSong();

void PrintAllShellData();

void RecursiveRemoval(long);
void RecursiveRemoval(long a)
	{

	
		if (a == LL.GetListLength())        // <- Listlength luon luon = const, a ? initialized, ??? ??? ??
		{                                   // Listlength will reduce at every time a link is removed ; a initialize as zero when called and passed  
			cout << "Removed all. " << endl;            //variable long a initialize as zero when called and passed
			return;
		}
		else
		{
			SgPtr = (Song*)LL.RemoveLinkFromFront();
			delete SgPtr;
			return RecursiveRemoval(a);
		}
	
	}


void PrintAllShellData() {
	if (LL.GetListLength() == 0) {
		cout << "DB file unopened or deleted" << endl;
	}
	else {
		cout << endl;
		SgPtr = (Song*)LL.GetFirstNode();
		for (i = 0; SgPtr != 0; i++)
		{
			SgPtr->PrintToConsole();
			SgPtr = (Song*)LL.GetNextNode();
			cout << endl;
			counterForSongObjects++;
		}
		cout << endl;
		cout << "Printed " << LL.GetListLength() << " Song objects." << endl << endl;
		
	}
}
void SplitFileName(const string& str);
void SplitFileName(const string& str)
{
	char pathmp3[ENTRY_SZ], namemp3[ENTRY_SZ];
	string newstring;
	
	size_t found = str.find_last_of("/\\");

//	cout << " path: " << str.substr(0, found) << '\n';
	strcpy(pathmp3, str.substr(0, found).c_str());
	//	cout << "??" << str.substr(0, found) << endl;

//	cout << " file: " << str.substr(found + 1) << '\n';
	strcpy(namemp3, str.substr(found + 1).c_str());

	Song *songPtr = new Song(namemp3);
	songPtr->SetSongPath(pathmp3);                                             
	LL.AddLinkToBack(songPtr);



	

}

void LoadSongFile();
void LoadSongFile() {

	fstream songFile;
	cout << "Enter the full file path: ";
	cin >> filepath;

	songFile.open(filepath);
	int numLines = 0;
	int counterForSongObjects = 0;
	char str[255];
	if (songFile.is_open()) {
		int j;
		for (j = 0; j < 256; j++) {
			Song::songListFile_[j] = filepath[j];
			if (filepath[j] == 0) {
				cout << endl;
				break;
			}
		}
		for (numLines = 0; songFile.peek() != EOF; numLines++) {
			songFile.getline(str, 255);
			counterForSongObjects++;  // this is working as same as numLines - so can use numLines instead of this variable.
			newstring = str;
			SplitFileName(newstring);

			 
													
		}

		openChecker = &counterForSongObjects;
		cout << "Loaded file and read " << counterForSongObjects << " Song objects." << endl << endl;
	}
}

void AddNewSong();
void AddNewSong() {

	
	if (openChecker == &i) {

		cout << "File hasn't been opened." << endl;
	}
	else {

		
		char pathmp3[ENTRY_SZ], namemp3[ENTRY_SZ];
		cout << "Enter the full song path and name: ";
		cin.ignore();       // reason of need an ignore here : the input from main menu make one "enter key" stays
							// in the input buffer. So , this ignore should be moved to that menu - before the command return. 
		getline(cin, str);
		


		size_t found = str.find_last_of("/\\"); //	??? ???? ("/\\") = ?????

		cout << " path: " << str.substr(0, found) << '\n';
		strcpy(pathmp3, str.substr(0, found).c_str());
		//	cout << "??" << str.substr(0, found) << endl;


		cout << " file: " << str.substr(found + 1) << '\n';
		strcpy(namemp3, str.substr(found + 1).c_str());
		Song *songPtr2 = new Song(namemp3);
		songPtr2->SetSongPath(pathmp3);

		songPtr2->AppendToListFile();
		LL.AddLinkToBack(songPtr2);
	}
}



char menu()
{
	char aletter;
	cout << "Make a selection: " << endl;
	cout << "a) Open a song file" << endl;
	cout << "b) Add a song" << endl;
	cout << "c) Delete a song" << endl;
	cout << "d) Play a song" << endl;
	cout << "e) Print all songs" << endl;
	cout << "f) Quit" << endl;

	cin >> aletter;
	// suggest to put one ignore from cin here to solve issue of followed console reading.
	return (aletter);
}


void songSearcher();
void songSearcher() {
	char strArr[256];
	if (openChecker == &i) {

		cout << "File hasn't been opened." << endl;
	}
	else {

		cout << "Enter the song name with extension: ";
	


		cin.getline(strArr, 256);

		cout << " ?? ????: " << strArr << endl;

		// Where to perform List traverse search? in main or LL.CPP or song.cpp 
		// How to tell List that user input will be of Song class?

		// 1) Pass string to LL.cpp then use it inside LL.cpp..
		// 2) Make function inside LL.cpp to use GetfirstNode, GetNextNode;


	}
}


Song* FindASong();
Song* FindASong() {

	Song* sPtr;
	cout << "Enter the song name with extension: ";
	cin.ignore();
	cin.getline(namemp3, ENTRY_SZ);

	sPtr = (Song*)LL.GetFirstNode();
	for (i = 0; sPtr != 0; i++)
	{
		if (strcmp(sPtr->GetSongName(), namemp3) == 0)
		{
			return sPtr;
		};
		sPtr = (Song*)LL.GetNextNode();
	}
	return NULL;
}


void DeleteSong() {

	if (LL.GetListLength() == 0) {
		cout << "DB file unopened or deleted" << endl;
		return;
	}
	else SgPtr = FindASong();
	if (SgPtr != NULL) {
		LL.RemoveALink();
		cout << "Deleted song" << endl;
		cout << endl;
		delete SgPtr;
	}
	else {
		cout << "That song is not in the songlist." << endl;
	}
	return;
}


void PlayASong() {

	if (LL.GetListLength() == 0) {
		cout << "DB file unopened or deleted" << endl;
		return;
	}
	else SgPtr = FindASong();
	if (SgPtr != NULL) {
		SgPtr->PlaySong();
	}
	else {
		cout << "That song is not in the songlist." << endl;
	}
	return;
}



void SaveAllSongs() {
	if (LL.GetListLength() == 0) {
		cout << "DB file unopened or deleted" << endl;
	}
	else {
		fstream s;
		s.open(filepath, ios::out);
		if (s.is_open())
		{

			SgPtr = (Song*)LL.GetFirstNode();
			for (i = 0; SgPtr != 0; i++)
			{
				s << SgPtr->GetSongPath() << "/" << SgPtr->GetSongName() << endl;
				SgPtr = (Song*)LL.GetNextNode();
			}
			cout << endl;
			cout << "Saved " << LL.GetListLength() << " Song objects." << endl << endl;
		}
	}
}



int main() {

	do {
		letter = menu();
		switch (letter) {
		case 'a': {
			//			ReadFromFile();
			RecursiveRemoval(0);
			LoadSongFile();
			break;
		}
		case 'b': {

			//		UserInputShell();
			AddNewSong();

			break;
		}
		case 'c': {                 // This option to find a song and delete that single matched song only, don't use recursive here.
			// 
			DeleteSong();
			SaveAllSongs();
			break;
		}
		case 'd': {

			PlayASong();
			break;
		}
		case 'e': {

			PrintAllShellData();
			
			break;
		}
		case 'f': {

			break;
		}

		}
	} while (letter != 'f');
}


