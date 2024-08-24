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

i=1          #initialisation
while [ $i -le $1 ] 
do 
cowsay $i       # on utilise la commande cowsay
sleep 1         # afin d'avoir la pause d'une seconde 
clear              #rafraichir la page
i=$(expr $i + 1 )   #incrémentation
done

cowsay -T U $(expr $i - 1)    #en utilisant l'option -T vue dans le manuel afin de tirer la langue du dernier nombre affiché
