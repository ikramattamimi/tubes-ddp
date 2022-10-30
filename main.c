#include <stdio.h>
#include <time.h>
#include "waktutanggal.h"
#include "mahasiswa.h"
#include <stdbool.h>
#include "login.h"
#include <stdlib.h>

//======================================= VARIABEL GLOBAL =========================================
Mahasiswa Mhs;
Akun Admin;
int pilLogin;					// Variabel untuk memilih menu pada menu no. 0		(Menu Login)
int pilAdm; 					// Variabel untuk memilih menu pada menu no. 1 		(Menu Admin)
int pilAdmAdm;					// Variabel untuk memilih menu pada menu no. 1.1	(Menu Admin\Kelola Data Admin)
int pilAdmMhs;					// Variabel untuk memilih menu pada menu no. 1.2 	(Menu Admin\Kelola Data Mahasiswa)
int pilMhs;						// Variabel untuk memilih menu pada menu no. 2 		(Menu Login)

int pilBackLogin;				// Variabel untuk memilih kembali ke menu no. 0 	(Menu Login) atau tidak
int pilBackAdm;					// Variabel untuk memilih kembali ke menu no. 1 	(Menu Admin) 
int pilBackAdmAdm;				// Variabel untuk memilih kembali ke menu no. 1.1 	(Menu Admin\Kelola Data Admin) 
int pilBackAdmMhs;				// Variabel untuk memilih kembali ke menu no. 1.2 	(Menu Admin\Kelola Data Mahasiswa)
int pilBackMhs;					// Variabel untuk memilih kembali ke menu no. 2 	(Menu Mahasiswa) 

bool loopLogin = true;			// Variabel untuk loop menu no. 0 		(Menu Login) (Tidak pernah berubah)
bool loopAdm;					// Variabel untuk loop menu no. 1		(Menu Admin)
bool loopAdmAdm;				// Variabel untuk loop menu no. 1.1		(Menu Admin\Kelola Data Admin)
bool loopAdmMhs;				// Variabel untuk loop menu no. 1.2 	(Menu Admin\Kelola Data Mahasiswa)
bool loopMhs;					// Variabel untuk loop menu no. 2		(Menu Mahasiswa)

bool loopBackLogin = true;		// Variabel untuk loop Pilihan Kembali ke menu no. 0	(Menu Login)
bool loopBackAdmAdm;			// Variabel untuk loop pilihan Kembali ke menu no. 1.1	(Menu Admin\Kelola Data Admin)
bool loopBackAdmMhs;			// Variabel untuk loop pilihan Kembali ke menu no. 1.2	(Menu Admin\Kelola Data Mahasiswa)
bool loopBackMhs;				// Variabel untuk loop Pilihan Kembali ke menu no. 2	(Menu Mahasiswa)



//====================================================== MODUL BARIS ======================================================
void Baris() {
	printf("==================================================================================================== \n");
}

