package Quincaillerie;

public abstract class Piece {
	private String nom;
	private String reference;
	private int prix;
	private int fabrication;
	private int garantie;
	
	public Piece(String name, String ref, int mon, int jour, int mois) {
		nom = name; reference = ref; prix = mon; fabrication = jour; garantie = mois;
	}
	
	public String toString() {
		return 	"-------PIECE--------\n" +
				"nom : " + nom + "\n" +
				"reference : " + reference + "\n" +
				"prix : " + prix + " € " + "\n" +
				"fabrication : " + fabrication + " (jour.s)" + "\n" +
				"garantie : " + garantie + " (mois)" + "\n";
	}
	
	public void info() {
		System.out.println(this.toString());
	}
	
	public int getPrix() {
		return prix;
	}
	
	public void add(int x){prix += x;}
	
	public String getReference() {
		return reference;
	}
}
