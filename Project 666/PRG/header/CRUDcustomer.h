void CreateCustomer()
{
    FILE *fpr;
    int id;
	DesainUtama();
	PrintFile("logo/tulisan-customer.txt", 74, 3);

	gotoPrint("Pilihan : ", 7, 20);
	gotoPrint("1. Tambah Customer", 7, 22);
	gotoPrint("2. Edit Customer", 7, 23);
	gotoPrint("3. Hapus Customer", 7, 24);
	gotoPrint("4. Kembali", 7, 25);
	gotoPrint("5. Log Out", 7, 26);
	gotoPrint("[", 12, 27); gotoPrint("]", 14, 27);

	gotoPrint("========================= Masukkan Data Customer =========================", 35, 12);

	fpr = fopen("file/Customer.dat", "rb");
    fread(&cust.id_cus, sizeof(cust), 1, fpr);
	while(!feof(fpr))
    {
        fread(&cust.id_cus, sizeof(cust), 1, fpr);
        id = cust.id_cus;
    }
    fclose(fpr);
    cust.id_cus += 1;

    fp = fopen("file/Customer.dat","ab");
    gotoxy(35, 14); printf("ID Customer     : USR%d", cust.id_cus);
    gotoPrint("NIK Customer    : ", 35, 15);
    fflush(stdin); takeInput(cust.nik);
    gotoPrint("Nama Customer   : ", 35, 16);
    fflush(stdin); takeInput(cust.nama_cus);
    gotoPrint("Tempat Lahir    : ", 35, 17);
    fflush(stdin); takeInput(cust.tmpt_lahir);

    gotoPrint("Tanggal Lahir   :   /  /", 35, 18);
    InputTgl:
	DateTimeNow(&Now);
	gotoxy(53, 18); fflush(stdin); getnum(&cust.tgl_lahir.tgl, 2);
	gotoxy(53, 18);	printf("%02d", cust.tgl_lahir.tgl);
	if (cust.tgl_lahir.tgl == 0) {
		CreateCustomer();
	}
	gotoxy(56, 18); fflush(stdin); getnum(&cust.tgl_lahir.bulan, 2);
	gotoxy(56, 18);	printf("%02d", cust.tgl_lahir.bulan);
	gotoxy(59, 18); fflush(stdin); getnum(&cust.tgl_lahir.tahun, 4);
	gotoxy(59, 18);	printf("%04d", cust.tgl_lahir.tahun);

    gotoPrint("Alamat Customer : ", 35, 19);
    fflush(stdin); takeInput(cust.alamat);
    gotoPrint("Telp Customner  : ", 35, 20);
    fflush(stdin); takeInput(cust.telp);
    gotoPrint("Email Customner : ", 35, 21);
    fflush(stdin); takeInput(cust.email);

    fwrite(&cust, sizeof(cust), 1 , fp);
    fclose(fp);

    BersihSemuaLayar();
    CustomerMenu();
}

void ReadCustomer()
{
    int i,l;
	char harga[50];
    DesainUtama();
    PrintFile("logo/tulisan-customer.txt", 74, 3);
    gotoPrint("========================= Data Customer =========================", 35, 12);

    fp = fopen("file/Customer.dat", "rb");
    fread(&cust, sizeof(cust), 1, fp);

    fflush(stdin);
	gotoPrint("ID", 37, 15);
	gotoPrint("Nama", 51, 15);
	gotoPrint("Tpt Lhr", 68, 15);
	gotoPrint("Tgl Lhr", 85, 15);
	gotoPrint("Alamat", 100, 15);
	gotoPrint("Telp", 119, 15);
	gotoPrint("Email", 140, 15);
	//gotoPrint("---------------------------------------------------------------", 35, 16);
	//gotoPrint("_________________________________________________________________________________", 33, 16);

	gotoxy(33, 16); for (int brs = 33; brs <= 160; brs++){
        printf("_");
    }

	i= 17;
	while (!feof(fp))
	{
		fflush(stdin);
		gotoxy(35,i); printf("USR%d",cust.id_cus);
		gotoxy(44,i); printf("%s",cust.nama_cus);
		gotoxy(65,i); printf("%s",cust.tmpt_lahir);
		gotoxy(83,i); printf("%d/%d/%d",cust.tgl_lahir.tgl, cust.tgl_lahir.bulan, cust.tgl_lahir.tahun);
		gotoxy(96,i); printf("%s",cust.alamat);
		gotoxy(115,i); printf("%s",cust.telp);
		gotoxy(130,i); printf("%s",cust.email);
		fread(&cust, sizeof(cust), 1, fp);
		i++;
	}
	fclose(fp);
	for(l=15; l<i; l++)
    {
        gotoPrint("|", 33,l);
        gotoPrint("|", 42,l);
        gotoPrint("|", 63,l);
        gotoPrint("|", 81,l);
        gotoPrint("|", 94,l);
        gotoPrint("|", 113,l);
        gotoPrint("|", 128,l);
        gotoPrint("|", 160,l);
    }
}

