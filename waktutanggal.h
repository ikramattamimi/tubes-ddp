#ifndef WktTgl_H
#define WktTgl_H
#include "boolean.h"


//------------------------------------------------------------------------ADT JAM-------------------------------------------------------------------------------//

//Definisi ADT Jam//
typedef struct
{
	int H; //Jam valid dalam 0 - 23//
	int M; //Menit valid dalam 0 - 59//
	
} jam;

//Konstruktor//

jam CreateJam(jam *J); 
//Membentuk jam dengan nilai default 7.30

jam GetNow();
//Get Jam Lokal Otomatis//

jam MakeJam(int HH, int MM);
//Fungsi Membuat jam//

void SetJam(jam *J);
//Procedur Pengisian Jam//

void GetJam (jam J);
//Procedur Menampilkan Jam//

void GetLate(jam J);
//Procedur Keterlambatan//


//operator//

long int JamToMenit(jam J);
//Fungsi untuk mengkonversi jam ke menit//

jam MenitToJam(long int mn);
//Fungsi untuk mengkonversi menit ke jam//

jam CountLate(jam A, jam B);
//Fungsi menghitung keterlambatan//

boolean IsValid(int H, int M);
//Validitas Jam//


//--------------------------------------------------------------------ADT TANGGAL-------------------------------------------------------------------------------//

//Definisi ADT Tanggal//
typedef struct
{
	int DD; 
	int MM; 
	int YY;
	
} tgl;

//Konstruktor//
void CreateDate(tgl *D); //Membentuk tanggal dengan nilai default 1-1-1900//


tgl GetNowDate(); //Mengambil tanggal sistem lokal//

void GetDate(tgl D);  //Menampilkan tanggal

tgl SetDate(tgl *D);



#endif

