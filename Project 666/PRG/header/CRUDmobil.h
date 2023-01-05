void CreateMobil()
{
    FILE *fpr;
    int id;
	DesainUtama();
	PrintFile("logo/tulisan-mobil.txt", 74, 3);

	gotoPrint("Pilihan : ", 7, 20);
	gotoPrint("1. Tambah Mobil", 7, 22);
	gotoPrint("2. Edit Mobil", 7, 23);
	gotoPrint("3. Hapus Mobil", 7, 24);
	gotoPrint("4. Kembali", 7, 25);
	gotoPrint("5. Log Out", 7, 26);
	gotoPrint("[", 12, 27); gotoPrint("]", 14, 27);

	gotoPrint("========================= Masukkan Data Mobil =========================", 35, 12);

	fpr = fopen("file/Mobil.dat", "rb");
    fread(&dMobil.kd_mobil, sizeof(dMobil), 1, fpr);
	while(!feof(fpr))
    {
        fread(&dMobil.kd_mobil, sizeof(dMobil), 1, fpr);
        id = dMobil.kd_mobil;
    }
    fclose(fpr);
    dMobil.kd_mobil += 1;

    fp = fopen("file/Mobil.dat","ab");
    gotoxy(35, 14); printf("Kode Mobil\t: MBL%d", dMobil.kd_mobil);
    gotoPrint("Merk Mobil\t: ", 35, 15);
    fflush(stdin); takeInput(dMobil.merk_mobil);
    gotoPrint("Nama Mobil\t: ", 35, 16);
    fflush(stdin); takeInput(dMobil.nama_mobil);
    gotoPrint("Harga Mobil\t: Rp ", 35, 17);
    fflush(stdin); getRp(&dMobil.harga_mobil, 1, 20, 53, 17);
    gotoPrint("Stok Mobil\t: ", 35, 18);
    fflush(stdin); getnum(&dMobil.stok, 3);

    fwrite(&dMobil, sizeof(dMobil), 1 , fp);
    fclose(fp);

    BersihSemuaLayar();
    MobilMenu();
}

void ReadMobil()
{
	int i,l;
	char harga[50];
    DesainUtama();
    PrintFile("logo/tulisan-mobil.txt", 74, 3);
    gotoPrint("========================= Data Mobil =========================", 35, 12);

    fp = fopen("file/Mobil.dat", "rb");
    fread(&dMobil, sizeof(dMobil), 1, fp);

    fflush(stdin);
	gotoPrint("Kode", 36, 15);
	gotoPrint("Merk", 47, 15);
	gotoPrint("Nama", 65, 15);
	gotoPrint("Harga", 85, 15);
	gotoPrint("Stok", 103, 15);
	//gotoPrint("---------------------------------------------------------------", 35, 16);
	//gotoPrint("_____________________________________________________________________________", 33, 16);

	gotoxy(33, 16); for (int brs = 33; brs <= 110; brs++){
        printf("_");
    }
	i= 17;
	while (!feof(fp))
	{
		fflush(stdin);
		gotoxy(35,i); printf("MBL%d",dMobil.kd_mobil);
		gotoxy(44,i); printf("%s",dMobil.merk_mobil);
		gotoxy(59,i); printf("%s",dMobil.nama_mobil);
		gotoxy(79,i); printf("Rp "); RP(dMobil.harga_mobil);
		gotoxy(104,i); printf("%d",dMobil.stok);
		fread(&dMobil, sizeof(dMobil), 1, fp);
		i++;
	}
	fclose(fp);
	for(l=15; l<i; l++)
    {
        gotoPrint("|", 33,l);
        gotoPrint("|", 42,l);
        gotoPrint("|", 57,l);
        gotoPrint("|", 77,l);
        gotoPrint("|", 99,l);
        gotoPrint("|", 110,l);
    }
}

