#ifndef mahasiswa_h
#define mahasiswa_h
#include "waktutanggal.h"

typedef struct {
tgl now;
int NIM;
char Kelas[10];
char Nama[100];
jam masuk;
char Status[20];
char sandi[20];
char Ket[10];
}Mahasiswa;

void InputDataMahasiswa (Mahasiswa M);		// PROSEDUR UNTUK INPUT DATA MAHASISWA DAN MENYIMPANNYA KE DALAM FILE

int CekNIM(Mahasiswa M,int nim); 			// FUNCTION UNTUK MENGECEK NIM  YANG DIINPUTKAN

void Absensi (Mahasiswa M, int Nim_Absen);	// PROSEDUR UNTUK INPUT DATA ABSENSI MAHASISWA

void sort(Mahasiswa M);						// PROSEDUR UNTUK MENGURUTKAN DATA PADA CONSOLE

void TampilkanDataMahasiswa (Mahasiswa M);	// PROSEDUR UNTUK MENAMPILKAN DATA MAHASISWA KE CONSOLE

void HapusData(Mahasiswa M);				// Prosedur untuk menghapus salah satu atau semua data mahasiswa

void carapakai();

int CekTgl(Mahasiswa M);


//void SalinFileHadir(Mahasiswa M);

//void KehadiranHariIni(Mahasiswa M);
#endif
