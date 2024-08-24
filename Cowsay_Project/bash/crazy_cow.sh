#bin/bash
#verification des arguments  avant le traitement de la fonction

if [ $# -gt 1  ]  #le nombre d'arguments
 then 
    echo "Veuillez saisir un seul argument."
    exit 1   #arreter le programme (break) 
fi

if [ $1 -lt 0 ] #l'argument est bien positif 
 then 
    echo "Veuillez saisir un entier naturel positif "
    exit 1   #arreter le programme (break) 
fi 

#Compte la factorielel d'un nombre mit en argument
#Dessine un dragon avec le nombre voulu et prononce le resultat de sa factorielle
n=$1
fac=1
while [ $n -gt 0 ]
    do
        fac=$(($fac * $n))
        n=$(($n - 1))
    done
    cowsay -f dragon  "La factorielle de $1  est $fac"

