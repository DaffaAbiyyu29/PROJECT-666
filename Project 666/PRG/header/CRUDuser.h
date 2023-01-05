void CreateUser()
{
    FILE *fpr;
    int id;
	DesainUtama();
	PrintFile("logo/tulisan-user.txt", 74, 3);

	gotoPrint("Pilihan : ", 7, 20);
	gotoPrint("1. Tambah User", 7, 22);
	gotoPrint("2. Edit User", 7, 23);
	gotoPrint("3. Hapus User", 7, 24);
	gotoPrint("4. Kembali", 7, 25);
	gotoPrint("5. Log Out", 7, 26);
	gotoPrint("[", 12, 27); gotoPrint("]", 14, 27);

	gotoPrint("========================= Masukkan Data User =========================", 35, 12);

	fpr = fopen("file/User.dat", "rb");
    fread(&dUser.id, sizeof(dUser), 1, fpr);
	while(!feof(fpr))
    {
        fread(&dUser.id, sizeof(dUser), 1, fpr);
        id = dUser.id;
    }
    fclose(fpr);
    dUser.id += 1;

    fp = fopen("file/User.dat","ab");
    gotoxy(35, 14); printf("ID User\t: USR%d", dUser.id);
    gotoPrint("Nama User\t: ", 35, 15);
    fflush(stdin); takeInput(dUser.nama);
    gotoPrint("Alamat User\t: ", 35, 16);
    fflush(stdin); takeInput(dUser.alamat);
    gotoPrint("Telp User\t: ", 35, 17);
    fflush(stdin); takeInput(dUser.telp);
    gotoPrint("Username\t: ", 35, 18);
    fflush(stdin); takeInput(dUser.username);
    gotoPrint("Password\t: ", 35, 19);
    fflush(stdin); takePassword(dUser.password);
    gotoPrint("Role\t\t: ", 35, 20);
    fflush(stdin); takeInput(dUser.role);
    //fflush(stdin); dUser.id = id;

    fwrite(&dUser, sizeof(dUser), 1 , fp);
    fclose(fp);

    BersihSemuaLayar();
    UserMenu();
}

void ReadUser()
{
    int i,l;
	char harga[50];
    DesainUtama();
    PrintFile("logo/tulisan-user.txt", 74, 3);
    gotoPrint("========================= Data User =========================", 35, 12);

    fp = fopen("file/User.dat", "rb");
    fread(&dUser, sizeof(dUser), 1, fp);

    fflush(stdin);
	gotoPrint("ID", 36, 15);
	gotoPrint("Nama", 49, 15);
	gotoPrint("Alamat", 72, 15);
	gotoPrint("Telp", 91, 15);
	gotoPrint("Role", 106, 15);
	//gotoPrint("---------------------------------------------------------------", 35, 16);
	//gotoPrint("_________________________________________________________________________________", 33, 16);

	gotoxy(33, 16); for (int brs = 33; brs <= 114; brs++){
        printf("_");
    }
	i= 17;
	while (!feof(fp))
	{
		fflush(stdin);
		gotoxy(35,i); printf("USR%d",dUser.id);
		gotoxy(44,i); printf("%s",dUser.nama);
		gotoxy(65,i); printf("%s",dUser.alamat);
		gotoxy(87,i); printf("%s",dUser.telp);
		gotoxy(103,i); printf("%s",dUser.role);
		fread(&dUser, sizeof(dUser), 1, fp);
		i++;
	}
	fclose(fp);
	for(l=15; l<i; l++)
    {
        gotoPrint("|", 33,l);
        gotoPrint("|", 42,l);
        gotoPrint("|", 63,l);
        gotoPrint("|", 85,l);
        gotoPrint("|", 101,l);
        gotoPrint("|", 114,l);
    }
}

