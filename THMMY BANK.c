#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h> //�������




// �������
#define BLACK            0
#define BLUE            1
#define GREEN            2
#define CYAN            3
#define RED            4
#define MAGENTA        5
#define BROWN            6
#define LIGHTGRAY        7
#define DARKGRAY        8
#define LIGHTBLUE        9
#define LIGHTGREEN    10
#define LIGHTCYAN        11
#define LIGHTRED        12
#define LIGHTMAGENTA    13
#define YELLOW        14
#define WHITE            15
#define MAX 1000 //������� ���� ��������,���������,��������� ��������

struct stoixeia { //������ ���� ��� �������� �� �������� ��� ������
char onoma[50];
char epitheto[50];
char username[50];
unsigned long int AFM;
char IBAN[28];
char BBAN[24]; // Basic Bank Account Number, ��������������� ��� �� ���������� ��� IBAN
long int ARITHMOSLOG; // ������� �����������, ��������� ��� ���� ������, �� 8 �����.
                        // ������� ������� �� long int ���� ��� long long int, ����� �� codeblocks ����������� �������� �� �� long long int.
char ARITHMOS_LOGARIASMOY_ARR[17]; //������� ����������� ���� �� ���������, ���� �� ������ �� ������� print.
int PIN; // Personal Identification Number, ����������� ������� ��� ������
float ypoloipo;

}user;

struct synallages { //���� ��� ������ ����������, ���������

long int ARITHMOSLOG;
float poso;
char date_time[100];
char parathrhseis[200]; //������� ������������ �� ���, ����������, ��������� ���������
}synallagh;




struct stoixeia eggrafh(); // ������� ���� ����������� ���� �������
void syndesh(); //������� �� ��� ������� ����������
struct synallages katathesi(long int ARITHMOSLOG,float poso,struct stoixeia user,FILE *file); //�������� ���������� �����
struct synallages analipsi(long int ARITHMOSLOG,float poso,struct stoixeia user,FILE *file);  //������� ���������� �����
void epiloges(long int ARITHMOSLOG,struct stoixeia user,FILE *file); // ����� �� ��� �������� ��� ���� � ������� ���� ������������� ������� �� ����������
struct synallages metafora (long int ARITHMOSLOG,struct stoixeia user, FILE *file); // �������� ���������� ����� ��� ���� ���������� �� �����
void delay(int number_of_seconds); // ��������������� �� ��������� �� �� ���������� <time.h> ��� �� ��������� ������� �����������
                                   // ���� ��� ������ ������������ ����������� �������� �� ���� ����������.

void process(){
//  ������ ��������� ��� ������ �� ���������. ��� ���������� ������ ����, ���� ������� �����������.
system("cls");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); // ������ �������� �� �����

printf("----------------------------THMMY BANK----------------------------\n");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //������ �������� �� �����

printf("\n ������� ����������� <1>\n ������� ����������� <2>");


char c;
    first: printf("\n �������������� ��� ������� ���: ");
    int choice1;
    scanf("%d",&choice1);
    while ( (c = getchar())!='\n' && c!=EOF);
    switch (choice1)
   {
     case 1:
       printf("\n ��������� ������� �����������");
       eggrafh();
       break;
     case 2:
       printf("\n ��������� ������� �����������");
       syndesh();
       break;
     default:
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);// ������� �����
     printf("\n ����� �������, �������� ����\n");
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ����� �����
     goto first;

}
}




