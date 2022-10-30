#include "login.h"
#include "mahasiswa.h"
#include <stdbool.h>
#include <string.h>

//======================== PROSEDUR UNTUK INPUT DATA AKUN ADMIN ============================
void InputUPAdm(Akun acc) {

	FILE *fp;
	fp = fopen("Data_Akun.dat", "ab");

	int check;
	do {
		printf(" Username\t= ");
		scanf("%s", &acc.uname);

		check = CekUname (acc, acc.uname);

		if (check == 1) {
			printf(" Username telah digunakan, masukkan usernme yang berbeda!\n\n");
		}
	} while (check == 1);

	printf(" Sandi\t\t= ");
	scanf("%s", &acc.pass);

	fwrite(&acc, sizeof(acc),1,fp);
	fclose(fp);
}

//======================== FUNGSI UNTUK MENGECEK USERNAME ADMIN ============================
int CekUname(Akun acc, char id[20]) {
	FILE *fp;

	fp = fopen("Data_Akun.dat","rb");
	while (fread(&acc, sizeof(acc),1,fp)) {
		if(strcmp(id, acc.uname)==0) {
			return 1;
		}
	}
	fclose(fp);
}

//======================== PROSEDUR UNTUK LOGIN ADMIN ============================
void LoginAdm (Akun acc) {
	FILE *fp;
	fp = fopen("Data_Akun.dat", "rb");

	char un[20];
	char pwd[20];
	int check;
	int check1;

	//Input dan cek username admin
	do {
		printf(" Username\t= ");
		scanf("%s", &un);

		check = CekUname (acc, un);

		if (check == 0) {
			printf(" Username tidak ditemukan, check kembali username anda!\n\n");
		}
	} while (check == 0);

	//Input dan cek sandi admin
	do {
		printf(" Sandi\t\t= ");
		scanf("%s", &pwd);
		check1 = CekPass (acc, un, pwd);

		if (check1 == 0) {
			printf(" Kata sandi salah, check kembali kata sandi anda!\n\n");
		}
	} while (check1 == 0);
	fclose(fp);
}

//======================== FUNGSI UNTUK MENGECEK PW ADMIN ============================
int CekPass(Akun acc, char un[20], char pw[20]) {
	FILE *fp;
	int c = 1;

	fp = fopen("Data_Akun.dat","rb");
	while (fread(&acc, sizeof(acc),1,fp)) {
		if(strcmp(un, acc.uname)==0 && strcmp(pw, acc.pass)==0) {
			fclose(fp);
			return 1;
		}
	}
}

//======================== FUNGSI UNTUK LOGIN MAHASISWA ============================
int LoginMhs (Mahasiswa M) {
	FILE *fp;
	fp = fopen("Data_Mahasiswa.txt", "rb");

//	int nim;
	char pwd[8];
	int check;
	int nim;
	do {
		printf(" NIM\t\t= ");
		scanf("%i", &nim);
		check = CekNIM (M, nim);

		if (check == 0) {
			printf(" NIM tidak ditemukan, cek kembali username anda!\n\n");
		}
	} while (check == 0);

	int check1;
	do {
		printf(" Sandi\t\t= ");
		scanf("%s", &pwd);
		check1 = CekPassMhs(M, pwd);

		if (check1 == 0) {
			printf(" Kata sandi salah, check kembali kata sandi anda!\n\n");
		}
	} while (check1 == 0);
	fclose(fp);
	return nim;
}

