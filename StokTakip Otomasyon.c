#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 30

struct Urun {
    char kategori[SIZE];
    int urunKodu;
    char urunAdi[SIZE];
    int satisFiyati;
    int stokMiktari;
};

struct Tedarikci {
    int tedarikciNo;
    char ad[SIZE];
    char adres[SIZE * 3];
    char sehir[SIZE];
};

struct StokGiris {
    int urunKodu;
    int tedarikciNo;
    int alisMiktari;
    char tarih[SIZE];
};

struct Urun ** urunler;
int urunAdet = 0;

struct Tedarikci ** tedarikciler;
int tedarikciAdet = 0;

struct StokGiris ** stokGirisler;
int stokGirisAdet = 0;

int satirSayisiniGetir(FILE *fp);

void urunOku();
void urunEkle();
void urunSil();
void urunGuncelle();
void urunListele();
void urunYaz();

void tedarikciOku();
void tedarikciEkle();
void tedarikciSil();
void tedarikciGuncelle();
void tedarikciListele();
void tedarikciYaz();

void stokGirisOku();
void stokGirisEkle();
void stokGirisSil();
void stokGirisListele();
void stokGirisYaz();

void iade();

int main() {
    urunOku();
    tedarikciOku();
    stokGirisOku();
    printf("---------------------------------------------- ");
    printf("\n\t\tSTOK TAKIP OTOMASYON SISTEMINE");
    printf("\n\t\t\t\tHOSGELDINIZ\n");
    printf("---------------------------------------------- \n");
    int secim1, secim2;
    while(1) {
        here:
        printf("Gitmek Istediginiz Alani Seciniz");
        printf("\n1-)Urun\n2-)Tedarikci\n3-)Stok-Giris->");
        scanf("%d" ,&secim1);

        switch(secim1) {
            case 1:
                while(1) {
                    printf("\nIslem Seciniz\n\n");
                    printf("1-)Ekle\n2-)Sil\n3-)Bilgi Guncelle\n4-)Listele\n5-)Mod Degistir\n6-)Cikis\n->");
                    scanf("%d", &secim2);

                    switch(secim2) {
                        case 1:urunEkle();
                            break;
                        case 2:urunSil();
                            break;
                        case 3:urunGuncelle();
                            break;
                        case 4:urunListele();
                            break;
                        case 5:goto here;
                        case 6:
                            iade();
                            return 0;
                    }
                }
            case 2:
                while(1) {
                    printf("\nIslem Seciniz\n\n");
                    printf("1-)Ekle\n2-)Sil\n3-)Bilgi Guncelle\n4-)Listele\n5-)Mod Degistir\n6-)Cikis\n->");
                    scanf("%d", &secim2);

                    switch(secim2) {
                        case 1:tedarikciEkle();
                            break;
                        case 2:tedarikciSil();
                            break;
                        case 3:tedarikciGuncelle();
                            break;
                        case 4:tedarikciListele();
                            break;
                        case 5:goto here;
                        case 6:
                            iade();
                            return 0;
                    }
                }
            case 3:
                while(1) {
                    printf("\nIslem Seciniz\n\n");
                    printf("1-)Ekle\n2-)Sil\n3-)Listele\n4-)Mod Degistir\n5-)Cikis\n->");
                    scanf("%d", &secim2);

                    switch(secim2) {
                        case 1:stokGirisEkle();
                            break;
                        case 2:stokGirisSil();
                            break;
                        case 3:stokGirisListele();
                            break;
                        case 4:goto here;
                        case 5:
                            iade();
                            return 0;
                    }
                }
        }
    }
}

int satirSayisiniGetir(FILE *fp) {
    if(!fp) {
        printf("Dosya bulunamadi");
        return -1;
    } else {
        char c;
        int counter = 1;
        for (c = getc(fp); c != EOF; c = getc(fp)) {
            if (c == '\n') {
                counter = counter + 1;
            }
        }
        return counter;
    }
}

void urunOku() {
    urunler = malloc(sizeof(struct Urun *) * 3);

    urunler[0] = malloc(sizeof(struct Urun));
    strcpy(urunler[0]->kategori, "Teknoloji");
    urunler[0]->urunKodu = 0001;
    strcpy(urunler[0]->urunAdi, "Televizyon");
    urunler[0]->satisFiyati = 10000;
    urunler[0]->stokMiktari = 75;

    urunler[1] = malloc(sizeof(struct Urun));
    strcpy(urunler[1]->kategori, "Teknoloji");
    urunler[1]->urunKodu = 0002;
    strcpy(urunler[1]->urunAdi, "Telefon");
    urunler[1]->satisFiyati = 8000;
    urunler[1]->stokMiktari = 75;

    urunler[2] = malloc(sizeof(struct Urun));
    strcpy(urunler[2]->kategori, "Teknoloji");
    urunler[2]->urunKodu = 0003;
    strcpy(urunler[2]->urunAdi, "Bilgisayar");
    urunler[2]->satisFiyati = 12000;
    urunler[2]->stokMiktari = 75;

    urunAdet = 3;
}

