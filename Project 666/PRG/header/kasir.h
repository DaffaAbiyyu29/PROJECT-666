#include "variable.h"

void KasirMenu()
{
	MainFrame();
	copyright();
	PrintFile("logo/accountant-logo.txt", 32, 3);

	gotoPrint("Pilihan : ", 76, 23);
	gotoPrint("1. ....", 76, 24);
	gotoPrint("2. ....", 76, 25);
	gotoPrint("3. ....", 76, 26);
	gotoPrint("0. Keluar", 76, 27);
	gotoPrint("[", 78, 28); gotoPrint("]", 80, 28);
    gotoxy(79, 28); scanf("%d", &pilih);

    if(pilih==0)
    {
        BersihSemuaLayar();
        LoginForm();
    } else if(pilih==0)
    {
        LoginForm();
    }
}
