#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

// Deklarasi untuk public
int login();
void skor(int);
void header();
void petunjuk();
void daftar();
void jikabenar();
void jikasalah();
void pilihan();
void lower();
void upper();
void lowercircle();
void uppercircle();
void quiz1();
void quiz2();
void quiz3();

void mainmenu();
void cheque();
void tentang();

struct biodata
{
    char name[25];
    char username[25];
    char pwd[25];
    int age;
} d;

struct dftr
{
    char uname[25];
    int uang;
} c;

int q1, lifeline;

int main()
{
    int n, p = 0;
p1:
    printf("********************************************************************************\n");
    printf("**********\t  SELAMAT DATANG \t\t **********\n");
    printf("**********\t        DI \t\t **********\n");
    printf("**********\tWHO WANT TO BE A MILLIONARE \t **********\n");
    printf("**********\t  KELOMPOK 1 INFUSK 21 \t\t **********\n");
    printf("********************************************************************************\n");
    printf("\n1.Login\n\t\t\t2.Daftar\n\t\t\tMasukkan pilihan : ");
    fflush(stdin);
    scanf("%d", &n);
    system("cls");
    switch (n)
    {
    case 1:
    {
        printf("\n\n\n\n");
        p = 1;
        login();
        break;
    }
    case 2:
    {
        printf("\n\n\n\n");
        p = 1;
        daftar();
        break;
    }
    default:
    {
        printf("Tekan Enter....");
        system("cls");
        goto p1;
    }
    }
    if (p == 0)
        goto p1;
    else if (p == 1)
    {
        system("cls");
        petunjuk();
        system("cls");
        header();
        mainmenu();
    }
    return 0;
}

void header()
{
    system("cls");
    printf("\t\t");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("\t\t");

    printf("**********************************************************\n\n");
    printf("\t\t");
    printf("\t$$$$                 INFUSK Who Want To Be Millionare                 $$$$\n\n \t\t\t\tUSERNAME :: \" %s\"\n\n", d.username);
    printf("\t\t");
    printf("***********************************************************\n\n");
    printf("\t\t");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
}

void petunjuk()
{
    header();
    printf("\n\t\t************Sebelum Kita Memulai**************\n\n\t\t********* Baca Petunjuk*********\n\n");
    printf("\n\n\t\t1. Game ini memiliki 3 level :\n\t\t1.Easy\t\t\t2.Medium\t\t\t3.Hard  \n");
    printf("\n\n\t\t2. Satu Level terdiri dari 10 soal\n\t\t dijawab satu peRpatu .\n");
    printf("\n\t\t3. Dimulai dari \n\t\t Rp. 10,000 to Rp. 1 M  \n\t.\n");
    printf("\n\t\t4. Jawablah dengan benar\n\t\t dan kamu akan mendapatkan banyak uang .\n");
    printf("\n\t\t5. Jika kamu salah jawab maka ulangi lagi sampai kamu bisa\n\t\t tetapi harus dimulai dari awal.\n");
    printf("\n\t\t6. Kamu dapat keluar dari geme .");
    getch();
}

void daftar()
{
    FILE *fp, *fp1;
    fp = fopen("b.txt", "ab");
    fp1 = fopen("p.txt", "a");
    printf("Masukkan Nama Anda: \t");
    scanf("%s", d.name);
    printf("Masukkan Username: \t");
    fflush(stdin);
    scanf("%s", d.username);
    strcpy(c.uname, d.username);
    fprintf(fp1, "%s ", c.uname);
    printf("Masukkan Password: \t");
    fflush(stdin);
    scanf("%s", d.pwd);
    printf("Masukkan Umur Anda: \t");
    scanf("%d", &d.age);
    fwrite(&d, sizeof(d), 1, fp);
    fclose(fp);
    fclose(fp1);
}

int login()
{
    char usr[25], pw[25];
    FILE *fp;
    fp = fopen("b.txt", "rb");
    printf("\t\tUsername:-  ");
    scanf("%s", usr);
    printf("\t\tPassword:-  ");
    fflush(stdin);
    scanf("%s", pw);
    while (!feof(fp))
    {
        fread(&d, sizeof(d), 1, fp);
        if ((strcmp(d.username, usr) == 0) && (strcmp(d.pwd, pw) == 0))
        {
            printf("Login Sukses.....\n");
            getch();
            return 1;
        }
    }
    fclose(fp);
    printf("\n\t\tTolong Masukkan Username dan nama yang valid\n");
    getch();
    system("cls");
    main();
    return 0;
}

void skor(int a)
{
    FILE *fp;
    fp = fopen("p.txt", "a");
    if (q1 == 1 && a)
    {
        printf("Selamat!!!\nSaudara memenangkan Rp.%d.", 10000);
        c.uang = 10000;
        getch();
    }
    else if (q1 == 1 && a == 0)

    {
        printf("Kerja Bagus...\nKamu tidak membawa pulang uang..");
        c.uang = 0;
        fprintf(fp, "%d\n", c.uang);
        getch();
    }
    else if (q1 == 2 && a)
    {
        printf("Selamat!!!\nsaudara mendapatkan Rp.%d.", 80000);
        c.uang = 80000;
        getch();
    }
    else if (q1 == 2 && a == 0)
    {
        printf("Kerja Bagus.....\nKamu tidak membawa pulang uang..");
        c.uang = 0;
        fprintf(fp, "%d\n", c.uang);
        getch();
    }
    else if (q1 == 3 && a)
    {
        printf("Selamat!!!\nKamu memenangkan Rp.%d.", 160000);
        c.uang = 160000;
        getch();
    }
    else if (q1 == 3 && a == 0)
    {
        printf("Kerja bagus.....\nKamu tidak mendapatkan rupiah..");
        c.uang = 0;
        fprintf(fp, "%d\n", c.uang);
    }
    else if (q1 == 4 && a)
    {
        printf("Selamat!!!\nLKamu mendapatkan uang Rp.250.000");
        printf("\nMenakjubkan!!!!!!Kamu berhasil melewati tahap pertama. Di kirim ke rekening anda sebesar Rp.250.000 .");
        c.uang = 250000;
        getch();
        cheque(c.uang);
    }
    else if (q1 == 4 && a == 0)
    {
        printf("Kerja bagus.....\nTetapi hanya memenangkan Rp.250.000, ayo coba lagi..");
        c.uang = 250000;
        fprintf(fp, "%d\n", c.uang);
        getch();
        cheque(c.uang);
    }
    else if (q1 == 5 && a)
    {
        printf("Selamat!!!\nSaudara mendapatkan Rp.%d.", 320000);
        c.uang = 320000;
        getch();
    }
    else if (q1 == 5 && a == 0)
    {
        printf("Kerja Bagus.....\nKamu mendapatkan Rp.250.000");
        c.uang = 250000;
        fprintf(fp, "%d\n", c.uang);
        getch();
        cheque(c.uang);
    }
    else if (q1 == 6 & a)
    {
        printf("Selamat!!!\nKamu mendapatkan Rp.%d.", 640000);
        c.uang = 640000;
        getch();
    }
    else if (q1 == 6 & a == 0)
    {
        printf("Kerja bagus.....\nkamu membawa pulang Rp.250.000");
        c.uang = 250000;
        fprintf(fp, "%d\n", c.uang);
        getch();
        cheque(c.uang);
    }
    else if (q1 == 7 && a)
    {
        printf("Keren!!!Saudara melewati tahap dua Who want to be Millionare....");
        printf("Selamat!!!\nKamu mendapatkan Rp.%d.", 1250000);
        c.uang = 1250000;
        getch();
        cheque(c.uang);
    }
    else if (q1 == 7 && a == 0)
    {
        printf("Bagus Sekali.....\nKamu bisa membawa pulang Rp.1.250.000");
        c.uang = 250000;
        fprintf(fp, "%d\n", c.uang);
        getch();
        cheque(c.uang);
    }
    else if (q1 == 8 && a)
    {
        printf("Selamat!!!\nKamu mendapatkan Rp.%d.", 2500000);
        c.uang = 2500000;
        getch();
    }
    else if (q1 == 8 && a == 0)
    {
        printf("Kerja bagus.....\nKamu membawa pulang Rp.2.500.000");
        c.uang = 1250000;
        fprintf(fp, "%d\n", c.uang);
        getch();
        cheque(c.uang);
    }
    else if (q1 == 9 && a)
    {
        printf("Selamat!!!\nKamu berhasil mendapatkan  Rp.%d.", 500000);
        c.uang = 500000;
        getch();
    }
    else if (q1 == 9 && a == 0)
    {
        printf("Kerja bagus.....\ntapi hanya dapat Rp.1.250.000");
        c.uang = 1250000;
        fprintf(fp, "%d\n", c.uang);
        getch();
        cheque(c.uang);
    }
    else if (q1 == 10 && a)
    {
        printf("Selamat!!!\nKamu memenangkan Rp.%d.", 1000000);
        printf("\n\t\tYOU ARE A MILLIONAIRE!!");
        c.uang = 1000000;
        fprintf(fp, "%d\n", c.uang);
        getch();
        cheque(c.uang);
    }
    else if (q1 == 10 && a == 0)
    {
        printf("Kerja bagus.....\n Kamu membawa pulang Rp.1.250.000 .");
        c.uang = 1250000;
        fprintf(fp, "%d\n", c.uang);
        getch();
        cheque(c.uang);
    }
}

