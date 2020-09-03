Pour compiler utiliser les commandes suivantes:

##############
Sans l'index :
(début)
--> pdflatex document.tex > enter
(fin)

############
Avec index :
(début)
--> pdflatex document.tex > enter
--> makeindex document.idx > enter (si vous voulez l'index seulement)
--> pdflatex document.tex > enter
(fin)

################
Après l'étape de fin un fichier document.pdf aura été créer, ouvre le avec un navigateur tel que Firefox ou Chrome
ou un lecteur pdf comme Adobe Acrobat.