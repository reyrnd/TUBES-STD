#include "mll.h"

void createListBengkel(ListBengkel &L){
    L.first = nullptr;
    L.last = nullptr;
}

bool isEmptyMekanik(ListBengkel L){
    return L.first == nullptr && L.last == nullptr;
}

bool isEmptyPelanggan(adrMekanik p){
    return p->firstPelanggan == nullptr;
}

adrMekanik createElemenMekanik(string nama, string no_telp){
    adrMekanik p = new elemenMekanik;

    p->info.nama = nama;
    p->info.no_telp = no_telp;

    p->next = nullptr;
    p->prev = nullptr;
    p->firstPelanggan = nullptr;

    return p;
}

adrPelanggan createElemenPelanggan(string nama, string motor, string plat){
    adrPelanggan q = new elemenPelanggan;

    q->info.nama = nama;
    q->info.motor = motor;
    q->info.plat = plat;

    q->next = nullptr;

    return q;
}

void addFirstMekanik(ListBengkel &L, adrMekanik p){
    if(isEmptyMekanik(L)) {
        L.first = p;
        L.last = p;
    } else {
        L.first->prev = p;
        p->next = L.first;
        L.first = p;
    }
}

void addLastMekanik(ListBengkel &L, adrMekanik p){
    L.last->next = p;
    p->prev = L.last;
    L.last = p;
}

void addAfterMekanik(ListBengkel &L, adrMekanik p, adrMekanik prec){
    p->next = prec->next;
    p->prev = prec;

    prec->next->prev = p;

    prec->next = p;
}


void addMekanik(ListBengkel &L, adrMekanik p) {
    if (isEmptyMekanik(L)) {
        addFirstMekanik(L, p);
        return;
    }

    if (p->info.nama < L.first->info.nama) {
        addFirstMekanik(L, p);
        return;
    }

    if (p->info.nama > L.last->info.nama) {
        addLastMekanik(L, p);
        return;
    }

    adrMekanik q = L.first;

    while (q != NULL && p->info.nama > q->info.nama) {
        q = q->next;
    }

    addAfterMekanik(L, p, q->prev);
}

void addPelanggan(adrMekanik &p, adrPelanggan q){
    if(isEmptyPelanggan(p)) {
        p->firstPelanggan = q;
    } else {
        adrPelanggan temp = p->firstPelanggan;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = q;
    }
}

adrMekanik searchMekanik(ListBengkel L, string no_telp){
    adrMekanik p = L.first;

    while (p != nullptr){
        if (p->info.no_telp == no_telp){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

bool searchPelangganAll(ListBengkel L, string motor){
    adrMekanik m = L.first;

    while (m != nullptr){
        adrPelanggan p = m->firstPelanggan;

        if (p->info.motor == motor){
            return true;
        }
        m = m->next;
    }
    return false;
}

adrPelanggan searchPelangganByMekanik(adrMekanik p, string plat){
    adrPelanggan m = p->firstPelanggan;

    while (m != nullptr){
        if (m->info.plat == plat){
            return m;
        }
        m = m->next;
    }
    return nullptr;
}

void deletePelanggan(ListBengkel L, string motor) {
    adrMekanik m = L.first;

    while(m != nullptr) {
        adrPelanggan p = m->firstPelanggan;
        adrPelanggan prev = nullptr;

        while(p != nullptr) {
            if(p->info.motor == motor) {
                adrPelanggan nextNode = p->next;

                if(prev == nullptr) {
                    m->firstPelanggan = nextNode;
                } else {
                    prev->next = nextNode;
                }

                p = nextNode;
            } else {
                prev = p;
                p = p->next;
            }
        }
        m = m->next;
    }
}


void displayList(ListBengkel L){
    adrMekanik p = L.first;

    if(p == nullptr) {
        cout << "BELUM ADA DATA BENGKEL" << endl;
    }

    while (p != nullptr){
        cout << "Mekanik: " << p->info.nama << " (" << p->info.no_telp << ")" << endl;

        cout << "Pelanggan: ";
        adrPelanggan q = p->firstPelanggan;

        if(q == nullptr) {
            cout << "Tidak ada";
        }

        while (q != nullptr){
            cout << q->info.nama << " (" << q->info.motor << ", " << q->info.plat << ") " << (q->next != nullptr ? ", " : "");
            q = q->next;
        }
        cout << endl << endl;

        p = p->next;
    }
}
