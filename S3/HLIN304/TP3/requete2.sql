SELECT numero_operateur,SUM(quantite) FROM piece GROUP BY numero_operateur;
SELECT nom, SUM(quantite) AS Quantite FROM piece,operateur WHERE numero_operateur = numero GROUP BY numero_operateur,nom HAVING SUM(quantite) > 500;
SELECT COUNT(*) AS NB_Operateur, reference_machine FROM qualifie_sur GROUP BY reference_machine;
SELECT COUNT(*) AS NB_Pieces,reference_machine FROM piece GROUP BY reference_machine;
SELECT numero_operateur, COUNT(*) FROM qualifie_sur GROUP BY numero_operateur;
SELECT SUM(quantite),reference_machine FROM piece GROUP BY reference_machine;
