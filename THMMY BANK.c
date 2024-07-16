#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h> //χρώματα




// χρώματα
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
#define MAX 1000 //μέγιστο όριο ανάληψης,κατάθεσης,μεταφοράς χρημάτων

struct stoixeia { //βασική δομή που περιέχει τα στοιχεία του χρήστη
char onoma[50];
char epitheto[50];
char username[50];
unsigned long int AFM;
char IBAN[28];
char BBAN[24]; // Basic Bank Account Number, χρησιμοποιείται για τη δημιουργία του IBAN
long int ARITHMOSLOG; // Αριθμός λογαριασμού, μοναδικός για κάθε χρήστη, με 8 ψηφία.
                        // Γίνεται ανάθεση σε long int αντι για long long int, καθώς το codeblocks παρουσιάζει πρόβλημα με το long long int.
char ARITHMOS_LOGARIASMOY_ARR[17]; //αριθμός λογαριασμού αλλά σε συστοιχία, ώστε να μπορεί να γίνεται print.
int PIN; // Personal Identification Number, τετραψήφιος αριθμός του χρήστη
float ypoloipo;

}user;

struct synallages { //δομή για αρχεία καταθέσεων, αναλήψεων

long int ARITHMOSLOG;
float poso;
char date_time[100];
char parathrhseis[200]; //κείμενο παρατηρήσεων με ώρα, ημερομηνία, τελευταία συναλλαγή
}synallagh;




struct stoixeia eggrafh(); // Εγγραφή νέου λογαριασμού στην τράπεζα
void syndesh(); //Σύνδεση σε ήδη υπάρχων λογαριασμό
struct synallages katathesi(long int ARITHMOSLOG,float poso,struct stoixeia user,FILE *file); //κατάθεση χρηματικού ποσού
struct synallages analipsi(long int ARITHMOSLOG,float poso,struct stoixeia user,FILE *file);  //ανάληψη χρηματικού ποσού
void epiloges(long int ARITHMOSLOG,struct stoixeia user,FILE *file); // μενού με τις επιλογές που έχει ο χρήστης οταν πραγματοποιεί σύνδεση σε λογαριασμό
struct synallages metafora (long int ARITHMOSLOG,struct stoixeia user, FILE *file); // μεταφορά χρηματικού ποσού απο εναν λογαριασμό σε άλλον
void delay(int number_of_seconds); // χρησιμοποιείται σε συνδυασμό με τη βιβλιοθήκη <time.h> για να προβάλλει χρονική καθυστέρηση
                                   // μετά από πολλές αποτυχημένες προσπάθειες σύνδεσης σε εναν λογαριασμό.

void process(){
//  Βασική συνάρτηση που ξεκινά το πρόγραμμα. Δεν επιστρέφει κάποια τιμή, ούτε δέχεται παραμέτρους.
system("cls");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); // αλλαγή χρώματος σε κυανό

printf("----------------------------THMMY BANK----------------------------\n");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //αλλαγή χρώματος σε άσπρο

printf("\n Εγγραφή λογαριασμού <1>\n Σύνδεση λογαριασμού <2>");


char c;
    first: printf("\n Πληκτρολογήστε την επιλογή σας: ");
    int choice1;
    scanf("%d",&choice1);
    while ( (c = getchar())!='\n' && c!=EOF);
    switch (choice1)
   {
     case 1:
       printf("\n Επιλέξατε εγγραφή λογαριασμού");
       eggrafh();
       break;
     case 2:
       printf("\n Επιλέξατε σύνδεση λογαριασμού");
       syndesh();
       break;
     default:
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);// κόκκινο χρώμα
     printf("\n Λάθος επιλογή, επιλέξτε ξανά\n");
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // άσπρο χρώμα
     goto first;

}
}




