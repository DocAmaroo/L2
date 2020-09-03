package Quincaillerie;

public abstract class Client {
	private String coordonnee;
	private	String adressePostale;
	private String identifiant;
	private CarteFidelite carteFidelite;
	
	public Client(String c, String a, String ad) {
		coordonnee = c; adressePostale = a; identifiant = ad;
		carteFidelite = new CarteFidelite();
	}

	public String toString() {
		return 	"-----------------CLIENT-------------------\n" +
				"Coordonnee : " + coordonnee + "\n" +
				"Adresse Postale : " + adressePostale + "\n" +
				"ID : " + identifiant + "\n" +
				"Nbr de Points : " + carteFidelite.getPts();
	}
	
	public void info() {
		System.out.println(this.toString());
	}
	
	public String getID() {
		return identifiant;
	}
	
	public CarteFidelite getCarte() {
		return carteFidelite;
	}
}