void cheque(int a)
{
    system("cls");
    printf("\n\t--------------------------------------------------------------------\n");
    printf("\t|                             *                                     |\n");
    printf("\t|                           ****                                    |\n");
    printf("\t|                         ********                                  |\n");
    printf("\t|                       ************                                |\n");
    printf("\t|                   ****  BANK USK ****           \t\t    |\n");
    printf("\t|                                                                   |\n");
    printf("\t|   Kepada:     %s                          Uang Masuk         |\n", d.username);
    printf("\t|                                                                   |\n");
    printf("\t|                                                                   |\n");
    printf("\t|   Rp. %d                                                 |\n", a);
    printf("\t|                                                                   |\n");
    printf("\t|                                                                   |\n");
    printf("\t|                                                                   |\n");
    printf("\t|  SELAMAT ANDA TELAH MENCAPAI TITIK INI                            |\n");
    printf("\t|                                                                   |\n");
    printf("\t|                                          __________________       |\n");
    printf("\t|                                              %s                    |\n", d.username);
    printf("\t|                                                                   |\n");
    printf("\t|                                                                   |\n");
    printf("\t---------------------------------------------------------------------");
    Beep(1000, 400);
    Beep(500, 400);
    Beep(1200, 400);
    printf("\n\n\t\t\tTekan Enter Untuk Continue...");
    getch();
}

void mainmenu()
{
    while (1)

    {
        system("cls");
        int pilih;

        header();
        printf("\n\n\t\t\t\t\t*** MAIN MENU ***");
        printf("\n\n\t\t\t\t\t1. Mulai");
        printf("\n\t\t\t\t\t2. petunjuk");
        printf("\n\t\t\t\t\t3. Tentang");
        printf("\n\t\t\t\t\t4. Logout User");
        printf("\n\t\t\t\t\t5. Exit");

        printf("\n\n\t\t\t\t\tPilih menu:  >>>");
        fflush(stdin);
        scanf("%d", &pilih);
        system("cls");
        switch (pilih)
        {
        case 1:
            pilihan();
            break;

        case 2:
            petunjuk();
            printf("\n\n\t\t\t\t<<<Kembali Ke Menu... >>>");
            getch();
            break;

        case 3:
            tentang();
            break;

        case 4:
            main();

        case 5:
            exit(0);

        default:
            printf("\nEnter any valid choice");
            getch();
            fflush(stdin);
        }
    }
}

void pilihan()
{
    system("cls");
    printf("\n\n\t\t\t\t  Level : !");
    printf("\n\n\t\t\t\t  1. Mudah  ");
    printf("\n\n\t\t\t\t  2. Standar ");
    printf("\n\n\t\t\t\t  3. Sulit ");
    printf("\n\n\t\t\t\t\tMasukkan Pilihan Anda >>> ");
    int levelpilih;
    fflush(stdin);
    scanf("%d", &levelpilih);
    lifeline = 2;
    switch (levelpilih)
    {
    case 1:
        printf("\n\n\t\t\t\t  SEMANGAT !");
        printf("\n\n\t\t\t\t<<<Enter dan mulai...>>>");
        getch();
        quiz1();
        break;

    case 2:
        printf("\n\n\t\t\t\t  SEMANGAT !");
        printf("\n\n\t\t\t\t<<<Enter dan mulai...>>>");
        getch();
        quiz2();
        break;

    case 3:
        printf("\n\n\t\t\t\t  SEMANGAT !");
        printf("\n\n\t\t\t\t<<<Enter dan mulai...>>>");
        getch();
        quiz3();
        break;

    default:
        printf("\nChoose benar Mode");
        getch();
        pilihan();
        fflush(stdin);
    }
}

void tentang()
{
    header();
    printf("\n\n\t\t\t\t\t*** Tentang***");
    printf("\n\n\n\t\tKelompok 1 ");
    printf("\n\n\n\t\tWho Want to be a millionare");
    printf("\n\n\n\t\tBy: 1. KHAIRIL ILMI\n2. MUHAMMAD DANIS RABANI\n3. DJULKIRAM HILMI\n.4.ARIF ");
    printf("\n\t\tKelas A");
    getch();
}

void lower()
{

    int n = 10, i, j, l = 9;
    printf("\t\t\t\t");
    for (i = n; i > 0; i--)
    {
        printf("\t\t\t");
        for (j = 0; j < l; j++)
            printf(" ");

        for (j = 0; j < i; j++)
            printf("* ");

        printf("\n");
        l++;
    }
}

void upper()
{
    int n = 10, i, j;
    int l = n - 1;

    for (i = 0; i < n; i++)
    {
        printf("\t\t\t\t");
        for (j = 0; j < l; j++)
            printf(" ");

        for (j = 0; j <= i; j++)
            printf("* ");

        printf("\n");
        l--;
    }
}

void lowercircle()
{

    int n = 10, i, j, l = 9;
    printf("\t\t\t");
    for (i = n; i > 0; i--)
    {
        printf("\t\t\t");
        for (j = 0; j < l; j++)
            printf(" ");

        for (j = 0; j < i; j++)
            printf("O ");

        printf("\n");
        l++;
    }
}

void uppercircle()
{
    int n = 10;
    int i, j;
    int l = n - 1;

    for (i = 0; i < n; i++)
    {
        printf("\t\t\t\t");
        for (j = 0; j < l; j++)
            printf(" ");

        for (j = 0; j <= i; j++)
            printf("O ");

        printf("\n");
        l--;
    }
}

void jikabenar()
{
    system("cls");
    upper();
    printf("\t\t*************Selamat!!!***********  \n\n\t\t\t\t Saudara benar.");
    lower();

    Beep(500, 500);
    Beep(1000, 500);
    Beep(1500, 500);
    skor(1);
}

void jikasalah()
{
    system("cls");
    uppercircle();
    printf("\t\t*************Wah!!!***********  \n\n\t\t\t\t Belum belum benar.");
    lowercircle();
    Beep(5000, 500);
    Beep(4500, 500);
    Beep(3500, 500);
    skor(0);
    printf("\n\n\t\t\t\t Kembali Ke Menu... >> ");
    getch();
    mainmenu();
}

void keluar()
{
    FILE *fp1;
    fp1 = fopen("p.txt", "w");
    header();
    printf("\n\n \t\t\tKamu telah keluar dari game");
    printf("\n\n \t\t\tKamu adalah seorang pemenang ");
    printf("Rp. %d  ", c.uang);
    if (c.uang >= 10000)
        cheque(c.uang);
    fprintf(fp1, "%d\n", c.uang);
    fclose(fp1);
    printf("\n\n\t\t\t\t Kembali Ke Menu... >> ");
    getch();
    mainmenu();
}