//====================================================== MODUL UTAMA ======================================================
int main() {
// 0. MENU LOGIN
	do {
		system("cls");
		Baris();
		printf("                                         Absensi Mahasiswa \n");
		Baris();
		printf(" Silahkan Login Terlebih Dahulu! \n");
		printf("   1. Admin \n");
		printf("   2. Mahasiswa \n");
		printf("   3. Help \n");
		printf("   4. Exit \n");
		Baris();
		printf(" Pilihan : ");
		scanf ("%d", &pilLogin);
		Baris();
		loopBackLogin = true;
		switch(pilLogin) {

//	0.1 LOGIN ADMIN
	case 1	:
		system("cls");
		Baris();
		printf("\t\t\t    Login Admin\n");
		Baris();
		LoginAdm(Admin);
		loopAdm = true;
				
//	1.	MENU ADMIN
	do {
		system("cls");
		Baris();
		printf(" \t\t\t\t     Menu \n");
		Baris();
		printf("   1. Kelola Data Admin \n");
		printf("   2. Kelola Data Mahasiswa \n");
		printf("   3. Logout \n");
		printf("   4. Exit \n");
		Baris();
		printf(" Pilihan : ");
		scanf ("%d", &pilAdm);
		Baris();
		switch(pilAdm) {

//	1.1	KELOLA DATA ADMIN
	case 1:
		do {
			loopAdmAdm=true;
			loopBackAdmAdm=true;
			system("cls");
			Baris();
			printf("                             Kelola Data Admin \n");
			Baris();
			printf("   1. Input Akun Admin Baru \n");
			printf("   2. Ubah Akun Admin \n");
			printf("   3. Hapus Akun Admin \n");
			printf("   4. Tampilkan Seluruh Akun Admin \n");
			printf("   5. Kembali \n");
			Baris();
			printf(" Pilihan : ");
			scanf ("%d", &pilAdmAdm);
			switch(pilAdmAdm) {
									
//	1.1.1	INPUT AKUN ADMIN BARU
	case 1	:
		system("cls");
		Baris();
		printf("\t\t\t    Input Akun Admin Baru\n");
		Baris();
		InputUPAdm(Admin);
		break;
									
//	1.1.2	UBAH AKUN ADMIN
	case 2	:
		system("cls");
		Baris();
		printf("\t\t\t    Ubah Akun Admin\n");
		Baris();
		UbahAkunAdmin(Admin);
		break;
									
//	1.1.3	HAPUS AKUN ADMIN
	case 3	:
		system("cls");
		Baris();
		printf("\t\t\t    Hapus Akun Admin \n");
		Baris();
		HapusAkun(Admin);
		break;
									
//	1.1.4	TAMPILKAN AKUN ADMIN
	case 4	:
		system("cls");
		Baris();
		printf("\t\t\t    Akun-akun Admin \n");
		Baris();
		TampilAkun(Admin);
		break;
									
//	1.1.5	KEMBALI KE MENU NO 1 (MENU ADMIN)
	case 5	:
		loopAdmAdm=false;
		loopBackAdmAdm=false;
		loopBackMhs = false;
		break;
	default :
		printf("\nPilihan tidak ada!\n\n");
	}
								
//	#PILIHAN KEMBALI KE MENU NO 1.1 (KELOLA DATA ADMIN)
	while(loopBackAdmAdm==true) {
		Baris();
		printf(" Kembali ke Menu? \n");
		printf("   1.Yes\n   0.No\n");
		Baris();
		printf(" Pilihan : ");
		scanf ("%d", &pilBackAdmAdm);
		Baris();
		switch(pilBackAdmAdm) {
			case 1:
				loopBackAdmAdm = false;
				break;
			case 0:
				system("cls");
				exit(1);
				break;
			default:
				printf("\nPilihan tidak ada!\n\n");
		}
	};
	} while (loopAdmAdm==1);

break;

//	1.2	KELOLA DATA MAHASISWA
	case 2	:
		do {
			loopAdmMhs = true;
			loopBackAdmMhs=true;
			system("cls");
			Baris();
			printf("\t\t\t    Kelola Data Mahasiswa\n");
			Baris();
			printf("   1. Input Data Mahasiswa \n");
			printf("   2. Ubah Data Mahasiswa \n");
			printf("   3. Hapus Data Mahasiswa \n");
			printf("   4. Kehadiran Hari Ini \n");
			printf("   5. Buka Seluruh Data Mahasiswa \n");
			printf("   6. Kembali \n");
			Baris();
			printf(" Pilihan: ");
			scanf("%d", &pilAdmMhs);
			switch(pilAdmMhs) {
								
//	1.2.1	INPUT DATA MAHASISWA
	case 1	:
		system("cls");
		Baris();
		printf("\t\t\t    Input Data Mahasiswa\n");
		Baris();
		InputDataMahasiswa(Mhs);
		break;
									
//	1.2.2	UBAH DATA MAHASISWA
	case 2	:
		system("cls");
		Baris();
		printf("\t\t\t    Ubah Data Mahasiswa\n");
		Baris();
		UbahDataMhs(Mhs);
		break;
									
//	1.2.3	HAPUS DATA MAHASISWA
	case 3	:
		system("cls");
		
		Baris();
		printf("\t\t\t    Hapus Data Mahasiswa\n");
		Baris();
		HapusData(Mhs);
		break;
									
//	1.2.4	MENAMPILKAN DATA KEHADIRAN HARI INI
	case 4  :
		system("cls");
		
		Baris();
		printf("\t\t\t Kehadiran Hari Ini\n");
		Baris();
		CekTgl(Mhs);
		break;
								
//	1.2.5	MENAMPILKAN SELURUH DATA MAHASISWA
	case 5	:
		system("cls");
		Baris();
		printf("\t\t\t Buka Seluruh Data Mahasiswa\n");
		Baris();
		TampilkanDataMahasiswa(Mhs);
		break;
									
//	1.2.6	KEMBALI KE MENU NO 1 (MENU ADMIN)
	case 6	:
		loopAdmMhs = false;
		loopBackAdmMhs=false;
		loopBackMhs = false;
		break;
	default	:
		printf("Pilihan tidak ada!");
	}
								
//	#PILIHAN KEMBALI KE MENU NO 1.2 (KELOLA DATA MAHASISWA)
	while(loopBackAdmMhs==true) {
		Baris();
		printf(" Kembali ke Menu? \n");
		printf("   1.Yes\n   0.No\n");
		Baris();
		printf(" Pilihan : ");
		scanf ("%d", &pilBackAdmMhs);
		Baris();
		//system("cls");
		switch(pilBackAdmMhs) {
			case 1:
				loopBackAdmMhs = false;
				break;
			case 0:
				system("cls");
				exit(1);
				break;
			default:
				printf("\nPilihan tidak ada!\n\n");
		}
	};
	} while (loopAdmMhs == true);
	break;

//	1.3 LOGOUT ADMIN
	case 3	:
		system("cls");
		loopAdm = false;
		printf("\n Logout berhasil!\n");
		break;
	
//	1.4 EXIT
	case 4	:
		exit(1);
		break;
	default :
		printf("\n Pilihan tidak ada!\n\n");
	}
	} while(loopAdm==true);
	break;

//	0.2	LOGIN MAHASISWA
	case 2	:
		system("cls");
		Baris();
		printf("\t\t\t    Login Mahasiswa\n");
		Baris();
		int nim;
		nim = LoginMhs(Mhs);
		loopMhs = true;
				
//	2.	MENU MAHASISWA
	do {
		loopBackMhs = true;
		system("cls");
		Baris();
		printf("\t\t\t    Menu Mahasiswa\n");
		Baris();
		printf("   1. Input Absensi\n");
		printf("   2. Tampilkan Data Kehadiran Hari Ini \n");
		printf("   3. Logout \n");
		printf("   4. Exit \n");
		Baris();
		printf(" Pilihan : ");
		scanf ("%d", &pilMhs);
		Baris();
		switch(pilMhs) {
						
//	2.1	INPUT ABSENSI
	case 1	:
		system("cls");
		Absensi(Mhs, nim);
		break;
					
//	2.2	TAMPILKAN DATA KEHADIRAN HARI INI
	case 2	:
		system("cls");
		Baris();
		printf("\t\t\t Kehadiran Hari Ini\n");
		Baris();
		CekTgl(Mhs);
		break;
						
//	2.3	LOGOUT MAHASISWA
	case 3	:
		system("cls");
		loopMhs = false;
		loopBackMhs = false;
		printf("\n Logout berhasil!\n");
		break;
						
//	2.4 EXIT
	case 4	:
		system("cls");
		exit(1);
	}
					
//	#PILIHAN KEMBALI KE MENU NO 2 (MENU MAHASISWA)
	while(loopBackMhs==true) {
		Baris();
		printf(" Kembali ke Menu? \n");
		printf("   1.Yes\n   0.No\n");
		Baris();
		printf(" Pilihan : ");
		scanf ("%d", &pilBackMhs);
		Baris();
		system("cls");
		switch (pilBackMhs) {
			case 0	:
				system("cls");
				exit(1);
				break;
			case 1	:
				loopBackMhs=false;
				break;
			default	:
				printf(" Pilihan tidak ada!");
				break;
		}
	} ;
	} while(loopMhs==true);
	break;
			
//	0.3	MENAMPILKAN CARA PAKAI PROGRAM
	case 3	:
		system("cls");
		Baris();
		printf("\t\t\t    Cara Pakai Program\n");
		Baris();
		carapakai();
		break;
			
//	0.4 EXIT
	case 4	:
		system("cls");
		exit(1);
	default :
		printf("\n Pilihan tidak ada. Mohon pilih angka yang ada pada daftar!\n\n");
	}
		
//	#PILIHAN KEMBALI KE MENU NO 0 (MENU LOGIN)
	while(loopBackLogin==true) {
		Baris();
		printf(" Kembali ke Menu Login? \n");
		printf("   1.Yes\n   0.No\n");
		Baris();
		printf(" Pilihan : ");
		scanf ("%d", &pilBackLogin);
		Baris();
		system("cls");
		switch (pilBackLogin) {
			case 0	:
				system("cls");
				exit(1);
				break;
			case 1	:
				loopBackLogin=false;	// KEMBALI KE MENU NO 0 (MENU LOGIN)
				break;
			default	:
				printf(" Pilihan tidak ada!");
				break;
		}
	} ;
	
	
	} while(loopLogin==true);	// LOOP UNTUK KEMBALI KE MENU LOGIN
	
	return 0;
}
