#include "variable.h"

FILE *fp;
Mobil dMobil;
User dUser;
Customer cust;

void AdminMenu()
{
	DesainUtama();
	PrintFile("logo/admin-logo.txt", 72, 3);
	PrintFile("logo/welcome-admin.txt", 34, 13);

	gotoPrint("Pilihan : ", 7, 20);
	gotoPrint("1. User", 7, 22);
	gotoPrint("2. Mobil", 7, 23);
	gotoPrint("3. Customer", 7, 24);
	gotoPrint("4. ......", 7, 25);
	gotoPrint("5. Keluar", 7, 26);
	gotoPrint("[", 10, 27); gotoPrint("]", 12, 27);
    gotoxy(11, 27); getnum(&pilih,1);

    switch(pilih)
    {
        case 1 : BersihSemuaLayar(); UserMenu(); break;
        case 2 : BersihSemuaLayar(); MobilMenu(); break;
        case 3 : BersihSemuaLayar(); CustomerMenu(); break;
        case 4 : BersihSemuaLayar(); /*DeleteUser();*/ break;
        case 5 : BersihSemuaLayar(); LoginForm(); /*MenuUtama();*/ break;
        default: BersihSemuaLayar(); AdminMenu(); break;
    }
}

void MobilMenu()
{
	DesainUtama();

	ReadMobil();
	pilihanmobil();
}

void pilihanmobil()
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
        default: BersihSemuaLayar(); MobilMenu(); break;
    }
}

void UserMenu()
{
	DesainUtama();

	ReadUser();
	pilihanuser();
}

void pilihanuser()
{
	gotoPrint("Pilihan : ", 7, 20);
	gotoPrint("1. Tambah User", 7, 22);
	gotoPrint("2. Edit User", 7, 23);
	gotoPrint("3. Hapus User", 7, 24);
	gotoPrint("4. Kembali", 7, 25);
	gotoPrint("5. Log Out", 7, 26);
	gotoPrint("[", 12, 27); gotoPrint("]", 14, 27);
    gotoxy(13, 27); getnum(&pilih,1);

    switch(pilih)
    {
        case 1 : BersihSemuaLayar(); CreateUser(); break;
        case 2 : BersihSemuaLayar(); UpdateUser(); break;
        case 3 : BersihSemuaLayar(); DeleteUser(); break;
        case 4 : BersihSemuaLayar(); AdminMenu(); break;
        case 5 : BersihSemuaLayar(); LoginForm(); break;
        default: BersihSemuaLayar(); UserMenu(); break;
    }
}

void CustomerMenu()
{
    DesainUtama();

	ReadCustomer();
	pilihancustomer();
}

void pilihancustomer()
{
	gotoPrint("Pilihan : ", 7, 20);
	gotoPrint("1. Tambah Customer", 7, 22);
	gotoPrint("2. Edit Customer", 7, 23);
	gotoPrint("3. Hapus Customer", 7, 24);
	gotoPrint("4. Kembali", 7, 25);
	gotoPrint("5. Log Out", 7, 26);
	gotoPrint("[", 12, 27); gotoPrint("]", 14, 27);
    gotoxy(13, 27); getnum(&pilih,1);

    switch(pilih)
    {
        case 1 : BersihSemuaLayar(); CreateCustomer(); break;
        case 2 : BersihSemuaLayar(); UpdateCustomer(); break;
        case 3 : BersihSemuaLayar(); /*DeleteCustomer();*/ break;
        case 4 : BersihSemuaLayar(); AdminMenu(); break;
        case 5 : BersihSemuaLayar(); LoginForm(); break;
        default: BersihSemuaLayar(); CustomerMenu(); break;
    }
}