void UpdateUser()
{
    DesainUtama();
    PrintFile("logo/tulisan-user.txt", 74, 3);
    gotoPrint("========================= Update User =========================", 35, 12);

    gotoPrint("Pilihan : ", 7, 20);
	gotoPrint("1. Tambah User", 7, 22);
	gotoPrint("2. Edit User", 7, 23);
	gotoPrint("3. Hapus User", 7, 24);
	gotoPrint("4. Kembali", 7, 25);
	gotoPrint("5. Log Out", 7, 26);
	gotoPrint("[", 12, 27); gotoPrint("]", 14, 27);

    FILE *TEMP;
    bool found;
    int kode;

    fp = fopen("file/User.dat", "rb");
    TEMP = fopen("file/UserTemp.dat", "wb");

    gotoxy(35, 14); printf("Masukkan Kode User Yang Ingin Diupdate : USR");
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
	        fread(&dUser, sizeof(dUser), 1, fp);
	        if(dUser.id == kode)
	        {
	            found = true;
	        }
	        else
	        {
	            fwrite(&dUser, sizeof(dUser), 1, TEMP);
	        }
	    }

	    if(found == true)
	    {
	        gotoxy(35,17); printf("ID User\t: USR%d",dUser.id);
			gotoxy(35,18); printf("Nama User\t: %s",dUser.nama);
			gotoxy(35,19); printf("Alamat User\t: %s",dUser.alamat);
			gotoxy(35,20); printf("Telp User\t: %s", dUser.telp);
			gotoxy(35,21); printf("Role User\t: %s", dUser.role);


			gotoxy(73,17); printf("Data yang ingin diupdate : ");
            gotoxy(73,18); printf("1. Biodata");
            gotoxy(73,19); printf("2. Akun");
            gotoxy(77,20); printf("["); gotoxy(79,20); printf("]");
            gotoxy(78,20); getnum(&pilih,1);

            if(pilih == 1)
            {
                gotoPrint("-----Masukkan Biodata User Tebaru-----", 110, 17);
                gotoPrint("Nama User\t: ", 110, 18); fflush(stdin); takeInput(&dUser.nama);
                gotoPrint("Alamat\t: ", 110, 19); fflush(stdin); takeInput(&dUser.alamat);
                gotoPrint("Telp User\t: ", 110, 20); fflush(stdin); takeInput(&dUser.telp);
            } else if(pilih == 2)
            {
                gotoPrint("-----Masukkan Data Akun Tebaru-----", 110, 17);
                gotoPrint("Username\t: ", 110, 18); fflush(stdin); takeInput(&dUser.username);
                gotoPrint("Password\t: ", 110, 19); fflush(stdin); takePassword(&dUser.password);
                gotoPrint("Role\t\t: ", 110, 20); fflush(stdin); takeInput(&dUser.role);

            }
	        fwrite(&dUser,sizeof(dUser),1,TEMP);
	        fread(&dUser,sizeof(dUser),1,fp);

	        while(!feof(fp))
	        {
	            fwrite(&dUser,sizeof(dUser),1,TEMP);
	            fread(&dUser,sizeof(dUser),1,fp);
	        }
	        fclose(fp);
	        fclose(TEMP);
	        remove("file/User.dat");
	        rename("file/UserTemp.dat", "file/User.dat");
	        MessageBox(NULL, "DATA BERHASIL DIUBAH", "SUCCESS", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
	        BersihSemuaLayar();
	        UserMenu();
	    }
	    else
        {
            MessageBox(NULL, "DATA USER TIDAK ADA", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            BersihSemuaLayar();
            UpdateUser();
        }
	}
}

void DeleteUser()
{
    DesainUtama();
    PrintFile("logo/tulisan-user.txt", 74, 3);
    gotoPrint("========================= Update User =========================", 35, 12);

    gotoPrint("Pilihan : ", 7, 20);
	gotoPrint("1. Tambah User", 7, 22);
	gotoPrint("2. Edit User", 7, 23);
	gotoPrint("3. Hapus User", 7, 24);
	gotoPrint("4. Kembali", 7, 25);
	gotoPrint("5. Log Out", 7, 26);
	gotoPrint("[", 12, 27); gotoPrint("]", 14, 27);

    FILE *TEMP;
    bool found;
    int kode;
    char yn;

    fp = fopen("file/User.dat", "rb");
    TEMP = fopen("file/UserTemp.dat", "wb");

    gotoxy(35, 14); printf("Masukkan Kode User Yang Ingin Dihapus : USR");
    getnum(&kode, 4);
    found = false;

    if(kode == 0)
    {
        BersihSemuaLayar();
    	UserMenu();
    } else if(kode != 0)
    {
        fread(&dUser, sizeof(dUser), 1, fp);
        while(!found && !feof(fp))
        {
            if(dUser.id == kode)
            {
                found = true;
            }
            else
            {
                fwrite(&dUser, sizeof(dUser), 1, TEMP);
                fread(&dUser, sizeof(dUser), 1, fp);
            }
        }

        if(found == true)
        {
            gotoxy(35,17); printf("ID User\t: USR%d",dUser.id);
			gotoxy(35,18); printf("Nama User\t: %s",dUser.nama);
			gotoxy(35,19); printf("Alamat User\t: %s",dUser.alamat);
			gotoxy(35,20); printf("Telp User\t: %s",dUser.telp);
			gotoxy(35,21); printf("Role User\t: %s",dUser.role);

			gotoxy(35, 23); printf("APAKAH YAKIN INGIN MENGHAPUS? : ");
            scanf("%c", &yn);

            if(yn == 'n' || yn == 'N')
            {
                BersihSemuaLayar();
                DeleteUser();
            } else if(yn == 'y' || yn == 'Y')
            {
                fread(&dUser, sizeof(dUser), 1, fp);
                while(!feof(fp))
                {
                    fwrite(&dUser, sizeof(dUser), 1, TEMP);
                    fread(&dUser, sizeof(dUser), 1, fp);
                }
                fclose(TEMP);
                fclose(fp);

                remove("file/User.dat");
                rename("file/UserTemp.dat", "file/User.dat");
                MessageBox(NULL, "DATA BERHASIL DIHAPUS", "SUCCESS", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                BersihSemuaLayar();
                UserMenu();
            }
        }
        else
        {
            MessageBox(NULL, "DATA USER TIDAK ADA", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            BersihSemuaLayar();
            UserMenu();
        }
    }
}