void quiz1()
{
    char q, l;
    /*  SOAL 1 */
    q1 = 1;
q111:
    header();
    printf("\n Pertanyaan no. 1");
    printf("\t\t\t\t\t\t\t\t\t\tRp.10,000/-");
    printf("\n\n\t\t\tWho is popularly known as 'Father of Indian Cinema'?");
    printf("\n\n\t\t\t\tA. Dadasaheb Phalke");
    printf("\n\t\t\t\tB. V. Shantaram");
    printf("\n\t\t\t\tC. Ardeshir Irani");
    printf("\n\t\t\t\tD. Kidar Sharma");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'A':
        jikabenar();
        break;
    case 'B':
    case 'C':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q110:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q112;
            break;

        case 'B':
            goto q113;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q110;
        }

    q112:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 1    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.10,000/-");
        printf("\n\n\t\t\tWho is popularly known as 'Father of Indian Cinema'?");
        printf("\n\n\t\t\t\tA. Dadasaheb Phalke");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD. Kidar Sharma");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q113;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q112;
        }
        break;
    }

    q113:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 1    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.10,000/-");
        printf("\n\n\t\t\tWho is popularly known as 'Father of Indian Cinema'?");
        printf("\n\n\t\t\t\tA. Dadasaheb Phalke");
        printf("\n\t\t\t\tB. V. Shantaram");
        printf("\n\t\t\t\tC. Ardeshir Irani");
        printf("\n\t\t\t\tD. Kidar Sharma");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tA. Dadasaheb Phalke");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'B':
        case 'C':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q112;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q113;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q111;
    }
    }

    /*  QUESTION 2 */

q121:
    header();
    q1 = 2;
    printf("\n Pertanyaan no. 2");
    printf("\t\t\t\t\t\t\t\t\t\tRp.80,000/-");
    printf("\n\n\t\t\tWhat is the age limit for the athletes participating in the Youth Olympic Games?");
    printf("\n\n\t\t\t\tA. 14 to 20");
    printf("\n\t\t\t\tB. 15 to 22");
    printf("\n\t\t\t\tC. 14 to 18");
    printf("\n\t\t\t\tD. 16 to 25");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'C':
        jikabenar();
        break;
    case 'B':
    case 'A':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q120:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q122;
            break;

        case 'B':
            goto q123;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q120;
        }

    q122:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 2    You are using life line 50:50");
        printf("\t\t\t\t\t\t\t\t\t\tRp.80,000/-");
        printf("\n\n\t\t\tWhat is the age limit for the athletes participating in the Youth Olympic Games?");
        printf("\n\n\t\t\t\t");
        printf("\n\t\t\t\tB. 15 to 22");
        printf("\n\t\t\t\tC. 14 to 18");
        printf("\n\t\t\t\t");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'B':
            jikasalah();
            break;
        case 'E':
            goto q123;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q122;
        }
        break;
    }

    q123:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 2    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.80,000/-");
        printf("\n\n\t\t\tWhat is the age limit for the athletes participating in the Youth Olympic Games?");
        printf("\n\n\t\t\t\tA. 14 to 20");
        printf("\n\t\t\t\tB. 15 to 22");
        printf("\n\t\t\t\tC. 14 to 18");
        printf("\n\t\t\t\tD. 16 to 25");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tC. 14 to 18");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'B':
        case 'A':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q122;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q123;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q121;
    }
    }

    /*  QUESTION 3 */

q131:
    header();
    q1 = 3;
    printf("\n Pertanyaan no. 3");
    printf("\t\t\t\t\t\t\t\t\t\tRp.1,60,000/-");
    printf("\n\n\t\t\tWhat is the name for the mapped hexagonal geographic areas that make up the cellular phone grid?");
    printf("\n\n\t\t\t\tA. Hexagrids");
    printf("\n\t\t\t\tB. Pins");
    printf("\n\t\t\t\tC. Cells");
    printf("\n\t\t\t\tD. ContaineRp");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'C':
        jikabenar();
        break;
    case 'B':
    case 'A':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q130:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q132;
            break;

        case 'B':
            goto q133;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q130;
        }

    q132:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 1    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.1,60,000/-");
        printf("\n\n\t\t\tWhat is the name for the mapped hexagonal geographic areas that make up the cellular phone grid?");
        printf("\n\n\t\t\t\tA. Hexagrids");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tC. Cells");
        printf("\n\t\t\t\t");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q133;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q132;
        }
        break;
    }

    q133:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 3    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.1,60,000/-");
        printf("\n\n\t\t\tWhat is the name for the mapped hexagonal geographic areas that make up the cellular phone grid?");
        printf("\n\n\t\t\t\tA. Hexagrids");
        printf("\n\t\t\t\tB. Pins");
        printf("\n\t\t\t\tC. Cells");
        printf("\n\t\t\t\tD. ContaineRp");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tC. Cells");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'B':
        case 'A':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q132;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q133;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q131;
    }
    }

    /*  QUESTION 4 */

q141:
    header();
    q1 = 4;
    printf("\n Pertanyaan no. 4");
    printf("\t\t\t\t\t\t\t\t\t\tRp.2,50,000/-");
    printf("\n\n\t\t\tWho is the only leader to be selected Prime Minister of Pakistan three times ??");
    printf("\n\n\t\t\t\tA. Syed Yousaf Raza Gillani");
    printf("\n\t\t\t\tB. Benazir Bhutto");
    printf("\n\t\t\t\tC. Liaqat Ali Khan");
    printf("\n\t\t\t\tD. Nawaz Sharif ");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'D':
        jikabenar();
        break;
    case 'B':
    case 'C':
    case 'A':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q140:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q142;
            break;

        case 'B':
            goto q143;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q140;
        }

    q142:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 4    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.2,50,000/-");
        printf("\n\n\t\t\tWho is the only leader to be selected Prime Minister of Pakistan three times ??");
        printf("\n\n\t\t\t\tA. Syed Yousaf Raza Gillani");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD. Nawaz Sharif ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'D':
            jikabenar();
            break;
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q143;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q142;
        }
        break;
    }

    q143:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 4    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.2,50,000/-");
        printf("\n\n\t\t\tWho is the only leader to be selected Prime Minister of Pakistan three times ??");
        printf("\n\n\t\t\t\tA. Syed Yousaf Raza Gillani");
        printf("\n\t\t\t\tB. Benazir Bhutto");
        printf("\n\t\t\t\tC. Liaqat Ali Khan");
        printf("\n\t\t\t\tD. Nawaz Sharif ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tD. Nawaz Sharif ");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'D':
            jikabenar();
            break;
        case 'B':
        case 'C':
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q142;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q143;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q141;
    }
    }

/*  QUESTION 5 */
q151:
    header();
    q1 = 5;
    printf("\n Pertanyaan no. 5");
    printf("\t\t\t\t\t\t\t\t\t\tRp.3,20,000/-");
    printf("\n\n\t\t\tWhich was the fiRpt telephone company to create a handheld mobile phone");
    printf("\n\n\t\t\t\tA. Apple");
    printf("\n\t\t\t\tB. Motorola");
    printf("\n\t\t\t\tC. Nokia");
    printf("\n\t\t\t\tD. Samsung ");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'B':
        jikabenar();
        break;
    case 'A':
    case 'C':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q150:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q152;
            break;

        case 'B':
            goto q153;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q150;
        }

    q152:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 5    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.3,20,000/-");
        printf("\n\n\t\t\tWhich was the fiRpt telephone company to create a handheld mobile phone");
        printf("\n\n\t\t\t\tA. Apple");
        printf("\n\t\t\t\tB. Motorola");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'B':
            jikabenar();
            break;
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q153;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q152;
        }
        break;
    }

    q153:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 5    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.3,20,000/-");
        printf("\n\n\t\t\tWhich was the fiRpt telephone company to create a handheld mobile phone");
        printf("\n\n\t\t\t\tA. Apple");
        printf("\n\t\t\t\tB. Motorola");
        printf("\n\t\t\t\tC. Nokia");
        printf("\n\t\t\t\tD. Samsung ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tB. Motorola");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'B':
            jikabenar();
            break;
        case 'A':
        case 'C':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q152;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q153;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q151;
    }
    }

    /*  QUESTION 6 */
q161:
    header();
    q1 = 6;
    printf("\n Pertanyaan no. 6");
    printf("\t\t\t\t\t\t\t\t\t\tRp.6,40,000/-");
    printf("\n\n\t\t\tIn 2012, which of these countries has been removed by WHO from the polioendemic countries ?");
    printf("\n\n\t\t\t\tA. Pakistan ");
    printf("\n\t\t\t\tB. Nigeria ");
    printf("\n\t\t\t\tC. India ");
    printf("\n\t\t\t\tD. Afghanistan  ");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'C':
        jikabenar();
        break;
    case 'B':
    case 'A':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q160:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q162;
            break;

        case 'B':
            goto q163;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q160;
        }

    q162:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 6    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.6,40,000/-");
        printf("\n\n\t\t\tIn 2012, which of these countries has been removed by WHO from the polioendemic countries ?");
        printf("\n\n\t\t\t\t ");
        printf("\n\t\t\t\tB. Nigeria ");
        printf("\n\t\t\t\tC. India ");
        printf("\n\t\t\t\t ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'B':
            jikasalah();
            break;
        case 'E':
            goto q163;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q162;
        }
        break;
    }

    q163:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 6    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.6,40,000/-");
        printf("\n\n\t\t\tIn 2012, which of these countries has been removed by WHO from the polioendemic countries ?");
        printf("\n\n\t\t\t\tA. Pakistan ");
        printf("\n\t\t\t\tB. Nigeria ");
        printf("\n\t\t\t\tC. India ");
        printf("\n\t\t\t\tD. Afghanistan  ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tC. India ");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'B':
        case 'A':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q162;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q163;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q161;
    }
    }

    /*  QUESTION 7 */

