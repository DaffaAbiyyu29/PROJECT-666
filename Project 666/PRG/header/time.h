/* ARSY Library
   =======================
   App		: ARSY BENGKEL
   Author	: Aryobimo & Syahrul
   =======================
    SISTEM INFORMASI 2020
*/

typedef enum {
	false = 0,
	true = 1
} bool;

typedef struct {
	int tgl, bulan, tahun;
} Date;

typedef struct {
	int tgl, bulan, tahun, hour, min, sec;
} DateTime;

bool found;
DateTime Now;
void SetColorBlock(unsigned short color);

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

//COLOR OPTION
void SetColor(int ForgC)
{
 	WORD wColor;

  	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  	CONSOLE_SCREEN_BUFFER_INFO csbi;
    //We use csbi for the wAttributes word.
 	if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
    	//Mask out all but the background attribute, and add in the forgournd color
      	wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      	SetConsoleTextAttribute(hStdOut, wColor);
 	}
}

void SetColorBlock(unsigned short color){
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}

void DateTimeNow(DateTime *TglOutput) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	TglOutput->tgl = tm.tm_mday;
	TglOutput->bulan = tm.tm_mon+1;
	TglOutput->tahun = tm.tm_year+1900;
	TglOutput->sec = tm.tm_sec;
	TglOutput->min = tm.tm_min;
	TglOutput->hour = tm.tm_hour;
}

void DateNow(Date *TglOutput) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	TglOutput->tgl = tm.tm_mday;
	TglOutput->bulan = tm.tm_mon+1;
	TglOutput->tahun = tm.tm_year+1900;
}

void formatID(char tipe[4], int id, char newID[]) {

	if(id < 10) {
		sprintf(newID, "%s00%d", tipe, id);
	} else if(id < 100) {
		sprintf(newID, "%s0%d", tipe, id);
	} else {
		sprintf(newID, "%s%d", tipe, id);
	}
}

bool dateValid(Date Tgl) {
	bool valid;
    //check year
    if(Tgl.tahun>=1900 && Tgl.tahun<=9999)
    {
        //check month
        if(Tgl.bulan>=1 && Tgl.bulan<=12)
        {
            //check days
            if((Tgl.tgl>=1 && Tgl.tgl<=31) && (Tgl.bulan==1 || Tgl.bulan==3 || Tgl.bulan==5 || Tgl.bulan==7 || Tgl.bulan==8 || Tgl.bulan==10 || Tgl.bulan==12))
                valid = true;
            else if((Tgl.tgl>=1 && Tgl.tgl<=30) && (Tgl.bulan==4 || Tgl.bulan==6 || Tgl.bulan==9 || Tgl.bulan==11))
                valid = true;
            else if((Tgl.tgl>=1 && Tgl.tgl<=28) && (Tgl.bulan==2))
                valid = true;
            else if(Tgl.tgl==29 && Tgl.bulan==2 && (Tgl.tahun%400==0 ||(Tgl.tahun%4==0 && Tgl.tahun%100!=0)))
                valid = true;
            else
                valid = false;
        }
        else
        {
            valid = false;
        }
    }
    else
    {
        valid = false;
    }

    return valid;
}

int countTable(char filechar[40]) {
	FILE *fileptr;
    int count_lines = 0;
    char chr;

    fileptr = fopen(filechar, "r");
   //extract character from file and store in chr
    chr = getc(fileptr);
    while (chr != EOF)
    {
        //Count whenever new line is encountered
        if (chr == 'n')
        {
            count_lines = count_lines + 1;
        }
        //take next character from file.
        chr = getc(fileptr);
    }
    fclose(fileptr); //close file.

    return count_lines;
}

void printPass(char text[]) {
	int i;

	for(i = 0; i < strlen(text); i++) {
		printf("*");
	}
}

/* Date Add */
bool isLeap(int y)
{
    if (y%100 != 0 && y%4 == 0 || y %400 == 0)
        return true;

    return false;
}

// Given a date, returns number of days elapsed
// from the  beginning of the current year (1st
// jan).
int offsetDays(int d, int m, int y)
{
    int offset = d;

    switch (m - 1)
    {
    case 11:
        offset += 30;
    case 10:
        offset += 31;
    case 9:
        offset += 30;
    case 8:
        offset += 31;
    case 7:
        offset += 31;
    case 6:
        offset += 30;
    case 5:
        offset += 31;
    case 4:
        offset += 30;
    case 3:
        offset += 31;
    case 2:
        offset += 28;
    case 1:
        offset += 31;
    }

    if (isLeap(y) && m > 2)
        offset += 1;

    return offset;
}

// Given a year and days elapsed in it, finds
// date by storing results in d and m.
void revoffsetDays(int offset, int y, int *d, int *m)
{
    int month[13] = { 0, 31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31 };

    if (isLeap(y))
        month[2] = 29;

    int i;
    for (i = 1; i <= 12; i++)
    {
        if (offset <= month[i])
            break;
        offset = offset - month[i];
    }

    *d = offset;
    *m = i;
}

// Add x days to the given date.
void addDays(Date TglInp, Date *TglOut, int x)
{
    int offset1 = offsetDays(TglInp.tgl, TglInp.bulan, TglInp.tahun);
    int remDays = isLeap(TglInp.tahun) ? (366-offset1) : (365-offset1);

    // y2 is going to store result year and
    // offset2 is going to store offset days
    // in result year.
    int y2, offset2;
    if (x <= remDays) {
        y2 = TglInp.tahun;
        offset2 = offset1 + x;
    } else {
        // x may store thousands of days.
        // We find correct year and offset
        // in the year.
        x -= remDays;
        y2 = TglInp.tahun + 1;
        int y2days = isLeap(y2)?366:365;
        while (x >= y2days)
        {
            x -= y2days;
            y2++;
            y2days = isLeap(y2)?366:365;
        }
        offset2 = x;
    }

    // Find values of day and month from
    // offset of result year.
    int m2, d2;
    revoffsetDays(offset2, y2, &d2, &m2);

  	/* Output Date */
  	TglOut->tgl = d2;
  	TglOut->bulan = m2;
  	TglOut->tahun = y2;
}