struct stoixeia eggrafh(){
// ��������� ���� ������ �� ����� ������� ���� ���� ����������� ��� �������.
// ���������� ��� ������������� ��� ����� struct stoixeia ��� ��� ������� �����������.
FILE *file1;
char c;
srand(time(0)); //�������� � srand �� seed ��� �������� ���, �� ����� �� ���������� ������� ������� ��� ��������
system("cls");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
printf("----------------------------THMMY BANK----------------------------\n");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
printf("�������� �� ����� ���:");
scanf("%s", user.onoma);
while ( (c = getchar())!='\n' && c!=EOF); // � ������������ ������� �� �� getchar ��� ��������� �� "�����������" �� buffer ��� ���������� ��� flush

printf("\n�������� �� ������� ���:");
scanf("%s", user.epitheto);
while ( (c = getchar())!='\n' && c!=EOF);

printf("\n�������� ����� ������:");
scanf("%s", user.username);
while ( (c = getchar())!='\n' && c!=EOF);


while (1) {
printf("\n�������� �� ��� ���(9 �����):");
scanf("%lu", &user.AFM);
while ( (c = getchar())!='\n' && c!=EOF);
int digits = log10(user.AFM) + 1; // ����������� ����� ��� ��� ������ ������ ���� �������. ������� ���� �� ������������ ���� ������� �� 9 ����� ��� ���� ��� ���.
if (digits==9)
    break;
else {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("���������� ��������,����������� ����:");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}

}
user.PIN = 1000+(rand()%9000); // ���������� ������� ����������� �������. ����� ����������� ��� �� rand()%10000, ����� �� rand()%10000 ��� �������� ���� ����������, ��������� ��� ����������� ��������

user.BBAN[0] = 6; user.BBAN[1] = 9; user.BBAN[2] = 6;                   // ���� ������ ������ ����������� ������ �� ���� ����� ����� ��� ��� ������ ��� ��������,
user.BBAN[3] = 2; user.BBAN[4] = 0; user.BBAN[5] = 0; user.BBAN[6]= 4;  // �� ������� ������� ��� ��� ������ ��� ������������ ���
                                                                        // 16 ��������� �����, �� ��������� 8 �� ��� ������ ��������� ��� ������ �����������
                                                                        // ��� THMMY BANK �������� ��� ������ ��� �������� "696" ��� ��� ������ ��� ������������ "2004"
                                                                        // ������ ��� ������ �������� �� ��������� �� ��� �����������. �� �������� ����� ������� ��� ����� ���� �������

for (int i=7;i<23;i++) user.BBAN[i] = rand()%10; //�� 8 ��������� ����� ��������� ��� ������ ����������� ��� ������, � ������ ��� ��������� �� �������� ���� ���������� ���
                                                //�� ��������� �� �� PIN
user.ARITHMOSLOG=0;
user.IBAN[0]='G'; user.IBAN[1] = 'R';            //�� ��� ������ ����������� ���������� ��� IBAN ������������� �� ���� (GR) ��� �� �������� 2 ����� ����� ������� (���������� �� 77)
user.IBAN[2]=7; user.IBAN[3]=7;
for (int k=4;k<27;k++)
    user.IBAN[k] = user.BBAN[k-4];              // �� ��������� ����� ��� IBAN(22 ��������� �����) ����� �� BBAN, �� ����� ���� ������������ ��� ����
for (int i=15;i<23;i++)
    user.ARITHMOS_LOGARIASMOY_ARR[i-15] = user.BBAN[i]; // � ������� ����������� ������ ����� �� 8 ��������� ����� ��� BBAN.
for (int i=0;i<8;i++)
    user.ARITHMOSLOG = 10*user.ARITHMOSLOG + user.ARITHMOS_LOGARIASMOY_ARR[i]; //���������� ��� �� ��������� ��� ARITHMOS_LOGARIASMOY_ARR (��� ����� ���������� ���������) ��� user.ARITHMOSLOG
                                                                               // ��� ����� long int. ���� �� "�����" ��� ��������� �� ������������ ��� �������� ��� codeblocks
                                                                               // �� �������� �� long long int ��������.
file1 = fopen("stoixeia.dat", "a+b"); //��������� �� ������ �� �� �������� ��� �������, �� mode append to binary ���� �� ����������� �� ��� ������������� ����� ��� ������.
user.ypoloipo = 0;
fwrite(&user,sizeof(struct stoixeia), 1,file1); // �������� �� ��� ������������� ����� ��� ������ (������ �� �������� ��� ���� ������ ���).


if ( (file1!=NULL) ) {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);// ������� �����
    printf("\n�������� ���������� �����������!");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    printf("\n� ���������� ������� ��� ������������ (PIN): %d", user.PIN);

