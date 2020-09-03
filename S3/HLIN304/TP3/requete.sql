SELECT COUNT(*) AS Nombre_De_Film,annee FROM film GROUP BY annee;
SELECT MAX(nbspectateurs),annee FROM film GROUP BY annee;
SELECT COUNT(*),annee FROM film WHERE annee > 1990 GROUP BY annee;
SELECT COUNT(*),annee FROM film WHERE nbspectateurs > 1000000 GROUP BY annee;
