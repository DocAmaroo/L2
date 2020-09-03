package Quincaillerie;

public class PieceKit extends PieceComposite {

	public PieceKit(String name, String ref, int mon, int jour, int mois, int mont) {
		super(name, "01"+ref, mon, jour, mois, mont);
	}

}
