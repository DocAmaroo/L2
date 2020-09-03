package quincaillerie;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public abstract class PieceComposite extends Piece {

	private ArrayList<Piece> listeComposant = new ArrayList<Piece>();
	
	public PieceComposite(String nom, String reference) {
		super(nom, reference);
	}
	
	public double getDureeFabrication() {
		return Collections.max(listeComposant, Comparator.comparing(Piece::getDureeFabrication)).getDureeFabrication();
	}

	public double getGarantie() {
		return Collections.min(listeComposant, Comparator.comparing(Piece::getGarantie)).getGarantie();
	}
	
	public abstract String getInfos();
	
	public void ajouterPiece(Piece p){
		listeComposant.add(p);
	}
	
	public double getPrix(){
		
		double total = 0;
		
		for (Piece p : listeComposant){
			total += p.getPrix();
		}
		
		return total;
	}
	
	public String printListeComposant(String space){
		String res = "";
		int taille = listeComposant.size() - 1; 
		for (int i = 0; i < taille; i++){

			res += space + listeComposant.get(i).libelle() + "\n";
		}
		res += space + listeComposant.get(taille).libelle();
		return res;
	}

	
	public String libelle() {
		String res = "";
		res += getNom() + " - " + getReference();
		res += "\n"+printListeComposant("      ");
		return res;
	}
	
	@Override
	public String toString() {
		String res = "";
		res += "\nprix : " + getPrix() + "euros\n";
		res += "garantie : " + getGarantie() +"mois\n";
		res += "duree de fabrication : " + getDureeFabrication() + "jour(s)\n";
		res += getInfos();
		res += "\n";
		res += "composant(s) : \n"+printListeComposant("  ");
		return super.toString() + res;
	}
}
