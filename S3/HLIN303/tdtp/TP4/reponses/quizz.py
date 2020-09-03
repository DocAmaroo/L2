#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys #Pour les arguments
import random #Pour les aléatoires
import os #Pour les commandes de terminales

os.system('clear') #Clear le terminal
if len(sys.argv) < 2: #Regarde si il y'a un argurment qui set le nombre de question
    print("=====================ERREUR=====================")
    print("= Rentrez en paramètres le nombre de questions =")
    print("=====================ERREUR=====================")
    exit()

file = open("capitales.csv","r") #Ouvre le fichier capitales.csv
nbquestion = int(sys.argv[1]) #Initialise
listepays = []
listecapitale = []

for lines in file: #regarde chaque ligne dans le fichier
    pays, capitale = lines.split(',') #sépare la ligne en deux valeurs :
    listepays.append(pays) #Rajoute pays dans la listepays
    capitale = capitale.replace("\n","") #Enlève le \n de la fin des capitales
    listecapitale.append(capitale.lower()) #Rajoute capitale en minuscules dans la listecapitale
file.close() #Ferme le fichier

taille = len(listepays) #récupère la nombre de pays|capitales
if taille < nbquestion:
    print("===============================ERREUR===============================")
    print("= Il y a plus de questions demandé que de Pays|Capitales existante =")
    print("===============================ERREUR===============================")
    exit()

score = 0 #Initialise le score
print("Ecrire les réponses en minuscules")
for i in range(0,nbquestion):
    taille = len(listepays) #Met a jour le nombre de pays|capitales
    r = random.randint(0,taille-1) #Fait un entier entre 0 et le nombre de pays|capitales - 1
    rep = input("Question n°"+str(i+1)+": Quelle est la capitale de: "+listepays[r]+" : ") #Récupère la réponse dans rep
    if rep == listecapitale[r]: #Regarde si la réponse est bonne
        score = score + 1 #Rajoute 1 au score
    del listepays[r] #Supprime le pays de la liste
    del listecapitale[r] #Supprime la capitale de la liste

pourcent = round((score*100/nbquestion),2) #Calcule le pourcentage du score et l'arrondi a la deuxieme décimale
print("Nombre de bonne réponses : "+str(score)+"/"+str(nbquestion)+"\nTu as "+str(pourcent)+"% de bonnes réponses") #Affiche le score total et le % de bonne réponses
