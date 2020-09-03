package Quincaillerie;

public class PieceMontee extends PieceComposite {

	private int prixMontage;
	
	public PieceMontee(String name, String ref, int mon, int jour, int mois, int mont, int prix) {
		super(name, "02"+ref, mon+prix, jour, mois, mont);
		prixMontage = mon;
	}

	public String toString() {
		return super.toString() + "\n" +
						"----------------------------------\n" +
						"Prix Montage : " + prixMontage + "\n";
	}
}