q171:
    header();
    q1 = 7;
    printf("\n Pertanyaan no. 7");
    printf("\t\t\t\t\t\t\t\t\t\tRp.12,50,000/-");
    printf("\n\n\t\t\tWhich of these peRponalities has also served as Deputy Prime Minister of India ? ?");
    printf("\n\n\t\t\t\tA. Lal Bahadur Shastri  ");
    printf("\n\t\t\t\tB. L K Advani  ");
    printf("\n\t\t\t\tC. Gulzarilal Nanda");
    printf("\n\t\t\t\tD. Arjun Singh ");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'B':
        jikabenar();
        break;
    case 'A':
    case 'C':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q170:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q172;
            break;

        case 'B':
            goto q173;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q170;
        }

    q172:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 7    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.12,50,000/-");
        printf("\n\n\t\t\tWhich of these peRponalities has also served as Deputy Prime Minister of India ? ?");
        printf("\n\n\t\t\t\tA. Lal Bahadur Shastri  ");
        printf("\n\t\t\t\tB. L K Advani  ");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'B':
            jikabenar();
            break;
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q173;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q172;
        }
        break;
    }

    q173:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 7    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.12,50,000/-");
        printf("\n\n\t\t\tWhich of these peRponalities has also served as Deputy Prime Minister of India ? ?");
        printf("\n\n\t\t\t\tA. Lal Bahadur Shastri  ");
        printf("\n\t\t\t\tB. L K Advani  ");
        printf("\n\t\t\t\tC. Gulzarilal Nanda");
        printf("\n\t\t\t\tD. Arjun Singh ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tB. L K Advani  ");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'B':
            jikabenar();
            break;
        case 'A':
        case 'C':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q172;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q173;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q171;
    }
    }

    /*  QUESTION 8 */

q181:
    header();
    q1 = 8;
    printf("\n Pertanyaan no. 8");
    printf("\t\t\t\t\t\t\t\t\t\tRp.25,00,000/-");
    printf("\n\n\t\t\tWho among these conqueroRp was the fiRpt to invade India ?");
    printf("\n\n\t\t\t\tA. Timur  ");
    printf("\n\t\t\t\tB. Nadir Shah  ");
    printf("\n\t\t\t\tC. Ahmad Shah Durrani");
    printf("\n\t\t\t\tD. Babur ");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'A':
        jikabenar();
        break;
    case 'B':
    case 'C':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q180:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q182;
            break;

        case 'B':
            goto q183;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q180;
        }

    q182:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 8    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.25,00,000/-");
        printf("\n\n\t\t\tWho among these conqueroRp was the fiRpt to invade India ?");
        printf("\n\n\t\t\t\tA. Timur  ");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD. Babur ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q183;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q182;
        }
        break;
    }

    q183:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 8    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.25,00,000/-");
        printf("\n\n\t\t\tWho among these conqueroRp was the fiRpt to invade India ?");
        printf("\n\n\t\t\t\tA. Timur  ");
        printf("\n\t\t\t\tB. Nadir Shah  ");
        printf("\n\t\t\t\tC. Ahmad Shah Durrani");
        printf("\n\t\t\t\tD. Babur ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tA. Timur  ");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'B':
        case 'C':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q182;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q183;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q181;
    }
    }

    /*  QUESTION 9 */
q191:
    header();
    q1 = 9;
    printf("\n Pertanyaan no. 9");
    printf("\t\t\t\t\t\t\t\t\t\tRp.50,00,000/-");
    printf("\n\n\t\t\t What part of the body is normally cut open during an appendix operation?");
    printf("\n\n\t\t\t\tA. Abdomen  ");
    printf("\n\t\t\t\tB. Chest  ");
    printf("\n\t\t\t\tC. Head");
    printf("\n\t\t\t\tD. Neck");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'A':
        jikabenar();
        break;
    case 'B':
    case 'C':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q190:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q192;
            break;

        case 'B':
            goto q193;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q190;
        }

    q192:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 9    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.50,00,000/-");
        printf("\n\n\t\t\t What part of the body is normally cut open during an appendix operation?");
        printf("\n\n\t\t\t\tA. Abdomen  ");
        printf("\n\t\t\t\t  ");
        printf("\n\t\t\t\tC. Head");
        printf("\n\t\t\t\t");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'C':
            jikasalah();
            break;
        case 'E':
            goto q193;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q192;
        }
        break;
    }

    q193:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 9    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.5000.000/-");
        printf("\n\n\t\t\t What part of the body is normally cut open during an appendix operation?");
        printf("\n\n\t\t\t\tA. Abdomen  ");
        printf("\n\t\t\t\tB. Chest  ");
        printf("\n\t\t\t\tC. Head");
        printf("\n\t\t\t\tD. Neck");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tA. Abdomen ");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'B':
        case 'C':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q192;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q193;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q191;
    }
    }

    /*  QUESTION 10*/

q1101:
    header();
    q1 = 10;
    printf("\n Pertanyaan no. 10");
    printf("\t\t\t\t\t\t\t\t\t\tRp. 1 CRORE/-");
    printf("\n\n\t\t\t What was the largest social network prior to Facebook??");
    printf("\n\n\t\t\t\tA. LetsBeFriends  ");
    printf("\n\t\t\t\tB. Google+  ");
    printf("\n\t\t\t\tC.Friendster");
    printf("\n\t\t\t\tD. MySpace");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'D':
        jikabenar();
        break;
    case 'B':
    case 'C':
    case 'A':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q1100:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q1102;
            break;

        case 'B':
            goto q1103;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q1100;
        }

    q1102:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 10    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp. 1 CRORE/-");
        printf("\n\n\t\t\t What was the largest social network prior to Facebook??");
        printf("\n\n\t\t\t\t ");
        printf("\n\t\t\t\t ");
        printf("\n\t\t\t\tC.Friendster");
        printf("\n\t\t\t\tD. MySpace");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'D':
            jikabenar();
            break;
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q1103;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q1102;
        }
        break;
    }

    q1103:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 10    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp. 1 CRORE/-");
        printf("\n\n\t\t\t What was the largest social network prior to Facebook??");
        printf("\n\n\t\t\t\tA. LetsBeFriends  ");
        printf("\n\t\t\t\tB. Google+  ");
        printf("\n\t\t\t\tC.Friendster");
        printf("\n\t\t\t\tD. MySpace");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tD. MySpace");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'D':
            jikabenar();
            break;
        case 'B':
        case 'C':
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q1102;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q1103;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q1101;
    }
    }
    return;
}

void quiz2()
{
    char q, l;
    /*  QUESTION 1 */
    q1 = 1;
q111:
    header();
    printf("\n Pertanyaan no. 1");
    printf("\t\t\t\t\t\t\t\t\t\tRp.10,000/-");
    printf("\n\n\t\t\tWhich was the last movie directed by Yash Chopra?");
    printf("\n\n\t\t\t\tA. Jab Tak Hai Jaan");
    printf("\n\t\t\t\tB. Rab Ne Bana Di Jodi");
    printf("\n\t\t\t\tC. Veer Zara");
    printf("\n\t\t\t\tD. Ek Tha Tiger");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'A':
        jikabenar();
        break;
    case 'B':
    case 'C':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q110:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q112;
            break;

        case 'B':
            goto q113;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q110;
        }

    q112:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 1    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.10,000/-");
        printf("\n\n\t\t\tWhich was the last movie directed by Yash Chopra?");
        printf("\n\n\t\t\t\tA. Jab Tak Hai Jaan");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tC. Veer Zara");
        printf("\n\t\t\t\t");

        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'C':
            jikasalah();
            break;
        case 'E':
            goto q113;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q112;
        }
        break;
    }

    q113:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 1    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.10,000/-");
        printf("\n\n\t\t\tWhich was the last movie directed by Yash Chopra?");
        printf("\n\n\t\t\t\tA. Jab Tak Hai Jaan");
        printf("\n\t\t\t\tB. Rab Ne Bana Di Jodi");
        printf("\n\t\t\t\tC. Veer Zara");
        printf("\n\t\t\t\tD. Ek Tha Tiger");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tA. Jab Tak Hai Jaan");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'B':
        case 'C':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q112;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q113;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q111;
    }
    }

    /*  QUESTION 2 */

