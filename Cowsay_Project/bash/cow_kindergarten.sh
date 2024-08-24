#bin/bash
i=1      #initialisation
while [ $i -le 10 ] 
do 
cowsay $i       # on utilise la commande cowsay
sleep 1         # afin d'avoir la pause d'une seconde 
clear              #raffrichir la page
i=$(expr $i + 1 )   #incrémentation
done
cowsay -T U "10"   #en utilisant l'option -T vue dans le manuel afin de tirer la langue