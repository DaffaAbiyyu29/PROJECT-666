#include "variable.h"

//SALES COUNTER
void SCMenu()
{
	DesainUtama();
	PrintFile("logo/kasir-logo.txt", 75, 3);
    PrintFile("logo/welcome-kasir.txt", 34, 13);


	gotoPrint("Pilihan : ", 7, 20);
	gotoPrint("1. Jual Mobil", 7, 22);
	gotoPrint("2. Restok Mobil", 7, 23);
	gotoPrint("3. Keluar", 7, 24);
	gotoPrint("[", 10, 25); gotoPrint("]", 12, 25);
    gotoxy(11, 25); getnum(&pilih,1);

    switch(pilih)
    {
        case 1 : BersihSemuaLayar(); TransaksiJualMobil(); break;
        case 2 : BersihSemuaLayar(); RestokMobil(); break;
        case 3 : BersihSemuaLayar(); LoginForm(); break;
        default: BersihSemuaLayar(); SCMenu(); break;
    }
}
