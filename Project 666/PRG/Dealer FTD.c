//LIBRARY
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

//FILE HEADER
#include "header/login.h"
#include "header/design.h"
#include "header/menu.h"
#include "header/admin.h"
#include "header/CRUDmobil.h"
#include "header/CRUDuser.h"
#include "header/CRUDcustomer.h"
#include "header/manager.h"
#include "header/sales counter.h"
#include "header/leasing.h"
#include "header/transaksi.h"

main()
{
	fullscreen();
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	system("color 03");

	MainFrame();

    LoginForm();
    //AdminMenu();
    //KasirMenu();
    //ManagerMenu();
    BersihSemuaLayar();
    //DesainUtama();
}
