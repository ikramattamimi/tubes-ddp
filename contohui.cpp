#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

/**
*bundet.com
*Contoh C++ Fungsi Dengan Nilai Balik
*Menghitung Nilai Mahasiswa
*/

void judul();
char tanya();
void isi();
char huruf(float rat);

void cetak(int a, int b, char *teks)
{
 gotoxy(b,a);cout<<teks;
}

void cetakc(int a, char *teks)
{
 gotoxy(40-((strlen(teks)/2)),a);cout<<teks;
}

void main()
{
 judul();
 isi();
   cout<<endl<<endl;
 cout<<"copyright2014-www.gatewan.com";
 getch();
}

void judul()
{
 cetakc(1,"DAFTAR NILAI");
 cetakc(2,"PRODI TEKNIK INFORMATIKA");
cetak(4,4,"========================================================================");
 cetak(5,4,"|");
 cetak(5,7,"No");
 cetak(5,10,"|");
 cetak(5,14,"NIM");
 cetak(5,21,"|");
 cetak(5,27,"N A M A");
 cetak(5,44,"|");
 cetak(5,46,"UTS");
 cetak(5,50,"|");
 cetak(5,52,"UAS");
 cetak(5,56,"|");
 cetak(5,58,"TUGAS");
 cetak(5,64,"|");
 cetak(5,66,"NILAI HRF");
 cetak(5,76,"|");
cetak(6,4,"========================================================================");
}

void isi()
{
 int nim,uts,uas,tugas,tot;
 char nama[15],maxnm[15],minnm[15];
 float rata,maxnil,minnil,ratkelas,totrat;
 char jawab;
 static int i = 1;
 maxnil=0;minnil=100;totrat=0;
 do
 {
 gotoxy(4,6+i);cout<<"|";
 gotoxy(7,6+i);cin>>i;
 gotoxy(10,6+i);cout<<"|";
 gotoxy(12,6+i);cin>>nim;
 gotoxy(21,6+i);cout<<"|";
 gotoxy(23,6+i);cin>>nama;
 gotoxy(44,6+i);cout<<"|";
 gotoxy(46,6+i);cin>>uts;
 gotoxy(50,6+i);cout<<"|";
 gotoxy(52,6+i);cin>>uas;
 gotoxy(56,6+i);cout<<"|";
 gotoxy(58,6+i);cin>>tugas;
 gotoxy(64,6+i);cout<<"|";

 tot=uts+uas+tugas;
 rata=tot/3;
 totrat=totrat+rata;
 ratkelas=totrat/i;
 if(rata>maxnil)
 {
  maxnil=rata;
  strcpy(maxnm,nama);
 }
 if(rata<minnil)
 {
  minnil=rata;
  strcpy(minnm,nama);
 }
 gotoxy(69,6+i);cout<<huruf(rata);
 gotoxy(76,6+i);cout<<"|";
 jawab=tanya();
 if(jawab=='t')
 {
 gotoxy(4,7+i);
 cout<<"========================================================================";
 gotoxy(4,8+i);cout<<"Jumlah data : "<<i;
 gotoxy(4,9+i);cout<<"Rata kelas : "<<ratkelas;
 gotoxy(4,10+i);cout<<"Nilai tertinggi : "<<maxnil;
 gotoxy(30,10+i);cout<<"Nama : "<<maxnm;
 gotoxy(4,11+i);cout<<"Nilai terendah : "<<minnil;
 gotoxy(30,11+i);cout<<"Nama : "<<minnm;
 }
 i++;
 }while(jawab!='t');
}

char tanya()
{
 char jw;
 cetak(3,20,"input data lagi[Y/T]? : ");
 cin>>jw;
 gotoxy(20,3);clreol();
 return(jw);
}

char huruf(float rat)
{
 if(rat>80)
 return('A');
 else if(rat>70)
 return('B');
 else if(rat>60)
 return('C');
 else if(rat>50)
 return('D');
 else
 return('E');
}
