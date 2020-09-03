#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys

if len(sys.argv) <= 1:
	print("Erreur : aucun paramètre n donnée")
	exit()

def estPremier(n):
	for i in range(2,n):
		if (n%i) == 0:
			return False

	return True

def listePremier(n):
	list_premier = []
	for i in range(2,n):
		if ( estPremier(i) ):
			list_premier.append(i)
	return list_premier

def afficheNnbPremier(n):
	i=n
	while len(listePremier(i))<n :
		i+=1
	return listePremier(i)

#print( listePremier( int(sys.argv[1])) )
print( afficheNnbPremier(int(sys.argv[1])))