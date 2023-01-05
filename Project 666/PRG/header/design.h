#include "variable.h"
#define Nmaks 100

void fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
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
		for(j=0; j <= 43; j++)
		{
			gotoxy(i,j); printf(" ");
		}
	}
}

void copyright()
{
    PrintFile("logo/copyright.txt", 4, 37);
}

void MainFrame()
{
	 /* DECLARATION : */
    int i, j;

	 /* ALGORITHM : */
    system("color 03");
    //garis kiri, kanan, tengah
    for(i=0;i<=43;i++)
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
    gotoxy(i,43),	printf("%c",219); //bawah
	}
}

void DesainUtama()
{
	int i;

	time_t t = time(NULL);
	struct tm tm = * localtime(&t);
	gotoxy(11, 12); printf("%d/%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

	PrintFile("logo/DFTD.txt", 8, 5);

	//garis kiri, kanan, tengah
	for(i=0;i<=43;i++)
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
		gotoxy(i,43),	printf("%c",219); //bawah
	}
}

void underline(char text[255], int x, int y) {
	int i;

	gotoxy(x, y);
	printf("%s", text);
	for(i = 0; i < strlen(text); i++) {
		gotoxy(x+i, y+1);
		printf("%c", 196);
	}
}

void textbox(int last, int a, int b,int c, int d){
	int i;
	for(i=0;i<last;i++)
	{
	Vline(a,b,c,186);
	Vline(a,b,d,186);
	Hline(c,d,a,205);
	Hline(c,d,b,205);
	gotoxy(c,a);printf("%c",201);
	gotoxy(d,a);printf("%c",187);
	gotoxy(c,b);printf("%c",200);
	gotoxy(d,b);printf("%c",188);
	a+=3;
	b+=3;
	}
}

/*void textBox2(int x, int y, int width, int height) {
	int i, j;

	//first Line
	gotoxy(x, y);
	printf("%c", 201);
	for(i = 1; i <= width; i++) {
		printf("%c", 205);
	}
	printf("%c", 187);

	//looping for height
	for(i = 1; i <= height; i++) {
		gotoxy(x, y + i);
		printf("%c", 186);
		for(j = 1; j <= width; j++) {
			printf(" ");
		}
		gotoxy(x + width + 1, y + i);
		printf("%c", 186);
	}

	//last line
	printf("\n");
	gotoxy(x, y + height);
	printf("%c", 200);
	for(i = 1; i <= width; i++) {
		printf("%c", 205);
	}
	printf("%c", 188);
}*/

void BoxBlock(int x, int y, int width, int height, int color) {
	int i, j;

	/* first Line */
	SetColorBlock(color);
	for(i = 0; i <= height; i++) {
		for(j = 0; j < width; j++) {
			gotoxy(x + j, y + i);
			printf("%c", 219);
		}
	}
}

void chooseBox(int x, int y, int width, int height) { //[]
	int i, j;

	/* first Line */
	gotoxy(x, y);
	printf("%c", 201);
	for(i = 1; i <= width; i++) {
		printf("%c", 205);
	}
	printf("%c", 187);

	/* last line */
	printf("\n");
	gotoxy(x, y + height);
	printf("%c", 200);
	for(i = 1; i <= width; i++) {
		printf("%c", 205);
	}
	printf("%c", 188);
}

void textAreaInput(char input[], int min, int max, int x, int y, int maxOneLine)
{
	char inpkey;
	int i,n,m, oneline;
	oneline = maxOneLine;
	n = 0;
	do
	{
		inpkey = getch();  // membaca masukan dari keyboard per-karakter //

//---- Menghapus Input ----//
		if(inpkey == '\b' && n != 0)
		{
			if(n == oneline-maxOneLine) {
				oneline -= maxOneLine;
				y--;
				gotoxy(x+maxOneLine, y);
			}
			printf("\b \b");
			input[n]='\0';
			n--;
		} else if(isprint(inpkey)){ //karakter yang bisa di print
			if(n == max) {
				continue;
			}
			else {
				if(n == oneline) {
					oneline += maxOneLine;
					y++;
					gotoxy(x, y);
				}
				printf("%c", inpkey);
				input[n]=inpkey;
				n++;
			}
		}
		else if(inpkey == 13)
		{
			if(n < min) {
				printf("\a");
				inpkey = 0;
			}
			else input[n]='\0';
		}
	}
	while(inpkey != 13);
}
