#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
struct ogrenci {
    char *numara=(char*)malloc(sizeof(char)*9);//dinamik hafıza ile numara tanımlanması
    int odevsayisi=0;//odev sayisi tanımı
    float vizenotu=0;//vize notu tanımı
    float finalnotu=0;//final notu tanımı
    int *odevnotu = (int*)malloc(sizeof(int)*odevsayisi);//dinamik hafıza ile odev notları için dizi tanımlanması
    float ortalama=0;//ortalama not tanımı
};
float sınıfortalaması(float ortalamalar[], int sayac)
{
    float genelortalama = 0;//genel ortalama için tanımlama
    for (int i = 0; i < sayac; i++) {
        genelortalama += ortalamalar[i];//bütün ortalamaların genelortalama içine atılması
    }
    genelortalama = genelortalama / sayac;//genel ortalama hesaplama
    return genelortalama;//genel ortalamayı return etme
}

float enkucukortalama(float ortalamalar[], int sayac) //en kucuk ortalamayı bulmak için gerekli parametreler tanımlandı
{
    float enkucukortalama = 100;//en kucuk ortalamayı bulmak için 100 en küçük ortalama olarak seçildi
    for (int i = 0; i < sayac; i++) {
        if (ortalamalar[i] < enkucukortalama) {
            enkucukortalama = ortalamalar[i];//en kucuk ortalamanın bulunması
        }
    }
    return enkucukortalama;//enkucukortalama değişkeninin geri döndürülmesi
}

float enbuyukortalama(float ortalamalar[], int sayac) //en buyuk ortalamayı bulmak için gerekli parametreler tanımlandı
{
    float enbuyukortalama = 0;//en buyuk ortalamayı bulmak için 0 en küçük ortalama olarak seçildi
    for (int i = 0; i < sayac; i++) {
        if (ortalamalar[i] > enbuyukortalama) {
            enbuyukortalama = ortalamalar[i];//en buyuk ortalamanın bulunması
        }
    }
    return enbuyukortalama;//enbuyukortalama değikeninin geri döndürülmesi
}

float odevortalaması(struct ogrenci ogrenci) //odev ortalaması için gerekli parametreler tanımlandı
{
    float odevortalaması = 0;
    for (int i = 1; i <= ogrenci.odevsayisi; i++) {
        odevortalaması += ogrenci.odevnotu[i];//odev notlarının toplanması
    }
    odevortalaması = odevortalaması / ogrenci.odevsayisi;//odev ortalamasının hesaplanması
    return odevortalaması;//odevortalaması değişkeninin geri döndürülmesi
}

