
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>



struct osumnjicen
{
     char ime[50];
     char adresa[50];
     char ime_oca[50];
     char ime_majke[50];
     char broj_telefona[50];
     char mail[50];
     char jmbg[50];

    };
void meni();
void dodaj();
void pretrazi();
void lista();
int main()
{
    system("color 71");
    meni();
    return 0;
}


void meni()
{
	system("cls");

printf("\t--------------------> SISTEM ZA OSUMLJICENE <--------------------\n\n");
printf("\n\n\t\t\t-> MUP--------------------\t\t\n\n");
printf("\t\t\t\t  1.Dodaj\t\t\t\n\n");
printf("\t\t\t\t  2.Pretrazi\n\n");
printf("\t\t\t\t  3.Lista\n\n");
printf("\t\t\t\t  4.Exit\n\n");
printf("\t\t\t---------------BEOGRAD <-\n\n");


switch(_getch())
{
    case '1':
			dodaj();break;
	case '2':
			pretrazi();break;
    case '3':
			lista();break;
    case '4':
			exit(0);break;
   default:

               printf("\n\t\t*Morate da unese broj od 1 do 4");

                _getch();

meni();
}
}

void dodaj()
{

        system("cls");
        FILE *f;
        struct osumnjicen o;
        f=fopen("file.txt","w");
        printf("\nIme i Prezime: ");
        gets(o.ime);
        printf("\nDodaj adresu: ");
        gets(o.adresa);
        printf("\nIme oca: ");
        gets(o.ime_oca);
        printf("\nIme majke: ");
        gets(o.ime_majke);
        printf("\nBroj telefona: ");
        gets(o.broj_telefona);
        printf("\nE-mail aresa: ");
        gets(o.mail);
        printf("\nJMBG: ");
        gets(o.jmbg);

		fwrite(&o,1,sizeof(o),f);


        printf("\n\n\nOsumnjiceni unet u sistem!");

fclose(f);

    printf("\n\n\n\n\n\nPritisni ENTER da se vratite u glavni meni.");

	 _getch();

     meni();
}
void lista()
{
	system("cls");
    struct osumnjicen o;
	FILE *f;


f=fopen("file.txt","r");
if(f==NULL)
{
    printf("\n Nijedan osumnjiceni nije unet u sistem!\n\n");
    printf("\n\n\n\t\tPritisnite ENTER da se vratite u meni");

	_getch();

	meni();

}
printf("Lista svih osumnjicenih koji su uneti u sistem:\n\n");
while(fread(&o,sizeof(o),1,f)==1)
{

		printf("\nIme i Prezime: %s \nAdresa: %s \nIme oca: %s \nIme majke: %s \nBroj telefona: %s \nMail: %s \nJMBG: %s \n\n\n--------------------------\n\n\n\n ", o.ime, o.adresa, o.ime_oca, o.ime_majke, o.broj_telefona, o.mail, o.jmbg);



}
 fclose(f);
  printf("\n Pritisnite ENTER da se vratite u glavni meni");

	 getch();
meni();

}
void pretrazi()
{
	system("cls");
    struct osumnjicen o;
FILE *f;
char ime[100];

f=fopen("file.txt","r");
if(f==NULL)
{
    printf("\n error in opening\a\a\a\a");
    exit(1);

}
printf("\nUpisite osumnjicenog kojeg zelite da proverite:\n\n");
gets(ime);
while(fread(&o,sizeof(o),1,f)==1)
{
    if(strcmp(o.ime,ime)==0)
    {
        printf("\n\t---> Informacije o osumnjicenom %s <---\n\n",ime);
		printf("\nIme i Prezime: %s \nAdresa: %s \nIme oca: %s \nIme majke: %s \nBroj telefona: %s \nMail: %s \nJMBG: %s \n\n\n\n\n\n\n ", o.ime, o.adresa, o.ime_oca, o.ime_majke, o.broj_telefona, o.mail, o.jmbg);

	}


}
 fclose(f);
  printf("\n\n Pritisnite ENTER da se vratite u glavni meni.");

	 getch();
	 meni();

}

