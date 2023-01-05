#include "time.h"

int delay(int i)
{
     int j=0;
     while (j<i)
     {
           j++;
     }
     return(i);
}

void takeInput(char ch[50])
{
    fgets(ch, 50, stdin);
    ch[strlen(ch) - 1] = 0;
}

void takePassword(char pwds[50])
{
    int is;
    char chs;

    while(1)
    {
        chs = getch();
        if (chs == ENTER || chs == TAB)
        {
            pwds[is] = '\0';
            break;
        } else if (chs == BCKSPC)
        {
            if (is > 0)
            {
                is--;
                printf("\b \b");
            }
        } else
        {
            pwds[is++] = chs;
            printf("* \b");
        }
    }
}

void getallinput(char input[], int min, int max, int type)
{
	char inpkey;
	int i,n,x,m;
	n = 0;
	x=0;
	do
	{
		inpkey = getch(); // membaca masukan dari keyboard per-karakter //

//---- Menghapus Input ----//
//start//
		if(inpkey == '\b' && n != 0)
		{
			printf("\b \b");
			n--;
			input[n]='\0';
		}
//end//
		else if(isprint(inpkey)){ //karakter yang bisa di print
			if(n == max) {
				continue;
			}
			else{
				if(type == 3){ //isdigit = angka doang
					if(isdigit(inpkey)) {
						printf("%c", inpkey);
						input[n]=inpkey;
						n++;
					}
					else printf("\a"); //pemberitahuan suara tidak dapat di input (allert)
				}
				else if(type == 2){ //isalpha = alpabet dan spasi co : nama
					if(isalpha(inpkey) || inpkey == ' ') {
						printf("%c", inpkey);
						input[n]=inpkey;
						n++;
					}
					else printf("\a");
				}
				else { // inpkeyword //0= bebas
					if(type == 1)
							{
								if (inpkey=='\r')
								{
									inpkey='\0';
									break;
								}
							/*	if (inpkey[i]=='\b')
								{
								if(i!=0)printf("\b \b");
								inpkey[i]='\0';
								inpkey[i-1]='\0';
								i-=2;
								if(n<-1)n=-1;
								{
								continue;
								}*/
								input[n]=inpkey;
								printf("*");
								n++;
								}


					else
					{
						printf("%c", inpkey);
						input[n]=inpkey;
						n++;
					}
				}
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
		//else if(current == 27) end();
	}
	while(inpkey != 13);
}

void getinput(char input[], int max, int type)
{
	getallinput(input, 1, max, type);
}

void getnum(int *nilai, int max)
{
	char input[max];
	getinput(input, max, 3);
	*nilai = atoi(input);
}

void getRp(int *nilai, int min, int max, int x, int y)
{
	char input[255];
	char inpkey;
	int i,n,m;
	n = 0;
	do
	{
		inpkey = getch(); // membaca masukan dari keyboard per-karakter //

		if(inpkey == '\b' && n != 0) /* Hapus karakter */
		{
			n--;
			input[n]='\0';

			m = n % 3;
			if((n-m) % 3 == 0 || n == m) {
				printf("\b \b");
				printf("\b \b");
			} else {
				printf("\b \b");
			}

			gotoxy(x, y);		/* Cetak ulang sesuai format */
			for(i = 0; i < n; i++) {
				if((i+1) == m || (i+1-m) % 3 == 0) {
					printf("%c", input[i]);
					if(i != (n-1)) {
						printf(".");
					}
				} else {
					printf("%c", input[i]);
				}
			}
		} else if(isprint(inpkey)){  /* Karakter yang bisa di print */
			if(n == max) {
				continue;
			} else {
				if(isdigit(inpkey)) { /* Print angka */
					gotoxy(x, y);
					input[n]=inpkey;
					n++;
					m = n % 3;
					for(i = 0; i < n; i++) { /* Cetak ulang sesuai format */
						if((i+1) == m || (i+1-m) % 3 == 0) {
							printf("%c", input[i]);
							if(i != (n-1)) {
								printf(".");
							}
						} else {
							printf("%c", input[i]);
						}
					}

				}
				else printf("\a"); /* Pemberitahuan suara tidak dapat di input (alert) */
			}
		}
		else if(inpkey == 13)	/* Jika menekan enter sebelum mengisi karakter akan muncul suara tidak dapat diinput (alert) */
		{
			if(n < min) {
				printf("\a");
				inpkey = 0;
			}
			else input[n]='\0';
		}
	}
	while(inpkey != 13);

	*nilai = atoi(input);   /* Memasukkan nilai input (char) ke nilai (int) */
}

void RP(int n)
{
	if (n < 0)
	{
		printf ("-");
		RP (-n);
		return;
	}
	if (n < 1000)
	{
		printf ("%d", n);
		return;
	}
	RP (n/1000);
	printf (".%03d", n%1000);
}

void rupiah(int number, char output[])
{
	// menampilkan Bentuk Rupiah
	if(number < 1000) sprintf(output, "%d", number);
    else if(number < 1000000) sprintf(output, "%d.%03d", number/1000, number%1000);
    else if(number < 1000000000) sprintf(output, "%d.%03d.%03d", number/1000000, (number%1000000)/1000, number%1000);
    else sprintf(output, "%d.%03d.%03d.%03d", number/1000000000, (number%1000000000)/1000, (number%1000000)/1000, number%1000);
}

void Hline( int min, int max,int y, int a)
{
	int i;
	for(i=min;i<=max;i++)
	{
		gotoxy(i,y);printf("%c",a);
	}
}

void Vline( int min, int max,int y, int a)
{
	int i;
	for(i=min;i<=max;i++)
	{
		gotoxy(y,i);printf("%c",a);
	}
}