float hesapla(struct ogrenci ogrenci, float ortalamalar[])
{
    if (ogrenci.odevsayisi == 0) //odev sayisina göre yapılacak işlemler ayrımı için karar yapısı
    {
        printf("Lutfen %s numarali ogrencinin vize notunu giriniz: ", ogrenci.numara);
        scanf("%f", &ogrenci.vizenotu);//vize notu öğrenme
        while (ogrenci.vizenotu < 0 || ogrenci.vizenotu>100) {
            printf("Gecersiz deger lutfen tekrar deneyiniz: ");//girilen vize notu için kontrol yapsısı
            scanf("%f", &ogrenci.vizenotu);
        }
        printf("Lutfen %s numarali ogrencinin final notunu giriniz: ", ogrenci.numara);
        scanf("%f", &ogrenci.finalnotu);//final notu öğrenme
        while (ogrenci.finalnotu < 0 || ogrenci.finalnotu>100) {
            printf("Gecersiz deger lutfen tekrar deneyiniz: ");//girilen final notu için kontrol yapısı
            scanf("%f", &ogrenci.finalnotu);
        }
        ogrenci.ortalama= ogrenci.vizenotu * 0.6 +ogrenci.finalnotu * 0.4;//ortalama hesaplama
        static int sayac = 0;//ortalamaları diziye tanımlarken sürekli 0 değerinden başlamaması için static olarak tanımlandı
        ortalamalar[sayac] =ogrenci.ortalama ;//hesaplanan ortalamaların diziye tanımlanması
        sayac++;
        return ogrenci.ortalama;//ortalama değikenin geri döndürülmesi
    }
    else
    {
        printf("Lutfen %s nolu ogrencinin vize notunu giriniz: ", ogrenci.numara);
        scanf("%f", &ogrenci.vizenotu);//vize notu öğrenme
        while (ogrenci.vizenotu < 0 || ogrenci.vizenotu>100)
        {
            printf("Gecersiz deger lutfen tekrar giriniz: ");//girilen vize notu için kontrol yapısı
            scanf("%f", &ogrenci.vizenotu);
        }
        printf("Lutfen %s nolu ogrencinin final notunu giriniz: ", ogrenci.numara);
        scanf("%f", &ogrenci.finalnotu);//final notu öğrenme
        while (ogrenci.finalnotu < 0 || ogrenci.finalnotu>100)
        {
            printf("Gecersiz deger lutfen tekrar giriniz: ");//girilen final notu için konrtol yapısı
            scanf("%f", &ogrenci.finalnotu);
        }
        for (int i = 1; i <=ogrenci.odevsayisi; i++) //girilen ödev notlarının diziye tanımlanması ve odev ortalamsı için döngü kullanıldı
        {
            printf("Lutfen %s numarali ogrencinin %d. odev notunu giriniz: ", ogrenci.numara, i);
            scanf("%d", &ogrenci.odevnotu[i]);//odev notlarının diziye tanımlanması
            if (ogrenci.odevnotu[i]< 0 || ogrenci.odevnotu[i]>100) {
                printf("Hatali giris yaptiniz lutfen tekrar giriniz: ");//girilen ödev notları için kontrol yapısı
                scanf("%d", &ogrenci.odevnotu[i]);
            }
        }
        float odevortalamasi = odevortalaması(ogrenci) * 0.3;//odev ortalamasının hesaplanması
        ogrenci.ortalama = ogrenci.vizenotu * 0.3 +ogrenci.finalnotu * 0.4 + odevortalamasi;//ortalama hesplanması
        static int sayac = 0;//ortalamaları diziye tanımlarken sürekli 0 değerinden başlamaması için static olarak tanımlandı
        ortalamalar[sayac] = ogrenci.ortalama;//hesaplanan ortalamaların diziye tanımlanması
        sayac++;
        return ogrenci.ortalama;//ortalama değikenin geri döndürülmesi
    }
}
int main()
{
    struct ogrenci ogrenci;//struct yapısıyla ogrenci değiskeni tanımlanması
    char kullanıcıkarar[2];//kullanıcı kararı için dizi tanımı
    int sayac = 0;//kaç öğrenci notu girildiğini bilmek için değişken tanımlama
    printf("NOT ORTALAMASI HESAPLAMA\n**************************\n");
    float ortalamalar[100];//ortalama karşılaştırması için dizi kullanıldı ve iki fonksiyon için global variable tanımlandı
    printf("Lutfen dersin odev sayisini giriniz: ");
    scanf("%d", &ogrenci.odevsayisi);//odev sayısı öğrenme
    while (ogrenci.odevsayisi<0||ogrenci.odevsayisi>10) {
        printf("Odev sayisi 0-10 arasinda olamalidir: ");//odev sayısı için kontrol adımı
        scanf("%d", &ogrenci.odevsayisi);
    }
    do
    {
        printf("Lutfen ogrenci numarasini giriniz:");
        scanf("%s", ogrenci.numara);//ogrenci numarasi öğrenme
        bool numarakontrol = true;//harf kontrolü için bool tanımı
        for (int i = 0; ogrenci.numara[i] != '\0'; i++) {
            if (ogrenci.numara[i] < '0' || ogrenci.numara[i] >'9')//rakam dışında karakter girisi olmamasi için ASCII kodu kontrolü
                numarakontrol = false;
            while (numarakontrol == false) {
                printf("Hatali giris yaptiniz lutfen tekrar deneyiniz:");//harf kontrolü için tekrar giriş
                scanf("%s",ogrenci.numara);
                if (ogrenci.numara[i] < '0' || ogrenci.numara[i] >'9') {
                    numarakontrol = false;
                }
                else {
                    numarakontrol = true;
                }
            }
        }
        printf("Ogrenci ortalamasi: %.2f\n", hesapla(ogrenci, ortalamalar));//hesapla fonksiyonu çağırma ve ortalamanın yazdırılmasi
        if (ogrenci.odevsayisi != 0) {
            printf("Odev ortalamasi: %.2f\n", odevortalaması(ogrenci));//odev ortalamasinin kontrol edilip yazdırılması
        }
        printf("Devam etmek icin 1'i(evet) kapatmak icin 0'i(hayir) giriniz:\n");//devam etmek için kullanıcı kararı alınması
        scanf(" %s", &kullanıcıkarar);
        bool karar = true;//kullanıcı kararında harf konrolü için bool tanımı
        for (int i = 0;karar==true&&kullanıcıkarar[i] != '\0'; i++) {//kullanıcı kararında 0 veya 1 dışında karakter kontrolü
            if (kullanıcıkarar[i]!='0'&&kullanıcıkarar[i] !='1') {
                karar =false;
                while (karar == false) {
                    printf("Hatali giris yaptiniz lutfen tekrar giriniz:\n");//harf kontrolü için tekrar giriş
                    scanf(" %s", &kullanıcıkarar);
                    if (kullanıcıkarar[i]>= '0' && kullanıcıkarar[i] <= '1') {
                        karar = true;
                    }
                }
            }
            sayac++;//girilen öğrenci sayısı için döngünün dönme sayısını bulmak için kullanıldı
        }
    } while (kullanıcıkarar[0] == '1');
    printf("En yuksek ortalama: %.2f\n", enbuyukortalama(ortalamalar, sayac));
    printf("En dusuk ortalama: %.2f\n", enkucukortalama(ortalamalar, sayac));//girilen notlar arasından sonra genel istatistikler yazdırıldı
    printf("Sinif ortalamasi: %.2f\n", sınıfortalaması(ortalamalar, sayac));
    system("pause");
    return 0;
}