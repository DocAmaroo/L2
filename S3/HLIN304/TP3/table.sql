DROP TABLE jouer;
DROP TABLE film;
DROP TABLE genre;
DROP TABLE realisateur;
DROP TABLE acteur;	

CREATE TABLE acteur
(
	idA NUMERIC(5) PRIMARY KEY,
	nom CHARACTER(20) NOT NULL,
	prenom CHARACTER(20),
	nationalite CHARACTER(40)
);

CREATE TABLE realisateur
(
	idR NUMERIC(5) PRIMARY KEY,
	nom CHARACTER(20) NOT NULL,
	prenom CHARACTER(20),
	nationalite CHARACTER(40)
);

CREATE TABLE genre
(
	idG NUMERIC(5) PRIMARY KEY,
	description CHARACTER(40)
);

CREATE TABLE film
(
	idF NUMERIC(5) PRIMARY KEY,
	titre CHARACTER(60),
	annee NUMERIC(4),
	pays CHARACTER(40),
	nbspectateurs NUMERIC(10),
	idRealisateur NUMERIC(5),
	idGenre NUMERIC(5),
	FOREIGN KEY (idRealisateur) REFERENCES realisateur(idR),
	FOREIGN KEY (idGenre) REFERENCES genre(idG),
	CONSTRAINT const_CK_nbspectateurs CHECK (nbspectateurs > 0)
);

CREATE TABLE jouer
(
	idActeur NUMERIC(5),
	idFilm NUMERIC(5),
	salaire NUMERIC(10),
	CONSTRAINT const_PK_keys PRIMARY KEY (idActeur, idFilm),
	CONSTRAINT const_CK_salaire CHECK (salaire>0)
);