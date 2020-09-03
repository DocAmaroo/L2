-- numero nom age
INSERT INTO operateur VALUES ('OP42','Robert',32);
INSERT INTO operateur VALUES ('OP10','Sophie',41);
INSERT INTO operateur VALUES ('OP78','Lucette',25);
INSERT INTO operateur VALUES ('OP22','Alberto',25);
INSERT INTO operateur VALUES ('OP57','Marc',38);
-- referenceM designationM
INSERT INTO machine VALUES ('M12','Perceuse');
INSERT INTO machine VALUES ('M13','Ponceuse');
INSERT INTO machine VALUES ('M14','Tour numérique');
-- referenceP reference_machine numero_operateur designationP quantite
INSERT INTO piece VALUES ('P1','M12','OP10','Pièce1',250);
INSERT INTO piece VALUES ('P2','M12','OP22','Pièce2',600);
INSERT INTO piece VALUES ('P3','M14','OP22','Pièce3',200);
INSERT INTO piece VALUES ('P4','M13','OP78','Pièce4',150);
-- numero_operateur reference_machine DATE
INSERT INTO qualifie_sur VALUES ('OP10','M12',SYSDATE);
INSERT INTO qualifie_sur VALUES ('OP22','M12',SYSDATE);
INSERT INTO qualifie_sur VALUES ('OP10','M13',SYSDATE);
INSERT INTO qualifie_sur VALUES ('OP42','M13',SYSDATE);
INSERT INTO qualifie_sur VALUES ('OP78','M12',SYSDATE);
INSERT INTO qualifie_sur VALUES ('OP10','M14',SYSDATE);
