#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "mahasiswa.h"
#include "waktutanggal.h"
#include "login.h"
#include <string.h>
#include <stdlib.h>

// ============== PROSEDUR UNTUK INPUT DATA MAHASISWA DAN MENYIMPANNYA KE DALAM FILE ==============
void InputDataMahasiswa (Mahasiswa M) {

	int check;
	FILE *fp;
	fp = fopen("Data_Mahasiswa.txt", "ab");

	do {
		printf("NIM\t\t= ");
		scanf("%i", &M.NIM);

		check = CekNIM(M, M.NIM);

		if (check == 1) {
			printf("NIM telah terdaftar, masukkan NIM yang berbeda!\n\n");
		}
	} while (check == 1);
	printf("Nama\t\t= ");
	fflush(stdin);
	gets(M.Nama);
	printf("Kelas\t\t= ");
	scanf("%s", &M.Kelas);

	printf("Sandi\t\t= ");
	scanf("%s", &M.sandi);

	fwrite(&M, sizeof(M),1,fp);
	fclose(fp);
}

//======================== PROSEDUR UNTUK INPUT DATA ABSENSI MAHASISWA ============================
void Absensi (Mahasiswa M, int Nim_Absen) {

	FILE *fp;
	FILE *fpt;

	int Cek_NA,s, pilAbsen;

	fp  = fopen("Data_Mahasiswa.txt","rb");
	fpt = fopen("Temp_Data.txt", "wb");
	while (fread(&M, sizeof(M),1, fp)) {
		s = M.NIM;
		if (s != Nim_Absen) {
			fwrite(&M,sizeof(M),1,fpt);
		} else {
			SetDate(&M.now);
			printf("\nMasukkan Status Absensi:\n");
			printf("   1. Hadir\n");
			printf("   2. Izin \n");
			printf("   3. Sakit \n");
			Baris();
			printf(" Pilihan : ");
			scanf ("%d", &pilAbsen);
			Baris();
			switch(pilAbsen) {
				case 1:
					system("cls");
					strcpy(M.Status, "Hadir");
					jam vjam, telat;
					CreateJam(&vjam);
					SetJam(&M.masuk);
					telat = CountLate(M.masuk, vjam);
					if((JamToMenit(M.masuk)) > (JamToMenit(vjam))) {
						printf("\nAnda Telat: \n");
						GetLate(telat);
						strcpy(M.Ket, "Terlambat:(");
					} else if((JamToMenit(M.masuk)) <= (JamToMenit(vjam))) {
						printf("\nAnda Masuk Tepat Waktu :) \n");
						strcpy(M.Ket, "Tepat Waktu :)");
					}
					printf("\n\n");
					break;
				case 2:
					system("cls");
					strcpy(M.Status, "Izin");
					printf("Masukkan Keterangan:");
					fflush(stdin);
					gets(M.Ket);
					break;
				case 3:
					system("cls");
					strcpy(M.Status, "Sakit");
					printf("Masukkan Keterangan:");
					fflush(stdin);
					gets(M.Ket);
					break;
				default:
					printf("\nPilihan tidak ada!\n\n");
			}

		}
		fwrite(&M,sizeof(M),1,fpt);
	}
	fclose(fp);
	fclose(fpt);

	fp  = fopen("Data_Mahasiswa.txt","wb+");
	fpt = fopen("Temp_Data.txt", "rb");
	while (fread(&M, sizeof(M),1, fpt)) {
		fwrite(&M,sizeof(M),1,fp);
	}
	fclose(fp);
	fclose(fpt);
}

//================================================= FUNCTION UNTUK MENGECEK NIM =================================================
int CekNIM(Mahasiswa M,int id) {
	FILE *fp;
	int c = 1;

	fp = fopen("Data_Mahasiswa.txt","rb");
	while (fread(&M, sizeof(M),1,fp)) {
		if( id == M.NIM) {
			fclose(fp);
			return 1;
		} 
	}
}

//==================== PROSEDUR UNTUK MENAMPILKAN DATA MAHASISWA KE CONSOLE =======================
void TampilkanDataMahasiswa (Mahasiswa M) {

	FILE *fp1;
	fp1 = fopen("Data_Mahasiswa.txt", "rb");

	printf("NIM\t\tKelas\t\tNama\t\tSandi\n");
	sort(M);

	while(fread(&M, sizeof(M), 1, fp1)) {
		printf("%d\t%s\t\t%s\t\t%s\n", M.NIM, M.Kelas, M.Nama, M.sandi);
	}
	fclose(fp1);
}