q121:
    header();
    q1 = 2;
    printf("\n Pertanyaan no. 2");
    printf("\t\t\t\t\t\t\t\t\t\tRp.80,000/-");
    printf("\n\n\t\t\tWho has been India's longest serving woman Chief Minister ?");
    printf("\n\n\t\t\t\tA. Vasundhara Raje");
    printf("\n\t\t\t\tB. Jayalalita");
    printf("\n\t\t\t\tC. Sheila Dixit ");
    printf("\n\t\t\t\tD. Mayavati");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'C':
        jikabenar();
        break;
    case 'B':
    case 'A':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q120:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q122;
            break;

        case 'B':
            goto q123;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q120;
        }

    q122:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 2    You are using life line 50:50");
        printf("\t\t\t\t\t\t\t\t\t\tRp.80,000/-");
        printf("\n\n\t\t\tWho has been India's longest serving woman Chief Minister ?");
        printf("\n\n\t\t\t\t");
        printf("\n\t\t\t\tB. Jayalalita");
        printf("\n\t\t\t\tC. Sheila Dixit ");
        printf("\n\t\t\t\t");

        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'B':
            jikasalah();
            break;
        case 'E':
            goto q123;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q122;
        }
        break;
    }

    q123:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 2    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.80,000/-");
        printf("\n\n\t\t\tWho has been India's longest serving woman Chief Minister ?");
        printf("\n\n\t\t\t\tA. Vasundhara Raje");
        printf("\n\t\t\t\tB. Jayalalita");
        printf("\n\t\t\t\tC. Sheila Dixit ");
        printf("\n\t\t\t\tD. Mayavati");

        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tC. Sheila Dixit ");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'B':
        case 'A':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q122;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q123;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q121;
    }
    }

    /*  QUESTION 3 */

q131:
    header();
    q1 = 3;
    printf("\n Pertanyaan no. 3");
    printf("\t\t\t\t\t\t\t\t\t\tRp.1,60,000/-");
    printf("\n\n\t\t\tWho won the fiRpt nobel prize from India");
    printf("\n\n\t\t\t\tA. Mahatma Gandhi");
    printf("\n\t\t\t\tB. Rabindra Naath Tagore");
    printf("\n\t\t\t\tC. C V Raman");
    printf("\n\t\t\t\tD. Mother Teresa");

    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'C':
        jikabenar();
        break;
    case 'B':
    case 'A':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q130:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q132;
            break;

        case 'B':
            goto q133;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q130;
        }

    q132:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 1    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.1,60,000/-");
        printf("\n\n\t\t\tWho won the fiRpt nobel prize from India");
        printf("\n\n\t\t\t\t");
        printf("\n\t\t\t\tB. Rabindra Naath Tagore");
        printf("\n\t\t\t\tC. C V Raman");
        printf("\n\t\t\t\t");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'B':
            jikasalah();
            break;
        case 'E':
            goto q133;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q132;
        }
        break;
    }

    q133:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 3    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.1,60,000/-");
        printf("\n\n\t\t\tWho won the fiRpt nobel prize from India");
        printf("\n\n\t\t\t\tA. Mahatma Gandhi");
        printf("\n\t\t\t\tB. Rabindra Naath Tagore");
        printf("\n\t\t\t\tC. C V Raman");
        printf("\n\t\t\t\tD. Mother Teresa");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tC. C V Raman");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'B':
        case 'A':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q132;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q133;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q131;
    }
    }

    /*  QUESTION 4 */

q141:
    header();
    q1 = 4;
    printf("\n Pertanyaan no. 4");
    printf("\t\t\t\t\t\t\t\t\t\tRp.2,50,000/-");
    printf("\n\n\t\t\t.Olympic games 2008 were held in which  of the following places?");
    printf("\n\n\t\t\t\tA. London");
    printf("\n\t\t\t\tB. Brazil");
    printf("\n\t\t\t\tC. Athenes");
    printf("\n\t\t\t\tD. Beijing ");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'D':
        jikabenar();
        break;
    case 'B':
    case 'C':
    case 'A':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q140:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q142;
            break;

        case 'B':
            goto q143;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q140;
        }

    q142:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 4    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.2,50,000/-");
        printf("\n\n\t\t\t.Olympic games 2008 were held in which  of the following places?");
        printf("\n\n\t\t\t\tA. London");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD. Beijing ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'D':
            jikabenar();
            break;
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q143;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q142;
        }
        break;
    }

    q143:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 4    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.2,50,000/-");
        printf("\n\n\t\t\t.Olympic games 2008 were held in which  of the following places?");
        printf("\n\n\t\t\t\tA. London");
        printf("\n\t\t\t\tB. Brazil");
        printf("\n\t\t\t\tC. Athenes");
        printf("\n\t\t\t\tD. Beijing ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tD. Beijing");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'D':
            jikabenar();
            break;
        case 'B':
        case 'C':
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q142;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q143;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q141;
    }
    }

/*  QUESTION 5 */
q151:
    header();
    q1 = 5;
    printf("\n Pertanyaan no. 5");
    printf("\t\t\t\t\t\t\t\t\t\tRp.3,20,000/-");
    printf("\n\n\t\t\tWeb pages are written using");
    printf("\n\n\t\t\t\tA. FTPB");
    printf("\n\t\t\t\tB. HTML");
    printf("\n\t\t\t\tC. c++");
    printf("\n\t\t\t\tD. URL   ");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'B':
        jikabenar();
        break;
    case 'A':
    case 'C':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q150:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q152;
            break;

        case 'B':
            goto q153;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q150;
        }

    q152:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 5    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.3,20,000/-");
        printf("\n\n\t\t\tWeb pages are written using");
        printf("\n\n\t\t\t\tA. FTPB");
        printf("\n\t\t\t\tB. HTML");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");

        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'B':
            jikabenar();
            break;
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q153;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q152;
        }
        break;
    }

    q153:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 5    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.3,20,000/-");
        printf("\n\n\t\t\tWeb pages are written using");
        printf("\n\n\t\t\t\tA. FTPB");
        printf("\n\t\t\t\tB. HTML");
        printf("\n\t\t\t\tC. c++");
        printf("\n\t\t\t\tD. URL   ");

        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tB. HTML");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'B':
            jikabenar();
            break;
        case 'A':
        case 'C':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q152;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q153;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q151;
    }
    }

    /*  QUESTION 6 */
q161:
    header();
    q1 = 6;
    printf("\n Pertanyaan no. 6");
    printf("\t\t\t\t\t\t\t\t\t\tRp.6,40,000/-");
    printf("\n\n\t\t\tWhich one of the following air pollution can affect blood stream leading to death ?");
    printf("\n\n\t\t\t\tA. Cadmium  ");
    printf("\n\t\t\t\tB. Asbestos dust  ");
    printf("\n\t\t\t\tC. Carbon monodioxide ");
    printf("\n\t\t\t\tD. Lead   ");

    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'C':
        jikabenar();
        break;
    case 'B':
    case 'A':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q160:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q162;
            break;

        case 'B':
            goto q163;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q160;
        }

    q162:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 6    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.6,40,000/-");
        printf("\n\n\t\t\tWhich one of the following air pollution can affect blood stream leading to death ?");
        printf("\n\n\t\t\t\t");
        printf("\n\t\t\t\tB. Asbestos dust  ");
        printf("\n\t\t\t\tC. Carbon monodioxide ");
        printf("\n\t\t\t\t ");

        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'B':
            jikasalah();
            break;
        case 'E':
            goto q163;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q162;
        }
        break;
    }

    q163:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 6    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.6,40,000/-");
        printf("\n\n\t\t\tWhich one of the following air pollution can affect blood stream leading to death ?");
        printf("\n\n\t\t\t\tA.  Cadmium  ");
        printf("\n\t\t\t\tB. Asbestos dust  ");
        printf("\n\t\t\t\tC. Carbon monodioxide ");
        printf("\n\t\t\t\tD. Lead   ");

        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tC. Carbon monodioxide");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'B':
        case 'A':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q162;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q163;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q161;
    }
    }

    /*  QUESTION 7 */

