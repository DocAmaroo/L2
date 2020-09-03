package quincaillerie;

public class PieceBase extends Piece {
	
	private double prix;
	private double garantie;
	private int dureeFabrication;

	public PieceBase(String nom, String reference, double prix, double garantie, int dureeFabrication) {
		super(nom, reference);
		this.prix = prix;
		this.garantie = garantie;
		this.dureeFabrication = dureeFabrication;
	}
	
	public double getPrix() {
		return prix;
	}

	public double getGarantie() {
		return garantie;
	}

	public double getDureeFabrication() {
		return dureeFabrication;
	}
	
	public String getPrefixeReference(){
		return "00";
	}
	
	public String libelle(){
		return getNom() + " - " + getReference();
	}
	
	@Override
	public String toString() {
		String res = "";
		res += "\nprix : " + getPrix() + "euros\n";
		res += "garantie : " + getGarantie() +"mois\n";
		res += "duree de fabrication : " + getDureeFabrication() + "jour(s)\n";
		return super.toString() + res;
	}
}