struct stoixeia eggrafh(){
// Επιτρέπει στον χρήστη να κάνει εγγραφή ενός νέου λογαριασμού στο σύστημα.
// Επιστρέφει ένα αναγνωριστικό της δομής struct stoixeia και δεν δέχεται παραμέτρους.
FILE *file1;
char c;
srand(time(0)); //Καλείται η srand με seed την τρέχουσα ώρα, με στόχο τη δημιουργία τυχαίων αριθμών στη συνέχεια
system("cls");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
printf("----------------------------THMMY BANK----------------------------\n");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
printf("Εισάγετε το όνομα σας:");
scanf("%s", user.onoma);
while ( (c = getchar())!='\n' && c!=EOF); // Η επαναληπτική μέθοδος με το getchar μας επιτρέπει να "καθαρίζουμε" το buffer και λειτουργεί σαν flush

printf("\nΕισάγετε το επώνυμό σας:");
scanf("%s", user.epitheto);
while ( (c = getchar())!='\n' && c!=EOF);

printf("\nΕπιλέξτε όνομα χρήστη:");
scanf("%s", user.username);
while ( (c = getchar())!='\n' && c!=EOF);


while (1) {
printf("\nΕισάγετε το ΑΦΜ σας(9 ψηφία):");
scanf("%lu", &user.AFM);
while ( (c = getchar())!='\n' && c!=EOF);
int digits = log10(user.AFM) + 1; // Μαθηματικός τύπος για την εύρεση ψηφίων ενός αριθμού. Βοηθάει ώστε να εξασφαλιστεί ένάς αριθμός με 9 ψηφία στη θέση του ΑΦΜ.
if (digits==9)
    break;
else {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("Λανθασμένη εισαγωγή,προσπαθήστε ξανά:");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}

}
user.PIN = 1000+(rand()%9000); // Δημιουργία τυχαίου τετραψήφιου αριθμού. Ειναι προτιμότερο από το rand()%10000, καθώς το rand()%10000 δεν αποκλέει τους τριψήφιους, διψηφιους και μονοψηφιους αριθμους

user.BBAN[0] = 6; user.BBAN[1] = 9; user.BBAN[2] = 6;                   // Στον βασικό αριθμό λογαριασμού έχουμε τα τρία πρώτα ψηφία για τον αριθμό της τράπεζας,
user.BBAN[3] = 2; user.BBAN[4] = 0; user.BBAN[5] = 0; user.BBAN[6]= 4;  // Τα τέσσερα επόμενα για τον κωδικό του καταστήματος και
                                                                        // 16 τελευταία ψηφία, τα τελευταία 8 εκ των οποιων αποτελουν τον αριθμο λογαριασμου
                                                                        // Στο THMMY BANK ορίζουμε τον αριθμό της τράπεζας "696" και τον κωδικό του καταστήματος "2004"
                                                                        // Εφόσον δεν έχουμε προλάβει να επεκταθεί σε νέα καταστήματα. Τα παραπάνω ειναι σταθερά για ολους τους πελάτες

for (int i=7;i<23;i++) user.BBAN[i] = rand()%10; //Τα 8 τελευταία ψηφία αποτελούν τον αριθμό λογαριασμού του χρήστη, ο οποίος του επιτρέπει να συνδεθει στον λογαριασμό του
                                                //Σε συνδυασμό με το PIN
user.ARITHMOSLOG=0;
user.IBAN[0]='G'; user.IBAN[1] = 'R';            //Οι δύο πρώτοι αλφαβητικοί χαρακτήρες στο IBAN προσδιορίζουν τη χώρα (GR) ενώ οι επόμενοι 2 ειναι ψηφια ελεγχου (επιλέχθηκε το 77)
user.IBAN[2]=7; user.IBAN[3]=7;
for (int k=4;k<27;k++)
    user.IBAN[k] = user.BBAN[k-4];              // Το τελευταίο τμήμα του IBAN(22 τελευταία ψηφία) ειναι το BBAN, το οποίο εχει δημιουργηθει πιο πάνω
for (int i=15;i<23;i++)
    user.ARITHMOS_LOGARIASMOY_ARR[i-15] = user.BBAN[i]; // Ο αριθμός λογαριασμού χρήστη ειναι τα 8 τελευταία ψηφία του BBAN.
for (int i=0;i<8;i++)
    user.ARITHMOSLOG = 10*user.ARITHMOSLOG + user.ARITHMOS_LOGARIASMOY_ARR[i]; //Αλγόριθμος για τη μετατροπή του ARITHMOS_LOGARIASMOY_ARR (που ειναι αριθμητική συστοιχία) στο user.ARITHMOSLOG
                                                                               // που ειναι long int. Αυτό το "κόλπο" μας επιτρέπει να παραβλέψουμε την αδυναμία του codeblocks
                                                                               // να δουλέυει με long long int αριθμούς.
file1 = fopen("stoixeia.dat", "a+b"); //Ανοίγουμε το αρχείο με τα στοιχεία των πελατών, σε mode append to binary ώστε να προσθέσουμε το νέο αναγνωριστικό δομής στο αρχείο.
user.ypoloipo = 0;
fwrite(&user,sizeof(struct stoixeia), 1,file1); // Γράφουμε το νέο αναγνωριστικό δομής στο αρχείο (δηλαδή τα στοιχεια του νέου πελάτη μας).


if ( (file1!=NULL) ) {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);// πράσινο χρώμα
    printf("\nΕπιτυχής δημιουργία λογαριασμού!");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    printf("\nΟ προσωπικός αριθμός σας ταυτοποίησης (PIN): %d", user.PIN);