void urunEkle() {

    urunler = realloc(urunler, sizeof(struct Urun *) * (urunAdet + 1));
    urunler[urunAdet] = malloc(sizeof(struct Urun));

    strcpy(urunler[urunAdet]->kategori, "Teknoloji");
    printf("Urun Kodu Giriniz: ");
    scanf("%d", &urunler[urunAdet]->urunKodu);
    printf("Urun Adi Giriniz: ");
    scanf("%s", urunler[urunAdet]->urunAdi);
    printf("Urun Satis Fiyatini Giriniz: ");
    scanf("%d", &urunler[urunAdet]->satisFiyati);
    printf("Urun Stok Miktarini Giriniz: ");
    scanf("%d", &urunler[urunAdet]->stokMiktari);

    urunAdet++;
    printf("Urun Eklendi.\n");
}

void urunSil() {
    urunListele();
    int secim = 0;
    int i;
    printf("Silmek Istediginiz Urunu Seciniz: ");
    scanf("%d", &secim);

    if(secim == urunAdet)
        urunler = realloc(urunler, sizeof(struct Urun *) * (urunAdet - 1));
    else {
        for(i = secim; i < urunAdet; i++) {
            urunler[i - 1] = urunler[i];
        }
        urunler = realloc(urunler, sizeof(struct Urun *) * (urunAdet - 1));
    }
    urunAdet--;

    printf("Urun Silindi.\n");
}

void urunGuncelle() {
    urunListele();
    int secim = 0;
    printf("Guncellemek Istediginiz Urunu Seciniz: ");
    scanf("%d", &secim);

    printf("Yeni Urun Kodu Giriniz: ");
    scanf("%d", &urunler[secim - 1]->urunKodu);
    printf("Yeni Urun Adi Giriniz: ");
    scanf("%s", urunler[secim - 1]->urunAdi);
    printf("Yeni Urun Satis Fiyatini Giriniz: ");
    scanf("%d", &urunler[secim - 1]->satisFiyati);
    printf("Yeni Urun Stok Miktarini Giriniz: ");
    scanf("%d", &urunler[secim - 1]->stokMiktari);

    printf("Urun Guncellendi.\n");
}

void urunListele() {
	int i; 
    printf("KATEGORI\tURUN KODU\t\tURUN ADI\tSATIS FIYATI\tSTOK MIKTARI\n");
    for(i = 0; i < urunAdet; i++) {
        printf("%d-) %s\t\t%d\t%s\t\t%d\t\t%d\n", (i + 1), urunler[i]->kategori, urunler[i]->urunKodu, urunler[i]->urunAdi, urunler[i]->satisFiyati, urunler[i]->stokMiktari);
    }
}

void urunYaz() {

}

void tedarikciOku() {
    tedarikciler = malloc(sizeof(struct Tedarikci *) * 2);
    tedarikciler[0] = malloc(sizeof(struct Tedarikci));
    tedarikciler[0]->tedarikciNo = 1;
    strcpy(tedarikciler[0]->sehir, "Izmir");
    strcpy(tedarikciler[0]->ad, "Eren");
    strcpy(tedarikciler[0]->adres, "Yali Mahallesi");

    tedarikciler[1] = malloc(sizeof(struct Tedarikci));
    tedarikciler[1]->tedarikciNo = 2;
    strcpy(tedarikciler[1]->sehir, "Izmir");
    strcpy(tedarikciler[1]->ad, "Dile");
    strcpy(tedarikciler[1]->adres, "Bostanli Mahallesi");

    tedarikciAdet = 2;
}
void tedarikciEkle() {
    tedarikciler = realloc(tedarikciler, sizeof(struct Tedarikci *) * (tedarikciAdet + 1));
    tedarikciler[tedarikciAdet] = malloc(sizeof(struct Tedarikci));

    printf("Tedarikci No Giriniz: ");
    scanf("%d", &tedarikciler[tedarikciAdet]->tedarikciNo);
    strcpy(tedarikciler[tedarikciAdet]->sehir, "Izmir");
    printf("Tedarikci Adi Giriniz: ");
    scanf("%s", tedarikciler[tedarikciAdet]->ad);
    printf("Tedarikci Adresi Giriniz: ");
    scanf("%s", tedarikciler[tedarikciAdet]->adres);

    tedarikciAdet++;
    printf("Tedarikci Eklendi.\n");
}

void tedarikciSil() {
    tedarikciListele();
    int secim = 0;
    int i; 
    printf("Silmek Istediginiz Tedarikciyi Seciniz: ");
    scanf("%d", &secim);

    if(secim == tedarikciAdet)
        tedarikciler = realloc(tedarikciler, sizeof(struct Tedarikci *) * (tedarikciAdet - 1));
    else {
        for(i = secim; i < tedarikciAdet; i++) {
            tedarikciler[i - 1] = tedarikciler[i];
        }
        tedarikciler = realloc(tedarikciler, sizeof(struct Tedarikci *) * (tedarikciAdet - 1));
    }

    tedarikciAdet--;
    printf("Tedarikci Silindi.\n");
}

