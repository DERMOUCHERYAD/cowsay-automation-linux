#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>

void update(){ printf ("\033[H\033[J");}
void gotoxy(x,y){ printf ("\033[%d;%dH" ,x,y);}


int max(int a, int b){
    if(a>=b) return a;
    else return b;
}

void affiche_vache_liferocks(){
    int i = 0;
    update();
    printf("        \\   ^__^\n");
    printf("         \\  (^^)\\_______\n");
    printf("            (__)\\       )\\/\\\n");
    printf("                ||----w ||\n");
    printf("                ||      ||\n");
    while(i<3){
        gotoxy(4,0);
        printf("                //----w //\n");
        printf("                \\\\      \\\\\n");
        sleep(1);
        gotoxy(4,0);
        printf("                ||----w ||\n");
        printf("                ||      ||\n");
        sleep(1);
        i++;
    }
}

void affiche_vache_lifesucks(){
    int i = 0;
    update();
    printf("        \\   ^__^\n");
    printf("         \\  (--)\\_______\n");
    printf("            (__)\\       )\\/\\\n");
    printf("                ||----w ||\n");
    printf("                ||      ||\n");
    sleep(1);
    gotoxy(4, 0);
    printf("                //----w //\n");
    printf("                \\\\      \\\\\n");
    sleep(1);
    update();
    gotoxy(2,0);
    printf("        \\   ^__^\n");
    printf("         \\  (--)\\_______\n");
    printf("            (__)\\       )\\/\\\n");
    printf("          ====== ----w-- =====\n");
}

void affiche_vache_byebyelife(){
    update();
    printf("\n        \\   ^__^\n");
    printf("         \\  (xx)\\_______\n");
    printf("            (^)\\  RIP  )\\/\\\n");
    printf("          ====== ----w-- =====\n");
}

int main(void){
    affiche_vache_liferocks();
    int game_over = 0;
    int lunchfood, digestion, crop;
    int stock = 5;
    int fitness = 5;
    srand(time(NULL));
    int duree_de_vie = 0;
    while(game_over != 1){
        printf("stock: %d\n choisissez combien vous voulez la nourrir :", stock);
        scanf("%d", &lunchfood);
        while (lunchfood>stock ||lunchfood + fitness > 10){ //verifier que l'utilisateur tappe une valeur valide de lunchfood
            printf("valeur invalid ,esseyez encore: ");
            scanf("%d", &lunchfood);
        }
        digestion = -(rand() % 4); 
        fitness = max(0, fitness + lunchfood + digestion); //on utilise max pour eviter les cas ou (fitness + lunchfood + digestion) < 0
        crop = (rand() % 7)-3;
        stock = max(0, stock - lunchfood + crop);
        if (fitness > 3 && fitness < 7){ 
            affiche_vache_liferocks();
        }
        else if (fitness != 0 && fitness != 10){
            affiche_vache_lifesucks();
        }
        else{
            affiche_vache_byebyelife();
            game_over = 1;
            printf("t'as survécu %d unité du temps\n", duree_de_vie);
        }
        duree_de_vie++;
    }
}