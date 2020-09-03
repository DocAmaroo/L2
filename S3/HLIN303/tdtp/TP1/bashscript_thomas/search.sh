#!/bin/bash

#===============================================================================
# Name	 : search.sh
# Author : CANTA Thomas 
#===============================================================================
# Description :
#
#	;It allows to find if the words given in parameter are in the files of 
#	the directory of the script. If so, it puts them in the DUMP directory
#
# Command :
#
#	;search	 : ./search.sh [param1] [param2] ...
#	;restart : ./search.sh -r
#===============================================================================

#==========
# DUMP_dir
#==========

#create a "DUMP" directory
if [ ! -d "DUMP" ]
then
	mkdir DUMP
fi

#=========
# search
#=========

#for each parameter we give
for param in $*
do
	#for each files in this directory
	for files in *
	do
		#if file name != search.sh AND DUMP
		#because we don't want to move the script and DUMP is a directory
		if [ "$files" != "search.sh" -a "$files" != "DUMP" ];then

			#new command : easiest way to use this grep command
			GREP_COMMAND=$(grep -l $param $files)

			#if file name == file name find by grep
			if [ "$files" ==  "$GREP_COMMAND" ];then

				#new command : easiest way to use of the move command
				MOVE=$(mv $files DUMP)

				#display the param find in the file
				echo "$files : $param"
				echo -e " Move $files in DUMP..."
				$MOVE
				echo -e "   OK.......\n"
			fi
		fi
	done
echo "...done"
done

#=========
# restart
#=========

#replace all files in is directory
if [ "$1" == "-r" -a ! -z "$(ls -A DUMP)" ]
then
	mv DUMP/* .
fi
