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

#La suite de fibonnaci commencent par 0, 1, 1,2,3,5 ...

u=0  #On itialise u à 0
v=1 #On itialise v à 1
i=1

#IMPOSSIBLE D'AFFICHER LE PREMIER TERME DE LA SUITE CAR LA COMMANDE COWSAY NE PERMET PAS D'AFFICHER 0 
while [ $i -lt $1 ]
do 
cowsay $i
sleep 1     # afin d'avoir la pause d'une seconde        
clear       # rafraichir la page
i=$(expr "$u" + "$v") 
u=$v   #Pour la prochaine boucle u prend la valeur de v
v=$i   #Et v prend la valeur de la derniere somme compté (valeur de i)       
done
cowsay -T U $(expr $u)    #en utilisant l'option -T vue dans le manuel afin de tirer la langue du dernier nombre affiché ici la suite précedente de la dernière suite qui est bien u 
