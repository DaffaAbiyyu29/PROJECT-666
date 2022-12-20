#include "variable.h"
#define Nmaks 100

void fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

void Border()
{
	//DECLARATION
	int i,j;

	//ALGORITM
	gotoxy(0,0); printf("\xc9");			//sudut siku-siku kiri atas
	for(i=1; i<=172; i++)
	{
		gotoxy(i,0); printf("\xcd");		//garis horizontal
	}
	gotoxy(i,0); printf("\xbb");			//sudut siku-siku kanan atas

	for(j=1; j<=48; j++)
	{
		gotoxy(173,j); printf("\xba");		//garis vertikal
	}

	for(j=1; j<=48; j++)
	{
		gotoxy(0,j); printf("\xba");		//garis vertikal
	}
	gotoxy(0,j); printf("\xc8");			//sudut siku-siku kanan bawah

	for(i=1; i<=172; i++)
	{
		gotoxy(i,j); printf("\xcd");		//garis horizontal
	}
	gotoxy(i,j); printf("\xbc");			//sudut siku-siku kiri bawah

}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void gotoPrint(char text[255], int x, int y) {
	gotoxy(x, y);
	printf(text);
}

void PrintFile (char filename[255], int x, int y)
{
    FILE *fp;
    char str[MAXCHAR];
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s", filename);
    }
    i = 0;
    while (fgets(str, MAXCHAR, fp) != NULL) {
    	gotoxy(x, y + i);
        printf("%s", str);
        i++;
	}
    fclose(fp);
}

void textBox1(int x, int y, int width, int height)
{
	int i, j;

	/* first Line */
	gotoxy(x, y);
	printf("%c", 218);
	for(i = 1; i <= width; i++) {
		printf("%c", 196);
	}
	printf("%c", 191);

	/* looping for height */
	for(i = 1; i <= height; i++) {
		gotoxy(x, y + i);
		printf("%c", 179);

		gotoxy(x + width + 1, y + i);
		printf("%c", 179);
	}

	/* last line */
	printf("\n");
	gotoxy(x, y + height);
	printf("%c", 192);
	for(i = 1; i <= width; i++) {
		printf("%c", 196);
	}
	printf("%c", 217);
}

void loading(int x, int y)
{
	int i;

	gotoxy(x + 12, y-1);
	printf("LOADING");
	textBox1(x, y, 30, 2);
	for(i = 1; i <= 30; i++) {
		gotoxy(x + i, y + 1);
		printf("%c", 177);
		Sleep(50);
		if(i == 8 || i == 28) {
			Sleep(200);
		} else if(i == 20) {
			Sleep(400);
		}

	}
}

void BersihSemuaLayar ()
{
	//DECLARATION
	int i;
	int j;

	//ALGORITM
	for (i=0; i<= 175; i++)
	{
		for(j=0; j <= 50; j++)
		{
			gotoxy(i,j); printf(" ");
		}
	}
}

void copyright()
{
    PrintFile("logo/copyright.txt", 4, 39);
}

void MainFrame()
{
	 /* DECLARATION : */
    int i, j;
    
	 /* ALGORITHM : */
    system("color 03");
    //garis kiri, kanan, tengah
    for(i=0;i<=45;i++)
    {
        gotoxy(1,i),printf("%c%c",219,219);//kiri
        gotoxy(169,i),printf("%c%c",219,219);//kanan
        delay(100000);
        delay(100000);
    }

    for(i=1;i<=169;i++)
	{
    gotoxy(i,0),	printf("%c%c",219,219); //atas
    gotoxy(i,10),	printf("%c",219); //tengah
    gotoxy(i,45),	printf("%c",219); //bawah
	}



		//DrawFile(103, 23, "text/tahun.txt");
}

void DesainUtama()
{
	int i;

	time_t t = time(NULL);
	struct tm tm = * localtime(&t);
	gotoxy(11, 12); printf("%d/%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	
	PrintFile("logo/DFTD.txt", 8, 5);

	//garis kiri, kanan, tengah
	for(i=0;i<=45;i++)
	{
		gotoxy(1,i),printf("%c%c",219,219);//kiri
		gotoxy(169,i),printf("%c%c",219,219);//kanan
		gotoxy(29,i),printf("%c%c",219,219);//tengah
	}

	//kotak pinggir pilihan menu
	for(i=18;i<=32;i++)
	{
		gotoxy(5,i),	printf("%c",219);//sebelah atas
		gotoxy(26,i),	printf("%c",219);//sebelah bawah
	}
	for(i=5;i<=26;i++)
	{
		gotoxy(i,18),	printf("%c",219);//sebelah kiri
		gotoxy(i,32),	printf("%c",219);//sebelah kanan
	}
	//garis atas, bawah, tengah
	for(i=1;i<=169;i++)
	{
		gotoxy(i,0),	printf("%c%c",219,219); //atas
		gotoxy(i,10),	printf("%c",219); //tengah
		gotoxy(i,45),	printf("%c",219); //bawah
	}
}

/*void MenuUtama()
{
    Border();
    copyright();

    PrintFile("logo/logo-dealer.txt", 37, 10);

    gotoPrint("Pilih Tindakan :", 76, 30);
	gotoPrint("1. Daftar", 76, 31);
	gotoPrint("2. Masuk", 76, 32);
	gotoPrint("0. Keluar", 76, 33);
	gotoPrint("[", 79, 34); gotoPrint("]", 81, 34);
	gotoxy(80, 34); scanf("%d", &pilih);

	switch(pilih)
	{
		case 1 : BersihSemuaLayar(); SignupForm(); break;
		case 2 : BersihSemuaLayar(); LoginForm(); break;
		case 0 : MessageBox(NULL, "Terimakasih sudah menggunakan aplikasi ini"," ATTENTION ", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY); exit(0); break;
		default : MessageBox(NULL, "ANGKA TIDAK VALID", "WARNING", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
	}

}*/
