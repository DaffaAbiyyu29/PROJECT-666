#include "variable.h"

Transaksi trs;
Restok rst;

void ManagerMenu()
{
    DesainUtama();
	PrintFile("logo/manager-logo.txt", 62, 3);
	PrintFile("logo/welcome-manager.txt", 34, 13);

	pilihanmanager();
}

void pilihanmanager()
{
    gotoPrint("Pilihan : ", 7, 20);
	gotoPrint("1. Laporan", 7, 22);
	gotoPrint("   Penjualan", 7, 23);
	gotoPrint("2. Laporan", 7, 24);
	gotoPrint("   Restok Mobil", 7, 25);
	gotoPrint("3. Laporan Kredit", 7, 26);
	gotoPrint("4. Kembali", 7, 27);
	gotoPrint("5. Keluar", 7, 28);
	gotoPrint("[", 10, 29); gotoPrint("]", 12, 29);
    gotoxy(11, 29); getnum(&pilih,1);

    switch(pilih)
    {
        case 1 : BersihSemuaLayar(); LaporanPenjualan(); break;
        case 2 : BersihSemuaLayar(); LaporanRestok(); break;
        case 3 : BersihSemuaLayar(); /*LaporanKredit();*/ break;
        case 4 : BersihSemuaLayar(); ManagerMenu(); /*MenuUtama();*/ break;
        case 5 : BersihSemuaLayar(); LoginForm(); /*MenuUtama();*/ break;
        default: BersihSemuaLayar(); AdminMenu(); break;
    }
}

void LaporanPenjualan()
{
    DesainUtama();
	PrintFile("logo/manager-logo.txt", 62, 3);
    gotoPrint("========================= Laporan Transaksi Penjualan Mobil =========================", 35, 12);

	int i,l;
	char harga[50];

    fp = fopen("file/TransaksiJual.dat", "rb");
    fread(&trs, sizeof(trs), 1, fp);

    fflush(stdin);
	gotoPrint("KD TRS", 36, 15);
	gotoPrint("Tanggal", 48, 15);
	gotoPrint("KD MBL", 62, 15);
	gotoPrint("Nama Mobil", 75, 15);
	gotoPrint("Harga", 96, 15);
	gotoPrint("Jumlah", 109, 15);
	gotoPrint("Total", 123, 15);
	gotoPrint("______________________________________________________________________________________________________", 33, 16);
	i= 17;
	while (!feof(fp))
	{
		fflush(stdin);
		gotoxy(35,i); printf("TRS%d",trs.kd_transaksi);
		gotoxy(47,i); printf("%d/%d/%d",trs.tanggal.tgl, trs.tanggal.bulan, trs.tanggal.tahun);
		gotoxy(61,i); printf("MBL%d",trs.kd_mobil);
		gotoxy(72,i); printf("%s",trs.nama_mobil);
		gotoxy(91,i); printf("Rp "); RP(trs.harga_mobil);
		gotoxy(111,i); printf("%d", trs.jumlah);
        gotoxy(118,i); printf("Rp "); RP(trs.total_harga);
		fread(&trs, sizeof(trs), 1, fp);
		i++;
	}
	fclose(fp);
	for(l=15; l<i; l++)
    {
        gotoPrint("|", 33,l);
        gotoPrint("|", 44,l);
        gotoPrint("|", 59,l);
        gotoPrint("|", 70,l);
        gotoPrint("|", 89,l);
        gotoPrint("|", 107,l);
        gotoPrint("|", 116,l);
        gotoPrint("|", 134,l);
    }
    pilihanmanager();
}

void LaporanRestok()
{
    DesainUtama();
	PrintFile("logo/manager-logo.txt", 62, 3);
    gotoPrint("========================= Laporan Transaksi Penjualan Mobil =========================", 35, 12);

	int i,l;
	char harga[50];

    fp = fopen("file/RestokMobil.dat", "rb");
    fread(&rst, sizeof(rst), 1, fp);

    fflush(stdin);
	gotoPrint("KD TRS", 36, 15);
	gotoPrint("Tanggal", 48, 15);
	gotoPrint("KD MBL", 62, 15);
	gotoPrint("Nama Mobil", 75, 15);
	gotoPrint("Harga", 96, 15);
	gotoPrint("Jumlah", 109, 15);
	gotoPrint("Total", 123, 15);
	gotoPrint("______________________________________________________________________________________________________", 33, 16);
	i= 17;
	while (!feof(fp))
	{
		fflush(stdin);
		gotoxy(35,i); printf("RST%d",rst.kd_restok);
		gotoxy(47,i); printf("%d/%d/%d",rst.tanggal.tgl, rst.tanggal.bulan, rst.tanggal.tahun);
		gotoxy(61,i); printf("MBL%d",rst.kd_mobil);
		gotoxy(72,i); printf("%s",rst.nama_mobil);
		gotoxy(91,i); printf("Rp "); RP(rst.harga_mobil);
		gotoxy(111,i); printf("%d", rst.jumlah);
        gotoxy(118,i); printf("Rp "); RP(rst.total_harga);
		fread(&rst, sizeof(rst), 1, fp);
		i++;
	}
	fclose(fp);
	for(l=15; l<i; l++)
    {
        gotoPrint("|", 33,l);
        gotoPrint("|", 44,l);
        gotoPrint("|", 59,l);
        gotoPrint("|", 70,l);
        gotoPrint("|", 89,l);
        gotoPrint("|", 107,l);
        gotoPrint("|", 116,l);
        gotoPrint("|", 134,l);
    }
    pilihanmanager();
}
