#include <stdio.h>
#include "waktutanggal.h"
#include <time.h>



//------------------------------------------------------------------------FUNGSI JAM----------------------------------------------------------------------------//


//--------------------------------//

jam CreateJam(jam *J){
	(*J).H = 07;
	(*J).M = 30;
	}
	
//--------------------------------//

void GetJam (jam J)
{
	printf("%2ld:%2ld",J.H,J.M);
	printf("\n");
}

//--------------------------------//

void GetLate(jam J){
	printf("%2ld Jam %2ld Menit",J.H,J.M);
	printf("\n");
}

//--------------------------------//

jam GetNow(){

	jam J;
    char buff[100];
    time_t now = time(0);
    struct tm now_t = *localtime(&now);
    strftime (buff, 100, " %d-%m-%Y %H:%M:%S", &now_t);    

    J.H = now_t.tm_hour;
    J.M = now_t.tm_min;
	
	return J;
}

//--------------------------------//

jam MakeJam (int HH, int MM)
{
	jam j;
	(j).H = HH;
	(j).M = MM;
	return j;
}

//--------------------------------//

void SetJam (jam *J)
{
	
	int vH, vM, next=1;	
	while(next==1){
	printf ("\nMasukkan jam\t= ");
	scanf  ("%ld", &vH);
	printf ("Masukkan menit\t= ");
	scanf  ("%ld", &vM);
	if(IsValid(vH,vM))
	{
		*J = MakeJam(vH,vM);
		next=0;
	}else{
			printf("\ndata jam tidak valid");
			printf("\n----------------------");
			next=1;
		}
	}
}

//--------------------------------//

long int JamToMenit(jam J){
	long int mn;
	
		mn=((J.H)*60)+(J.M);
	return mn;
}

//--------------------------------//

jam MenitToJam(long int mn){
	
	jam J;
	long int temp1,temp2;
	
	temp1=mn;
	J.H=temp1/60;
	temp2=temp1-(J.H*60);
	J.M=temp2;
	return J;
}

//--------------------------------//

jam CountLate(jam A, jam B){
  jam H;
  H = MenitToJam((JamToMenit(A)) - (JamToMenit(B)));	
  return H;
}

//--------------------------------//

boolean IsValid(int H, int M){
	return ((H>=0 && H<=23) && (M>=0 && M<=59));
}

//--------------------------------//

//--------------------------------------------------------------FUNGSI TANGGAL-------------------------------------------------------------------//



void CreateDate(tgl *D){
	(*D).DD = 1;
	(*D).MM = 1;
	(*D).YY = 1900;
	}

void GetDate (tgl D)
{
	printf("%2ld:%2ld:%2ld", D.DD, D.MM, D.YY);
	printf("\n");
}


tgl GetNowDate(){
    tgl D;
    char buff[100];
    time_t now = time(0);
    struct tm now_t = *localtime(&now);
    strftime (buff, 100, " %d-%m-%Y %H:%M:%S", &now_t);    

    D.DD = now_t.tm_mday;
    D.MM = now_t.tm_mon+1;
    D.YY = 1900+now_t.tm_year;
	
	return D;
}

tgl SetDate(tgl *D){
    return	*D= GetNowDate();
}

boolean IsValidDate(int DD, int MM, int YY){
	return ((DD>=0 && DD<=30) && (MM>=0 && MM<=11)&&(YY>=0 && YY<=2050));
}