q171:
    header();
    q1 = 7;
    printf("\n Pertanyaan no. 7");
    printf("\t\t\t\t\t\t\t\t\t\tRp.12,50,000/-");
    printf("\n\n\t\t\t Out of the given countries which got independence on 15 August 1971 ?");
    printf("\n\n\t\t\t\tA.  Congoi  ");
    printf("\n\t\t\t\tB. Bahrain   ");
    printf("\n\t\t\t\tC.  Pakistan ");
    printf("\n\t\t\t\tD. India");

    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'B':
        jikabenar();
        break;
    case 'A':
    case 'C':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q170:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q172;
            break;

        case 'B':
            goto q173;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q170;
        }

    q172:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 7    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.12,50,000/-");
        printf("\n\n\t\t\t Out of the given countries which got independence on 15 August 1971 ?");
        printf("\n\n\t\t\t\tA.  Congoi  ");
        printf("\n\t\t\t\tB. Bahrain   ");
        printf("\n\t\t\t\tC. ");
        printf("\n\t\t\t\tD. ");

        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'B':
            jikabenar();
            break;
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q173;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q172;
        }
        break;
    }

    q173:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 7    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.12,50,000/-");
        printf("\n\n\t\t\t Out of the given countries which got independence on 15 August 1971 ?");
        printf("\n\n\t\t\t\tA.  Congoi  ");
        printf("\n\t\t\t\tB. Bahrain   ");
        printf("\n\t\t\t\tC.  Pakistan ");
        printf("\n\t\t\t\tD. India");

        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tB. Bahrain   ");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'B':
            jikabenar();
            break;
        case 'A':
        case 'C':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q172;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q173;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q171;
    }
    }

    /*  QUESTION 8 */

q181:
    header();
    q1 = 8;
    printf("\n Pertanyaan no. 8");
    printf("\t\t\t\t\t\t\t\t\t\tRp.25,00,000/-");
    printf("\n\n\t\t\tThe fiRpt mechanical computer designed by Charles Babbage was called what? ");
    printf("\n\n\t\t\t\tA. Analytical Engine  ");
    printf("\n\t\t\t\tB. Abacus  ");
    printf("\n\t\t\t\tC. Calculator");
    printf("\n\t\t\t\tD. Processor ");

    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }
    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'A':
        jikabenar();
        break;
    case 'B':
    case 'C':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q180:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q182;
            break;

        case 'B':
            goto q183;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q180;
        }

    q182:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 8    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.25,00,000/-");
        printf("\n\n\t\t\tThe fiRpt mechanical computer designed by Charles Babbage was called what? ");
        printf("\n\n\t\t\t\tA. Analytical Engine  ");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD. Processor ");

        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q183;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q182;
        }
        break;
    }

    q183:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 8    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.25,00,000/-");
        printf("\n\n\t\t\tThe fiRpt mechanical computer designed by Charles Babbage was called what? ");
        printf("\n\n\t\t\t\tA. Analytical Engine  ");
        printf("\n\t\t\t\tB. Abacus  ");
        printf("\n\t\t\t\tC. Calculator");
        printf("\n\t\t\t\tD. Processor ");

        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tA. Analytical Engine ");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'B':
        case 'C':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q182;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q183;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q181;
    }
    }

    /*  QUESTION 9 */
q191:
    header();
    q1 = 9;
    printf("\n Pertanyaan no. 9");
    printf("\t\t\t\t\t\t\t\t\t\tRp.50,00,000/-");
    printf("\n\n\t\t\t Who is the world�s second batsman to hit a double century in ODI cricket?");
    printf("\n\n\t\t\t\tA. Virendra Sehwag ");
    printf("\n\t\t\t\tB. Sachin Tendulkar  ");
    printf("\n\t\t\t\tC. Virat Kohli ");
    printf("\n\t\t\t\tD. Bryan Lara");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'A':
        jikabenar();
        break;
    case 'B':
    case 'C':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q190:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q192;
            break;

        case 'B':
            goto q193;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q190;
        }

    q192:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 9    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.50,00,000/-");
        printf("\n\n\t\t\t Who is the world�s second batsman to hit a double century in ODI cricket?");
        printf("\n\n\t\t\t\tA. Virendra Sehwag ");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tC. Virat Kohli ");
        printf("\n\t\t\t\t");

        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'C':
            jikasalah();
            break;
        case 'E':
            goto q193;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q192;
        }
        break;
    }

    q193:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 9    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.50,00,000/-");
        printf("\n\n\t\t\t Who is the world�s second batsman to hit a double century in ODI cricket?");
        printf("\n\n\t\t\t\tA. Virendra Sehwag ");
        printf("\n\t\t\t\tB. Sachin Tendulkar  ");
        printf("\n\t\t\t\tC. Virat Kohli ");
        printf("\n\t\t\t\tD. Bryan Lara");

        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tA. Virendra Sehwag ");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'B':
        case 'C':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q192;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q193;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q191;
    }
    }

    /*  QUESTION 10*/

q1101:
    header();
    q1 = 10;
    printf("\n Pertanyaan no. 10");
    printf("\t\t\t\t\t\t\t\t\t\tRp. 1 CRORE/-");
    printf("\n\n\t\t\t Where was Mughal empress Mumtaz Mahal originally buried in 1631 ?");
    printf("\n\n\t\t\t\t(A)  Agra  ");
    printf("\n\t\t\t\t(B) Burhanpur  ");
    printf("\n\t\t\t\t(C)  Gwalior");
    printf("\n\t\t\t\t(D) Lahore  ");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'B':
        jikabenar();
        break;
    case 'D':
    case 'C':
    case 'A':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q1100:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q1102;
            break;

        case 'B':
            goto q1103;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q1100;
        }

    q1102:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 10    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp. 1 CRORE/-");
        printf("\n\n\t\t\t Where was Mughal empress Mumtaz Mahal originally buried in 1631 ?");
        printf("\n\n\t\t\t\t");
        printf("\n\t\t\t\t(B) Burhanpur  ");
        printf("\n\t\t\t\t(C)  Gwalior");
        printf("\n\t\t\t\t");

        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'B':
            jikabenar();
            break;
        case 'C':
            jikasalah();
            break;
        case 'E':
            goto q1103;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q1102;
        }
        break;
    }

    q1103:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 10    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp. 1 CRORE/-");
        printf("\n\n\t\t\t Where was Mughal empress Mumtaz Mahal originally buried in 1631 ?");
        printf("\n\n\t\t\t\t(A)  Agra  ");
        printf("\n\t\t\t\t(B) Burhanpur  ");
        printf("\n\t\t\t\t(C)  Gwalior");
        printf("\n\t\t\t\t(D) Lahore  ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\t(B) Burhanpur");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'B':
            jikabenar();
            break;
        case 'D':
        case 'C':
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q1102;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q1103;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q1101;
    }
    }
    return;
}

void quiz3()
{
    char q, l;
    /*  QUESTION 1 */
    q1 = 1;
q111:
    header();
    printf("\n Pertanyaan no. 1");
    printf("\t\t\t\t\t\t\t\t\t\tRp.10,000/-");
    printf("\n\n\t\t\t1.Which of these artists was principally entrusted with the task of \n\t\t\t�illuminating� the original document of the Constitution of India?");
    printf("\n\n\t\t\t\tA.  Nandlal Bose ");
    printf("\n\t\t\t\tB.  Ram Kinker Baij");
    printf("\n\t\t\t\tC.  Benode Behari Mukherjee");
    printf("\n\t\t\t\tD.  Abanindranath Tagore");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'A':
        jikabenar();
        break;
    case 'B':
    case 'C':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q110:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q112;
            break;

        case 'B':
            goto q113;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q110;
        }

    q112:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 1    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.10,000/-");
        printf("\n\n\t\t\t1.Which of these artists was principally entrusted with the task of \n\t\t\t�illuminating� the original document of the Constitution of India?");
        printf("\n\n\t\t\t\tA.  Nandlal Bose ");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD.  Abanindranath Tagore");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q113;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q112;
        }
        break;
    }

    q113:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 1    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.10,000/-");
        printf("\n\n\t\t\t1.Which of these artists was principally entrusted with the task of \n\t\t\t�illuminating� the original document of the Constitution of India?");
        printf("\n\n\t\t\t\tA.  Nandlal Bose ");
        printf("\n\t\t\t\tB.  Ram Kinker Baij");
        printf("\n\t\t\t\tC.  Benode Behari Mukherjee");
        printf("\n\t\t\t\tD.  Abanindranath Tagore");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tA.  Nandlal Bose ");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'B':
        case 'C':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q112;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q113;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q111;
    }
    }

    /*  QUESTION 2 */

