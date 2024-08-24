#include<stdio.h>
#include<stdlib.h>

#include<string.h>  
void affiche_vache(nb_de_vache){
    for (int i = 0; i < nb_de_vache;i++){
        printf("               \\    ^__^\n\
                \\   (oo))\\_________\n\
                    (__)\\          )\\/\\\n\
                        || - - - -w |\n\
                        ||         ||\n");
    }
} 




int main(int argc,char *argv[]){
    int number;
    printf("Combien voulez-vous de vaches ? ");
    scanf("%d", &number);
    affiche_vache(number);
    return 0;
}
