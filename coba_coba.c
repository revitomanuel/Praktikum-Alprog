#include <stdio.h>
#include <math.h>

// Deklarasi prosedur untuk menghitung luas dan keliling segitiga
void hitungLuasKelilingSegitiga(float alas, float tinggi, float *luas, float *keliling) {
    *luas = 0.5 * alas * tinggi;
    *keliling = alas + (2 * sqrt(alas * alas / 4 + tinggi * tinggi));
}

// Deklarasi prosedur untuk menghitung luas dan keliling belah ketupat
void hitungLuasKelilingBelahKetupat(float diagonal1, float diagonal2, float *luas, float *keliling) {
    *luas = 0.5 * diagonal1 * diagonal2;
    *keliling = 4 * sqrt((diagonal1 * diagonal1 + diagonal2 * diagonal2) / 2);
}

// Deklarasi prosedur untuk menghitung luas dan keliling jajar genjang
void hitungLuasKelilingJajarGenjang(float alas, float tinggi, float *luas, float *keliling) {
    *luas = alas * tinggi;
    *keliling = 2 * (alas + tinggi);
}

// Deklarasi prosedur untuk menghitung luas dan keliling trapesium
void hitungLuasKelilingTrapesium(float sisi1, float sisi2, float tinggi, float *luas, float *keliling) {
    *luas = 0.5 * (sisi1 + sisi2) * tinggi;
    *keliling = sisi1 + sisi2 + 2 * sqrt((tinggi * tinggi) + ((sisi2 - sisi1) / 2) * ((sisi2 - sisi1) / 2));
}

// Deklarasi prosedur untuk menghitung luas dan keliling lingkaran
void hitungLuasKelilingLingkaran(float jariJari, float *luas, float *keliling) {
    *luas = 3.14159 * jariJari * jariJari;
    *keliling = 2 * 3.14159 * jariJari;
}

// Deklarasi prosedur untuk sapaan
void sapaPengguna() {
    printf("Selamat datang di program perhitungan luas dan keliling bangun datar!\n");
}

// Deklarasi prosedur untuk kata terima kasih
void terimaKasih() {
    printf("Terima kasih telah menggunakan program kami!\n");
}

int main() {
    int pilihan;
    float luas, keliling;

    sapaPengguna(); // Memberikan sapaan kepada pengguna

    do {
        printf("\nPilih bangun datar yang akan dihitung:\n");
        printf("1. Segitiga\n");
        printf("2. Belah Ketupat\n");
        printf("3. Jajar Genjang\n");
        printf("4. Trapesium\n");
        printf("5. Lingkaran\n");
        printf("6. Keluar\n");
        scanf("%d", &pilihan);

        if (pilihan >= 1 && pilihan <= 5) {
            int pilihanOperasi;
            printf("Pilih yang akan dihitung:\n");
            printf("1. Luas\n");
            printf("2. Keliling\n");
            scanf("%d", &pilihanOperasi);

            if (pilihanOperasi == 1) {
                float param1, param2;
                switch (pilihan) {
                    case 1: // Segitiga
                        printf("Masukkan panjang alas segitiga: ");
                        scanf("%f", &param1);
                        printf("Masukkan tinggi segitiga: ");
                        scanf("%f", &param2);
                        hitungLuasKelilingSegitiga(param1, param2, &luas, &keliling);
                        break;

                    case 2: // Belah Ketupat
                        printf("Masukkan panjang diagonal 1: ");
                        scanf("%f", &param1);
                        printf("Masukkan panjang diagonal 2: ");
                        scanf("%f", &param2);
                        hitungLuasKelilingBelahKetupat(param1, param2, &luas, &keliling);
                        break;

                    case 3: // Jajar Genjang
                        printf("Masukkan panjang alas jajar genjang: ");
                        scanf("%f", &param1);
                        printf("Masukkan tinggi jajar genjang: ");
                        scanf("%f", &param2);
                        hitungLuasKelilingJajarGenjang(param1, param2, &luas, &keliling);
                        break;

                    case 4: // Trapesium
                        printf("Masukkan panjang sisi atas trapesium: ");
                        scanf("%f", &param1);
                        printf("Masukkan panjang sisi bawah trapesium: ");
                        scanf("%f", &param2);
                        float tinggi;
                        printf("Masukkan tinggi trapesium: ");
                        scanf("%f", &tinggi);
                        hitungLuasKelilingTrapesium(param1, param2, tinggi, &luas, &keliling);
                        break;

                    case 5: // Lingkaran
                        printf("Masukkan panjang jari-jari lingkaran: ");
                        scanf("%f", &param1);
                        hitungLuasKelilingLingkaran(param1, &luas, &keliling);
                        break;
                }

                printf("Hasil perhitungan luas: %.2f\n", luas);
            } else if (pilihanOperasi == 2) {
                float param;
                switch (pilihan) {
                    case 1: // Segitiga
                        printf("Masukkan panjang alas segitiga: ");
                        scanf("%f", &param);
                        hitungLuasKelilingSegitiga(param, param, &luas, &keliling);
                        break;

                    case 2: // Belah Ketupat
                        printf("Masukkan panjang diagonal belah ketupat: ");
                        scanf("%f", &param);
                        hitungLuasKelilingBelahKetupat(param, param, &luas, &keliling);
                        break;

                    case 3: // Jajar Genjang
                        printf("Masukkan panjang alas jajar genjang: ");
                        scanf("%f", &param);
                        hitungLuasKelilingJajarGenjang(param, param, &luas, &keliling);
                        break;

                    case 4: // Trapesium
                        printf("Masukkan panjang sisi atas trapesium: ");
                        scanf("%f", &param);
                        hitungLuasKelilingTrapesium(param, param, param, &luas, &keliling);
                        break;

                    case 5: // Lingkaran
                        printf("Masukkan panjang jari-jari lingkaran: ");
                        scanf("%f", &param);
                        hitungLuasKelilingLingkaran(param, &luas, &keliling);
                        break;
                }

                printf("Hasil perhitungan keliling: %.2f\n", keliling);
            } else {
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
            }
        } else if (pilihan == 6) {
            terimaKasih(); // Memberikan kata terima kasih kepada pengguna
        } else {
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }

    } while (pilihan != 6);

    return 0;
}
