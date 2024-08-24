#include <stdio.h>
#include <string.h>
#include <unistd.h>


void update (){printf("\033[H\033[J");}
void gotoxy (x,y){printf ("\033[%d;%dH",x,y);}

void affiche_vache(char *t1, char *t2, char *str){ 
    int i=5,ci=0,j=25,nb_char=92,nbc=34,x=2,y=-4,lig_str=0,col_str=0,len_str;


    len_str = strlen(str);


    while (lig_str<3) {
        col_str = 0;
        while (col_str<len_str+4) {
            if (lig_str==0) {
                if ((col_str==0) || (col_str==len_str+4-1)) {
                    printf(" ");
                } else {
                    printf("_");
                }                
            } else if (lig_str==1) {                
                if (col_str==0) {
                    printf("<");
                } else if ((col_str==1) || (col_str==len_str+4-2)) {
                    printf(" ");
                } else if (col_str==len_str+4-1) {
                    printf(">");
                } else {
                    printf("%c",str[col_str-2]);                   
                }
            } else if (lig_str==2) {
                if ((col_str==0) || (col_str==len_str+4-1)) {
                    printf(" ");
                } else {
                    printf("-");
                }                
            }
            col_str++;
        }
        printf("\n");
        lig_str++;
    };


    gotoxy(x,y);


    while(ci<i){
        int cj=-12;
        gotoxy(x+3,y);
        while(cj<j){
            if ( ((ci==1) && ((cj==4) || (cj==5))) ) {
                if (strcmp(t1,"-e")==0) {
                    if (cj==4) printf("%c",t2[0]);
                    else if (cj==5) printf("%c",t2[1]);
                }
                else if (strcmp(t1,"-d")==0) {
                    printf("x");
                }
                else if (strcmp(t1,"-b")==0) {
                    printf("=");
                }
                else if (strcmp(t1,"-g")==0) {
                    printf("$");
                }
                else if (strcmp(t1,"-p")==0) {
                    printf("@");
                }
                else if (strcmp(t1,"-s")==0) {
                    printf("*");
                }
                else if (strcmp(t1,"-t")==0) {
                    printf("-");
                }
                else if (strcmp(t1,"-w")==0) {
                    printf("O");
                }
                else if (strcmp(t1,"-y")==0) {
                    printf(".");
                }
                else printf("o");
            }
            else if( ((ci==0) && (cj==-1)) || ((ci==1) && (cj==0)) || ((ci==0) && ((cj==7) || (cj==9))) || ((ci==1) && ((cj==7) || (cj==8) || (cj==16) || (cj==18))) || ((ci==2) && ((cj==7) || (cj==8) || (cj==17) || (cj==18) || (cj==20) || (cj==21) || (cj==22) || (cj==24))) || ((ci==3) && ((cj==16) || (cj==18))) || ((ci==4) && (cj==16)) ) printf("%c",nb_char);
            else if ( (ci==0) && ((cj==3) || (cj==6)) ) printf("^");
            else if( ((ci==0) && ((cj==5) || (cj==4))) || ((ci==1) && ((cj>=9) && (cj<=15))) || ((ci==2) && ((cj==4) || (cj==5))) ) printf("_");
            else if ( ((ci==3) && ((cj>=9) && (cj<=12))) ) printf("-");
            else if ( ((ci==0) && (cj==8)) || ((ci==1) && (cj==17)) || ((ci==2) && (cj==23)) || ((ci==3) && (cj==17)) || ((ci==4) && (cj==17)) ) printf("n");
            else if ( ((ci==1) && (cj==3)) || ((ci==2) && (cj==3)) ) printf("(");
            else if ( ((ci==1) && (cj==6)) || ((ci==2) && ((cj==6) || (cj==16))) ) printf(")");
            else if ( (ci==2) && (cj==19) ) printf("/");
            else if ( ((ci==3) && ((cj==7) || (cj==8) || (cj==15))) || ((ci==4) && ((cj==7) || (cj==8) || (cj==14) || (cj==15))) ) printf("|");
            else if ( (ci==3) && (cj==13) ) printf("w");
            else if ( (ci==4) && (cj==18) ) printf("%c",nbc);
            else if ( ((ci==3) && (cj==4)) && ((strcmp(t1,"-d")==0) || (strcmp(t1,"-s")==0)) ) printf("U");
            else if ( ((cj==4) && ((ci==3) || (ci==4))) && (strcmp(t1,"-T")==0) ) printf(".");
            else printf(" ");
            cj++;
        }
        printf("\n");
        x+=1;
        ci++;
    }    
}


int main(int argc, char *argv[]) {
    FILE *file;
    char car;
    int i=0; 
    char str[100];


    if (argc<2) {
        file = stdin;
    } else {
        if (argc==1) {
            printf("Il n'y a pas d'argument passe");
            return 2;
        } else {
            file = fopen(argv[argc-1],"r");
        }
        
        if (file==NULL) {
            perror(argv[1]);
            return 1;
        }


        fscanf(file,"%c",&car);
        str[i] = car;


        while (!feof(file)) {
            if (argc==4) {
                affiche_vache(argv[1],argv[2],str);
                sleep(1);
                update();
            } else if (argc==3) {
                affiche_vache(argv[1]," ",str);
                sleep(1);
                update();
            } else if (argc==2) {
                affiche_vache(" "," ",str);
                sleep(1);
                update();
            };
            fscanf(file,"%c",&car);
            i++;
            str[i] = car;
        }
        fclose(file);
        return 0;
    }
}
