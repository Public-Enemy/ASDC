#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "llsingle.h"
/*Kamus dan Konstanta*/
// trigger kalo bener keluar
// ngerandom soal
// fungsi anti besar kecil
// input fixed
int live = 4;
int stagesmati = 4; // karena tampilanya ada 4.

int tolower(int a){
	if(a > 65 && a < 91){
		a = a+32;
	}
	return a;
}

boolean ListInfoEq(List Banding, List Terbanding){
	int trueval = 0; // nilai jika dibanfingan list satu dengan list lain sama
	int wholeval = 0; // jumlah keseluruhan list yang ber ada
	address P = First(Banding);
	address Y = First(Terbanding);
	do{
		if(Info(P) == Info(Y)){
		}else{
			return false;
		}
		Y = Next(Y);
		P = Next(P);
	}while(P != Next(Last(Banding)) && Y != Next(Last(Terbanding)));
	return(trueval == wholeval);
}

void tesjawaban(List Soal,List Jawaban,List *Tampilan){
	// Fungsi Ini Untuk Mencek Hasilnya
	// - belom bikin buat nyawa
	boolean found;
	address P1,P2,P3;
	P1 = First(Soal);
	P2 = First(Jawaban);
	P3 = First(*Tampilan);
	// pemuktian list josong
	if ((IsListEmpty(Soal)) || (IsListEmpty(Jawaban)) &&(IsListEmpty(*Tampilan))){
		printf("ListKosong");
		while(IsListEmpty(Soal)){
			//InsertFirst(&Soal,Alokasi(1));
		};
		if (!IsListEmpty(Soal)){
			PrintInfo(Soal);
		};
	}
	//PrintInfo(Jawaban);
	//PrintInfo(Soal);
	// Pencarian ini mengunakan Metode Traversal ( Mencari sampai ujung walaupun sudah ketemu)
	do{ //kalo gak ada next aja
		//printf("1 Info %c , pada  %d \n",Info(P2),P2);
		do{
			//printf("2 Info %c , pada  %d \n",Info(P1),P1);
			if(tolower(Info(P1))==tolower(Info(P2))){ // kalo jawaban bener terus disi L3 sebagai tampilan , serta input case insensitive
				Info(P3) = Info(P1);
				found = true;
			}
				P1 = Next(P1); // fix looping disni 23:49
				P3 = Next(P3);
		}while(P1 != Next(Last(Soal))); // Fixed
		//exit(0);
		//printf("Error\n");
		P3 = First(*Tampilan);
		P1 = First(Soal);
		P2 = Next(P2);
		//PrintInfoChar(*Tampilan);
		if (ListInfoEq(Soal,*Tampilan)){ // untuk memastikan Tampilan benar dan penuh
			printf(" Benar \n");
			PrintInfoChar(*Tampilan); // setelah itu diprint semua
			exit(0);
		}else{
			//exit(0);
		}/**/
	}while(P2 != Next(Last(Jawaban)));
	if (found != true){ // kalo jawaban kagak bener dapet mines
		stagesmati--;
		orangmati(stagesmati);
	}
	found = false;
	live--;
	//printf("New Loops \n");
	//PrintInfoChar(*Tampilan);
}

void orangmati(int stagemati){
	switch(stagemati){
		case 0:
		printf("");
		printf("+--------\n");
		printf("|      |\n");
		printf("|     ( )\n");
		printf("|    --|--\n");
		printf("|      |\n");
		printf("|     /^\\ \n");
		printf("|\n");
		printf("");
		break;
		case 1:
		printf("");
		printf("+--------\n");
		printf("|       |\n");
		printf("|      ( )\n");
		printf("|     --|--\n");
		printf("|       \n");
		printf("|\n");
		printf("|\n");
		printf("");
		break;
		case 2:
		printf("");
		printf("+--------\n");
		printf("|\n");
		printf("|\n");
		printf("|\n");
		printf("|\n");
		printf("|\n");
		printf("|\n");
		printf("");
		break;
		case 3:
		printf("");
		printf("+\n");
		printf("|     \n");
		printf("|     \n");
		printf("|     \n");
		printf("|\n");
		printf("|\n");
		printf("|\n");
		printf("");
		break;

		default:
		printf("Defaults\n");
	}
}

void Insert(List *input,int X){
	if(IsListEmpty(*input)){
		InsertFirst(&(*input),X);
	}else{
		InsertLast(&(*input),X);
	}
}

