package Quincaillerie;

import java.util.HashMap;

public class Main {

	@SuppressWarnings("unchecked")
	public static void main(String[] args) {

		@SuppressWarnings("rawtypes")
		HashMap BDD = new HashMap<String, Piece>();
		
		PieceBase Planche = new PieceBase("Planche", "2", 3, 1, 4);
		PieceBase Clou = new PieceBase("Clou", "1", 1, 1, 2);
		PieceBase Argent = new PieceBase("Argent","3",300,0,0);
		
		PieceMontee PlancheCloute = new PieceMontee("PlancheCloute", "1", 1, 1, 5, 0, 1);
		PlancheCloute.ac(Clou);
		PlancheCloute.ac(Clou);
		PlancheCloute.ac(Planche);
		
		Quincaillerie IBob = new Quincaillerie("3630");
		IBob.add(PlancheCloute);
		IBob.add(Planche);
		IBob.add(Clou);
		IBob.add(Argent);
		
		Commande Q1 = new Commande(IBob,BDD);

		Particulier Patrick = new Particulier("118218", "patrick@lebeauf.fr", "001", "Patrick", Civilite.M, Sexe.M);
		BDD.put("001", Patrick);

		Q1.add(Clou);
		Q1.add(Clou);
		Q1.add(Clou);
		Q1.add(Argent);
		Q1.add(Planche);
		Q1.add(PlancheCloute);
		
		IBob.info();
		
		Patrick.info();
		
		System.out.println(Q1.facture());
		
		System.out.println("\n///////////////////////////////////////////////////////////////\n");
		
		Q1.retirer(Argent);
		System.out.println(Q1.facture());
		
	}

}
