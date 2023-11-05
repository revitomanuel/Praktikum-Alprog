/* Program Menghitung Luas dan Keliling Bangun Datar dengan Konsep Prosedur */

#include <stdio.h>
#include <ctype.h>

//Deklarasi prosedur untuk membersihkan tampilan layar
void cls() {
    system("cls");
}


int validInt(int *var)
{
    char buff[1020];
    char cek;
    fflush(stdin);
    if (fgets(buff, sizeof(buff), stdin) != NULL)
    {
        if (sscanf(buff, "%d %c", var, &cek) == 1)
        {
            return 1;
        }
    }
    return 0;
}

void inputInt(int *var, char *prompt)
{
    while (1)
    {
        printf(prompt);
        if (validInt(var))
            break;
        printf("Input hanya  boleh berupa angka!! \n");
        printf("\n");
    }
}


//Deklarasi prosedur untuk menyapa pengguna
void greeting() {
    printf("Halo! Selamat datang di program ini. \n");
}

//Deklarasi prosedur untuk mengucapkan terima kasih kepada pengguna
void thanks() {
    printf("Terima kasih telah menggunakan program kami. Sampai jumpa!");
}


//Deklarasi prosedur untuk menghitung luas dan keliling segitiga sembarang
void segitiga_sembarang(float alas, float tinggi, float sisi1, float sisi2, float sisi3, float *luas, float *keliling) {
    *luas = 0.5 * alas * tinggi;
    *keliling = sisi1 + sisi2 + sisi3;
}

//Deklarasi prosedur untuk menghitung luas dan keliling belah ketupat
void belah_ketupat(float diagonal1, float diagonal2, float sisi, float *luas, float *keliling) {
    *luas = 0.5 * diagonal1 * diagonal2;
    *keliling = 4 * sisi;
}

//Deklarasi prosedur untuk menghitung luas dan keliling jajar genjang
void jajar_genjang(float alas, float tinggi, float sisi_miring, float *luas, float *keliling) {
    *luas = alas * tinggi;
    *keliling = 2 * (alas + sisi_miring);
}

//Deklarasi prosedur untuk menghitung luas dan keliling trapesium
void trapesium(float alas, float tinggi, float sisi_atas, float sisi_miring1, float sisi_miring2, float *luas, float *keliling) {
    *luas = 0.5 * (alas + sisi_atas) * tinggi;
    *keliling = alas + sisi_atas + sisi_miring1 + sisi_miring2;
}

//Deklarasi prosedur untuk menghitung luas dan keliling lingkaran dengan jari-jari
void lingkaran(float jarijari, float *luas, float *keliling) {
    *luas = 3.14 * jarijari * jarijari;
    *keliling = 2 * 3.14 * jarijari;
}
    

int optionM, optionLK;
float luas, keliling, hasil;
float alas, tinggi, sisi, sisi1, sisi2, sisi3, sisi_miring, sisi_miring1, sisi_miring2, sisi_atas, diagonal1, diagonal2, jarijari;
char choice;