    printf("\n� ������� ����������� ���: ");
    printf("%ld", user.ARITHMOSLOG);

    printf("\n� ������� IBAN ���: ");
    for (int i =0;i<2;i++)
    printf("%c", user.IBAN[i]);
    for (int i=2;i<27;i++)
    printf("%d", user.IBAN[i]);

    printf("\n�������� �����������: %.2f",user.ypoloipo);





        }



else {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("\n������������� ��������. �������� ����������� ����.");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

    int newchoice;
    begin:printf("\n�� �� ������ �� ������; [�����]=1, [��������]=2\n");
    scanf("%d", &newchoice);

    switch (newchoice){

    case 1:
    fclose(file1);
    process();
    break;

    case 2:
    fclose(file1);
    break;

    default:
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("\n���������� �������, ����������� ����.");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    goto begin;
    break;


        }


fclose(file1);

return user;




}
void delay(int number_of_seconds){
// � ������������ ��������� ��������� ������� ����������� ���� ��� �������� ��� �������� �������.
// ������� �� ��������� ��� ������ ��� ������������� ��� ���������� �� ������������ �� ���������
// ���� �������� ��� ������� ������. ���������� ����

int milli_seconds = 1000 * number_of_seconds; // ��������� �� milliseconds

clock_t start_time = clock(); // ������ ��� ������

while (clock() < start_time + milli_seconds); // ������������� ������, ����� break ���� ������� � ������ ��� ������ ����� �� ��������� ��� ����������.


}