void UpdateCustomer()
{
    DesainUtama();
    PrintFile("logo/tulisan-customer.txt", 74, 3);
    gotoPrint("========================= Update Customer =========================", 35, 12);

    gotoPrint("Pilihan : ", 7, 20);
	gotoPrint("1. Tambah Customer", 7, 22);
	gotoPrint("2. Edit Customer", 7, 23);
	gotoPrint("3. Hapus Customer", 7, 24);
	gotoPrint("4. Kembali", 7, 25);
	gotoPrint("5. Log Out", 7, 26);
	gotoPrint("[", 12, 27); gotoPrint("]", 14, 27);

    FILE *TEMP;
    bool found;
    int kode;

    fp = fopen("file/Customer.dat", "rb");
    TEMP = fopen("file/CustomerTemp.dat", "wb");

    gotoxy(35, 14); printf("Masukkan Kode Customer Yang Ingin Diupdate : USR");
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
	        fread(&cust, sizeof(cust), 1, fp);
	        if(cust.id_cus == kode)
	        {
	            found = true;
	        }
	        else
	        {
	            fwrite(&cust, sizeof(cust), 1, TEMP);
	        }
	    }

	    if(found == true)
	    {
	        gotoxy(35,17); printf("ID             : USR%d",cust.id_cus);
			gotoxy(35,18); printf("NIK            : %s",cust.nik);
			gotoxy(35,19); printf("Nama           : %s",cust.nama_cus);
			gotoxy(35,20); printf("Tempat Lahir   : %s",cust.tmpt_lahir);
			gotoxy(35,21); printf("Tanggal Lahir  : %d/%d/%d",cust.tgl_lahir.tgl, cust.tgl_lahir.bulan, cust.tgl_lahir.tahun);
			gotoxy(35,22); printf("Alamat         : %s",cust.alamat);
			gotoxy(35,23); printf("Telp           : %s", cust.telp);
			gotoxy(35,24); printf("Email          : %s", cust.email);

			gotoPrint("-----Masukkan Biodata Customer Tebaru-----", 110, 17);
            gotoPrint("Nama           : ", 110, 18); fflush(stdin); takeInput(&cust.nama_cus);
            gotoPrint("Tempat Lahir   : ", 110, 19); fflush(stdin); takeInput(&cust.tmpt_lahir);
            gotoPrint("Tanggal Lahir  : ", 110, 20);
            InputTgl:
            DateTimeNow(&Now);
            gotoxy(128, 20); fflush(stdin); getnum(&cust.tgl_lahir.tgl, 2);
            gotoxy(128, 20);	printf("%02d", cust.tgl_lahir.tgl);
            if (cust.tgl_lahir.tgl == 0) {
                CreateCustomer();
            }
            gotoxy(131, 20); fflush(stdin); getnum(&cust.tgl_lahir.bulan, 2);
            gotoxy(131, 20);	printf("%02d", cust.tgl_lahir.bulan);
            gotoxy(134, 20); fflush(stdin); getnum(&cust.tgl_lahir.tahun, 4);
            gotoxy(134, 20);	printf("%04d", cust.tgl_lahir.tahun);

            gotoPrint("Alamat         : ", 110, 21); fflush(stdin); takeInput(&cust.alamat);
            gotoPrint("Telp           : ", 110, 22); fflush(stdin); takeInput(&cust.telp);
            gotoPrint("Email          : ", 110, 23); fflush(stdin); takeInput(&cust.email);

	        fwrite(&cust,sizeof(cust),1,TEMP);
	        fread(&cust,sizeof(cust),1,fp);

	        while(!feof(fp))
	        {
	            fwrite(&cust,sizeof(cust),1,TEMP);
	            fread(&cust,sizeof(cust),1,fp);
	        }
	        fclose(fp);
	        fclose(TEMP);
	        remove("file/Customer.dat");
	        rename("file/CustomerTemp.dat", "file/Customer.dat");
	        MessageBox(NULL, "DATA BERHASIL DIUBAH", "SUCCESS", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
	        BersihSemuaLayar();
	        CustomerMenu();
	    }
	    else
        {
            MessageBox(NULL, "DATA Customer TIDAK ADA", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            BersihSemuaLayar();
            UpdateCustomer();
        }
	}
}

