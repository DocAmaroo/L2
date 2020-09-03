SELECT COUNT(*) AS QUESTION_1 FROM personne;
SELECT COUNT(*) AS ANONYMOUS FROM personne WHERE prenom IS NULL;
SELECT COUNT(*) AS NB_VOITURE_BY_PROPRIO, nom, prenom FROM tuture,personne WHERE id=idProprio GROUP BY id,nom,prenom;
SELECT SUM(prix) AS CAPITAL, nom, prenom FROM tuture,personne WHERE id=idProprio GROUP BY id,nom,prenom;
SELECT AVG(prix) AS MOYENNE, marque FROM tuture GROUP BY marque;
SELECT COUNT(*) AS TUTURE_SUP_20000,nom,prenom FROM tuture, personne WHERE id=idProprio AND prix > 20000 GROUP BY id,nom,prenom;
SELECT SUM(prix) AS CAPITAL_SUP_50000, id, nom, prenom FROM tuture, personne WHERE id=idProprio HAVING SUM(prix) > 50000 GROUP BY id, nom, prenom;
SELECT SUM(prix) AS CAPITAL_BY_ANNEE, id, nom, prenom, annee FROM tuture, personne WHERE id=idProprio GROUP BY id, nom, prenom, annee ORDER BY annee;