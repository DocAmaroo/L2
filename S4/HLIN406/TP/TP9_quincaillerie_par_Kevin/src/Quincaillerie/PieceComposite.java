package Quincaillerie;

import java.util.ArrayList;

public abstract class PieceComposite extends Piece{

	private int montage;
	private ArrayList<Piece> composants;
	
	public PieceComposite(String name, String ref, int mon, int jour, int mois, int mont) {
		super(name, ref, mon, jour, mois);
		montage = mont;
		composants = new ArrayList<Piece>();
	}

	public void ac(Piece p){
		this.add(p.getPrix());
		composants.add(p);
	}
	
	public String toString() {
		String res = super.toString() + "\n" +
				"montage : " + montage + " (min)" + "\n";
		for(Piece p : composants) {
			res += "+ --> " + p.toString() + "\n";
		}
		return res;
	}
	
}
