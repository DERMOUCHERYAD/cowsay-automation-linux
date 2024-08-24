#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*Comme pour la commande cowsay, les deux premiers

caracteres de la chaine
representeront la langue de la vache, si qu'un seul
carractere est donne
la vache possedera une langue représentée par le caractere
donné*/
void affiche_vache(char *tongue){
    printf("               \\    ^__^\n\
                \\   (oo)\\ _________\n\
                    (%c%c)\\          )\\/\\\n\
                        ||- - - -w |\n\
                        ||        ||\n",tongue[0],tongue[1]);
}


int main(int argc, char* argv[]) {
    if (argc==3){
        if ( strcmp( argv[1], "-T")==0 ||strcmp( argv[1], "-Tongue")==0) 
        {
            affiche_vache(argv[2]);
            return 0;
        } 
    }
    else
        return 1; 
        
}
