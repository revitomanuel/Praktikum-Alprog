/* Program Kalkulator Sederhana */

#include <stdio.h>
#include <ctype.h> //untuk validasi opsi pada menu


void cls() {
    system("cls"); //untuk membersihkan layar 
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

double bilangan1, bilangan2;
int option;
char choice;
double hasil;

int main() {
    do {
        cls();

    //Nama program
    printf("|=========================================|\n");
    printf("       PROGRAM KALKULATOR SEDERHANA        \n");
    printf("                KELOMPOK 24                \n");
    printf("|=========================================|\n\n");
    
        do {

            //Meminta operasi hitung yang diinginkan
            printf("[M E N U]\n");
            printf("1. Pertambahan\n");
            printf("2. Pengurangan\n");
            printf("3. Perkalian\n");
            printf("4. Pembagian\n");
            printf("5. Modulus\n");
            inputInt(&option, "Pilih operasi hitung yang diinginkan: ");

                //Memvalidasi bahwa input pada menu hanya berupa angka 1-5
                if (option >= 1 && option <= 5) {
                    break;
                }
                else {
                    printf("Mohon maaf, input yang Anda masukkan tidak cocok dengan opsi yang tersedia.\n\n");
                    while (getchar() != '\n');
                }
                
        } while (1);

    //Meminta dan memvalidasi input bilangan pertama
    while (1) { //1 dalam konteks ini adalah true. Jadi kalau nilainya selalu true, maka loop akan terus berjalan.
        printf("Masukkan bilangan pertama: ");
        if (scanf("%lf", &bilangan1) == 1) {
            break; //Input yang dimasukkan benar, keluar dari loop
        } 
        else {
            printf("Input hanya boleh berupa bilangan.\n");
            while (getchar() != '\n'); // Membersihkan buffer masukan.
        }
    }

    //Meminta dan memvalidasi input bilangan kedua
    while (1) {
        printf("Masukkan bilangan kedua: ");
        if (scanf("%lf", &bilangan2) == 1) {
            break;
        } 
        else {
            printf("Input hanya boleh berupa bilangan.\n");
            while (getchar() != '\n');
        }
    }

        //Kasus
        switch (option) {
            case 1:
                hasil = bilangan1 + bilangan2;
                break;
            case 2:
                hasil = bilangan1 - bilangan2;
                break;
            case 3:
                hasil = bilangan1 * bilangan2;
                break;
            case 4:
                if (bilangan2 != 0) {
                    hasil = bilangan1 / bilangan2;
                } 
                else {
                    printf("Error: Tidak bisa dibagi dengan 0.\n");
                    continue; // Melanjutkan penghitungan.
                }
                break;
            case 5:
                if (bilangan2 != 0) {
                    hasil = (int)bilangan1 % (int)bilangan2;
                } 
                else {
                    printf("Error: Operasi modulus tidak dapat dilakukan dengan pembagi 0.\n");
                    continue; // Melanjutkan penghitungan.
                }
                break;
        }

    //Menampilkan hasil
    printf("Hasil dari operasi hitung yang Anda pilih adalah: %.2lf\n", hasil);

    //Lanjut atau Stop?
    printf("Apakah Anda ingin melanjutkan hitung? (Y/N): ");
    scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    cls();

    printf("Terima kasih telah menggunakan program kami. Sampai jumpa!");
    return 0;
}