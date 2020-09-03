#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys


if len(sys.argv) <= 1:
	print("Erreur --> aucun entier donné en paramètre")
	exit()

n=0
for i in range( 0, int(sys.argv[1]) ):
	if( i==0 ):
		n = 1
	else:
		n = n*i

print(n)