#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>


#include "header/login.h"
#include "header/design.h"
#include "header/menu.h"
#include "header/admin.h"
#include "header/manager.h"
#include "header/kasir.h"

main()
{
	fullscreen();
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	system("color 03");

	MainFrame();
	/*PrintFile("logo/logo-dealer.txt", 36, 3);
    PrintFile("logo/mobil.txt", 47, 17);
    loading(69, 33);
	gotoxy(72, 37);printf("Tekan apapun untuk mulai!");
	getch();
    BersihSemuaLayar();*/

    LoginForm();
    //AdminMenu();
    //MainFrame();
    BersihSemuaLayar();
    //DesainUtama();MainMenu
}
