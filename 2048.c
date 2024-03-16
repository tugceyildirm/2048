#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>



int tablo[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};	// Oyun için gereken durum şablonu:

int puan=0,sifir_sayisi=0;  // random olarak yeni numara ekle  score sıfırdan başlat:


int main(){
    setlocale(LC_ALL, "Turkish");

	yenisayi_ekle();    //yeni numara ekle

	yenisayi_ekle();

	tabloya_ekle();



	while(1){


		char hareket;   // hareketleri belirlemek için.

		scanf("%c",&hareket);


		switch(hareket){


		case 'w':{   //yukarı hareket

			cevir(1);  //döndür

			islem();

			yenisayi_ekle();

			yenisayi_ekle();

			cevir(3);

			tabloya_ekle();



			break;


		}


       case 'a':
		    {
		    //sola hareket

			islem();

			yenisayi_ekle();

			yenisayi_ekle();

			tabloya_ekle();


			break;

		}


	// Aşağı
      case 's':{


			cevir(3);

			islem();

			yenisayi_ekle();

			yenisayi_ekle();

			cevir(1);

			tabloya_ekle();


			break;

		}

        // sağa hareket
		case 'd':{

			cevir(2);

			islem();

			yenisayi_ekle();

			yenisayi_ekle();

			cevir(2);

			tabloya_ekle();


			break;


		}
         //oyunu tekrar oynamak için
		case 'r':
        {
            islem();

            oyunu_yenile();

            tabloya_ekle();

            yenisayi_ekle();

            yenisayi_ekle();


            break;

        }

        // oyundan çıkış
		case 'e':{
			oyun_bitti();

            break;

		}

			return 0;

		}

	}



	return 0;


}

//2 Sayılarını rastgele yerlere yerleştirmeye yarar.
void yenisayi_ekle(){


	int i,j;

	srand(time(NULL));  //srand(time(NULL)) komutu C dilinde rastgele farklı sayılar atamak için kullanılır.
	//Tabloda boş yerleri tespit edip  sayı atar

	sifir_ekle();


	if(sifir_sayisi!=0){

		while(1){

			i=rand()%4;   // rand rastgele sayı üretmek için kullanılıyor

			j=rand()%4;


			if(tablo[i][j]==0){  // i ve j boş ise yeni değer olarak 2 ekliyoruz


				(tablo[i][j]=2) ;



				break;


				}


		}


	}


}


void sifir_ekle(){


	int i,j;


	sifir_sayisi=0;


	for(i=0;i<4;i++){


		for(j=0;j<4;j++){


			if(tablo[i][j]==0){


				sifir_sayisi++;


			}


		}


	}


}

//tabloyu ekranda gösterir
void tabloya_ekle(){

	int i,j;

	system("cls");
                 //girişteki yazıyı yazacağımız yerler

	printf("               ***2048***               \n");

	printf("Hoş geldiniz, w (yukarı), a (sol),s (aşağı), d (sağ), e (çıkış), r (Tekrar oyna) tuşlarına basıp sonrasında enter tuşuna basarak oyunu oynayabilirsiniz.\n\n");


// i ve j satır ve sütun
	for(i=0;i<4;i++){

		for(j=0;j<4;j++){

			printf("   %d  ",tablo[i][j]); // tablo oluşturuyoruz

		}


		printf("\n\n");

	}
// skoru ekrana yazdır

	printf("_______________________________________________Puanınız : %d\n",puan);


}



//saat yönünün tersine 90 derece döndürme.
//Tek bir yön için yazdıgımız kodu hareket yönüne göre döndürerek diger yönler içinde kullanılabilir hale getiriyoruz.

// (1)


void cevir(sayi_cevir){

	int i,temp=0;

	for(i=0;i<sayi_cevir;i++){

		// 1


		temp=tablo[0][0];

		tablo[0][0]=tablo[0][3];

		tablo[0][3]=tablo[3][3];

		tablo[3][3]=tablo[3][0];

		tablo[3][0]=temp;

		temp=0;


		// 2


		temp=tablo[0][1];

		tablo[0][1]=tablo[1][3];

		tablo[1][3]=tablo[3][2];

		tablo[3][2]=tablo[2][0];

		tablo[2][0]=temp;

		temp=0;


		// 3


		temp=tablo[0][2];

		tablo[0][2]=tablo[2][3];

		tablo[2][3]=tablo[3][1];

		tablo[3][1]=tablo[1][0];

		tablo[1][0]=temp;

		temp=0;


		// 4


		temp=tablo[1][1];

		tablo[1][1]=tablo[1][2];

		tablo[1][2]=tablo[2][2];

		tablo[2][2]=tablo[2][1];

		tablo[2][1]=temp;

		temp=0;


	}


}




void islem(){
//Hareket yönünde sayılar aynı ise kaydırılarak iki katı alınır.

	int i,j,k,l,sayac=0;


	for(i=0;i<4;i++){


		for(l=0;l<4;l++){


			for(j=3;0<j;j--){


				if(tablo[i][j-1]==0){

					tablo[i][j-1]=tablo[i][j];

					tablo[i][j]=0;

					sayac+=1;

				}


			}


		}

		for(k=1;k<4;k++){


			if(tablo[i][k]==tablo[i][k-1]){

				tablo[i][k-1]=tablo[i][k]*2;

				tablo[i][k]=0;

				sayac+=1;

				puan+=tablo[i][k-1];


			}


		}


		for(l=0;l<4;l++){


			for(j=3;0<j;j--){


				if(tablo[i][j-1]==0){


					tablo[i][j-1]=tablo[i][j];

					tablo[i][j]=0;

					sayac+=1;


				}


			}


		}


	}


	if(sayac==0){

		oyun_bitti();


	}


}




// oyunu tekrarlamak için
void oyunu_yenile()
{
            int i,j;
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    tablo[i][j]=0;
                }
            }
            system("cls") ;
            printf("     %d    ",tablo[i][j]);

            puan=0;
            yenisayi_ekle();

}


//Eğer yapacak hamle kalmadı ise oyun biter.

void oyun_bitti(){


	system("cls"); //ekranı temizler ve ekranın üstüne yazılacak olan verilerin görüntülenmesine yardımcı olur.


// skor ve oyunun bittiğini yazdıran kod
	printf("__________________________________OYUN BİTTİ\n ");

	printf("__________________________________PUANINIZ :%d ",puan);


	getch(); //klavyeden girilen karakteri okumak için


	return 0;


}