void tedarikciGuncelle() {
    tedarikciListele();
    int secim = 0;
    printf("Guncellemek Istediginiz Tedarikciyi Seciniz: ");
    scanf("%d", &secim);

    printf("Yeni Tedarikci No Giriniz: ");
    scanf("%d", &tedarikciler[secim - 1]->tedarikciNo);
    printf("Yeni Tedarikci Adi Giriniz: ");
    scanf("%s", tedarikciler[secim - 1]->ad);
    printf("Yeni Tedarikci Adresi Giriniz: ");
    scanf("%s", tedarikciler[secim - 1]->adres);

    printf("Tedarikci Guncellendi.\n");
}

void tedarikciListele() {
	int i; 
    printf("TEDARIKCI NO\tSEHIR\tAD\t\tADRES\n");
    for(i = 0; i < tedarikciAdet; i++) {
        printf("%d-) %d\t\t%s\t\t%s\t\t%s\n", (i + 1), tedarikciler[i]->tedarikciNo, tedarikciler[i]->sehir, tedarikciler[i]->ad, tedarikciler[i]->adres);
    }
}

void tedarikciYaz() {

}

void stokGirisOku() {
    stokGirisler = malloc(sizeof(struct StokGiris *) * 2);
    stokGirisler[0] = malloc(sizeof(struct StokGiris));
    stokGirisler[0]->urunKodu = 1;
    stokGirisler[0]->tedarikciNo = 1;
    stokGirisler[0]->alisMiktari = 20;
    strcpy(stokGirisler[0]->tarih, "2021-06-16");

    stokGirisler[1] = malloc(sizeof(struct StokGiris));
    stokGirisler[1]->urunKodu = 2;
    stokGirisler[1]->tedarikciNo = 1;
    stokGirisler[1]->alisMiktari = 10;
    strcpy(stokGirisler[1]->tarih, "2021-07-16");

    stokGirisAdet = 2;
}

void stokGirisEkle() {
    tedarikciListele();
    int secim = 0, tedarikciNo = 0, urunKodu = 0, alisMiktari = 0;
    printf("Tedarikci Seciniz: ");
    scanf("%d", &secim);
    tedarikciNo = tedarikciler[secim - 1]->tedarikciNo;

    urunListele();
    printf("Urun Seciniz: ");
    scanf("%d", &secim);
    urunKodu = urunler[secim - 1]->urunKodu;

    printf("Alis Miktari Giriniz: ");
    scanf("%d", &alisMiktari);
    urunler[secim - 1]->stokMiktari -= alisMiktari;

    stokGirisler = realloc(stokGirisler, sizeof(struct StokGiris *) * (stokGirisAdet + 1));
    stokGirisler[stokGirisAdet] = malloc(sizeof(struct StokGiris));

    stokGirisler[stokGirisAdet]->urunKodu = urunKodu;
    stokGirisler[stokGirisAdet]->tedarikciNo = tedarikciNo;
    stokGirisler[stokGirisAdet]->alisMiktari = alisMiktari;

    printf("Tarih Giriniz: ");
    scanf("%s", stokGirisler[stokGirisAdet]->tarih);

    stokGirisAdet++;
    printf("Stok-Giris Eklendi.\n");
}

void stokGirisSil(){
    stokGirisListele();
    int secim = 0;
    int i; 
    printf("Silmek Istediginiz Stok-Girisi Seciniz: ");
    scanf("%d", &secim);

    if(secim == stokGirisAdet)
        stokGirisler = realloc(stokGirisler, sizeof(struct StokGiris *) * (stokGirisAdet - 1));
    else {
        for(i = secim; i < stokGirisAdet; i++) {
            stokGirisler[i - 1] = stokGirisler[i];
        }
        stokGirisler = realloc(stokGirisler, sizeof(struct StokGiris *) * (stokGirisAdet - 1));
    }

    stokGirisAdet--;
    printf("Stok-Giris Silindi.\n");
}

void stokGirisListele() {
	int i; 
    printf("URUN KODU\tTEDARIKCI NO\tALIS MIKTARI\tTARIH\n");
    for(i = 0; i < stokGirisAdet; i++) {
        printf("%d-) %d\t\t\t%d\t\t\t%d\t\t\t%s\n", (i + 1), stokGirisler[i]->urunKodu, stokGirisler[i]->tedarikciNo, stokGirisler[i]->alisMiktari, stokGirisler[i]->tarih);
    }
}

void stokGirisYaz() {

}

void iade() {
    urunYaz();
    tedarikciYaz();
    stokGirisYaz();
}