void syndesh(){
// ��������� ��� ������� �� ��� ������� ���������� ��� ��������.
// ���������� ����, �� ������� ��������.
int pin,cnt=0;
int j=0;
long int ARITHMOS;


FILE *file;
char username[50];
int choice2;
char c;
login:system("cls");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
printf("----------------------------THMMY BANK----------------------------\n\n");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
printf("������� ��������:\n");                 // � ������� ���� ��� ������� ��������:
                                                //1. �� ��������� username & pin, 2. �� ��������� ������� ����������� & pin.
printf("����� ������ ��� PIN <1>\n");
printf("������� ����������� ��� PIN <2>\n");
printf("��������: ");
scanf("%d", &choice2);
while ( (c = getchar())!='\n' && c!=EOF);
system("cls");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
printf("----------------------------THMMY BANK----------------------------\n\n");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
switch (choice2){

case 1: // ������� �� ��������� username, pin
    first:

        if (cnt>=3) { //���� ���� ��� � ������� ����� ����� �������, � ��������� cnt ��������� ���� 1. (�������� ��� �� 0)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("\n���������� �� ���� ��� ������������ �����������."); //���� ��� 3 ������������ �����������, � ������� ������ �� ��������� 10 ������������ ����
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ����������� ���� �� ��������, ��� ������ ���������.
            printf("\n����������� ���������� 10 ������������:");
            for (int x=10;x>0;x--){
                delay(1);               //��� ���������� � ��������� delay, � ����� ����������� ����������� 1 ������������� ����� ������������ �� ������� ��� �� 10 ��� ��� �� 1.
                printf("%d ", x);}
            putchar('\n');
            cnt=0;}



    printf("����� ������: ");
    scanf("%s", username);
    while ( (c = getchar())!='\n' && c!=EOF);

    printf("\n������� PIN: ");
    scanf("%d", &pin);
    while ( (c = getchar())!='\n' && c!=EOF);

    file = fopen("stoixeia.dat","r+b");








    if(file!=NULL){
        while(!feof(file)){
            if (fread(&user, sizeof(struct stoixeia),1,file) == 1 && strcmp(user.username,username)==0 && user.PIN==pin) {
            //� �������� ������ ������� �� ���������� ��� �� ������������� ����� ��� �������� ��� ������ �� �� �������� ��� �������
            // ����� �� ������ ������ ������������� ��� ���������� ��� ��������� username ��� PIN ��� ����� � �������.
            // ���� ������ ����������� �� ���������� username ��� PIN, � ������� ��������� ��� ������������ ��� ����� ��� ��������.
                printf("�������� �������!\n");
                epiloges(user.ARITHMOSLOG,user,file);
                j=1;
                break;
                }



    }

    if (j!=1) { //�� ��������� �� ��������� ��������, � ������� �������� �� ��������� �� �������� ��� ����������� ���.
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("\n� ������� ��� �����������, ����������� ����.\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            fclose(file);
            cnt++; // ������ ��� cnt ���� 1. ���� ������ �� 3, ���� ������ ����, �������� ��� � ������� �� ������ �� ��������� ���� ������������� �� ��������.
            goto first; }

    }


fclose(file);
break;


case 2: // �������� �� ��������� ������� ����������� ��� PIN.
    prwto: if (cnt>=3) { //����� �� �� case 1
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                printf("\n���������� �� ���� ��� ������������ �����������.");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                printf("\n����������� ���������� 10 ������������:");
                for (int x=10;x>0;x--){
                    delay(1);
                    printf("%d ", x);}
                putchar('\n');
                cnt=0;}


    printf("������� �����������: ");
    scanf("%ld", &ARITHMOS);
    while ( (c = getchar())!='\n' && c!=EOF);
    printf("\n������� PIN: ");
    scanf("%d", &pin);
    while ( (c = getchar())!='\n' && c!=EOF);
    file = fopen("stoixeia.dat","r+b");

    if(file!=NULL){
        while(!feof(file)){
            if (fread(&user, sizeof(struct stoixeia),1,file)==1 &&  ARITHMOS==user.ARITHMOSLOG && user.PIN==pin) {
                // ����� �� �� case 1, ������ ���� ��� username ����� ���������� �� ��� 8����� ������ �����������.
                printf("�������� �������!\n");
                epiloges(user.ARITHMOSLOG,user,file);
                j=1;
                break;}}

     if (j!=1) { //�� �������� �������
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("\n� ������� ��� �����������, ����������� ����.\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            cnt++;
            fclose(file);
            goto prwto; }

    }





    fclose(file);
    break;

default: // �� ��������� ��� � ������� ��� �������� ���� ������� ���� �������
    goto login;
    break;
}


}

struct synallages katathesi(long int ARITHMOSLOG,float poso,struct stoixeia user,FILE *file){
// ��������� ��� ��� �������� ���������� �����.
// ������� �� ����������� ��� ������ ����������� ��� ������, �� ���� ���������, ������������ ��� ����� struct stoixeia, ��� �� ������ �� �� ��������.
// ���������� ��� ������������� ��� ����� struct synallages, � ����� �������� ����������� ��� ��� ��������� ���������� ��� ������



FILE *file2;
fclose(file);

fopen("stoixeia.dat","r+b");

while(!feof(file)){
            if (fread(&user, sizeof(struct stoixeia),1,file) == 1 && ARITHMOSLOG == user.ARITHMOSLOG) {
                // � ��������� fread ��������� ��� ������ ��� file ��� ����� ��� �������������� ��� ����� ��� ��������.
                // ����� ������� �� �������������� �� �������� ��� ������, �� ����� �������� �� ��������� ����� ��� ����� ���
                // ��� ���� sizeof(user.ypoloipo) = sizeof(float) = 4.
                fseek(file,-4,SEEK_CUR);
                //��� �� �� ������� ��� fseek ����������� ��� ������ ��� file 4 byte ��� ��������, ���� ��� �������� �� �������������� �� �������� ��� ������.
                time_t t = time(NULL); // ������ ��� clock

                user.ypoloipo = user.ypoloipo + poso;
                fwrite(&user.ypoloipo, sizeof(user.ypoloipo), 1,file);
                // �������� �� ��� ���� ��� user.ypoloipo ��� ���� ��� ����� � ������� ��� file.

                synallagh.ARITHMOSLOG = user.ARITHMOSLOG; // ����������� ��� ������������� ��� ����� ���������� ��� ����������� ��� �� �������� ���������
                synallagh.poso = poso;
                strcpy(synallagh.date_time,ctime(&t)); // �� ctime(&t) �� ��������� �� �� time_t t = time(NULL) ������������� ��� ���������� ��� ��� ��� ��� ����� � ���������.
                sprintf(synallagh.parathrhseis, "\n����� �������� %.2f ���� ���� ������ %s ���� %s.",poso,user.username,ctime(&t));
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // ������� �����
                puts(synallagh.parathrhseis);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                printf("��� �������� ��� ������ %s: %.2f\n",user.username,user.ypoloipo);

                file2 = fopen("katatheseis.dat", "a+b");
                fwrite(&synallagh,sizeof(struct synallages), 1,file2);

                fclose(file2);
                fclose(file);
                break; }}


return synallagh;
}

struct synallages analipsi(long int ARITHMOSLOG,float poso,struct stoixeia user,FILE *file){
//��������� ��� ��� ������� ���������� �����.
// ���� ��� � ��������� ���������, ������� �� ����������� ��� ������ ����������� ��� ������, �� ���� ��������, ������������ ��� ����� struct stoixeia, ��� �� ������ �� �� ��������.
// ���������� ��� ������������� ����� ��� ���� struct synallages.
FILE *file3;

fclose(file);
float poso_analipsis;

fopen("stoixeia.dat","r+b");
while(!feof(file)){
            if (fread(&user, sizeof(struct stoixeia),1,file) == 1 && ARITHMOSLOG == user.ARITHMOSLOG) {

fseek(file,-4,SEEK_CUR); //����� ������� �� ��� ��������

if (poso>=user.ypoloipo){ //���� ��������� ��� �� ���� �������� ����� ���������� ��� �� ��������, � ������� ����� ������� �,�� ��������� ���� ���� ������ ��� �������� ���.

poso_analipsis = user.ypoloipo;
user.ypoloipo = 0;
fwrite(&user.ypoloipo, sizeof(user.ypoloipo), 1,file);

time_t t = time(NULL);
synallagh.ARITHMOSLOG = user.ARITHMOSLOG;
synallagh.poso = poso;
strcpy(synallagh.date_time,ctime(&t));


sprintf(synallagh.parathrhseis, "\n����� ������� %.2f ���� ��� ��� ������ %s ���� %s",poso_analipsis,user.username,ctime(&t));
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // ������� �����
puts(synallagh.parathrhseis);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
printf("��� �������� ��� ������ %s: %.2f\n", user.username,user.ypoloipo);

file3 = fopen("analipseis.dat", "a+b");
fwrite(&synallagh,sizeof(struct synallages), 1,file3);

fclose(file3);
fclose(file);

return synallagh;


}
else { // ���� ��������� ��� �� ���� �������� ����� ��������� ��� �� ��������, ���� ����� �� ���� ���������� ��� �� �������� ��� ������.

user.ypoloipo = user.ypoloipo - poso;
fwrite(&user.ypoloipo, sizeof(user.ypoloipo), 1,file);

time_t t = time(NULL);
synallagh.ARITHMOSLOG = user.ARITHMOSLOG;
synallagh.poso = poso;
strcpy(synallagh.date_time,ctime(&t));

sprintf(synallagh.parathrhseis, "\n����� ������� %.2f ���� ��� ��� ������ %s ���� %s",poso,user.username,ctime(&t));
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
puts(synallagh.parathrhseis);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

printf("��� �������� ��� ������ %s: %.2f\n",user.username,user.ypoloipo);

file3 = fopen("analipseis.dat", "a+b");
fwrite(&synallagh,sizeof(struct synallages), 1,file3);

fclose(file3);
fclose(file);


break;
}

return synallagh;}}

return synallagh;
}

struct synallages metafora (long int ARITHMOSLOG,struct stoixeia user, FILE *file){
// ��������� ��� �� �������� �������� ��� ���� ������ � �� ���� ������ �.
// �� ����������� ������� ��� ������ ����������� ��� ������ �, ��� ������������� �� ������ struct stoixeia, ��� �� ������ �� �� ��������.
// ���������� ��� ������������� ����� ��� struct synallages.

long int arithmos2; // ������� ����������� ��� ������ �
float poso;
int temp=0;
float temp1;

while(!feof(file)){
            if (fread(&user, sizeof(struct stoixeia),1,file) == 1 && ARITHMOSLOG == user.ARITHMOSLOG){
                temp1 = user.ypoloipo;}}

afetiria:printf("\n�������������� ��� ������ ����������� ��� ������ ���� ������ �� ����� � ��������: "); // � ���������� ������ ��� ��� ����������� ������� �� �� ������� ��� ������� �����������.
scanf("%ld", &arithmos2);

fclose(file);
file = fopen("stoixeia.dat","r+b");

while(!feof(file)){
            if (fread(&user, sizeof(struct stoixeia),1,file) == 1 && arithmos2 == user.ARITHMOSLOG) // ��������� �� � arithmos2 �������� ����������� �� ������� ����������.
                temp=1;
                }
if (temp!=1) { // �� ��������� ��� ��� ����������� �� ������� ����������, � ������� �������� �� ������� �� ���� ����� ������ �����������.
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("� ������������� ������� ����������� ��� ����������� �� ������� ������.");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    goto afetiria;}

else {
while (1) {
printf("\n�������������� �� ��������� ���� ���������: ");
scanf("%f", &poso);

 if (poso>MAX) { // �� ���, ������ ������� ���� ��������,��������� ��� ��������� �������� ������ ������ ��� ������ 1000.
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("�������! ������� ���� ���������: 1000 ����.");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    else if (poso>0 && poso<=MAX) break; // �� �� ���� ����� ������ ��� ���� ��� 1000, ���� ����� � ������������� ������.
   else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("\n���������� ��������");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}
}


fclose(file);


if (poso>temp1){ //��� temp1 ������ ����������� �� �������� ��� ������ ������. �� �� ���� ��������� ����� ���������� ��� �� �������� ��� ������ ������
                 // ���� ������� ������� ����� ��� ��� ����� ������ ��� �� �� �������� ���, ��� �������� ����� ���� ������� ������.
    analipsi(ARITHMOSLOG,temp1,user,file);
    katathesi(arithmos2,temp1,user,file);}
else { //������, ������� ������� ��� ����� ��� ��� ����� ������ ��� �������� ����� ���� �������. (��� ���� ���������)
    analipsi(ARITHMOSLOG,poso,user,file);
    katathesi(arithmos2,poso,user,file); }

fclose(file);

return synallagh;

}}


void epiloges(long int ARITHMOSLOG,struct stoixeia user,FILE *file){
// ��������� ��� ��������� �� ����� �������� ��� ������, ������ ����� �������� ���� ���������� ���.
// � ������� ���� ������ 6 ��������, �� ������ ������������ ��������.
// ������� �� ����������� ��� ������ ����������� ��� ������, �� ������������� ��� ������ ��� ���� struct stoixeia ��� �� ������ �� �� ��������.
// ���������� ����.
arxh:system("cls"); // ���������� ������
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
printf("----------------------------THMMY BANK----------------------------\n\n");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

// ������ ��������
printf("\n������� �������� <1>\n");
printf("�������� �������� <2>\n");
printf("�������� �������� <3>\n");
printf("������� ��������� ����������� <4>\n");
printf("������� ������� ����������� <5>\n");
printf("������ ������� PIN <6>\n");
printf("�������� ��� ��������� ����������:");
float poso;
int choice3,i;
char c;

scanf("%d", &choice3);
while ( (c = getchar())!='\n' && c!=EOF);


switch(choice3){

case 1: // ������� ���������� �����
    while (1){
    printf("\n�������������� �� ��������� ���� ��������: ");
    scanf("%f", &poso);

    if (poso>MAX) { // ������� �� �� ���� ����� ���� ��� ���� ���
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("�������! ������� ���� ��������: 1000 ����.");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    else if (poso>0 && poso<=MAX) break;
    else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("\n���������� ��������");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}
}

    analipsi(ARITHMOSLOG,poso,user,file);
    fseek(file,4,SEEK_CUR);

    i=0;
    while(i!=2 && i!=1 && i!=3){
    printf("\n�� �� ������ �� ������; [��������]=1, [����������]=2, [��������]=3\n"); // ������������� ������ ��� ��������� ���� ������ �� ��������� �� ����� ��� ���
    scanf("%d", &i);                                                                  // ������ ��� ��� ���������� ��� ����������.
    if (i==3)
        break;
    else if (i==2)
            process();
    else if(i==1)
        goto arxh;
    else
        {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("\n���������� ��������");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}
}

    break;
case 2: // �������� ��������
    while (1){
    printf("\n�������������� �� ���� ��� �� ����������: ");
    scanf("%f", &poso);

     if (poso>MAX) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("�������! ������� ���� ���������: 1000 ����.");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    else if (poso>0 && poso<=MAX) break;

    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("\n���������� ��������");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}
}
    katathesi(ARITHMOSLOG,poso,user,file);
    fseek(file,4,SEEK_CUR);

    i=0;
    while(i!=2 && i!=1 && i!=3){
    printf("\n�� �� ������ �� ������; [��������]=1, [����������]=2, [��������]=3\n");
    // ������������� ������ ��� ��������� ���� ������ �� ��������� �� ����� ��� ���
    // ������ ��� ��� ���������� ��� ����������.
    scanf("%d", &i);
    if (i==3)
        break;
    else if (i==2)
            process();
    else if(i==1)
        goto arxh;
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("\n���������� ��������");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}
}

    break;
case 3://�������� ��������
    file = fopen("stoixeia.dat","r+b");
    metafora(ARITHMOSLOG,user,file);
    i=0;
    while(i!=2 && i!=1 && i!=3){
    printf("\n�� �� ������ �� ������; [��������]=1, [����������]=2, [��������]=3\n");
    scanf("%d", &i);
    if (i==3)
        break;
    else if (i==2)
            process();
    else if(i==1)
        goto arxh;
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("\n���������� ��������");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}}
    break;
case 4:// ������� ���������
    fclose(file);

    fopen("stoixeia.dat","r+b");

   while(!feof(file)){
            if (fread(&user, sizeof(struct stoixeia),1,file) == 1 && ARITHMOSLOG == user.ARITHMOSLOG){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                printf("��������� �������� ��� ������ %s: %.2f", user.username, user.ypoloipo);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    //������� ��� ������� stoixeia.dat ����� �� ���������� ������������ ����� �� ����� ��� ������ ����������� ��� ��������� ������
    //(� ������ ���� �������� �� ���������� ��� ��������� epiloges)
                i=0;
                while(i!=2 && i!=1 && i!=3){
                printf("\n�� �� ������ �� ������; [��������]=1, [����������]=2, [��������]=3\n");
                scanf("%d", &i);
                if (i==3)
                    break;
                else if (i==2)
                    process();
                else if(i==1)
                    goto arxh;
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("\n���������� ��������");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}


                break;}}}
    fclose(file);
    break;
