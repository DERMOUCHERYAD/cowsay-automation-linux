 #include <stdio.h>
#include <string.h>
#include <unistd.h>
/* Wildcow dessinera une vache amoureuse qui au fil du temps se verra
former un coeur avec sa queue */
void update() {printf ("\033[H\033[J");}
void gotoxy (x,y) { printf ("\033[%d;%dH",x,y) ;}
void wildcow()
{
update();
printf("\n\n\n");
// On dessine la vache amoureuse
printf(" \\ ^__^\n\
\\ (♥♥)\\ _______ \n\
(__)\\ ) \\/\\ \n\
|| ---- w |\n\
|| || \n");
sleep(1);
// ensemble d'instructions qui ferront que la vache aie une queue en forme de coeur
gotoxy(6,29); printf("/\n"); sleep(1);
gotoxy(5,30); printf("/\n"); sleep(1);
gotoxy(4,31); printf(")\n"); sleep(1);
gotoxy(3,30); printf("_\n"); sleep(1);
gotoxy(4,29); printf("/\n"); sleep(1);
gotoxy(4,28); printf("\\\n"); sleep(1);
gotoxy(3,27); printf("_\n"); sleep(1);
gotoxy(4,26); printf("(\n"); sleep(1);
gotoxy(5,27); printf("\\\n"); sleep(1);
gotoxy(6,28); printf("\\\n"); sleep(1);
gotoxy(9,0);
}

int main() {
wildcow();
return 0;
}

