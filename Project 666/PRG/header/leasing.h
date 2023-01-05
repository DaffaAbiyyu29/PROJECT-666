#include "variable.h"

//SALES COUNTER
void LeasingMenu()
{
	DesainUtama();
	PrintFile("logo/kasir-logo.txt", 75, 3);
    PrintFile("logo/welcome-kasir.txt", 34, 13);


	gotoPrint("Pilihan : ", 7, 20);
	gotoPrint("1. Data Kredit", 7, 22);
	gotoPrint("2. Tambah Kredit", 7, 23);
	gotoPrint("3. Ubah Kredit", 7, 24);
	gotoPrint("4. Keluar", 7, 25);
	gotoPrint("[", 10, 26); gotoPrint("]", 12, 26);
    gotoxy(11, 26); getnum(&pilih,1);

    switch(pilih)
    {
        case 1 : BersihSemuaLayar(); TransaksiJualMobil(); break;
        case 2 : BersihSemuaLayar(); RestokMobil(); break;
        case 3 : BersihSemuaLayar(); /*UbahKredit();*/ break;
        case 4 : BersihSemuaLayar(); LoginForm(); break;
        default: BersihSemuaLayar(); LeasingMenu(); break;
    }
}