//======================== PROSEDUR UNTUK MENGURUTKAN DATA PADA CONSOLE ===========================
void sort(Mahasiswa M) {
	int a[20];
	int count = 0;
	int i,j,t,c;
	FILE *fpo;
	FILE *fpt;
	fpo = fopen("Data_Mahasiswa.txt","rb");
	fpt = fopen("Temp_Data.txt","w");
	while (fread(&M, sizeof(M),1,fpo)) {
		a[count] = M.NIM;
		count++;
	}

	c = count;
	for (i = 0; i<count -1; i++) {
		for (j = i + 1; j<count; j++) {
			if (a[i]>a[j]) {
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	count = c;
	for (i = 0; i<count; i++) {
		rewind(fpo);
		while (fread(&M, sizeof(M),1,fpo)) {
			if (a[i]==M.NIM) {
				fwrite(&M, sizeof(M),1,fpt);
			}
		}
	}
	fclose(fpo);
	fclose(fpt);
	fpo = fopen("Data_Mahasiswa.txt","wb");
	fpt = fopen("Temp_Data.txt","r");
	while (fread(&M,sizeof(M),1, fpt)) {
		fwrite(&M,sizeof(M),1,fpo);
	}
	fclose(fpo);
	fclose(fpt);
}

//================================================= PROCEDUR MENGHAPUS DATA MAHASISWA =================================================
void HapusData(Mahasiswa M) {
	FILE *fpo;
	FILE *fpt;
	int r, s, pil;

	printf("   1. Hapus Seluruh Data Mahasiswa\n");
	printf("   2. Hapus Salah Satu Data Mahasiswa\n");
	printf("   3. Batal\n");
	Baris();
	printf(" Pilihan : ");
	scanf ("%d", &pil);
	switch (pil) {
		case 1:
			fpo = fopen("Data_Mahasiswa.txt","wb");
			printf("\nSemua data berhasil dihapus!\n");
			fclose(fpo);
			break;
		case 2:
			Baris();
			printf(" Masukan NIM : ");
			scanf("%d",&r);
			if (CekNIM(M, r) == 0) {
				printf("\n ID %d tidak ditemukan\n\n",r);
			} else {
				fpo = fopen("Data_Mahasiswa.txt","rb");
				fpt = fopen("Temp_Data.txt","wb");
				while (fread(&M, sizeof(M), 1, fpo)) {
					s = M.NIM;
					if ( s != r) {
						//Menyalin data file yang tidak ingin dihapus
						fwrite(&M, sizeof(M), 1, fpt);
					}
				}
				fclose(fpo);
				fclose(fpt);
				fpo = fopen("Data_Mahasiswa.txt","wb");
				fpt = fopen("Temp_Data.txt","rb");
				while(fread(&M,sizeof(M),1,fpt)) {
					fwrite(&M,sizeof(M),1,fpo);
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

//================================== PROCEDURE TAMPIL CARA KERJA PROGRAM ========================================
void carapakai() {
	FILE *ft;
	ft = fopen("Cara Pakai Program.txt","r");
	char s[10000];
	if(ft == NULL) {
		printf("\n File tidak dapat dibuka\n\n");
		exit(1);
	}
	while(fgets(s, sizeof(s), ft)){
        printf("%s", s);
    }
//	while(fgets(s,1000,ft)) {
//		printf("%s",s);
//	}
	fclose(ft);
}

//====================================== PROCEDURE CEK TANGGAL DAN TAMPIL DATA HADIR HARI INI ============================================

int CekTgl(Mahasiswa M) {

	FILE *fp1;
	fp1 = fopen("Data_Mahasiswa.txt", "rb");

	printf("NIM\t\tKelas\t\tNama\t\tJam Masuk\tStatus\t\tKeterangan\n");

	while(fread(&M, sizeof(M), 1, fp1)) {
		tgl today;
		SetDate(&today);
		if(M.now.DD == today.DD) {
			if(M.now.MM == today.MM) {
				if(M.now.YY == today.YY) {
					printf("%d\t%s\t\t%s\t\t%2ld:%2ld\t\t%s\t\t%s\n", M.NIM, M.Kelas, M.Nama ,M.masuk.H, M.masuk.M, M.Status, M.Ket);
				}
			}
		}
	}
	fclose(fp1);
	return 1;
}

//================================================= PROCEDUR MENGUBAH DATA MAHASISWA =================================================
void UbahDataMhs(Mahasiswa M) {
	int avl;
	FILE *fpt;
	FILE *fpo;
	int s,r,pilUbah, nimUbah;

	printf(" Masukkan NIM : ");
	scanf("%d",&nimUbah);
	avl = CekNIM(M, nimUbah);

	if (avl == 0 ) {
		printf("\n ID %d tidak ditemukan di dalam FILE!\n\n",r);
	} else {
		fpo = fopen("Data_Mahasiswa.txt","rb");
		fpt = fopen("Temp_Data.txt","wb");

		while (fread(&M,sizeof(M),1,fpo)) {
			s = M.NIM;
			if (M.NIM != nimUbah) {
				fwrite(&M,sizeof(M),1,fpt);
			} else {
				printf("   1. Ubah Nama\n");
				printf("   2. Ubah ID\n");
				printf("   3. Ubah Kelas\n");
				printf("   4. Ubah Sandi\n");
				printf("   5. Ubah Keseluruhan\n");
				Baris();
				printf(" Pilihan : ");
				scanf ("%d", &pilUbah);
				Baris();
				switch (pilUbah) {
					case 1:
						printf(" Masukkan Nama : ");
						fflush(stdin);
						gets(M.Nama);
						break;
					case 2:
						printf(" Masukkan NIM : ");
						scanf("%d",&M.NIM);
						break;
					case 3:
						printf(" Masukkan Kelas : ");
						scanf("%d",&M.Kelas);
						break;
					case 4:
						printf(" Masukkan Sandi : ");
						scanf("%d",&M.sandi);
						break;
					case 5:
						printf(" Masukkan ID 	   : ");
						scanf ("%d",&M.NIM);
						printf(" Masukan Nama 	   : ");
						fflush(stdin);
						gets(M.Nama);
						printf(" Masukan Kelas  : ");
						fflush(stdin);
						gets(M.Kelas);
						break;
					default:
						printf("\n Error!\n\n");
						break;
				}
				fwrite(&M, sizeof(M),1,fpt);
			}
		}
		fclose(fpo);
		fclose(fpt);
		fpo = fopen("Data_Mahasiswa.txt","wb");
		fpt = fopen("Temp_Data.txt","rb");
		while (fread(&M,sizeof(M),1, fpt)) {
			fwrite(&M,sizeof(M),1,fpo);
		}
		fclose(fpo);
		fclose(fpt);
		printf("\n Data Berhasil Diperbarui!\n");
	}
}
