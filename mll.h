#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct elemenMekanik *adrMekanik;
typedef struct elemenPelanggan* adrPelanggan;

struct Mekanik{
    string nama;
    string no_telp;
};

struct Pelanggan{
    string nama;
    string motor;
    string plat;
};

struct elemenMekanik{
    Mekanik info;
    adrMekanik next;
    adrMekanik prev;
    adrPelanggan firstPelanggan;
};

struct elemenPelanggan{
    Pelanggan info;
    adrPelanggan next;
};

struct ListBengkel{
    adrMekanik first;
    adrMekanik last;
};

void createListBengkel(ListBengkel &L);
bool isEmptyMekanik(ListBengkel L);
bool isEmptyPelanggan(adrMekanik p);
adrMekanik createElemenMekanik(string nama, string no_telp);
adrPelanggan createElemenPelanggan(string nama, string motor, string plat);
void addFirstMekanik(ListBengkel &L, adrMekanik p);
void addLastMekanik(ListBengkel &L, adrMekanik p);
void addAfterMekanik(ListBengkel &L, adrMekanik p, adrMekanik prec);
void addMekanik(ListBengkel &L, adrMekanik p);
void addPelanggan(adrMekanik &p, adrPelanggan q);
adrMekanik searchMekanik(ListBengkel L, string no_telp);
bool searchPelangganAll(ListBengkel L, string motor);
adrPelanggan searchPelangganByMekanik(adrMekanik p, string plat);
void deleteFirstMekanik(ListBengkel &L, adrMekanik p);
void deleteLastMekanik(ListBengkel &L, adrMekanik p);
void deleteAfterMekanik(ListBengkel &L, adrMekanik p, adrMekanik);
void deleteMekanik(ListBengkel &L, string no_telp);
void deletePelanggan(ListBengkel L, string motor);
void displayList(ListBengkel L);

#endif // MLL_H_INCLUDED
