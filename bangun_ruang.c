/* Program Menghitung Volume dan Luas Permukaan Bangun Ruang dengan Konsep Fungsi */

#include <stdio.h>
#include <math.h>
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


//Deklarasi fungsi untuk menghitung volume tabung
float VolumeTabung (float jarijari, float tinggi) {
    return 3.14 * jarijari * jarijari * tinggi;
}

//Deklarasi fungsi untuk menghitung luas permukaan tabung
float LpTabung (float jarijari, float tinggi) {
    return 2 * 3.14 * jarijari * (jarijari + tinggi);
}

//Deklarasi fungsi untuk menghitung volume bola
float VolumeBola (float jarijari) {
    return (4.0 / 3.0) * 3.14 * jarijari * jarijari * jarijari;
}

//Deklarasi fungsi untuk menghitung luas permukaan bola 
float LpBola (float jarijari) {
    return 4 * 3.14 * jarijari * jarijari;
}

//Deklarasi fungsi untuk menghitung volume limas segi empat
float VolumeLimas4 (float s_alas, float L_alas, float tinggi) {
    L_alas = s_alas * s_alas;
    return (1.0 / 3.0) * L_alas * tinggi;
}

//Deklarasi fungsi untuk menghitung luas permukaan limas segi empat
float LpLimas4 (float s_alas, float s_tegak, float L_alas, float K_alas) {
    L_alas = s_alas * s_alas;
    K_alas = 4 * s_alas;
    return L_alas + (0.5 * K_alas * s_tegak);
}

//Deklarasi fungsi untuk menghitung volume prisma segitiga
float VolumePrisma3 (float s_alas, float t_alas, float L_alas, float t_prisma) {
    L_alas = 0.5 * s_alas * t_alas;
    return L_alas * t_prisma;
}

//Deklarasi fungsi untuk menghitung luas permukaan prisma segitiga
float LpPrisma3 (float s_alas, float t_alas, float L_alas, float K_alas, float t_prisma) {
    L_alas = 0.5 * s_alas * t_alas;
    K_alas = 3 * s_alas;
    return 2 * L_alas + K_alas * t_prisma; 
}

//Deklarasi fungsi untuk menghitung volume kerucut
float VolumeKerucut (float jarijari, float tinggi) {
    return (1.0 / 3.0) * 3.14 * jarijari * jarijari * tinggi;
}

//Deklarasi fungsi untuk menghitung luas permukaan kerucut
float LpKerucut (float jarijari, float tinggi, float g_pelukis) {
    g_pelukis = sqrt((jarijari * jarijari) + (tinggi * tinggi));
    return 3.14 * jarijari * (jarijari + g_pelukis);
}


int option_M, option_VL;
float volume, luas_permukaan, hasil;
float jarijari, tinggi, s_alas, s_tegak, t_alas, t_prisma, g_pelukis, L_alas, K_alas;
char choice;


