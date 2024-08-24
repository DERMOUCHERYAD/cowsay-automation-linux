#!/bin/bash
#n1 sera compris comme etant le premier argument $1
#op sera compris comme etant le second argument $2
#n2 sera compris comme etant le troisieme argument $3

#On commence donc par initialiser une chaine de caractere au format voulu
ch="$1 $2 $3"

#Verification que l'operateur est 
if [ $2 = '+' -o $2 = '-' -o $2 = '\*' -o $2 = '/' ]
then

    # $(expr $ch) nous donnera le resultat de l'equation STR et sera ensuite afficher grace à l'option -e
    # la vache affichera de plus l'equation donnée en argument 
    cowsay -e $(expr $ch) $ch              
else 
    echo "Echec d'execution"
    echo donnez une chaine sous format : n1 op n2  
    echo "avec n1 et n2 des entiers et op une oppertation simple (+,-,*,/)"
fi