void UpdateMobil()
{
    DesainUtama();
    PrintFile("logo/tulisan-mobil.txt", 74, 3);
    gotoPrint("========================= Update Mobil =========================", 35, 12);

    gotoPrint("Pilihan : ", 7, 20);
	gotoPrint("1. Tambah Mobil", 7, 22);
	gotoPrint("2. Edit Mobil", 7, 23);
	gotoPrint("3. Hapus Mobil", 7, 24);
	gotoPrint("4. Kembali", 7, 25);
	gotoPrint("5. Log Out", 7, 26);
	gotoPrint("[", 12, 27); gotoPrint("]", 14, 27);

    FILE *TEMP;
    bool found;
    int kode;

    fp = fopen("file/Mobil.dat", "rb");
    TEMP = fopen("file/MobilTemp.dat", "wb");

    gotoxy(35, 14); printf("Masukkan Kode Mobil Yang Ingin Diupdate : MBL");
    getnum(&kode, 4);
    found = false;

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
	        gotoxy(35,17); printf("Kode Mobil\t: MBL%d",dMobil.kd_mobil);
			gotoxy(35,18); printf("Merk Mobil\t: %s",dMobil.merk_mobil);
			gotoxy(35,19); printf("Nama Mobil\t: %s",dMobil.nama_mobil);
			gotoxy(35,20); printf("Harga Mobil\t: Rp "); RP(dMobil.harga_mobil);

			gotoPrint("-----Masukkan Data Mobil Tebaru-----", 35, 22);
	        gotoPrint("Masukkan Merk Mobil  : ", 35, 23); fflush(stdin); takeInput(&dMobil.merk_mobil);
	        gotoPrint("Masukkan Nama Mobil  : ", 35, 24); fflush(stdin); takeInput(&dMobil.nama_mobil);
	        gotoPrint("Masukkan Harga Mobil : Rp ", 35, 25); fflush(stdin); getRp(&dMobil.harga_mobil, 1, 20, 61, 25);

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
	        MessageBox(NULL, "DATA BERHASIL DIUBAH", "SUCCESS", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
	        BersihSemuaLayar();
	        MobilMenu();
	    }
	    else
        {
            MessageBox(NULL, "DATA MOBIL TIDAK ADA", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            BersihSemuaLayar();
            UpdateMobil();
        }
	}
}

void DeleteMobil()
{
    DesainUtama();
    PrintFile("logo/tulisan-mobil.txt", 74, 3);
    gotoPrint("========================= Update Mobil =========================", 35, 12);

    gotoPrint("Pilihan : ", 7, 20);
	gotoPrint("1. Tambah Mobil", 7, 22);
	gotoPrint("2. Edit Mobil", 7, 23);
	gotoPrint("3. Hapus Mobil", 7, 24);
	gotoPrint("4. Kembali", 7, 25);
	gotoPrint("5. Log Out", 7, 26);
	gotoPrint("[", 12, 27); gotoPrint("]", 14, 27);

    FILE *TEMP;
    bool found;
    int kode;
    char yn;

    fp = fopen("file/Mobil.dat", "rb");
    TEMP = fopen("file/MobilTemp.dat", "wb");

    gotoxy(35, 14); printf("Masukkan Kode Mobil Yang Ingin Dihapus : MBL");
    getnum(&kode, 4);
    found = false;

    if(kode == 0)
    {
        BersihSemuaLayar();
    	MobilMenu();
    } else if(kode != 0)
    {
        fread(&dMobil, sizeof(dMobil), 1, fp);
        while(!found && !feof(fp))
        {
            if(dMobil.kd_mobil == kode)
            {
                found = true;
            }
            else
            {
                fwrite(&dMobil, sizeof(dMobil), 1, TEMP);
                fread(&dMobil, sizeof(dMobil), 1, fp);
            }
        }

        if(found == true)
        {
            gotoxy(35,17); printf("Kode Mobil\t: MBL%d",dMobil.kd_mobil);
			gotoxy(35,18); printf("Merk Mobil\t: %s",dMobil.merk_mobil);
			gotoxy(35,19); printf("Nama Mobil\t: %s",dMobil.nama_mobil);
			gotoxy(35,20); printf("Harga Mobil\t: Rp "); RP(dMobil.harga_mobil);

			gotoxy(35, 22); printf("APAKAH YAKIN INGIN MENGHAPUS? : ");
            scanf("%c", &yn);

            if(yn == 'n' || yn == 'N')
            {
                BersihSemuaLayar();
                DeleteMobil();
            } else if(yn == 'y' || yn == 'Y')
            {
                fread(&dMobil, sizeof(dMobil), 1, fp);
                while(!feof(fp))
                {
                    fwrite(&dMobil, sizeof(dMobil), 1, TEMP);
                    fread(&dMobil, sizeof(dMobil), 1, fp);
                }
                fclose(TEMP);
                fclose(fp);

                remove("file/Mobil.dat");
                rename("file/MobilTemp.dat", "file/Mobil.dat");
                MessageBox(NULL, "DATA BERHASIL DIHAPUS", "SUCCESS", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                BersihSemuaLayar();
                MobilMenu();
            }
        }
        else
        {
            MessageBox(NULL, "DATA MOBIL TIDAK ADA", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            BersihSemuaLayar();
            MobilMenu();
        }
    }
}
