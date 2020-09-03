#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os, sys
from collections import Counter

def parcours (repertoire) : #Fonction parcours qui prend un repertoire
    # print("Je suis dans "+repertoire)
    liste = os.listdir(repertoire) #Met dans une liste tous les fichiers et les dossiers dans une liste
    for fichier in liste:
        # print(fichier)
        if os.path.isdir(repertoire+fichier): #Renvoie true si c'est un dossier | On rajoute repertoire car sinon il commence a la racine
            parcours(repertoire+fichier+"/") #Appel récursif avec / en plus sinon c'est considéré comme un fichier et pas un dossier
        else :
            if fichier.find('.') != 1 and fichier.find('.') != -1:
                trash, extension = fichier.split('.',maxsplit=1) #Split en deux morceau un dans une poubelle (le nom du fichier sans extension) et l'autre dans extension
                listeExtension.append(extension) #rajoute l'extension dans un tableau

listeExtension = []
parcours(sys.argv[1]) #Appel initial de la fonction récursive
# print(listeExtension)
c = Counter(listeExtension)
# print(c)
for value, count in c.most_common() :
    print("."+str(value)+": "+str(count))