    printf("\nΟ αριθμός λογαριασμού σας: ");
    printf("%ld", user.ARITHMOSLOG);

    printf("\nΟ αριθμός IBAN σας: ");
    for (int i =0;i<2;i++)
    printf("%c", user.IBAN[i]);
    for (int i=2;i<27;i++)
    printf("%d", user.IBAN[i]);

    printf("\nΥπόλοιπο λογαριασμού: %.2f",user.ypoloipo);





        }



else {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("\nΠαρουσιάστηκε πρόβλημα. Παρακαλώ προσπαθήστε ξανά.");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

    int newchoice;
    begin:printf("\nΤι θα θέλατε να κάνετε; [Μενού]=1, [Κλείσιμο]=2\n");
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
    printf("\nΛανθασμένη επιλογή, προσπαθήστε ξανά.");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    goto begin;
    break;


        }


fclose(file1);

return user;




}
void delay(int number_of_seconds){
// Η συγκεκριμένη συνάρτηση προβάλλει χρονική καθυστέρηση πριν την εκτέλεση της επόμενης εντολής.
// Δέχεται ως παράμετρο τον αριθμό των δευτερολέπτων που επιθυμούμε να καθυστερήσει το πρόγραμμα
// Πριν διαβάσει την επόμενη εντολή. Επιστρέφει κενό

int milli_seconds = 1000 * number_of_seconds; // Μετατροπή σε milliseconds

clock_t start_time = clock(); // Έναρξη του χρόνου

while (clock() < start_time + milli_seconds); // Επαναληπτικός βρόχος, κάνει break όταν περάσει ο χρόνος που έχουμε δώσει ως παράμετρο της συνάρτησης.


}

