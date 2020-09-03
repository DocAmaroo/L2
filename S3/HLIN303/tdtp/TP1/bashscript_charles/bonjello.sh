#!/bin/bash

if [ ! -d "DUMP" ]
then
	mkdir DUMP
fi

if [ "$1" == "-r" -a ! -z "$(ls -A DUMP)" ]
then
	mv DUMP/* .
	exit 1
fi

a_deplace=false

for param in $*
do
	for file in *
	do
		nom_fichier=$(grep -l --directories="skip" $param $file)
		if [ ! -z "$nom_fichier" -a "$nom_fichier" != "$0" ]
		then
			a_deplace=true
			echo "La police a trouvé $param dans $nom_fichier EXPEDITION !"
			let rand="$RANDOM"%1000+1
			for i in `seq 1 "$rand"`
			do
				let x="$i"*100/"$rand"
				echo -ne "DEPLACEMENT EN COURS : $x%"\\r
				sleep 0.001
			done
			mv $nom_fichier DUMP/
		fi
	done
done

if [ "$a_deplace" = true ]; then echo "Déportation terminée."; fi