unsigned char* KumpulanSoal(int soal){
	switch(soal){
		case 0:
		printf("Hero  didota yang paling banyak spellnya ?");
		return "Invoker";
		case 1:
		printf("Nenek Jatuh Dari Langit?");
		return "Mustahil";
		break;

		case 2:
		printf("Orang tidak percaya Tuhan?");
		return "Ateis";
		break;

		case 3:
		printf("Awan Badai?");
		return "Kummulunimbus";
		break;

		case 4:
		printf("Air turun dari langit ?");
		return "Hujan";
		break;

		case 5:
		printf("Hewan tidak berkaki ,tidak  bermata , tidak berbunyi ?");
		return "Cacing";
		break;

		case 6:
		printf("Air dari Serutan Kelapa tua?");
		return "Santan";
		break;

		default:
		return " ";
		break;
	}
}

// fix
void ListIsiKata(List *Soal, List *Tampilan , unsigned char *strsoal){
	int konversi;
	//unsigned char *strsoal = "black"; // paradoks baru seharunya ada 
	int l;
	unsigned char *tampolansensor = "_";
	infotype cc2i;
	address P,L,O,X;
		P = First(*Soal);
		L = First(*Tampilan);
	for(l = 0;l < strlen(strsoal);l++){ // untuk pegngulangan string gua masih belom get , pake strlen bitched
		//printf("\n\n\n%d\n %c\n",strsoal[l],strsoal[l]);
		//printf("\n ukuran %d \n", sizeof(strsoal));
		if(O = Alokasi(strsoal[l])){
			//printf(" %c Teralokasi pada %d = %d \n",strsoal[l],O,strsoal[l]);
		}else{
			//printf("Error\n");
		};
/*		if (IsListEmpty(*Soal)){
			printf("List Kosong\n");
			while(IsListEmpty(*Tampilan)){
				//Insert(&(*Soal),Alokasi(12));
				Insert(&(*Tampilan),Alokasi());
				//printf("Alokasi Sukses\n");
			};*/
		if(X = Alokasi(tampolansensor[0])){
			//printf(" %c Teralokasi pada %d ",tampolansensor[0],X);
		} else {
			printf("eroor\n");
		};//debug list
		if (!IsListEmpty(*Soal)){
			//PrintInfo(*Soal);
		};
		//printf("%d",Next(P));
		Insert(&(*Soal),O); // mengisi soal
		Insert(&(*Tampilan),X); // mengisi tampilan
		//PrintInfo(*Soal); // error disekitaran sini
		//PrintInfo(*Tampilan);
		//printf("New Loops");
	};
}

int main(){
	int nomorsial;
	unsigned char masukan[14]; // for debug change to var name be masukan
	int i;
	srand(time(Nil));
	int randint = (rand()% 6);
	List Input,Soal,Tampilan;
	address D;
	CreateList(&Input);
	CreateList(&Soal);
	CreateList(&Tampilan);
	nomorsial = 1;
	//printf("Nyawa = %d \n",live);
	ListIsiKata(&Soal,&Tampilan,KumpulanSoal(randint));
	printf("%d\n",randint);
	//printf("\n\n\n test list \n\n");
	//PrintInfo(Tampilan);
	//PrintInfo(Soal);
	//printf("\n\n\n\n");
	//system("clear");
	while(live != 0){
		printf("\nPercobaan = %d \n",live);
		PrintInfoChar(Tampilan);
		//PrintInfoChar(Soal); // tampilan jawaba
		scanf("%s",masukan);
		for(i=0; i < strlen(masukan)+1;i++){
			//printf("%c \n",masukan[i]);
		}
		//printf("%s \n",masukan);
		if(!IsListEmpty(Input)){
			D = First(Input);
			while(D != Last(Input)){ // Ngulang Untung Ngebersihin
				DelLast(&Input,D);
				D = Next(D);
			};
			DelLast(&Input,Next(D));
		};
		for(i=0;i < strlen(masukan) +1;i++){
			if(masukan[i] !='\0'){
			if(D = Alokasi(masukan[i])){
				//printf(" %c Teralokasi pada %d ",masukan[i],D); // tanda alokasi berhasil
			} else {
				//printf("eroor\n");
			}
			Insert(&Input,D); // memasukan string input ke list input 
			//PrintInfoChar(Input);
			}
		};
		//DelLast(&Input,D); // untuk menhapus sentinel
		//printf("Isi Alokasi Terakhir %c \n",Info(D));
		tesjawaban(Soal,Input,&Tampilan);
		/*if(ListInfoEq(Soal,Tampilan)){
				printf("Benar");
				exit(0);
		}*/
		//--live;// debug
		//free(&(*masukan));
		if(live == 0){
					PrintInfoChar(Soal);
		}
	}
}
// tanpa bintang tidak pas reference 
// dengan bintang ada pas reference