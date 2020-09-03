package Quincaillerie;

import java.util.HashMap;
import java.util.Scanner;

public class Commande {
	private Quincaillerie vendeur;
	private Client acheteur;
	private PanierAchat panier;
	private HashMap<String, Client> BDD;
	
	public Commande(Quincaillerie vend, HashMap<String, Client> x) {
		vendeur = vend;
		BDD = x;
		panier = new PanierAchat();
	}
	
	public int prix() {
		return panier.prix();
	}
	
	public void achete(Client x){ acheteur = x; }
	
	public String facture() {
		
		float prix = this.prix();
		
		@SuppressWarnings("resource")
		Scanner sc = new Scanner(System.in);
		System.out.println("Etes-vous déjà client chez nous ? (Y/Autre)");
		String info1 = sc.nextLine();
		String res = "";
		if(info1.equals("Y")) {
			System.out.println("Saisissez votre identifiant client : ");
			String info2 = sc.nextLine();
			
			if(!BDD.containsKey(info2)){
				return "ID inexistant !!!!";
			}
			acheteur = BDD.get(info2);
			
		}else {
			//faire une saisie de nouveau client
			System.out.println("Coordonnée ?");
			String cord = sc.nextLine();
			System.out.println("Adresse ?");
			String adre = sc.nextLine();
			System.out.println("ID ?");
			String idr = sc.nextLine();
			System.out.println("Prenom ?");
			String pren = sc.nextLine();
			
			acheteur = new Particulier(cord,adre,idr,pren,Civilite.Mme,Sexe.F);
			BDD.put(idr,acheteur);
			
		}
		
		System.out.println("Souhaitez vous utilisez vos points de fidélité afin d'obtenir une réduction ? (Y/Autre)");
		String info3 = sc.nextLine();
		
		if(info3.equals("Y")) {
			
			float reduc = acheteur.getCarte().retirerPts();
			float red = 100 - (reduc * 100);
			
			res += "Réduction de "+ red +"% appliquée! \n";
			prix = prix * reduc;
			res += "Vous avez payé ";
			res += prix+" a payer !" ;
			
		}else {
			res += "Vous avez payé ";
			res += prix+" a payer !" ;
		}
		
		acheteur.getCarte().addPts((int)prix);
		panier.info();
		return res;
	}
	
	public void add(Piece p) {
		if(vendeur.vend(p)) {
			if(panier.contient(p)) {
				panier.up(p);
			}else {
				panier.add(p);
			}
		}
	}
	
	public void retirer(Piece p) {
		if(panier.contient(p)) {
			if(panier.quantite(p) == 1) {
				panier.remove(p);
			}else {
				panier.down(p);
			}
		}else {
			System.out.println("Le panier ne contient pas l'article : \n" + p.toString());
		}
	}
}
