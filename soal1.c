/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 1
 *   Hari dan Tanggal    : Senin, 12 April 2026
 *   Nama (NIM)          : Celvin Ello X. Silitonga (13224107)
 *   Nama File           : multigate.c
 *   Deskripsi           : Fungsi didekomposisi menjadi dua bagian, yakni bagian load data dan bubble sorting. Pada bagian bubble sort
 *                         praktikan membatasi pengulangan for hanya hingga indeks kedua terakhir untuk menghindari seg. fault.
 *                         Selain itu, untuk keperluan optimasi, praktikan menambahkan variabel boolean puppet untuk memeriksa apakah
 *                         bilangan-bilangan tersebut benar-benar sudah terurut atau tidak untuk menghindari redundancy.
 */

 /**
  * Status ditentukan dengan urutan prioritas berikut:
• Jika radiasi >= 6, keluaran TOLAK
• Else jika suhu >= 390, keluaran KARANTINA
• Else jika izin == 1 dan jam < 6 atau jam > 20, keluaran TOLAK
• Else jika izin == 1, keluaran MASUK
• Else jika izin == 2 dan radiasi <= 2 dan jam di antara 8 sampai 18 inklusif, keluaran MASUK
• Else jika izin == 2, keluaran PEMERIKSAAN
• Else jika izin == 3 dan radiasi == 0 dan suhu < 380, keluaran MASUK
• Selain itu, keluaran TOLAK
  */

#include <stdio.h>

//format input: izin suhu radiasi jam
void load_data(int* permission, int* temp, int* rad, int* hour);
void check(int permission, int temp, int rad, int hour);

int main(void){
    int permission, temp, rad, hour;

    load_data(&permission, &temp, &rad, &hour);
    check(permission, temp, rad, hour);

    return 0;
}

//format input: izin suhu radiasi jam
void load_data(int* permission, int* temp, int* rad, int* hour){
    scanf("%d %d %d %d", permission, temp, rad, hour);
}

void check(int permission, int temp, int rad, int hour){
    if(rad>=6){
        printf("TOLAK");
    } 
    
    else if (temp>=390)
    {
        printf("KARANTINA");
    } 
    
    else if (permission==1)
    {
        if((hour<6) || (hour>20)) printf("TOLAK\n");
        else printf("MASUK");
    }
    
    else if (permission==2)
    {
        if((rad<=2)&&(hour<=8)&&(hour>=8)){
            printf("MASUK");
        } else printf("PEMERIKSAAN");
    }
    
    else if ((permission==3)&&(rad==0)&&(temp<380))
    {
        printf("MASUK");
    } 
    
    else printf("TOLAK");
}