case 5://������� ������� ����������� ������, ���� ��������� ��� � ����� ��� ��� �������.
        //�������, ������, �� ��������� � ������� ���� ����������
    fclose(file);
    fopen("stoixeia.dat","r+b");


    while(!feof(file)){
            if (fread(&user, sizeof(struct stoixeia),1,file) == 1 && ARITHMOSLOG == user.ARITHMOSLOG){
                printf("��������� 8-������ ������� ����������� ��� ������ %s: %ld ", user.username, user.ARITHMOSLOG);
                i=0;
                while(i!=2 && i!=1 && i!=3){
                printf("\n�� �� ������ �� ������; [��������]=1, [����������]=2, [��������]=3\n");
                scanf("%d", &i);
                if (i==3)
                    break;
                else if (i==2)
                    process();
                else if(i==1)
                    goto arxh;
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("\n���������� ��������");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}

                break;}}}
    fclose(file);
    break;
case 6:;
    //���������� ������� ��� PIN.
    //�������, ��� ������ ���������, � ������� �� ������� �� ����� ������ ��� �� ��������� �� ��� ������ �����������
    //���� ������ �� �������� ��������� PIN.

    long int num;
    char name[50];
    int found=0,newpin,digits;
    char c;
    first: fclose(file);
    fopen("stoixeia.dat","r+b");
     printf("\n��� ������ ���������, ����������� �������� �� ����� ������ ��� ��� ������ ����������� ���:");
    printf("\n����� ������:");
    scanf("%s", name);
    while ( (c = getchar())!='\n' && c!=EOF);

    printf("������� �����������:");
    scanf("%ld", &num);
    while ( (c = getchar())!='\n' && c!=EOF);

    while(!feof(file)){
            if (fread(&user, sizeof(struct stoixeia),1,file) == 1 && strcmp(name,user.username)==0 && num == user.ARITHMOSLOG){
            found=1;
            start: printf("\n�������� �� ��� ��� PIN: ");
            scanf("%d", &newpin);
            while ( (c = getchar())!='\n' && c!=EOF);

            digits = log10(newpin) + 1; // ������ ������ ��� PIN (������ �� ����� ������������ �����������)
                if (digits!=4){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("\n���������� ��������, ����������� ����.");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                    goto start;}
                else {
                    fseek(file,-8,SEEK_CUR);
                    //����� �� ��� ������ ��� ��������� ��� ������, ������ �� PIN ����� ������������ ��� ���� stoixeia
                    //��� ��� ���� ������ � ������� �� ����������� 8 byte ��������, ������ ���� ��� ����� ��
                    //sizeof(user.ypoloipo) + sizeof(user.PIN)
                    user.PIN = newpin;
                    fwrite(&user.PIN, sizeof(user.ypoloipo), 1,file);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    printf("\n��������! �� ��� ��� pin: %d", user.PIN);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                    break;
              }}}


                if (found!=1){ // �� ��������� ��� ��� ������������� �� ���������� ��������
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("\n����������� ���������� ���������, ����������� ����:");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                goto first;}

                i=0;
                while(i!=2 && i!=1 && i!=3){
                loopstart:printf("\n�� �� ������ �� ������; [��������]=1, [����������]=2, [��������]=3\n");
                    scanf("%d", &i);
                if (i==3)
                    break;
                else if (i==2) {
                    fclose(file);
                    process();}
                else if(i==1){
                        fclose(file);
                        goto arxh;}
                else{
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        printf("���������� ��������\n");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                        }}

fclose(file);
break;




default: // �� ��������� ��� � ������� ��� ������� ���� ������ ��� �� 1 ��� �� 6.
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("���������� ��������\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    goto arxh;



}}



int main(void)
{ // ����� ���������, ����� ��� process ����� �� ���������� �� ����� ������ ����.
//���������� 0 ��� ��� ������� �����������.
        process();
        return 0;
}