/*void DeleteCustomer()
{
    DesainUtama();
    PrintFile("logo/tulisan-Customer.txt", 74, 3);
    gotoPrint("========================= Update Customer =========================", 35, 12);

    gotoPrint("Pilihan : ", 7, 20);
	gotoPrint("1. Tambah Customer", 7, 22);
	gotoPrint("2. Edit Customer", 7, 23);
	gotoPrint("3. Hapus Customer", 7, 24);
	gotoPrint("4. Kembali", 7, 25);
	gotoPrint("5. Log Out", 7, 26);
	gotoPrint("[", 12, 27); gotoPrint("]", 14, 27);

    FILE *TEMP;
    bool found;
    int kode;
    char yn;

    fp = fopen("file/Customer.dat", "rb");
    TEMP = fopen("file/CustomerTemp.dat", "wb");

    gotoxy(35, 14); printf("Masukkan Kode Customer Yang Ingin Dihapus : USR");
    getnum(&kode, 4);
    found = false;

    if(kode == 0)
    {
        BersihSemuaLayar();
    	CustomerMenu();
    } else if(kode != 0)
    {
        fread(&cust, sizeof(cust), 1, fp);
        while(!found && !feof(fp))
        {
            if(cust.id == kode)
            {
                found = true;
            }
            else
            {
                fwrite(&cust, sizeof(cust), 1, TEMP);
                fread(&cust, sizeof(cust), 1, fp);
            }
        }

        if(found == true)
        {
            gotoxy(35,17); printf("ID Customer\t: USR%d",cust.id);
			gotoxy(35,18); printf("Nama Customer\t: %s",cust.nama);
			gotoxy(35,19); printf("Alamat Customer\t: %s",cust.alamat);
			gotoxy(35,20); printf("Telp Customer\t: %s",cust.telp);
			gotoxy(35,21); printf("Role Customer\t: %s",cust.role);

			gotoxy(35, 23); printf("APAKAH YAKIN INGIN MENGHAPUS? : ");
            scanf("%c", &yn);

            if(yn == 'n' || yn == 'N')
            {
                BersihSemuaLayar();
                DeleteCustomer();
            } else if(yn == 'y' || yn == 'Y')
            {
                fread(&cust, sizeof(cust), 1, fp);
                while(!feof(fp))
                {
                    fwrite(&cust, sizeof(cust), 1, TEMP);
                    fread(&cust, sizeof(cust), 1, fp);
                }
                fclose(TEMP);
                fclose(fp);

                remove("file/Customer.dat");
                rename("file/CustomerTemp.dat", "file/Customer.dat");
                MessageBox(NULL, "DATA BERHASIL DIHAPUS", "SUCCESS", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                BersihSemuaLayar();
                CustomerMenu();
            }
        }
        else
        {
            MessageBox(NULL, "DATA Customer TIDAK ADA", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            BersihSemuaLayar();
            CustomerMenu();
        }
    }
}*/
