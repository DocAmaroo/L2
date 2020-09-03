#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys

#function
def param():
	if len(sys.argv) < 1 :
		return print("Erreur : Aucun paramètre n'a été donné")
	else :
		for param in range(len(sys.argv)) :
			if param == 0 :
				continue
			else :	
				print("Paramètre : ",sys.argv[param])

def factorielle(n):

	if n == 0 : return print("Factorielle ",n, " = ",n)
	else : 
		temp = 1
		for compteur in range(1,n+1) : 
			temp = temp * compteur
		return print("Factorielle ",n, " = ",temp)

def estPremier(n) :

	for i in range (2,n) :
		if ( n%i ) == 0  :
			return False
	return True

def listePremier(n) :

	liste = []
	for i in range(2,n) :
		if estPremier(i) :
			liste.append(i)

	return liste

def printPremier(n) :

	i=n
	while len(listePremier(i)) < n :
		i+=1
	return print(listePremier(i))


# main

#param()
#factorielle( int(sys.argv[1]) )
#estPremier( int(sys.argv[1]) )
listePremier( int(sys.argv[1]) )
printPremier( int(sys.argv[1]) )