q121:
    header();
    q1 = 2;
    printf("\n Pertanyaan no. 2");
    printf("\t\t\t\t\t\t\t\t\t\tRp.80,000/-");
    printf("\n\n\t\t       ?");
    printf("\n\n\t\t\t\tA. Solicitor General");
    printf("\n\t\t\t\tB. Cabinet Secretary");
    printf("\n\t\t\t\tC. Attorney General  ");
    printf("\n\t\t\t\tD. Chief Justice");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'C':
        jikabenar();
        break;
    case 'B':
    case 'A':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q120:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q122;
            break;

        case 'B':
            goto q123;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q120;
        }

    q122:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 2    You are using life line 50:50");
        printf("\t\t\t\t\t\t\t\t\t\tRp.80,000/-");
        printf("\n\n\t\t       ?");
        printf("\n\n\t\t\t\t");
        printf("\n\t\t\t\tB. Cabinet Secretary");
        printf("\n\t\t\t\tC. Attorney General  ");
        printf("\n\t\t\t\t");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'B':
            jikasalah();
            break;
        case 'E':
            goto q123;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q122;
        }
        break;
    }

    q123:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 2    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.80,000/-");
        printf("\n\n\t\t\tWhom does the Indian Constitution permit to take part in the Proceedings of Parliament?");
        printf("\n\n\t\t\t\tA. Solicitor General");
        printf("\n\t\t\t\tB. Cabinet Secretary");
        printf("\n\t\t\t\tC. Attorney General  ");
        printf("\n\t\t\t\tD. Chief Justice");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tC. Attorney General ");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'B':
        case 'A':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q122;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q123;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q121;
    }
    }

    /*  QUESTION 3 */

q131:
    header();
    q1 = 3;
    printf("\n Pertanyaan no. 3");
    printf("\t\t\t\t\t\t\t\t\t\tRp.1,60,000/-");
    printf("\n\n\t\t\tWhich colonial power ended its involvement in India by selling the rights of \n\t\t\tthe Nicobar Islands to the British on October 18, 1868?");
    printf("\n\n\t\t\t\tA. Belgium");
    printf("\n\t\t\t\tB. Italy");
    printf("\n\t\t\t\tC. Denmark ");
    printf("\n\t\t\t\tD. France");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'C':
        jikabenar();
        break;
    case 'B':
    case 'A':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q130:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q132;
            break;

        case 'B':
            goto q133;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q130;
        }

    q132:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 1    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.1,60,000/-");
        printf("\n\n\t\t\tWhich colonial power ended its involvement in India by selling the rights of \n\t\t\tthe Nicobar Islands to the British on October 18, 1868?");
        printf("\n\n\t\t\t\tA. Belgium");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tC. Denmark ");
        printf("\n\t\t\t\t");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q133;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q132;
        }
        break;
    }

    q133:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 3    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.1,60,000/-");
        printf("\n\n\t\t\tWhich colonial power ended its involvement in India by selling the rights of \n\t\t\tthe Nicobar Islands to the British on October 18, 1868?");
        printf("\n\n\t\t\t\tA. Belgium");
        printf("\n\t\t\t\tB. Italy");
        printf("\n\t\t\t\tC. Denmark ");
        printf("\n\t\t\t\tD. France");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tC. Denmark");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'B':
        case 'A':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q132;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q133;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q131;
    }
    }

    /*  QUESTION 4 */

q141:
    header();
    q1 = 4;
    printf("\n Pertanyaan no. 4");
    printf("\t\t\t\t\t\t\t\t\t\tRp.2,50,000/-");
    printf("\n\n\t\t\tWho is the fiRpt woman to successfully climb K2, the world�s second highest mountain peak?");
    printf("\n\n\t\t\t\tA. Junko Tabei");
    printf("\n\t\t\t\tB. Tamae Watanabe");
    printf("\n\t\t\t\tC. Chantal Maudui");
    printf("\n\t\t\t\tD. Wanda Rutkiewicz ");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'D':
        jikabenar();
        break;
    case 'B':
    case 'C':
    case 'A':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q140:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q142;
            break;

        case 'B':
            goto q143;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q140;
        }

    q142:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 4    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.2,50,000/-");
        printf("\n\n\t\t\tWho is the fiRpt woman to successfully climb K2, the world�s second highest mountain peak?");
        printf("\n\n\t\t\t\tA. Junko Tabei");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD. Wanda Rutkiewicz ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'D':
            jikabenar();
            break;
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q143;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q142;
        }
        break;
    }

    q143:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 4    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.2,50,000/-");
        printf("\n\n\t\t\tWho is the fiRpt woman to successfully climb K2, the world�s second highest mountain peak?");
        printf("\n\n\t\t\t\tA. Junko Tabei");
        printf("\n\t\t\t\tB. Tamae Watanabe");
        printf("\n\t\t\t\tC. Chantal Maudui");
        printf("\n\t\t\t\tD. Wanda Rutkiewicz ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tD. Wanda Rutkiewicz ");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'D':
            jikabenar();
            break;
        case 'B':
        case 'C':
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q142;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q143;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q141;
    }
    }

/*  QUESTION 5 */
q151:
    header();
    q1 = 5;
    printf("\n Pertanyaan no. 5");
    printf("\t\t\t\t\t\t\t\t\t\tRp.3,20,000/-");
    printf("\n\n\t\t\tWho, in 1978, became the fiRpt peRpon to be born in the continent of Antarctica?");
    printf("\n\n\t\t\t\tA. James Weddell");
    printf("\n\t\t\t\tB. Emilio Palma");
    printf("\n\t\t\t\tC. Nathaniel Palmer");
    printf("\n\t\t\t\tD. Chales Wilkes");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'B':
        jikabenar();
        break;
    case 'A':
    case 'C':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q150:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q152;
            break;

        case 'B':
            goto q153;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q150;
        }

    q152:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 5    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.3,20,000/-");
        printf("\n\n\t\t\tWho, in 1978, became the fiRpt peRpon to be born in the continent of Antarctica?");
        printf("\n\n\t\t\t\tA. James Weddell");
        printf("\n\t\t\t\tB. Emilio Palma");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'B':
            jikabenar();
            break;
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q153;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q152;
        }
        break;
    }

    q153:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 5    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.3,20,000/-");
        printf("\n\n\t\t\tWho, in 1978, became the fiRpt peRpon to be born in the continent of Antarctica?");
        printf("\n\n\t\t\t\tA. James Weddell");
        printf("\n\t\t\t\tB. Emilio Palma");
        printf("\n\t\t\t\tC. Nathaniel Palmer");
        printf("\n\t\t\t\tD. Chales Wilkes");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tB. Emilio Palma");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'B':
            jikabenar();
            break;
        case 'A':
        case 'C':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q152;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q153;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q151;
    }
    }

    /*  QUESTION 6 */
q161:
    header();
    q1 = 6;
    printf("\n Pertanyaan no. 6");
    printf("\t\t\t\t\t\t\t\t\t\tRp.6,40,000/-");
    printf("\n\n\t\t\tWho commanded the �Hector�, the fiRpt British trading ship to land at Surat?");
    printf("\n\n\t\t\t\tA. Paul Canning ");
    printf("\n\t\t\t\tB. Thomas Roe ");
    printf("\n\t\t\t\tC. William Hawkins  ");
    printf("\n\t\t\t\tD. James Lancaster");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'C':
        jikabenar();
        break;
    case 'B':
    case 'A':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q160:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q162;
            break;

        case 'B':
            goto q163;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q160;
        }

    q162:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 6    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.6,40,000/-");
        printf("\n\n\t\t\tWho commanded the �Hector�, the fiRpt British trading ship to land at Surat?");
        printf("\n\n\t\t\t\t ");
        printf("\n\t\t\t\tB. Thomas Roe ");
        printf("\n\t\t\t\tC. William Hawkins  ");
        printf("\n\t\t\t\t");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'B':
            jikasalah();
            break;
        case 'E':
            goto q163;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q162;
        }
        break;
    }

    q163:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 6    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.6,40,000/-");
        printf("\n\n\t\t\tWho commanded the �Hector�, the fiRpt British trading ship to land at Surat?");
        printf("\n\n\t\t\t\tA. Paul Canning ");
        printf("\n\t\t\t\tB. Thomas Roe ");
        printf("\n\t\t\t\tC. William Hawkins  ");
        printf("\n\t\t\t\tD. James Lancaster");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tC. William Hawkins ");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'B':
        case 'A':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q162;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q163;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q161;
    }
    }

    /*  QUESTION 7 */