int main () {
    do {
        cls();

    //Nama program
    printf("|=========================================|\n");
    printf("            PROGRAM BANGUN DATAR           \n");
    printf("                KELOMPOK 24                \n");
    printf("|=========================================|\n\n");

    greeting(); //Menampilkan sapaan untuk pengguna
    printf("\n");

        do {

            //Meminta bangun datar yang diinginkan
            printf("[MENU BANGUN DATAR]\n");
            printf("1. Segitiga sembarang\n");
            printf("2. Belah Ketupat\n");
            printf("3. Jajar genjang\n");
            printf("4. Trapesium\n");
            printf("5. Lingkaran\n");
            inputInt(&optionM, "Pilih bangun datar yang diinginkan: ");

            printf("\n");

                //Memvalidasi bahwa input pada menu hanya berupa angka 1-5
                if (optionM >= 1 && optionM <= 5) {
                    break;
                }
                else {
                    printf("Mohon maaf, input yang Anda masukkan tidak cocok dengan opsi yang tersedia.\n\n");
                    while (getchar() != '\n');
                }
                break;
                
        } while (1);


        do {

            //Meminta jenis operasi hitung yang diinginkan
            printf("Apa yang ingin Anda ketahui?\n");
            printf("1. Luas\n");
            printf("2. Keliling\n");
            inputInt(&optionLK, "Pilih opsi yang diinginkan: ");

            printf("\n");

            //Kasus
            if (optionLK == 1) {                
                switch (optionM) {
                    //Segitiga sembarang
                    case 1: 
                        printf("Masukkan panjang alas: ");
                        scanf("%f", &alas);
                        printf("Masukkan tinggi: ");
                        scanf("%f", &tinggi);
                        printf("\n");
                        segitiga_sembarang(alas, tinggi, sisi1, sisi2, sisi3, &luas, &keliling);
                        break;

                    //Belah Ketupat
                    case 2:
                        printf("Masukkan panjang diagonal 1: ");
                        scanf("%f", &diagonal1);
                        printf("Masukkan tinggi: ");
                        scanf("%f", &diagonal2);
                        printf("\n");
                        belah_ketupat(diagonal1, diagonal2, sisi, &luas, &keliling);
                        break;

                    //Jajar genjang
                    case 3:
                        printf("Masukkan panjang alas: ");
                        scanf("%f", &alas);
                        printf("Masukkan tinggi: ");
                        scanf("%f", &tinggi);
                        printf("\n");
                        jajar_genjang(alas, tinggi, sisi_miring, &luas, &keliling);
                        break;

                    //Trapesium
                    case 4:
                        printf("Masukkan panjang alas: ");
                        scanf("%f", &alas);
                        printf("Masukkan panjang sisi atas: ");
                        scanf("%f", &sisi_atas);
                        printf("Masukkan tinggi: ");
                        scanf("%f", &tinggi);
                        printf("\n");
                        trapesium(alas, tinggi, sisi_atas, sisi_miring1, sisi_miring2, &luas, &keliling);
                        break;

                    //Lingkaran 
                    case 5:
                        printf("Masukkan panjang jari-jari: ");
                        scanf("%f", &jarijari);
                        printf("\n");
                        lingkaran(jarijari, &luas, &keliling);
                        break;
                }

                printf("Hasil perhitungan luas: %.2f\n\n", luas);
            }
            else if (optionLK == 2) {                
                switch (optionM) {
                    //Segitiga sembarang
                    case 1: 
                        printf("Masukkan panjang sisi pertama: ");
                        scanf("%f", &sisi1);
                        printf("Masukkan panjang sisi kedua: ");
                        scanf("%f", &sisi2);
                        printf("Masukkan panjang sisi ketiga: ");
                        scanf("%f", &sisi3);
                        printf("\n");
                        segitiga_sembarang(alas, tinggi, sisi1, sisi2, sisi3, &luas, &keliling);
                        break;

                    //Belah Ketupat
                    case 2:
                        printf("Masukkan panjang sisi: ");
                        scanf("%f", &sisi);
                        printf("\n");
                        belah_ketupat(diagonal1, diagonal2, sisi, &luas, &keliling);
                        break;

                    //Jajar genjang
                    case 3:
                        printf("Masukkan panjang alas: ");
                        scanf("%f", &alas);
                        printf("Masukkan panjang sisi miring: ");
                        scanf("%f", &sisi_miring);
                        printf("\n");
                        jajar_genjang(alas, tinggi, sisi_miring, &luas, &keliling);
                        break;

                    //Trapesium
                    case 4:
                        printf("Masukkan panjang alas: ");
                        scanf("%f", &alas);
                        printf("Masukkan panjang sisi atas: ");
                        scanf("%f", &sisi_atas);
                        printf("Masukkan panjang sisi miring pertama: ");
                        scanf("%f", &sisi_miring1);
                        printf("Masukkan panjang sisi miring kedua: ");
                        scanf("%f", &sisi_miring2);
                        printf("\n");
                        trapesium(alas, tinggi, sisi_atas, sisi_miring1, sisi_miring2, &luas, &keliling);
                        break;

                    //Lingkaran 
                    case 5:
                        printf("Masukkan panjang jari-jari: ");
                        scanf("%f", &jarijari);
                        printf("\n");
                        lingkaran(jarijari, &luas, &keliling);
                        break;        
                }

                printf("Hasil perhitungan keliling: %.2f\n\n", keliling);
            }
            else {
                printf("Mohon maaf, input yang Anda masukkan tidak cocok dengan opsi yang tersedia.\n\n");
                while (getchar() != '\n');
            }
            break;

        } while (1);

                

    //Lanjut atau Stop?
    printf("Apakah Anda ingin melanjutkan hitung? (Y/N): ");
    scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    cls();
    thanks(); 
    
    return 0;
}
