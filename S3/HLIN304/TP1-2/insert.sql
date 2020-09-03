-- ACTEUR // idA - nom - prenom - nationalite
INSERT INTO acteur VALUES (0,'Reiter','Maxou','Belge');
INSERT INTO acteur VALUES (1,'Desgenetez','Charles','Allemand');
INSERT INTO acteur VALUES (2,'PeratBuvat','Florent','Sudiste');
INSERT INTO acteur VALUES (3,'Canta','Thomas','France');
INSERT INTO acteur VALUES (4,'Al','Pacino','Americain');

-- REALISATEUR // idR - nom - prenom - nationalite
INSERT INTO realisateur VALUES (0,'Bresson','Robert','France');
INSERT INTO realisateur VALUES (1,'Clint','Eastwood','Americain');
INSERT INTO realisateur VALUES (2,'Woody','Allen','Americain');
INSERT INTO realisateur VALUES (3,'Spielberg','Steven','Americain');
INSERT INTO realisateur VALUES (4,'Mon chien','mydoggydog','<3');
INSERT INTO realisateur VALUES (5,'Lamoureux','Robert','France');
INSERT INTO realisateur VALUES (6,'Daroussin','Prenom','France');

-- GENRE // idG - description
INSERT INTO genre VALUES(0,'Horreur');
INSERT INTO genre VALUES(1,'Science-Fiction');
INSERT INTO genre VALUES(2,'Drame');
INSERT INTO genre VALUES(3,'Comedie');
INSERT INTO genre VALUES(4,'Thriller');
INSERT INTO genre VALUES(5,'XXX');
INSERT INTO genre VALUES(6,'Fantastique');
INSERT INTO genre VALUES(7,'Policier');
INSERT INTO genre VALUES(8,'Comedie musical');

-- FILM // idF - titre - annee - pays - nb spectateur - idRealisateur - idGenre
INSERT INTO film VALUES(0,'MonChibreDepasseLaTourEiffelSaTourneMal_PASDEXPLICATION', '2155', 'FRANCOALLEMENDAMERICAINCHINOIS', 648569874, 4,5);
INSERT INTO film VALUES(1,'LaTerreEstPlate', '2018', 'unpaysbizarre', 36151321,2,1);
INSERT INTO film VALUES(2,'LaSeptièmeCompagnie', '1975', 'France', 99999999, 5,3);
INSERT INTO film VALUES(3,'Patate', '1999', 'ALaPolice', 100000,6,3);
INSERT INTO film VALUES(4,'Pomme de terre', '2000', 'pouet', 10000,6,1);
INSERT INTO film VALUES(5,'Ninja', '2010', 'somewhere', 10000,6,6);
INSERT INTO film VALUES(6,'HighSchoolMusicHall(old)', '-3000', 'caca', 1000000,0,8);


-- JOUER // idActeur - idFilm - salaire
INSERT INTO jouer VALUES(0,0,666);
INSERT INTO jouer VALUES(1,2,100000);
INSERT INTO jouer VALUES(3,0,100000);
INSERT INTO jouer VALUES(4,1,100000);
INSERT INTO jouer VALUES(4,5,100000);
