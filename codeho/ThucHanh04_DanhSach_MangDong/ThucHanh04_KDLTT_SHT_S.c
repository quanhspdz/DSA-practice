#include <stdio.h>
#include <stdlib.h>

struct SoHuuTy
{
	int tuSo;
	int mauSo;
};
typedef struct SoHuuTy SHT;

void nhapSHT(SHT *);
void inSHT(const SHT *);
void toiGianSHT(SHT *);
SHT* congSHT(const SHT *, const SHT *);
int soSanhSHT(const SHT *, const SHT *);
void sapXepLuaChonMangSHT(SHT *, int);

int main()
{
	// cap phat bo nho dong cho con tro toi mot so huu ti
	SHT * sht1 = malloc (sizeof(SHT));
    SHT * sht2 = malloc (sizeof(SHT));
    SHT * tongSHT = malloc (sizeof(SHT));

	// cap phat bo nho dong cho mang cac so huu ti
	SHT * mangSHT = (SHT*) malloc (sizeof(SHT) * 100);

    nhapSHT(sht1);
    inSHT(sht1);

    nhapSHT(sht2);
    inSHT(sht2);

    tongSHT = congSHT(sht1, sht2);
    inSHT(tongSHT);

	return 0;
}

// phai kiem tra xem mau so co khac 0 khong
// va so doc vao can luu o dang toi gian
void nhapSHT(SHT * sht)
{
    scanf("%i %i", &sht->tuSo, &sht->mauSo);
    toiGianSHT (sht);
}

// in duoi dang phan so a/b
void inSHT(const SHT *sht)
{
    printf("%i / %i", sht->tuSo, sht->mauSo);
}

// tu so va mau so cua 1 so huu ti nguyen to cung nhau
// luu y: so huu ti luon luon phai luu duoi dang nay
void toiGianSHT(SHT * sht)
{
    int a = sht->tuSo;
    int b = sht->mauSo;
    int r;
    while (a > 0 && b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    r = a + b;
    sht->tuSo /= r;
    sht->mauSo /= r;
}

SHT * congSHT(const SHT * sht1, const SHT * sht2)
{
	SHT * tongSHT = malloc (sizeof(SHT));
    tongSHT->tuSo = sht1->tuSo * sht2->mauSo + sht1->mauSo * sht2->tuSo;
	tongSHT->mauSo = sht1->mauSo * sht2->mauSo;
    toiGianSHT(tongSHT);
	return tongSHT;
}

// tra ve 1 neu sht1 > sht2
// tra ve 0 neu sht1 = sht2
// tra ve -1 neu sht1 < sht2
int soSanhSHT(const SHT * sht1, const SHT * sht2)
{
    return ( ((double)sht1->tuSo / sht1->mauSo) < ((double)sht2->tuSo / sht2->mauSo) );
}

// sap xep su dung thuat toan lua chon
void sapXepLuaChonMangSHT(SHT * mangSHT, int soPhanTu)
{
    int i, j;
    int viTriMin;
    for (i = 0; i < soPhanTu-1; i++)
    {
        viTriMin = i;
        for (j=i+1; j<soPhanTu; j++)
        {
            // thay doi vi tri cua min moi
            if (soSanhSHT(&mangSHT[viTriMin], &mangSHT[j]) == 1)
            {
                viTriMin = j;
            }
        }
        // doi cho phan tu nho nhat voi phan tu dau tien trong day chua sap xep (vi tri i)
        SHT temp = mangSHT[i];
        mangSHT[i] = mangSHT[viTriMin];
        mangSHT[viTriMin] = temp;
    }
}


