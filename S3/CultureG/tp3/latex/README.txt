Pour compiler utiliser les commandes suivantes:

##############
Sans l'index :
(d�but)
--> pdflatex document.tex > enter
(fin)

############
Avec index :
(d�but)
--> pdflatex document.tex > enter
--> makeindex document.idx > enter (si vous voulez l'index seulement)
--> pdflatex document.tex > enter
(fin)

################
Apr�s l'�tape de fin un fichier document.pdf aura �t� cr�er, ouvre le avec un navigateur tel que Firefox ou Chrome
ou un lecteur pdf comme Adobe Acrobat.