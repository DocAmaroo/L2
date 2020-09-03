-- update salaire
--UPDATE jouer SET salaire=salaire+(salaire*0.2);

-- delete un real
--DELETE FROM film WHERE idRealisateur=2;
--DELETE FROM realisateur WHERE idR=2;

-- les requetes sql
SELECT DISTINCT idA,nom FROM acteur,genre,film,jouer WHERE idA=idActeur AND idFilm = idF AND idGenre = idGenre AND (description='Policier' OR description='Comédie');
SELECT titre FROM film,realisateur WHERE idR = idRealisateur AND nom='Daroussin' AND annee>=2000;
SELECT DISTINCT realisateur.nom as realisateur, acteur.nom as acteur FROM realisateur,acteur ORDER BY realisateur.nom,acteur.nom;
SELECT DISTINCT description FROM genre,acteur,film,jouer WHERE idG=idGenre AND idFilm=idF AND idA=idActeur AND nom='Al' AND prenom='Pacino';
SELECT nom FROM realisateur,genre,film WHERE idR = idRealisateur AND idG = idGenre AND description = 'Comedie musical' ORDER BY idR;
SELECT COUNT(*) as Nombre_de_film FROM film;
SELECT annee FROM film WHERE annee = (Select MIN(annee) FROM film);
SELECT MAX(salaire) as salaire_max, AVG(salaire) as salaire_moyen, MIN(salaire) as salaire_min FROM jouer;
SELECT MAX(nbspectateurs) as nbspectateurs_max, AVG(nbspectateurs) as nbspectateurs_moyen, MIN(nbspectateurs) as nbspectateurs_min FROM film, genre WHERE idG=idGenre AND description='Comedie';
