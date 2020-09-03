package quincaillerie;

public abstract class Piece {
	private String nom;
	private String reference;
	
	public Piece(String nom, String reference) {
		this.nom = nom;
		this.reference = getPrefixeReference()+reference;
	}
	
	public String getNom() {
		return nom;
	}
	
	public String getReference() {
		return reference;
	}
	
	public abstract String getPrefixeReference();
	public abstract String libelle();
	public abstract double getDureeFabrication();
	public abstract double getGarantie();
	public abstract double getPrix();

	public String toString() {
		return "nom : " + getNom() + "\nreference : "+ getReference();
	}
}