int main () {
    do {
        cls();

    //Nama program
    printf("|=========================================|\n");
    printf("            PROGRAM BANGUN RUANG           \n");
    printf("                KELOMPOK 24                \n");
    printf("|=========================================|\n\n");

    greeting(); //Menampilkan sapaan untuk pengguna
    printf("\n");

        do {

            //Meminta bangun ruang yang diinginkan
            printf("[MENU BANGUN RUANG]\n");
            printf("1. Tabung\n");
            printf("2. Bola\n");
            printf("3. Limas segi empat\n");
            printf("4. Prisma segitiga\n");
            printf("5. Kerucut\n");
            inputInt(&option_M, "Pilih bangun ruang yang diinginkan: ");

            printf("\n");

                //Memvalidasi bahwa input pada menu hanya berupa angka 1-5
                if (option_M >= 1 && option_M <= 5) {
                    break;
                }
                else {
                    printf("Mohon maaf, input yang Anda masukkan tidak cocok dengan opsi yang tersedia.\n\n");
                    while (getchar() != '\n');
                }
                
        } while (1);


        do {

            //Meminta jenis operasi hitung yang diinginkan
            printf("Apa yang ingin Anda ketahui?\n");
            printf("1. Volume\n");
            printf("2. Luas Permukaan\n");
            inputInt(&option_VL, "Pilih opsi yang diinginkan: ");

            printf("\n");

            //Kasus
            if (option_VL == 1) {                
                switch (option_M) {
                    //Tabung
                    case 1:
                        printf("Masukkan panjang jari-jari alas: ");
                        scanf("%f", &jarijari);
                        printf("Masukkan tinggi tabung: ");
                        scanf("%f", &tinggi);
                        printf("\n");
                        volume = VolumeTabung(jarijari, tinggi);
                        printf("Hasil perhitungan volume: %.2f\n\n", volume);
                        break;

                    //Bola
                    case 2:
                        printf("Masukkan panjang jari-jari: ");
                        scanf("%f", &jarijari);
                        printf("\n");
                        volume = VolumeBola(jarijari);
                        printf("Hasil perhitungan volume: %.2f\n\n", volume);
                        break;

                    //Limas segi empat
                    case 3:
                        printf("Masukkan panjang sisi alas: ");
                        scanf("%f", &s_alas);
                        printf("Masukkan tinggi: ");
                        scanf("%f", &tinggi);
                        printf("\n");
                        volume = VolumeLimas4(s_alas, L_alas, tinggi);
                        printf("Hasil perhitungan volume: %.2f\n\n", volume);
                        break;

                    //Prisma segitiga
                    case 4:
                        printf("Masukkan panjang sisi alas: ");
                        scanf("%f", &s_alas);
                        printf("Masukkan tinggi alas: ");
                        scanf("%f", &t_alas);
                        printf("Masukkan tinggi prisma: ");
                        scanf("%f", &t_prisma);
                        printf("\n");
                        volume = VolumePrisma3(s_alas, L_alas, t_alas, t_prisma);
                        printf("Hasil perhitungan volume: %.2f\n\n", volume);
                        break;

                    //Kerucut 
                    case 5:
                        printf("Masukkan panjang jari-jari alas: ");
                        scanf("%f", &jarijari);
                        printf("Masukkan tinggi kerucut: ");
                        scanf("%f", &tinggi);
                        printf("\n");
                        volume = VolumeKerucut(jarijari, tinggi);
                        printf("Hasil perhitungan volume: %.2f\n\n", volume);
                        break;
                }
            }
            else if (option_VL == 2) {                
                switch (option_M) {
                    //Tabung
                    case 1:
                        printf("Masukkan panjang jari-jari alas: ");
                        scanf("%f", &jarijari);
                        printf("Masukkan tinggi tabung: ");
                        scanf("%f", &tinggi);
                        printf("\n");
                        luas_permukaan = LpTabung(jarijari, tinggi);
                        printf("Hasil perhitungan luas permukaan: %.2f\n\n", luas_permukaan);
                        break;

                    //Bola
                    case 2:
                        printf("Masukkan panjang jari-jari: ");
                        scanf("%f", &jarijari);
                        printf("\n");
                        luas_permukaan = LpBola(jarijari);
                        printf("Hasil perhitungan luas permukaan: %.2f\n\n", luas_permukaan);
                        break;

                    //Limas segi empat
                    case 3:
                        printf("Masukkan panjang sisi alas: ");
                        scanf("%f", &s_alas);
                        printf("Masukkan panjang sisi tegak: ");
                        scanf("%f", &s_tegak);
                        printf("\n");
                        luas_permukaan = LpLimas4(s_alas, s_tegak, L_alas, K_alas);
                        printf("Hasil perhitungan luas permukaan: %.2f\n\n", luas_permukaan);
                        break;

                    //Prisma segitiga
                    case 4:
                        printf("Masukkan panjang sisi alas: ");
                        scanf("%f", &s_alas);
                        printf("Masukkan tinggi alas: ");
                        scanf("%f", &t_alas);
                        printf("Masukkan tinggi prisma: ");
                        scanf("%f", &t_prisma);
                        printf("\n");
                        luas_permukaan = LpPrisma3(s_alas, t_alas, L_alas, K_alas, t_prisma);
                        printf("Hasil perhitungan luas permukaan: %.2f\n\n", luas_permukaan);
                        break;

                    //Kerucut 
                    case 5:
                        printf("Masukkan panjang jari-jari alas: ");
                        scanf("%f", &jarijari);
                        printf("Masukkan tinggi kerucut: ");
                        scanf("%f", &tinggi);
                        printf("\n");
                        luas_permukaan = LpKerucut(jarijari, tinggi, g_pelukis);
                        printf("Hasil perhitungan luas permukaan: %.2f\n\n", luas_permukaan);
                        break;
                }
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