//======================== PROSEDUR UNTUK HAPUS AKUN ADMIN ============================
void HapusAkun(Akun acc) {
	FILE *fpo;
	FILE *fpt;
	int pil;
	char unCopy[20];
	char unHapus[20];

	printf("   1. Hapus Seluruh Akun Admin\n");
	printf("   2. Hapus Salah Satu Akun Admin\n");
	printf("   3. Batal\n");
	Baris();
	printf(" Pilihan : ");
	scanf ("%d", &pil);
//	if (pil == 2)
	switch (pil) {
		case 1:
			fpo = fopen("Data_Akun.dat","wb");
			printf("\nSemua data berhasil dihapus!\n");
			fclose(fpo);
			break;
		case 2:
			Baris();
			printf(" Masukan username : ");
			scanf("%s",&unHapus);
			if (CekUname(acc, unHapus) == 0) {
				printf("\n ID %s tidak ditemukan\n\n", unHapus);
			} else {
				fpo = fopen("Data_Akun.dat","rb");
				fpt = fopen("Temp_Akun.dat","wb");
				while (fread(&acc, sizeof(acc), 1, fpo)) {

					if ( strcmp(acc.uname, unHapus)!=0) {
						//Menyalin data file yang tidak ingin dihapus
						fwrite(&acc, sizeof(acc), 1, fpt);
					}
				}
				fclose(fpo);
				fclose(fpt);
				fpo = fopen("Data_Akun.dat","wb");
				fpt = fopen("Temp_Akun.dat","rb");
				while(fread(&acc,sizeof(acc),1,fpt)) {
					fwrite(&acc,sizeof(acc),1,fpo);
				}
				printf("\n Data Berhasil Dihapus\n");
				fclose(fpo);
				fclose(fpt);
				break;
			case 3:
				break;
			}
	}

}

//======================== PROSEDUR UNTUK TAMPILKAN AKUN ADMIN KE KONSOLE ============================
void TampilAkun(Akun acc) {
	FILE *fptampilakun;
	fptampilakun = fopen("Data_Akun.dat", "rb");

	printf("Username\t\tSandi\n");
	//sort(M);

	while(fread(&acc, sizeof(acc), 1, fptampilakun)) {
		printf("%s\t\t%s\n", acc.uname, acc.pass);
	}
	fclose(fptampilakun);
}

//======================== FUNGSI UNTUK CEK SANDI MAHASISWA ============================
int CekPassMhs(Mahasiswa M, char pw[20]) {
	FILE *fp;
	int c = 1;

	fp = fopen("Data_Mahasiswa.txt","rb");
	while (fread(&M, sizeof(M),1,fp)) {
		if(strcmp(pw, M.sandi)==0) {
			fclose(fp);
			return 1;
		}
	}
}

//================================================= PROCEDUR MENGUBAH AKUN ADMIN =================================================
void UbahAkunAdmin(Akun acc) {
	char usernameUbah[20];
	char s[20];
	int check;
	FILE *fpt;
	FILE *fpo;
	int r,pilUbah, nimUbah;

	do {
		printf(" Username\t= ");
		scanf("%s", &usernameUbah);
		check = CekUname (acc, usernameUbah);
		if (check == 0) {
			printf(" Username tidak ditemukan, check kembali username anda!\n\n");
		}
	} while (check == 0);
	
	fpo = fopen("Data_Akun.dat","rb");
	fpt = fopen("Temp_Data.txt","wb");
	
	while (fread(&acc,sizeof(acc),1,fpo)) {
		strcpy(s,acc.uname);
		if (strcmp(s, usernameUbah)!=0) {
			fwrite(&acc,sizeof(acc),1,fpt);
		} else if (strcmp(s, usernameUbah)==0) {
			printf("   1. Ubah Username\n");
			printf("   2. Ubah Sandi\n");
			printf("   3. Ubah Keseluruhan\n");
			printf(" Pilihan : ");
			scanf ("%d", &pilUbah);
			Baris();
			switch (pilUbah) {
				case 1:
					printf(" Masukkan Username : ");
					scanf("%s",&acc.uname);
					break;
				case 2:
					printf(" Masukkan Sandi : ");
					scanf("%s",&acc.pass);
					break;
				case 3:
					printf(" Masukkan Username : ");
					scanf("%s",&acc.uname);
					printf(" Masukkan Sandi : ");
					scanf("%s",&acc.pass);
					break;
				default:
					printf("\n Error!\n\n");
					break;
			}
			fwrite(&acc, sizeof(acc),1,fpt);
		}
	}
	fclose(fpo);
	fclose(fpt);
	fpo = fopen("Data_Akun.dat","wb");
	fpt = fopen("Temp_Data.txt","rb");
	while (fread(&acc,sizeof(acc),1, fpt)) {
		fwrite(&acc,sizeof(acc),1,fpo);
	}
	fclose(fpo);
	fclose(fpt);
	printf("\n Data Berhasil Diperbarui!\n");
}
