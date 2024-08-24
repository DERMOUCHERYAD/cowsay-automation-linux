/*Comme pour la commande cowsay, les deux premiers caracteres
de la chaine
representeront les deux yeux de la vache, si qu'un seul
carractere est donne
la vache ne possedera qu'un unique oeil du caractere donné*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void affiche_vache(char *eyes){
    printf("               \\    ^__^\n\
                \\   (%c%c)\\ _________\n\
                    (__)\\          )\\/\\\n\
                        ||- - - -w |\n\
                        ||        ||\n",eyes[0],eyes[1]);
}

/*Comme pour la commande cowsay, les deux premiers caractères de la chaine representeront les deux yeux de la vache, si qu'un seul carractere est donne
la vache ne possedera qu'un unique oeil du caractere donné*/

int main(int argc, char* argv[]){
    if (argc==3){
        if ( strcmp( argv[1], "-e")==0 ||strcmp( argv[1], "-eyes")==0) {
            affiche_vache(argv[2]);
            return 0;}
    }else{
        return 1;
    }
}

