#include "variable.h"

Mobil dMobil;
Transaksi trs;
Restok rst;
Date tanggal;

void TransaksiJualMobil()
{
    DesainUtama();
	PrintFile("logo/kasir-logo.txt", 75, 3);
    gotoPrint("========================= Transaksi Penjualan Mobil =========================", 35, 12);
    gotoPrint("Pilihan : ", 7, 20);
	gotoPrint("1. Jual Mobil", 7, 22);
	gotoPrint("2. Restok Mobil", 7, 23);
	gotoPrint("3. Kredit", 7, 24);
	gotoPrint("4. Keluar", 7, 25);
	gotoPrint("[", 10, 26); gotoPrint("]", 12, 26);

    FILE *fp;
    FILE *fpt;
    int id, kode, jmlh;
    bool found;
    float tbunga, tharga;

    time_t t = time(NULL);
	struct tm tm = * localtime(&t);


    fpt = fopen("file/TransaksiJual.dat", "rb");

    fread(&trs.kd_transaksi, sizeof(trs), 1, fpt);
	while(!feof(fpt))
    {
        fread(&trs.kd_transaksi, sizeof(trs), 1, fpt);
        id = trs.kd_transaksi;

    }
    fclose(fpt);
    trs.kd_transaksi += 1;

    fpt = fopen("file/TransaksiJual.dat", "ab");
    gotoxy(35,14); printf("Kode Transaksi : TRS%d", trs.kd_transaksi);
    gotoxy(35,15); printf("Tanggal        :   /  /");
    /* Input tanggal Transaksi */
	InputTgl:
	DateTimeNow(&Now);
	gotoxy(52, 15); fflush(stdin); getnum(&trs.tanggal.tgl, 2);
	gotoxy(52, 15);	printf("%02d", trs.tanggal.tgl);
	if (trs.tanggal.tgl == 0) {
		TransaksiJualMobil();
	}
	gotoxy(55, 15); fflush(stdin); getnum(&trs.tanggal.bulan, 2);
	gotoxy(55, 15);	printf("%02d", trs.tanggal.bulan);
	gotoxy(58, 15); fflush(stdin); getnum(&trs.tanggal.tahun, 4);
	gotoxy(58, 15);	printf("%04d", trs.tanggal.tahun);

	if(trs.tanggal.tahun < Now.tahun
	|| trs.tanggal.tahun == Now.tahun && trs.tanggal.bulan < Now.bulan
	|| trs.tanggal.tahun == Now.tahun && trs.tanggal.bulan == Now.bulan && trs.tanggal.tgl < Now.tgl
	|| !dateValid(trs.tanggal)) {
		MessageBox(0, "Tanggal tidak valid", "Gagal", MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY);
		gotoPrint(52, 15, "  -  -    ");
		goto InputTgl;
	}

	gotoxy(35,16); printf("Nama Cust      : "); fflush(stdin); takeInput(trs.nama_cus);
    fp = fopen("file/Mobil.dat", "rb");
    gotoxy(35,17); printf("Kode Mobil     : MBL");
    getnum(&kode, 4);
    found = false;

    if(kode == 0)
    {
        BersihSemuaLayar();
    	TransaksiJualMobil();
    }
    else if(kode != 0)
    {
        while(!found && !feof(fp))
        {
            fread(&dMobil, sizeof(dMobil), 1, fp);
	        if(dMobil.kd_mobil == kode)
	        {
	            found = true;
	        }
        }


        if(found == true)
        {
            trs.bunga = 0.1;
            gotoxy(35,18); printf("Merk Mobil     : %s", dMobil.merk_mobil);
            gotoxy(35,19); printf("Nama Mobil     : %s", dMobil.nama_mobil);
            gotoxy(35,20); printf("Harga Mobil    : Rp "); RP(dMobil.harga_mobil);
            gotoxy(35,21); printf("Jumlah         : "); getnum(&jmlh, 2);

            trs.total_bunga = dMobil.harga_mobil * trs.bunga;
            trs.total_harga = (dMobil.harga_mobil + trs.total_bunga) * jmlh;

            gotoxy(35,22); printf("Total Bunga    : Rp "); RP(trs.total_bunga);
            gotoxy(35,23); printf("Total Harga    : Rp "); RP(trs.total_harga);

            trs.kd_mobil = dMobil.kd_mobil;
            strcpy(trs.merk_mobil, dMobil.merk_mobil);
            strcpy(trs.nama_mobil, dMobil.nama_mobil);
            trs.harga_mobil = dMobil.harga_mobil;
            trs.jumlah = jmlh;
            fwrite(&trs, sizeof(trs), 1 , fpt);
            fclose(fp);
            fclose(fpt);

            KurangiStok(kode, jmlh);
            getch();
            BersihSemuaLayar();
            SCMenu();

        }
        else
        {
            MessageBox(NULL, "DATA MOBIL TIDAK ADA", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            BersihSemuaLayar();
            SCMenu();
        }
    }
}

void KurangiStok(int kode, int jumlah)
{
    FILE *TEMP;
    bool found;
    int stokbaru;

    fp = fopen("file/Mobil.dat", "rb");
    TEMP = fopen("file/MobilTemp.dat", "wb");

    if(kode == 0)
    {
    	BersihSemuaLayar();
    	MobilMenu();
	}
	else if(kode != 0 && jumlah <= dMobil.stok)
	{
        while(!found && !feof(fp))
	    {
	        fread(&dMobil, sizeof(dMobil), 1, fp);
	        if(dMobil.kd_mobil == kode)
	        {
	            found = true;
	        }
	        else
	        {
	            fwrite(&dMobil, sizeof(dMobil), 1, TEMP);
	        }
	    }

	    if(found == true)
	    {
	        stokbaru = dMobil.stok - jumlah;
	        dMobil.stok = stokbaru;

	        fwrite(&dMobil,sizeof(dMobil),1,TEMP);
	        fread(&dMobil,sizeof(dMobil),1,fp);

	        while(!feof(fp))
	        {
	            fwrite(&dMobil,sizeof(dMobil),1,TEMP);
	            fread(&dMobil,sizeof(dMobil),1,fp);
	        }
	        fclose(fp);
	        fclose(TEMP);
	        remove("file/Mobil.dat");
	        rename("file/MobilTemp.dat", "file/Mobil.dat");
	    }
    }
}

void RestokMobil()
{
    DesainUtama();
	PrintFile("logo/kasir-logo.txt", 75, 3);
    gotoPrint("========================= Restok Mobil =========================", 35, 12);
    gotoPrint("Pilihan : ", 7, 20);
	gotoPrint("1. Jual Mobil", 7, 22);
	gotoPrint("2. Restok Mobil", 7, 23);
	gotoPrint("3. Kredit", 7, 24);
	gotoPrint("4. Keluar", 7, 25);
	gotoPrint("[", 10, 26); gotoPrint("]", 12, 26);

    FILE *fp;
    FILE *fpt;
    int id, kode, jmlh;
    bool found;
    float tbunga, tharga;

    time_t t = time(NULL);
	struct tm tm = * localtime(&t);


    fpt = fopen("file/RestokMobil.dat", "rb");

    fread(&rst.kd_restok, sizeof(rst), 1, fpt);
	while(!feof(fpt))
    {
        fread(&rst.kd_restok, sizeof(rst), 1, fpt);
        id = rst.kd_restok;

    }
    fclose(fpt);
    rst.kd_restok += 1;

    fpt = fopen("file/RestokMobil.dat", "ab");
    gotoxy(35,14); printf("Kode Transaksi : RST%d", rst.kd_restok);
    gotoxy(35,15); printf("Tanggal        :   /  /");
    /* Input tanggal Transaksi */
	InputTgl:
	DateTimeNow(&Now);
	gotoxy(52, 15); fflush(stdin); getnum(&rst.tanggal.tgl, 2);
	gotoxy(52, 15);	printf("%02d", rst.tanggal.tgl);
	if (rst.tanggal.tgl == 0) {
		RestokMobil();
	}
	gotoxy(55, 15); fflush(stdin); getnum(&rst.tanggal.bulan, 2);
	gotoxy(55, 15);	printf("%02d", rst.tanggal.bulan);
	gotoxy(58, 15); fflush(stdin); getnum(&rst.tanggal.tahun, 4);
	gotoxy(58, 15);	printf("%04d", rst.tanggal.tahun);

	if(rst.tanggal.tahun < Now.tahun
	|| rst.tanggal.tahun == Now.tahun && rst.tanggal.bulan < Now.bulan
	|| rst.tanggal.tahun == Now.tahun && rst.tanggal.bulan == Now.bulan && rst.tanggal.tgl < Now.tgl
	|| !dateValid(rst.tanggal)) {
		MessageBox(0, "Tanggal tidak valid", "Gagal", MB_ICONERROR | MB_OK | MB_DEFAULT_DESKTOP_ONLY);
		gotoPrint(52, 15, "  -  -    ");
		goto InputTgl;
	}

	gotoxy(35,16); printf("Nama Vendor    : "); fflush(stdin); takeInput(rst.nama_vendor);
    fp = fopen("file/Mobil.dat", "rb");
    gotoxy(35,17); printf("Kode Mobil     : MBL");
    getnum(&kode, 4);
    found = false;

    if(kode == 0)
    {
        BersihSemuaLayar();
    	RestokMobil();
    }
    else if(kode != 0)
    {
        while(!found && !feof(fp))
        {
            fread(&dMobil, sizeof(dMobil), 1, fp);
	        if(dMobil.kd_mobil == kode)
	        {
	            found = true;
	        }
        }


        if(found == true)
        {
            rst.bunga = 0.05;
            gotoxy(35,18); printf("Merk Mobil     : %s", dMobil.merk_mobil);
            gotoxy(35,19); printf("Nama Mobil     : %s", dMobil.nama_mobil);
            gotoxy(35,20); printf("Harga Mobil    : Rp "); RP(dMobil.harga_mobil);
            gotoxy(35,21); printf("Jumlah         : "); getnum(&jmlh, 2);

            rst.total_bunga = dMobil.harga_mobil * rst.bunga;
            rst.total_harga = (dMobil.harga_mobil + rst.total_bunga) * jmlh;

            gotoxy(35,22); printf("Total Bunga    : Rp "); RP(rst.total_bunga);
            gotoxy(35,23); printf("Total Harga    : Rp "); RP(rst.total_harga);

            rst.kd_mobil = dMobil.kd_mobil;
            strcpy(rst.merk_mobil, dMobil.merk_mobil);
            strcpy(rst.nama_mobil, dMobil.nama_mobil);
            rst.harga_mobil = dMobil.harga_mobil;
            rst.jumlah = jmlh;
            fwrite(&rst, sizeof(rst), 1 , fpt);
            fclose(fp);
            fclose(fpt);

            TambahStok(kode, jmlh);
            getch();
            BersihSemuaLayar();
            SCMenu();

        }
        else
        {
            MessageBox(NULL, "DATA MOBIL TIDAK ADA", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            BersihSemuaLayar();
            SCMenu();
        }
    }
}

void TambahStok(int kode, int jumlah)
{
    FILE *TEMP;
    bool found;
    int stokbaru;

    fp = fopen("file/Mobil.dat", "rb");
    TEMP = fopen("file/MobilTemp.dat", "wb");

    if(kode == 0)
    {
    	BersihSemuaLayar();
    	MobilMenu();
	}
	else if(kode != 0)
	{
        while(!found && !feof(fp))
	    {
	        fread(&dMobil, sizeof(dMobil), 1, fp);
	        if(dMobil.kd_mobil == kode)
	        {
	            found = true;
	        }
	        else
	        {
	            fwrite(&dMobil, sizeof(dMobil), 1, TEMP);
	        }
	    }

	    if(found == true)
	    {
	        stokbaru = dMobil.stok + jumlah;
	        dMobil.stok = stokbaru;

	        fwrite(&dMobil,sizeof(dMobil),1,TEMP);
	        fread(&dMobil,sizeof(dMobil),1,fp);

	        while(!feof(fp))
	        {
	            fwrite(&dMobil,sizeof(dMobil),1,TEMP);
	            fread(&dMobil,sizeof(dMobil),1,fp);
	        }
	        fclose(fp);
	        fclose(TEMP);
	        remove("file/Mobil.dat");
	        rename("file/MobilTemp.dat", "file/Mobil.dat");
	    }
    }
}
