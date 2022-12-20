//#include "variable.h"

#define ENTER 13
#define TAB 9
#define BCKSPC 8

/*static int i=0;
DataUser dUser;
char jbt1[20] = "Admin";
char jbt2[20] = "Manager";
char jbt3[20] = "Kasir";

FILE *fp;*/

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

void LoginForm()
{
    char username[30], password[30];
    int status =0, salah = 0;

	while (status < 3){
        MainFrame();
        copyright();
        PrintFile("logo/logo-dealer.txt", 36, 3);

        gotoxy(70,40); printf("Klik 0 Untuk Keluar..."); fflush(stdin);
        gotoxy(70,23); printf("***** Menu Login *****");fflush(stdin);
        gotoxy(70,24); printf("______________________");fflush(stdin);
        gotoxy(70,26); printf("Username: ");fflush(stdin);
        takeInput(username);

	    if (strcmp(username, "0") == 0)
	    {
	        MessageBox(NULL, "THANK YOU", "NOTIFY", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
	        exit(0);
	    }

	    gotoxy(70,27); printf("Password: ");
	    fflush(stdin);
	    takePassword(password);

	    if (strcmp(password, "0") == 0)
	    {
	        MessageBox(NULL, "THANK YOU", "NOTIFY", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
	        exit(0);
	    }

	    if ((strcmp(username, "admin") == 0) && (strcmp(password, "admin") == 0))
	    {
	        MessageBox(NULL, "LOGIN SUCCESSFULY", "SUCCESS", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
	        BersihSemuaLayar();
	        AdminMenu();
	    } else if ((strcmp(username, "manager") == 0) && (strcmp(password, "manager") == 0))
	    {
	        MessageBox(NULL, "LOGIN SUCCESSFULY", "SUCCESS", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
	        BersihSemuaLayar();
	        ManagerMenu();
	    } else if ((strcmp(username, "kasir") == 0) && (strcmp(password, "kasir") == 0))
	    {
	        MessageBox(NULL, "LOGIN SUCCESSFULY", "SUCCESS", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
	        BersihSemuaLayar();
	        KasirMenu();
	    } else {
	        Beep(800,300);
	        MessageBox(NULL, "USERNAME ATAU PASSWORD SALAH", "WARNING", MB_OK | MB_ICONWARNING | MB_DEFAULT_DESKTOP_ONLY);
	        BersihSemuaLayar();
	        salah++;
         	if(salah == 3){
           		MessageBox(NULL, "AKSES DITOLAK", "WARNING", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
           	}

	        system("cls");
        }
		status++;
	}
	system("pause");
}

/*void SignupForm()
{
    system("cls");
    Border();
    copyright();

    PrintFile("logo/logo-dealer.txt", 38, 3);

	FILE *FSignup;

    FSignup = fopen("file/User.dat", "ab");
    gotoPrint("Jabatan  : ", 76, 23);
    fflush(stdin); takeInput(dUser.jabatan);
    gotoPrint("Username : ", 76, 24);
    fflush(stdin); takeInput(dUser.username);
    gotoPrint("Password : ", 76, 25);
    fflush(stdin); takePassword(dUser.password);

    fwrite(&dUser, sizeof(dUser), 1, FSignup);
    fclose(FSignup);

    BersihSemuaLayar();
    MenuUtama();
}*/
