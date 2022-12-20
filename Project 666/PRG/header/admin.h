#include "variable.h"

FILE *fp;
Mobil dMobil;

void AdminMenu()
{
	DesainUtama();
	PrintFile("logo/admin-logo.txt", 72, 3);
	PrintFile("logo/welcome-admin.txt", 34, 13);

	gotoPrint("Pilihan : ", 7, 20);
	gotoPrint("1. User", 7, 22);
	gotoPrint("2. Mobil", 7, 23);
	gotoPrint("3. ......", 7, 24);
	gotoPrint("4. ......", 7, 25);
	gotoPrint("0. Keluar", 7, 26);
	gotoPrint("[", 10, 27); gotoPrint("]", 12, 27);
    gotoxy(11, 27); getnum(&pilih,1);

    switch(pilih)
    {
        case 1 : BersihSemuaLayar(); break;
        case 2 : BersihSemuaLayar(); MobilMenu(); break;
        case 3 : BersihSemuaLayar(); /*UpdateUser();*/ break;
        case 4 : BersihSemuaLayar(); /*DeleteUser();*/ break;
        case 0 : BersihSemuaLayar(); LoginForm(); /*MenuUtama();*/ break;
    }
}

void MobilMenu()
{
	DesainUtama();

	ReadMobil();
	pilihan();

}

void pilihan()
{
	gotoPrint("Pilihan : ", 7, 20);
	gotoPrint("1. Tambah Mobil", 7, 22);
	gotoPrint("2. Edit Mobil", 7, 23);
	gotoPrint("3. Hapus Mobil", 7, 24);
	gotoPrint("4. Kembali", 7, 25);
	gotoPrint("5. Log Out", 7, 26);
	gotoPrint("[", 12, 27); gotoPrint("]", 14, 27);
    gotoxy(13, 27); getnum(&pilih,1);

    switch(pilih)
    {
        case 1 : BersihSemuaLayar(); CreateMobil(); break;
        case 2 : BersihSemuaLayar(); UpdateMobil(); break;
        case 3 : BersihSemuaLayar(); DeleteMobil(); break;
        case 4 : BersihSemuaLayar(); AdminMenu(); break;
        case 5 : BersihSemuaLayar(); LoginForm(); break;
    }
}

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

	id=1;
	fpr = fopen("file/Mobil.dat", "rb");
    fread(&dMobil.kd_mobil, sizeof(dMobil), 1, fpr);
	while(!feof(fpr))
    {
        fread(&dMobil.kd_mobil, sizeof(dMobil), 1, fpr);
        id++;

    }

        fp = fopen("file/Mobil.dat","ab");
        gotoxy(35, 14); printf("Kode Mobil  : MBL%d", id);
        gotoPrint("Merk Mobil  : ", 35, 15);
        fflush(stdin); takeInput(dMobil.merk_mobil);
        gotoPrint("Nama Mobil  : ", 35, 16);
        fflush(stdin); takeInput(dMobil.nama_mobil);
        gotoPrint("Harga Mobil : Rp ", 35, 17);
        fflush(stdin); getRp(&dMobil.harga_mobil, 1, 20, 52, 17);
        fflush(stdin); dMobil.kd_mobil = id;

        fwrite(&dMobil, sizeof(dMobil), 1 , fp);
        fclose(fp);

        BersihSemuaLayar();
        MobilMenu();
}

void ReadMobil()
{
	int i;
	char harga[50];
    DesainUtama();
    PrintFile("logo/tulisan-mobil.txt", 74, 3);
    gotoPrint("========================= Data Mobil =========================", 35, 12);

    fp = fopen("file/Mobil.dat", "rb");
    fread(&dMobil, sizeof(dMobil), 1, fp);

    fflush(stdin);
	gotoPrint("Kode", 35, 15);
	gotoPrint("Merk", 44, 15);
	gotoPrint("Nama", 60, 15);
	gotoPrint("Harga", 83, 15);
	gotoPrint("---------------------------------------------------------------", 35, 16);
	i= 17;
	while (!feof(fp))
	{
		fflush(stdin);
		gotoxy(35,i); printf("MBL%d",dMobil.kd_mobil);
		gotoxy(43,i); printf("%s",dMobil.merk_mobil);
		gotoxy(59,i); printf("%s",dMobil.nama_mobil);
		gotoxy(79,i); printf("Rp "); RP(dMobil.harga_mobil);
		fread(&dMobil, sizeof(dMobil), 1, fp);
		i++;
	}
	fclose(fp);
	pilihan();
	system("cls");
}

void UpdateMobil()
{
    DesainUtama();
    PrintFile("logo/tulisan-mobil.txt", 74, 3);
    gotoPrint("========================= Update Mobil =========================", 35, 12);

    FILE *TEMP;
    bool found;
    int a, kode;
    char nama[20];

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
	        gotoxy(35,17); printf("Kode  : MBL%d",dMobil.kd_mobil);
			gotoxy(35,18); printf("Merk  : %s",dMobil.merk_mobil);
			gotoxy(35,19); printf("Nama  : %s",dMobil.nama_mobil);
			gotoxy(35,20); printf("Harga : Rp "); RP(dMobil.harga_mobil);

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

    FILE *TEMP;
    bool found;
    int kode;

    fp = fopen("file/Mobil.dat", "rb");
    TEMP = fopen("file/MobilTemp.dat", "wb");

    gotoxy(35, 14); printf("Masukkan Kode Mobil Yang Ingin Dihapus : MBL");
    getnum(&kode, 4);
    found = false;

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
        fread(&dMobil, sizeof(dMobil), 1, fp);
        while(!feof(fp))
        {
            fwrite(&dMobil, sizeof(dMobil), 1, TEMP);
            fread(&dMobil, sizeof(dMobil), 1, fp);
        }
    }
    else
    {
        MessageBox(NULL, "DATA MOBIL TIDAK ADA", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        BersihSemuaLayar();
        MobilMenu();
    }
    fclose(TEMP);
    fclose(fp);

    remove("file/Mobil.dat");
    rename("file/MobilTemp.dat", "file/Mobil.dat");
    MessageBox(NULL, "DATA BERHASIL DIHAPUS", "SUCCESS", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    BersihSemuaLayar();
    MobilMenu();
}

/*void CreateUser()
{

}

void ReadUser()
{
    DataUser dUser;

    FILE *rUser;

    rUser = fopen("file/User.dat", "rb");
    fread(&dUser, sizeof(dUser), 1, rUser);
    while(!feof(rUser))
    {
        gotoxy(50, 23); printf("\nJabatan  : %s", dUser.jabatan);
        gotoxy(50, 23); printf("\nUsername : %s", dUser.username);
        gotoxy(50, 23); printf("\nPassword : %s", dUser.password);
        printf("\n");
        fread(&dUser, sizeof(dUser), 1, rUser);
    }
    fclose(rUser);
}

void UpdateUser()
{

}

void DeleteUser()
{

}*/
