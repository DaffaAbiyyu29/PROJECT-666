#ifndef DECLARE_H_
#define DECLARE_H_

typedef struct
{
	char username[25];
	char password[25];
	char jabatan[25];
}DataUser;

typedef struct
{
	int kd_mobil;
	char jenis_mobil[50];
	char merk_mobil[50];
	char nama_mobil[50];
	int harga_mobil;
}Mobil;

int pilih;

#endif
