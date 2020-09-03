SELECT AVG(nbspectateurs) FROM film;
SELECT titre,nbspectateurs FROM film WHERE nbspectateurs > (SELECT AVG(nbspectateurs) FROM film);
SELECT nom,prenom,titre FROM realisateur,film WHERE idR = idRealisateur AND nbspectateurs > (SELECT AVG(nbspectateurs) FROM film);
SELECT nom,prenom FROM acteur,jouer,film WHERE idA = idActeur AND idF = idFilm AND nbspectateurs = (SELECT MAX(nbspectateurs) FROM film);
SELECT DISTINCT nom,prenom FROM acteur,jouer WHERE idA NOT IN (SELECT idActeur FROM jouer);
SELECT DISTINCT description FROM genre WHERE idG NOT IN (SELECT idGenre FROM film);
SELECT DISTINCT nom,prenom as REAL_JOUER_AVANT_2002 FROM realisateur WHERE idR NOT IN (SELECT idRealisateur FROM film WHERE annee < 2002 );
SELECT description as description_sup_50000 FROM genre WHERE idG NOT IN (SELECT idGenre FROM film WHERE nbspectateurs < 50000);
SELECT description as film_real_by_american FROM genre WHERE idG IN (SELECT idGenre FROM film, realisateur WHERE idRealisateur = idR AND nbspectateurs > 50000 AND nationalite = 'Americain' );