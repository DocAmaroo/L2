DROP TABLE tuture;
DROP TABLE personne;


CREATE TABLE personne
(
	id NUMERIC(10) PRIMARY KEY,
	nom CHARACTER(10),
	prenom CHARACTER(10)
);

CREATE TABLE tuture
(
	immat CHARACTER(8) PRIMARY KEY,
	marque CHARACTER(20),
	annee NUMERIC(4),
	prix NUMERIC(10) CHECK(prix>0),
	idProprio NUMERIC(10) REFERENCES personne(id)
);