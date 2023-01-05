#ifndef DECLARE_H_
#define DECLARE_H_

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

typedef struct
{
	char username[25];
	char password[25];
	char jabatan[25];
}DataUser;

typedef struct
{
    int id;
	char nama[30];
	char alamat[100];
	char telp[13];
	char username[25];
	char password[25];
	char role[25];
}User;

typedef struct
{
	int kd_mobil;
	char jenis_mobil[50];
	char merk_mobil[50];
	char nama_mobil[50];
	int harga_mobil;
	int stok;
}Mobil;

typedef struct
{
	int id_cus;
	char nik[16];
	char nama_cus[50];
	char tmpt_lahir[50];
	Date tgl_lahir;
	char alamat[100];
	char telp[50];
	char email[50];
}Customer;

typedef struct
{
    int kd_transaksi;
    int kd_mobil;
    Date tanggal;
    char merk_mobil[50];
	char nama_mobil[50];
	int harga_mobil;
	int jumlah;
	float bunga;
	float total_bunga;
	float total_harga;
	char nama_cus[30];
}Transaksi;

typedef struct
{
    int kd_restok;
    int kd_mobil;
    Date tanggal;
    char merk_mobil[50];
	char nama_mobil[50];
	int harga_mobil;
	int jumlah;
	float bunga;
	float total_bunga;
	float total_harga;
	char nama_vendor[30];
}Restok;

typedef struct
{
    int kd_asuransi;
    Date tanggal;
    int kd_mobil;
    char jenis_asuransi[10];
    int tenor_thn;
    int tenor_bln;
    float bunga;
    float total_bunga;
    int bulanke;
    float cicilan;
}Asuransi;

//BUAT CUSTOMER

int pilih;


#endif