q171:
    header();
    q1 = 7;
    printf("\n Pertanyaan no. 7");
    printf("\t\t\t\t\t\t\t\t\t\tRp.12,50,000/-");
    printf("\n\n\t\t\tWhich of the following is NOT a pair of parent and child, who have both won Nobel Prizes?");
    printf("\n\n\t\t\t\tA. Marie Curie, Irene Joliot Curie  ");
    printf("\n\t\t\t\tB. Herman Emil Fischer, Hans Fischer  ");
    printf("\n\t\t\t\tC. JJ Thomson, George Paget Thomson");
    printf("\n\t\t\t\tD. Niels Bohr, Aage Bohr ");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'B':
        jikabenar();
        break;
    case 'A':
    case 'C':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q170:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q172;
            break;

        case 'B':
            goto q173;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q170;
        }

    q172:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 7    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.12,50,000/-");
        printf("\n\n\t\t\tWhich of the following is NOT a pair of parent and child, who have both won Nobel Prizes?");
        printf("\n\n\t\t\t\tA. Marie Curie, Irene Joliot Curie  ");
        printf("\n\t\t\t\tB. Herman Emil Fischer, Hans Fischer  ");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'B':
            jikabenar();
            break;
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q173;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q172;
        }
        break;
    }

    q173:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 7    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.12,50,000/-");
        printf("\n\n\t\t\tWhich of the following is NOT a pair of parent and child, who have both won Nobel Prizes?");
        printf("\n\n\t\t\t\tA. Marie Curie, Irene Joliot Curie  ");
        printf("\n\t\t\t\tB. Herman Emil Fischer, Hans Fischer  ");
        printf("\n\t\t\t\tC. JJ Thomson, George Paget Thomson");
        printf("\n\t\t\t\tD. Niels Bohr, Aage Bohr ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tB. Herman Emil Fischer, Hans Fischer ");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'B':
            jikabenar();
            break;
        case 'A':
        case 'C':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q172;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q173;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q171;
    }
    }

    /*  QUESTION 8 */

q181:
    header();
    q1 = 8;
    printf("\n Pertanyaan no. 8");
    printf("\t\t\t\t\t\t\t\t\t\tRp.25,00,000/-");
    printf("\n\n\t\t\tWho became fiRpt sportspeRpon to be honoured with Rajiv Gandhi Khel Ratna award?");
    printf("\n\n\t\t\t\tA. Vishwanathan Anand ");
    printf("\n\t\t\t\tB. Sachin Tendulkar  ");
    printf("\n\t\t\t\tC. Geet Sethi");
    printf("\n\t\t\t\tD. Leande ");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'A':
        jikabenar();
        break;
    case 'B':
    case 'C':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q180:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q182;
            break;

        case 'B':
            goto q183;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q180;
        }

    q182:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 8    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.25,00,000/-");
        printf("\n\n\t\t\tWho became fiRpt sportspeRpon to be honoured with Rajiv Gandhi Khel Ratna award?");
        printf("\n\n\t\t\t\tA. Vishwanathan Anand ");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD. Leande ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q183;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q182;
        }
        break;
    }

    q183:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 8    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.25,00,000/-");
        printf("\n\n\t\t\tWho became fiRpt sportspeRpon to be honoured with Rajiv Gandhi Khel Ratna award?");
        printf("\n\n\t\t\t\tA. Vishwanathan Anand ");
        printf("\n\t\t\t\tB. Sachin Tendulkar  ");
        printf("\n\t\t\t\tC. Geet Sethi");
        printf("\n\t\t\t\tD. Leande ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tA. Vishwanathan Anand ");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'B':
        case 'C':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q182;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q183;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q181;
    }
    }

    /*  QUESTION 9 */
q191:
    header();
    q1 = 9;
    printf("\n Pertanyaan no. 9");
    printf("\t\t\t\t\t\t\t\t\t\tRp.50,00,000/-");
    printf("\n\n\t\t\t How long was the Mesozoic Era?");
    printf("\n\n\t\t\t\tA. 185 million yeaRp ");
    printf("\n\t\t\t\tB. 400 million yeaRp");
    printf("\n\t\t\t\tC. 250 million yeaRp");
    printf("\n\t\t\t\tD. 65 million yeaRp");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'A':
        jikabenar();
        break;
    case 'B':
    case 'C':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q190:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q192;
            break;

        case 'B':
            goto q193;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q190;
        }

    q192:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 9    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.50,00,000/-");
        printf("\n\n\t\t\t How long was the Mesozoic Era?");
        printf("\n\n\t\t\t\tA. 185 million yeaRp ");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tC. 250 million yeaRp");
        printf("\n\t\t\t\t");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'C':
            jikasalah();
            break;
        case 'E':
            goto q193;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q192;
        }
        break;
    }

    q193:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 9    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.50,00,000/-");
        printf("\n\n\t\t\t How long was the Mesozoic Era?");
        printf("\n\n\t\t\t\tA. 185 million yeaRp ");
        printf("\n\t\t\t\tB. 400 million yeaRp");
        printf("\n\t\t\t\tC. 250 million yeaRp");
        printf("\n\t\t\t\tD. 65 million yeaRp");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tA. 185 million yeaRp ");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'B':
        case 'C':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q192;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q193;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q191;
    }
    }

    /*  QUESTION 10*/

q1101:
    header();
    q1 = 10;
    printf("\n Pertanyaan no. 10");
    printf("\t\t\t\t\t\t\t\t\t\tRp. 1 CRORE/-");
    printf("\n\n\t\t\tWhich of the following forts was not built by the European colonial poweRp in India?");
    printf("\n\n\t\t\t\tA. Fort Dansborg");
    printf("\n\t\t\t\tB. Fort Naarden");
    printf("\n\t\t\t\tC. Fort Santa Katherina");
    printf("\n\t\t\t\tD. Fort Chambray ");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Use Life line");
    }

    printf("\n\n\t\t\t\tF. keluar Game");
    printf("\n\n\t\t\t\t Enter your choice >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'D':
        jikabenar();
        break;
    case 'B':
    case 'C':
    case 'A':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q1100:
        printf("\n\n\t\t\t\t Choose Your Life Line:");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Expert Advice");
        printf("\n\n\t\t\t\t\tEnter your choice >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q1102;
            break;

        case 'B':
            goto q1103;
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q1100;
        }

    q1102:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 10    You are using life line 50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp. 1 CRORE/-");
        printf("\n\n\t\t\tWhich of the following forts was not built by the European colonial poweRp in India?");
        printf("\n\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tC. Fort Santa Katherina");
        printf("\n\t\t\t\tD. Fort Chambray ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: \n\n\t\t\t\tExpert Advice");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'D':
            jikabenar();
            break;
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q1103;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nEnter any valid choice");
            getch();
            goto q1102;
        }
        break;
    }

    q1103:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 10    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp. 1 CRORE/-");
        printf("\n\n\t\t\tWhich of the following forts was not built by the European colonial poweRp in India?");
        printf("\n\n\t\t\t\tA. Fort Dansborg");
        printf("\n\t\t\t\tB. Fort Naarden");
        printf("\n\t\t\t\tC. Fort Santa Katherina");
        printf("\n\t\t\t\tD. Fort Chambray ");
        ;
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Use Life line: 50:50");
        }

        printf("\n\n\t\t\t\tF. keluar Game");
        printf("\n\n\t\t\t\t Expert Advices: \n\t\t\t\tD. Fort Chambray ");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'D':
            jikabenar();
            break;
        case 'B':
        case 'C':
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q1102;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nEnter any valid choice");
            getch();
            goto q1103;
        }
    }
    break;
    default:
        printf("\nEnter any valid choice");
        getch();
        goto q1101;
    }
    }
    return;
}

/*
 JAWABAN:
 1: A
 2: C
 3: C
 4: D
 5: B
 6: C
 7: B
 8: A
 9: A
10: D
*/
