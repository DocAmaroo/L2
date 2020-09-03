#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os, sys, subprocess, getpass

# ===========================
# = DEBUT AnglaistoFrançais =
# ===========================
def AnglaistoFrancais (MONTH) : #Transforme le mois Anglais -> Français
    if MONTH == "Jan" :
        return "janvier"
    if MONTH == "Feb" :
        return "février"
    if MONTH == "Mar" :
        return "mars"
    if MONTH == "Apr" :
        return "avril"
    if MONTH == "May" :
        return "mai"
    if MONTH == "Jun" :
        return "juin"
    if MONTH == "Jul" :
        return "juillet"
    if MONTH == "Aug" :
        return "aout"
    if MONTH == "Sep" :
        return "septembre"
    if MONTH == "Oct" :
        return "octobre"
    if MONTH == "Nov" :
        return "novembre"
    if MONTH == "Dec" :
        return "décembre"
# =========================
# = FIN AnglaistoFrançais =
# =========================

# ==============
# = DEBUT MAIN =
# ==============

result = subprocess.check_output("last > oui", shell=True)

file = open("oui", "r")
listeNom = []
listeMois = []
listeJour = []
listeMinute = []
listeHeure = []
compteur = 0
for lines in file :
    if "gone - no logout" in lines :
        continue    
    if lines != "\n" : #Ne prend pas les lignes vides
        nom, suite = lines.split(" ", maxsplit = 1) #Récupère le login et met tout le reste dans suite
        suite = suite.lstrip() #Enlève les espaces a gauche
        suite = suite[34:] #Enlèves les 34 premiers charactères car entre le début de suite et du mois il y a 34 charactères
        if nom != "reboot" and nom != "wtmp": #Vire le login reboot et wtmp (la dernière ligne)
            listeNom.append(nom)
            listeMois.append(AnglaistoFrancais(suite[0:3]))
            listeJour.append(suite[4:6].lstrip())
            trash,trash2,heure,minute = suite.split(":", maxsplit = 3)
            listeHeure.append(heure[len(heure)-2:])
            listeMinute.append(minute[:2])

# for i in range(0,len(listeNom)) :
#     print(listeNom[i]+" s'est connecté le : "+listeJour[i]+" "+listeMois[i]+" ,pendant : "+str(listeHeure[i])+"h"+listeMinute[i])

# ====================================
# = Nombre de connections par logins =
# ====================================
dict = {} #Dictionnaire
listeNom2 = []
for j in range(0,len(listeNom)):
    if listeNom[j] not in dict :
        dict[listeNom[j]] = 0
        listeNom2.append(listeNom[j])
    if listeNom[j] in dict :
        dict[listeNom[j]] = dict[listeNom[j]] + 1
for i in range(0,len(listeNom2)) :
    print(listeNom2[i]+" s'est connecté : "+str(dict[listeNom2[i]])+" fois")

# ==========================================
# = Nombre de minutes connectés par logins =
# ==========================================
dict2 = {}
for x in range(0,len(listeNom)) : # Temps de connections par minutes
    if listeNom[x] not in dict2 :
        dict2[listeNom[x]] = int(listeHeure[x]) * 60 + int(listeMinute[x])
    if listeNom[x] in dict2 :
        dict2[listeNom[x]] = dict2[listeNom[x]] + int(listeHeure[x]) * 60 + int(listeMinute[x])

for i in range(0,len(listeNom2)) :
    print(listeNom2[i]+" s'est connecté pendant : "+str(dict2[listeNom2[i]])+" minutes")

# =========================
# = Jours/Mois par logins =
# =========================
