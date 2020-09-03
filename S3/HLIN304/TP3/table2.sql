DROP TABLE qualifie_sur;
DROP TABLE piece;
DROP TABLE machine;
DROP TABLE operateur;

CREATE TABLE operateur
(
  numero CHARACTER(10) PRIMARY KEY,
  nom CHARACTER(40),
  age NUMERIC(3)
);

CREATE TABLE machine
(
  referenceM CHARACTER(10) PRIMARY KEY,
  designationM CHARACTER(40)
);

CREATE TABLE piece
(
  referenceP CHARACTER(10) PRIMARY KEY,
  reference_machine CHARACTER(10) REFERENCES machine(referenceM),
  numero_operateur CHARACTER(10) REFERENCES operateur(numero),
  designationP CHARACTER(40),
  quantite NUMERIC(5)
);

CREATE TABLE qualifie_sur
(
  numero_operateur CHARACTER(10) REFERENCES operateur(numero),
  reference_machine CHARACTER(10) REFERENCES machine(referenceM),
  DATEUH DATE
);
