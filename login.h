#ifndef login_h
#define login_h
#include <stdio.h>
#include "mahasiswa.h"

typedef struct{
	char uname[20];
	char pass[20];
}Akun;

void 	InputUPAdm(Akun acc);							// PROSEDUR UNTUK INPUT DATA USERNAME ADMIN

int 	CekUname(Akun acc, char id[20]);				// FUNGSI UNTUK MENGECEK USERNAME ADMIN

void 	LoginAdm (Akun acc);							// PROSEDUR UNTUK LOGIN ADMIN

int 	CekPass(Akun acc, char id[20], char pw[8]);		// FUNGSI UNTUK MENGECEK PW ADMIN

int 	LoginMhs (Mahasiswa M);							// PROSEDUR UNTUK LOGIN MAHASISWA

void 	HapusAkun(Akun acc);							// PROSEDUR UNTUK HAPUS AKUN ADMIN

void 	TampilAkun(Akun acc);							// PROSEDUR UNTUK TAMPILKAN AKUN ADMIN KE KONSOLE

int 	CekPassMhs(Mahasiswa M, char pw[20]);			// FUNGSI UNTUK CEK SANDI MAHASISWA

void 	UbahAkunAdmin(Akun acc);						// PROCEDUR MENGUBAH AKUN ADMIN
#endif
