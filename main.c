#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int teklif_veren_no;
    double teklif;
} Bid;

typedef struct
{
    Bid *teklifler;
    int teklif_veren_sayisi;
} Arttirma;

double odemeyi_hesapla(Arttirma a, int kazanan_no)
{
    double odeme = 0;
    int i;
    for (int i = 0; i < a.teklif_veren_sayisi; i++)
    {
        if (a.teklifler[i].teklif_veren_no == kazanan_no)
        {
            odeme += a.teklifler[i].teklif;
        }
    }
    return odeme;
}

void acikarttirma(Arttirma a)
{
    double odeme = 0;
    double en_yuksek_teklif = -1.0;
    int kazanan_no = -1;
    int i = 0;

    for (i = 0; i < a.teklif_veren_sayisi; i++)
    {
        if (a.teklifler[i].teklif > en_yuksek_teklif)
        {
            kazanan_no = a.teklifler[i].teklif_veren_no;
            en_yuksek_teklif = a.teklifler[i].teklif;
        }
    }
    odeme = odemeyi_hesapla(a, kazanan_no);
    printf("Kazanan no : %d\n", kazanan_no);
    printf("Odeme : %lf\n", odeme);
}

int main(int argc, char const *argv[])
{
    printf("Acik Arttirma Uygulamasi\n");

    Arttirma a;
    a.teklifler = (Bid *)malloc(sizeof(Bid) * 500);
    a.teklif_veren_sayisi = 0;
    while (1)
    {
        printf("a. Teklif Ekle\n");
        printf("q. Acik Arttirmayi Sonlandir\n");
        char secenek;

        printf("( secenek seciniz ) > ");
        scanf(" %c", &secenek);
        if (secenek == 'q')
        {
            break;
        }
        else if (secenek != 'a')
        {
            continue;
        }
        double teklif_miktar;
        int katilimci_no;
        printf("Teklif Giriniz : ");
        scanf("%lf", &teklif_miktar);

        printf("Katilimci No : ");
        scanf("%d", &katilimci_no);

        Bid *yeni_teklif = (Bid *)malloc(sizeof(Bid));
        yeni_teklif->teklif = teklif_miktar;
        yeni_teklif->teklif_veren_no = katilimci_no;
        a.teklifler[a.teklif_veren_sayisi] = *yeni_teklif;
        a.teklif_veren_sayisi++;
    }

    acikarttirma(a);
    return 0;
}
