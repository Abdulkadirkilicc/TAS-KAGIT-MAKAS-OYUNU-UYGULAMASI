#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    int KullaniciSkor = 0;
    int BilgisayarSkor = 0;
    int TurSayisi = 3;

    printf("TAS-KAGIT-MAKAS OYUNU \n");
    int tur = 0;
    for (tur = 1; tur <= TurSayisi; tur++) {
        printf("\n%d.Tur\n", tur);
        printf("Tas   (1) \nKagit (2)\nMakas (3)\nTercihinizi Yaziniz:");

        char kullaniciSecim[10];
        int bilgisayarSecim;

        srand(time(NULL) + tur);

        bilgisayarSecim = rand() % 3 + 1;

        scanf("%s", kullaniciSecim);
        int i = 0;
        for (i = 0; kullaniciSecim[i]; i++) {
            kullaniciSecim[i] = tolower(kullaniciSecim[i]);
        }

        int kullaniciSecimNumara = 0;

        if (strcmp(kullaniciSecim, "tas") == 0 || strcmp(kullaniciSecim, "1") == 0) {
            kullaniciSecimNumara = 1;
            printf("Siz Tas sectiniz.\n");
        } else if (strcmp(kullaniciSecim, "kagit") == 0 || strcmp(kullaniciSecim, "2") == 0) {
            kullaniciSecimNumara = 2;
            printf("Siz Kagit sectiniz.\n");
        } else if (strcmp(kullaniciSecim, "makas") == 0 || strcmp(kullaniciSecim, "3") == 0) {
            kullaniciSecimNumara = 3;
            printf("Siz Makas sectiniz.\n");
        } else {
            printf("Hatali Giris Yaptiniz! Lutfen 'Tas veya 1', 'Kagit veya 2 ', 'Makas veya 3' Yazin.\n");
            tur--;
            continue;
        }

        printf("Bilgisayar ");
        if (bilgisayarSecim == 1) {
            printf("Tas");
        } else if (bilgisayarSecim == 2) {
            printf("Kagit");
        } else {
            printf("Makas");
        }
        printf(" secti.\n");

        if (kullaniciSecimNumara == bilgisayarSecim) {
            printf("Berabere Kaldiniz!\n");
        } else if ((kullaniciSecimNumara == 1 && bilgisayarSecim == 3) || (kullaniciSecimNumara == 2 && bilgisayarSecim == 1) || (kullaniciSecimNumara == 3 && bilgisayarSecim == 2)) {
            printf("Kazandiniz!\n");
            KullaniciSkor++;
        } else {
            printf("Bilgisayar Kazandi!\n");
            BilgisayarSkor++;
        }
    }

    printf("\nSonucunuz:\n");
    printf("Skorunuz: %d \nBilgisayarin Skoru: %d\n", KullaniciSkor, BilgisayarSkor);

    if (KullaniciSkor > BilgisayarSkor) {
        printf("Tebrikler, Oyunu Kazandiniz!\n");
    } else if (KullaniciSkor < BilgisayarSkor) {
        printf("Uzgunuz, Bilgisayar Kazandi!\n");
    } else {
        printf("Oyun Berabere Bitti!\n");
    }

    return 0;
}

