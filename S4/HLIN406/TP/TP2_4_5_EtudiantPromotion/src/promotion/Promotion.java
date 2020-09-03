package promotion;

import java.util.ArrayList;
import java.time.LocalDate;

public class Promotion {

	// Liste d'étudiant
	private ArrayList<Etudiant> liste_etudiant;
	
	//-- CONSTRUCTEURS PAR DEFAULT
	public Promotion(int _annee){
		this.liste_etudiant = new ArrayList<Etudiant>();
		this.annee = _annee;
	}
	
	public Promotion(){
		this(LocalDate.now().getYear());
	}
	
	//LISTE ETUDIANT
	public void setListeEtudiant(ArrayList<Etudiant> liste){
		this.liste_etudiant = liste;
	}
	
	//ANNEEE
	private int annee;
	
	//-- ACCESSEUR
	public int getAnnee(){
		return annee;
	}
	
	//-- RECUPERE IEME ETUDIANT
	public Etudiant getEtudiant(int numero){
		int taille_liste = liste_etudiant.size();
		if (numero > taille_liste){
			System.out.println("[ ERROR ] L'élève n° " + numero + " n'est pas disponible !");
			return null;
		}
		
		else{ return liste_etudiant.get(numero); }
	}
	
	public int getNbEtudiant(){ return liste_etudiant.size(); }
	
	public void inscrire(Etudiant etudiant){ liste_etudiant.add(etudiant); }
	
	public double moyenneGeneral(){
		double res = 0;
		
		for (int i = 0; i < liste_etudiant.size(); i++) {
			res += liste_etudiant.get(i).getMoyenne();
		}
		
		return res / liste_etudiant.size();
	}
	
	public void afficheResultats() {
		for (Etudiant etudiant : liste_etudiant) {
			System.out.println(etudiant.ligneResultat());
		}
	}
	
	public Etudiant rechercher(String nomEtudiant) {
		for (Etudiant etudiant : liste_etudiant) {
			if(etudiant.getNom() == nomEtudiant) return etudiant;
		}
		return null;
	}
	
	// Liste des admis
	public ArrayList<Etudiant> listeAdmis() {
		ArrayList<Etudiant> admis = new ArrayList<Etudiant>();
		for (Etudiant e : liste_etudiant) {
			if(e.getMoyenne() > 10) admis.add(e);
		}
		return admis;
	}
	
	// Liste des etudiants inscris qui ne sont pas francophones.
	
	public ArrayList<Etudiant> inf() {
		ArrayList<Etudiant> nonfranco = new ArrayList<Etudiant>();
		for (Etudiant e : liste_etudiant) {
			if(e.getCodePays() != 33) nonfranco.add(e);
		}
		return nonfranco;
	}
	
	// Renvoi les majors de la promotion
	public ArrayList<Etudiant> getMajors() {
		ArrayList<Etudiant> majors = new ArrayList<Etudiant>();
		
		for (Etudiant e : liste_etudiant) {
			if(majors.size() < 5) majors.add(e);
			else {
				double moyenne = e.getMoyenne();
				for (int i = 0; i < majors.size(); i++) {
					if(majors.get(i).getMoyenne() < moyenne) {
						majors.remove(i); majors.add(e);
						break;
					}
				}
			}
		}
		return majors;
	}
	
}