void syndesh(){
// Συνάρτηση για σύνδεση σε ήδη υπάρχων λογαριασμό της τράπεζας.
// Επιστρέφει κενό, δε δέχεται ορίσματα.
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
printf("Μέθοδοι Σύνδεσης:\n");                 // Ο χρήστης έχει δύο τρόπους σύνδεσης:
                                                //1. Με συνδυασμό username & pin, 2. Με συνδυασμό αριθμού λογαριασμού & pin.
printf("Όνομα χρήστη και PIN <1>\n");
printf("Αριθμός λογαριασμού και PIN <2>\n");
printf("Επιλέξτε: ");
scanf("%d", &choice2);
while ( (c = getchar())!='\n' && c!=EOF);
system("cls");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
printf("----------------------------THMMY BANK----------------------------\n\n");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
switch (choice2){

case 1: // σύνδεση με συνδυασμό username, pin
    first:

        if (cnt>=3) { //κάθε φορά που ο χρήστης κάνει λάθος σύνδεση, η μεταβλητή cnt αυξάνεται κατά 1. (ξεκιναει απο το 0)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("\nΞεπεράσατε το όριο των αποτυχημένων προσπαθειών."); //μετά από 3 αποτυχημένες προσπάθειες, ο χρήστης πρέπει να περιμένει 10 δευτερόλεπτα πριν
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // προσπαθησει ξανά να συνδεθεί, για λόγους ασφάλειας.
            printf("\nΠαρακαλούμε περιμένετε 10 δευτερόλεπτα:");
            for (int x=10;x>0;x--){
                delay(1);               //Εδώ χρησιμεύει η συνάρτηση delay, η οποία εξασφαλίζει καθυστέρηση 1 δευτερολέπτου καθώς προβάλλονται οι αριθμοί από το 10 έως και το 1.
                printf("%d ", x);}
            putchar('\n');
            cnt=0;}



    printf("Όνομα χρήστη: ");
    scanf("%s", username);
    while ( (c = getchar())!='\n' && c!=EOF);

    printf("\nΑριθμός PIN: ");
    scanf("%d", &pin);
    while ( (c = getchar())!='\n' && c!=EOF);

    file = fopen("stoixeia.dat","r+b");








    if(file!=NULL){
        while(!feof(file)){
            if (fread(&user, sizeof(struct stoixeia),1,file) == 1 && strcmp(user.username,username)==0 && user.PIN==pin) {
            //Ο παραπάνω βρόχος βοηθάει να διαβαστούν όλα τα αναγνωριστικά δομών που υπάρχουν στο αρχείο με τα στοιχεία των πελατών
            // Μέχρι να βρεθεί κάποιο αναγνωριστικό που ικανοποιεί τον συνδυασμό username και PIN που δίνει ο χρήστης.
            // Όταν βρεθεί λογαριασμός με αντίστοιχο username και PIN, ο χρηστης συνδέεται και παραπέμπεται στο μενού των επιλογών.
                printf("Επιτυχής σύνδεση!\n");
                epiloges(user.ARITHMOSLOG,user,file);
                j=1;
                break;
                }



    }

    if (j!=1) { //Σε περίπτωση μη επιτυχούς σύνδεσης, ο χρήστης καλείται να ξαναδώσει τα στοιχεία του λογαριασμού του.
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("\nΟ χρήστης δεν εντοπίστηκε, προσπαθήστε ξανά.\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            fclose(file);
            cnt++; // Αύξηση του cnt κατά 1. Όταν φτάσει το 3, όπως είδαμε πριν, σημαινει πως ο χρήστης θα πρέπει να περιμενει πριν ξαναδοκιμάσει να συνδεθεί.
            goto first; }

    }


fclose(file);
break;


case 2: // σύνδεδση με συνδυασμό αριθμού λογαριασμού και PIN.
    prwto: if (cnt>=3) { //όμοια με το case 1
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                printf("\nΞεπεράσατε το όριο των αποτυχημένων προσπαθειών.");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                printf("\nΠαρακαλούμε περιμένετε 10 δευτερόλεπτα:");
                for (int x=10;x>0;x--){
                    delay(1);
                    printf("%d ", x);}
                putchar('\n');
                cnt=0;}


    printf("Αριθμός λογαριασμού: ");
    scanf("%ld", &ARITHMOS);
    while ( (c = getchar())!='\n' && c!=EOF);
    printf("\nΑριθμός PIN: ");
    scanf("%d", &pin);
    while ( (c = getchar())!='\n' && c!=EOF);
    file = fopen("stoixeia.dat","r+b");

    if(file!=NULL){
        while(!feof(file)){
            if (fread(&user, sizeof(struct stoixeia),1,file)==1 &&  ARITHMOS==user.ARITHMOSLOG && user.PIN==pin) {
                // όμοια με το case 1, ωστόσο αντί για username πλέον δουλέυουμε με τον 8ψηφιο αριθμό λογαριασμού.
                printf("Επιτυχής σύνδεση!\n");
                epiloges(user.ARITHMOSLOG,user,file);
                j=1;
                break;}}

     if (j!=1) { //μη επιτυχής σύνδεση
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("\nΟ χρήστης δεν εντοπίστηκε, προσπαθήστε ξανά.\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            cnt++;
            fclose(file);
            goto prwto; }

    }





    fclose(file);
    break;

default: // σε περίπτωση που ο χρήστης δεν επιλέξει ούτε εγγραφή ούτε σύνδεση
    goto login;
    break;
}


}

struct synallages katathesi(long int ARITHMOSLOG,float poso,struct stoixeia user,FILE *file){
// Συνάρτηση για την κατάθεση χρηματικού ποσού.
// Δέχεται ως παραμέτρους τον αριθμό λογαριασμού του χρήστη, το ποσό κατάθεσης, αναγνωρστικό της δομής struct stoixeia, και το αρχείο με τα στοιχεια.
// Επιστρέφει ένα αναγνωριστικό της δομής struct synallages, η οποία περίεχει πληροφορίες για τις πρόσφατες συναλλαγές του χρήστη



FILE *file2;
fclose(file);

fopen("stoixeia.dat","r+b");

while(!feof(file)){
            if (fread(&user, sizeof(struct stoixeia),1,file) == 1 && ARITHMOSLOG == user.ARITHMOSLOG) {
                // Η συνάρτηση fread τοποθετεί τον δείκτη του file στο τέλος του αναγνωριστικού της δομής που διαβάζει.
                // Εμείς θέλουμε να τροποποιήσουμε το υπόλοιπο του χρήστη, το οποίο αποτελεί το τελευταίο μέλος της δομής μας
                // Και έχει sizeof(user.ypoloipo) = sizeof(float) = 4.
                fseek(file,-4,SEEK_CUR);
                //’ρα με τη βοήθεια του fseek τοποθετούμε τον δείκτη του file 4 byte πιο αριστερά, ώστε στη συνέχεια να τροποποιήσουμε το υπόλοιπο του χρήστη.
                time_t t = time(NULL); // Έναρξη του clock

                user.ypoloipo = user.ypoloipo + poso;
                fwrite(&user.ypoloipo, sizeof(user.ypoloipo), 1,file);
                // Γράφουμε τη νέα τιμή του user.ypoloipo στη θέση που είναι ο δείκτης του file.

                synallagh.ARITHMOSLOG = user.ARITHMOSLOG; // Προσθέτουμε στο αναγνωριστικό της δομής συναλλαγών τις πληροφορίες για τη τρέχουσα συναλλαγή
                synallagh.poso = poso;
                strcpy(synallagh.date_time,ctime(&t)); // το ctime(&t) σε συνδυασμό με το time_t t = time(NULL) προσδιοριζουν την ημερομηνια και την ώρα που έγινε η συναλλαγή.
                sprintf(synallagh.parathrhseis, "\nΈγινε κατάθεση %.2f ευρώ στον χρήστη %s στις %s.",poso,user.username,ctime(&t));
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // Πράσινο χρώμα
                puts(synallagh.parathrhseis);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                printf("Νέο Υπόλοιπο του χρήστη %s: %.2f\n",user.username,user.ypoloipo);

                file2 = fopen("katatheseis.dat", "a+b");
                fwrite(&synallagh,sizeof(struct synallages), 1,file2);

                fclose(file2);
                fclose(file);
                break; }}


return synallagh;
}

struct synallages analipsi(long int ARITHMOSLOG,float poso,struct stoixeia user,FILE *file){
//Συνάρτηση για την ανάληψη χρηματικού ποσού.
// Όπως και η συνάρτηση κατάθεσης, δέχεται ως παραμέτρους τον αριθμό λογαριασμού του χρήστη, το ποσό ανάληψης, αναγνωρστικό της δομής struct stoixeia, και το αρχείο με τα στοιχεια.
// Επιστρέφει ενα αναγνωριστικό δομής στη δομή struct synallages.
FILE *file3;

fclose(file);
float poso_analipsis;

fopen("stoixeia.dat","r+b");
while(!feof(file)){
            if (fread(&user, sizeof(struct stoixeia),1,file) == 1 && ARITHMOSLOG == user.ARITHMOSLOG) {

fseek(file,-4,SEEK_CUR); //όμοια τεχνική με την κατάθεση

if (poso>=user.ypoloipo){ //στην περίπτωση που το ποσό ανάληψης ειναι μεγαλύτερο από το υπόλοιπο, ο χρήστης κάνει ανάληψη ό,τι χρηματικό ποσό έχει μείνει στο υπόλοιπο του.

poso_analipsis = user.ypoloipo;
user.ypoloipo = 0;
fwrite(&user.ypoloipo, sizeof(user.ypoloipo), 1,file);

time_t t = time(NULL);
synallagh.ARITHMOSLOG = user.ARITHMOSLOG;
synallagh.poso = poso;
strcpy(synallagh.date_time,ctime(&t));


sprintf(synallagh.parathrhseis, "\nΈγινε ανάληψη %.2f ευρώ από τον χρήστη %s στις %s",poso_analipsis,user.username,ctime(&t));
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // κίτρινο χρώμα
puts(synallagh.parathrhseis);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
printf("Νέο Υπόλοιπο του χρήστη %s: %.2f\n", user.username,user.ypoloipo);

file3 = fopen("analipseis.dat", "a+b");
fwrite(&synallagh,sizeof(struct synallages), 1,file3);

fclose(file3);
fclose(file);

return synallagh;


}
else { // στην περίπτωση που το ποσό ανάληψης ειναι μικρότερο από το υπόλοιπο, τότε απλώς το ποσό αφαιρείται από το υπόλοιπο του χρήστη.

user.ypoloipo = user.ypoloipo - poso;
fwrite(&user.ypoloipo, sizeof(user.ypoloipo), 1,file);

time_t t = time(NULL);
synallagh.ARITHMOSLOG = user.ARITHMOSLOG;
synallagh.poso = poso;
strcpy(synallagh.date_time,ctime(&t));

sprintf(synallagh.parathrhseis, "\nΈγινε ανάληψη %.2f ευρώ από τον χρήστη %s στις %s",poso,user.username,ctime(&t));
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
puts(synallagh.parathrhseis);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

printf("Νέο Υπόλοιπο του χρήστη %s: %.2f\n",user.username,user.ypoloipo);

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
// Συνάρτηση για τη μεταφορά χρημάτων από έναν χρήστη Α σε έναν χρήστη Β.
// Ως παραμέτρους δέχεται τον αριθμό λογαριασμού του χρήστη Α, ένα αναγνωριστικό τη ςδομής struct stoixeia, και το αρχείο με τα στοιχεία.
// Επιστρέφει ένα αναγνωριστικό δομής στη struct synallages.

long int arithmos2; // αριθμός λογαριασμού του χρήστη Β
float poso;
int temp=0;
float temp1;

while(!feof(file)){
            if (fread(&user, sizeof(struct stoixeia),1,file) == 1 && ARITHMOSLOG == user.ARITHMOSLOG){
                temp1 = user.ypoloipo;}}

afetiria:printf("\nΠληκτρολογήστε τον αριθμό λογαριασμού του χρήστη στον οποίον θα γίνει η μεταφορά: "); // Η διασύνδεση μεταξύ των δύο λογαριασμών γίνεται με τη βοηθεια του αριθμού λογαριασμού.
scanf("%ld", &arithmos2);

fclose(file);
file = fopen("stoixeia.dat","r+b");

while(!feof(file)){
            if (fread(&user, sizeof(struct stoixeia),1,file) == 1 && arithmos2 == user.ARITHMOSLOG) // ελέγχουμε αν ο arithmos2 πράγματι αντιστοιχει σε κάποιον λογαριασμό.
                temp=1;
                }
if (temp!=1) { // σε περίπτωση που δεν αντιστοιχει σε κάποιον λογαριασμό, ο χρήστης καλείται να εισάγει εκ νέου άλλον αριθμό λογαριασμού.
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("Ο συγκεκριμένος αριθμός λογαριασμού δεν αντιστοιχεί σε κάποιον χρήστη.");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    goto afetiria;}

else {
while (1) {
printf("\nΠληκτρολογήστε το επιθυμητό ποσό μεταφοράς: ");
scanf("%f", &poso);

 if (poso>MAX) { // ως ΜΑΧ, δηλαδή μέγιστο όριο ανάληψης,κατάθεσης και μεταφοράς χρημάτων εχουμε ορίσει τον αριθμό 1000.
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("Προσοχή! Μέγιστο όριο μεταφοράς: 1000 ευρώ.");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    else if (poso>0 && poso<=MAX) break; // αν το ποσό είναι θετικό και κάτω από 1000, τότε σπάει ο επαναληπτικός βρόχος.
   else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("\nΛανθασμένη εισαγωγή");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}
}


fclose(file);


if (poso>temp1){ //Στο temp1 εχουμε αποθηκεύσει το υπόλοιπο του πρώτου χρήστη. Αν το ποσο μεταφοράς ειναι μεγαλύτερο από το υπόλοιπο του πρώτου χρήστη
                 // Τότε γίνεται ανάληψη ποσού από τον πρώτο χρήστη ίση με το υπόλοιπό του, και μεταφορά αυτού στον δεύτερο χρήστη.
    analipsi(ARITHMOSLOG,temp1,user,file);
    katathesi(arithmos2,temp1,user,file);}
else { //Αλλιώς, γίνεται ανάληψη του ποσού από τον πρώτο χρήστη και κατάθεση αυτού στον δεύτερο. (Πιο απλή περιπτωση)
    analipsi(ARITHMOSLOG,poso,user,file);
    katathesi(arithmos2,poso,user,file); }

fclose(file);

return synallagh;

}}


void epiloges(long int ARITHMOSLOG,struct stoixeia user,FILE *file){
// Συνάρτηση που προβάλλει το μενού επιλογών του χρήστη, εφόσον αυτός συνδεθεί στον λογαριασμό του.
// Ο χρήστης εχει σύνολο 6 επιλογές, οι οποίες επεξηγούνται παρακάτω.
// Δεχεται ως παραμέτρους τον αριθμό λογαριασμού του χρήστη, το αναγνωριστικό του χρήστη στη δομη struct stoixeia και το αρχείο με τα στοιχεία.
// Επιστρέφει κενό.
arxh:system("cls"); // Καθαρισμός οθόνης
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
printf("----------------------------THMMY BANK----------------------------\n\n");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

// Σύνολο επιλογών
printf("\nΑνάληψη χρημάτων <1>\n");
printf("Κατάθεση χρημάτων <2>\n");
printf("Μεταφορά χρημάτων <3>\n");
printf("Προβολή υπολοίπου λογαριασμού <4>\n");
printf("Προβολή αριθμού λογαριασμού <5>\n");
printf("Αλλαγή αριθμού PIN <6>\n");
printf("Επιλέξτε την επιθυμητή λειτουργία:");
float poso;
int choice3,i;
char c;

scanf("%d", &choice3);
while ( (c = getchar())!='\n' && c!=EOF);


switch(choice3){

case 1: // Ανάληψη χρηματικού ποσού
    while (1){
    printf("\nΠληκτρολογήστε το επιθυμητό ποσό ανάληψης: ");
    scanf("%f", &poso);

    if (poso>MAX) { // έλεγχος αν το ποσό είναι μέσα στα όρια μας
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("Προσοχή! Μέγιστο όριο ανάληψης: 1000 ευρώ.");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    else if (poso>0 && poso<=MAX) break;
    else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("\nΛανθασμένη εισαγωγή");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}
}

    analipsi(ARITHMOSLOG,poso,user,file);
    fseek(file,4,SEEK_CUR);

    i=0;
    while(i!=2 && i!=1 && i!=3){
    printf("\nΤι θα θέλατε να κάνετε; [Συνέχεια]=1, [Αποσύνδεση]=2, [Κλείσιμο]=3\n"); // Επαναληπτικός βρόχος που επιτρέπει στον χρήστη να συνεχίσει τη χρήση του ΑΤΜ
    scanf("%d", &i);                                                                  // Έπειτα από την ολοκλήρωση της συναλλαγής.
    if (i==3)
        break;
    else if (i==2)
            process();
    else if(i==1)
        goto arxh;
    else
        {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("\nΛανθασμένη εισαγωγή");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}
}

    break;
case 2: // Κατάθεση χρημάτων
    while (1){
    printf("\nΠληκτρολογήστε το ποσό που θα καταθέσετε: ");
    scanf("%f", &poso);

     if (poso>MAX) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("Προσοχή! Μέγιστο όριο κατάθεσης: 1000 ευρώ.");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    else if (poso>0 && poso<=MAX) break;

    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("\nΛανθασμένη εισαγωγή");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}
}
    katathesi(ARITHMOSLOG,poso,user,file);
    fseek(file,4,SEEK_CUR);

    i=0;
    while(i!=2 && i!=1 && i!=3){
    printf("\nΤι θα θέλατε να κάνετε; [Συνέχεια]=1, [Αποσύνδεση]=2, [Κλείσιμο]=3\n");
    // Επαναληπτικός βρόχος που επιτρέπει στον χρήστη να συνεχίσει τη χρήση του ΑΤΜ
    // Έπειτα από την ολοκλήρωση της συναλλαγής.
    scanf("%d", &i);
    if (i==3)
        break;
    else if (i==2)
            process();
    else if(i==1)
        goto arxh;
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("\nΛανθασμένη εισαγωγή");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}
}

    break;
case 3://Μεταφορά χρημάτων
    file = fopen("stoixeia.dat","r+b");
    metafora(ARITHMOSLOG,user,file);
    i=0;
    while(i!=2 && i!=1 && i!=3){
    printf("\nΤι θα θέλατε να κάνετε; [Συνέχεια]=1, [Αποσύνδεση]=2, [Κλείσιμο]=3\n");
    scanf("%d", &i);
    if (i==3)
        break;
    else if (i==2)
            process();
    else if(i==1)
        goto arxh;
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("\nΛανθασμένη εισαγωγή");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}}
    break;
case 4:// Προβολή υπολοίπου
    fclose(file);

    fopen("stoixeia.dat","r+b");

   while(!feof(file)){
            if (fread(&user, sizeof(struct stoixeia),1,file) == 1 && ARITHMOSLOG == user.ARITHMOSLOG){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                printf("Διαθέσιμο υπόλοιπο του χρήστη %s: %.2f", user.username, user.ypoloipo);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    //’νοιγμα του αρχείου stoixeia.dat μέχρι να εντοπιστεί αναγνωριστκό δομής με μέλος τον αριθμό λογαριασμού του τρέχοντος χρήστη
    //(Ο οποίος έχει αντληθεί ως παράμετρος στη συνάρτηση epiloges)
                i=0;
                while(i!=2 && i!=1 && i!=3){
                printf("\nΤι θα θέλατε να κάνετε; [Συνέχεια]=1, [Αποσύνδεση]=2, [Κλείσιμο]=3\n");
                scanf("%d", &i);
                if (i==3)
                    break;
                else if (i==2)
                    process();
                else if(i==1)
                    goto arxh;
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("\nΛανθασμένη εισαγωγή");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}


                break;}}}
    fclose(file);
    break;
case 5://Προβολή αριθμού λογαριασμού χρήστη, στην περίπτωση που ο ίδιος δεν τον θυμάται.
        //Απαιτεί, φυσικά, να προηγηθεί η σύνδεση στον λογαριασμό
    fclose(file);
    fopen("stoixeia.dat","r+b");


    while(!feof(file)){
            if (fread(&user, sizeof(struct stoixeia),1,file) == 1 && ARITHMOSLOG == user.ARITHMOSLOG){
                printf("Μοναδικός 8-ψήφιος αριθμός λογαριασμού του χρήστη %s: %ld ", user.username, user.ARITHMOSLOG);
                i=0;
                while(i!=2 && i!=1 && i!=3){
                printf("\nΤι θα θέλατε να κάνετε; [Συνέχεια]=1, [Αποσύνδεση]=2, [Κλείσιμο]=3\n");
                scanf("%d", &i);
                if (i==3)
                    break;
                else if (i==2)
                    process();
                else if(i==1)
                    goto arxh;
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("\nΛανθασμένη εισαγωγή");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);}

                break;}}}
    fclose(file);
    break;
case 6:;
    //Δυνατότητα αλλαγής του PIN.
    //Απαιτεί, για λόγους ασφαλείας, ο χρήστης να εισάγει το όνομα χρήστη του σε συνδυασμό με τον αριθμό λογαριασμού
    //Πριν κληθεί να επιλέξει καινούριο PIN.

    long int num;
    char name[50];
    int found=0,newpin,digits;
    char c;
    first: fclose(file);
    fopen("stoixeia.dat","r+b");
     printf("\nΓια λόγους ασφάλειας, παρακαλούμε εισάγετε το όνομα χρήστη και τον αριθμό λογαριασμού σας:");
    printf("\nΌνομα χρήστη:");
    scanf("%s", name);
    while ( (c = getchar())!='\n' && c!=EOF);

    printf("Αριθμός λογαριασμού:");
    scanf("%ld", &num);
    while ( (c = getchar())!='\n' && c!=EOF);

    while(!feof(file)){
            if (fread(&user, sizeof(struct stoixeia),1,file) == 1 && strcmp(name,user.username)==0 && num == user.ARITHMOSLOG){
            found=1;
            start: printf("\nΕισάγετε το νέο σας PIN: ");
            scanf("%d", &newpin);
            while ( (c = getchar())!='\n' && c!=EOF);

            digits = log10(newpin) + 1; // Εύρεση ψηφίων του PIN (πρέπει να ειναι αποκλειστικά τετραψήφιος)
                if (digits!=4){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("\nΛανθασμένη εισαγωγή, προσπαθήστε ξανά.");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                    goto start;}
                else {
                    fseek(file,-8,SEEK_CUR);
                    //Όμοια με την αλλαγή του υπολοίπου του χρήστη, ωστόσο το PIN είναι προτελευταίο στη δομή stoixeia
                    //Και για αυτό Πρέπει ο δείκτης να μετακινηθεί 8 byte αριστερά, δηλαδή τόσο όσο ειναι το
                    //sizeof(user.ypoloipo) + sizeof(user.PIN)
                    user.PIN = newpin;
                    fwrite(&user.PIN, sizeof(user.ypoloipo), 1,file);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    printf("\nΕπιτυχία! Το νεό σας pin: %d", user.PIN);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                    break;
              }}}


                if (found!=1){ // Σε περίπτωση που δεν επαληθεύονται τα εισαγόμενα στοιχεία
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("\nΛανθασμένος συνδυασμός στοιχείων, προσπαθήστε ξανά:");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                goto first;}

                i=0;
                while(i!=2 && i!=1 && i!=3){
                loopstart:printf("\nΤι θα θέλατε να κάνετε; [Συνέχεια]=1, [Αποσύνδεση]=2, [Κλείσιμο]=3\n");
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
                        printf("Λανθασμένη εισαγωγή\n");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                        }}

fclose(file);
break;




default: // Σε περίπτωση που ο χρήστης δεν εισάγει έναν αριθμό από το 1 έως το 6.
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("Λανθασμένη εισαγωγή\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    goto arxh;



}}



int main(void)
{ // Κύρια συνάρτηση, καλεί την process χωρίς να χρειάζεται να κάνει τίποτα άλλο.
//Επιστρέφει 0 και δεν δέχεται παραμέτρους.
        process();
        return 0;
}
