package Quincaillerie;

public class PieceBase extends Piece {

	public PieceBase(String name, String ref, int mon, int jour, int mois) {
		super(name, "00"+ref, mon, jour, mois);
	}
	
}
