#!/bin/bash

# Vérification des arguments avant le traitement de la fonction

if [ $# -ne 1 ]; then
  echo "Veuillez saisir un seul argument."
  exit 1
fi

if [ $1 -lt 1 ]; then
  echo "Veuillez saisir un entier naturel positif."
  exit 1
fi 


#creer une fonction premier qui verifie si un nombre est premier ou pas en lui passant le nombre comme argument
premier() {
  i=2 #verifier à partir de 2 car le 1 est divisible par tout les entier 
  flag=0   #utiliser la notion des drapeaux afin de verifier l'existance des diviseurs pour un nombre ou pas 
  while [ $i -lt $1 ]   #cherhcer des diviseurs pour notre argument $1 pour verifier si c'est premier ou pas 
   do
    div=$(expr $1 % $i)   # % est le modulo de l'argument donné $1  par l'indice $i 
    if [ $div -eq 0 ]  
    then
      flag=1       # si le module est nul donc on a trouvé un diviseur alors notre argument n'est pas premier 
    fi
      i=$(expr $i + 1) #incrementation
  done

  # verifier si le drapeau est toujours nul donc pas de diviseurs alors notre argument est premier 
  if [ $flag -eq 0 ] 
  then 
    cowsay $1 #l'afficher en utilisant la vache 
    sleep 1   # afin d'avoir la pause d'une seconde
    clear     # #rafraichir la page
  fi 
}

#PROGRAMME PRINCIPAL
i=2 # initialisation par 2  car le 1 n'est pas premier
while [ $i -le $1 ]
 do 
  premier $i    # utilisant la fonction premier declarer en dessus 
  i=$(expr $i + 1)
done
cowsay -T U $(expr $i - 1)  #en utilisant l'option -T vue dans le manuel afin de tirer la langue du dernier nombre affiché
