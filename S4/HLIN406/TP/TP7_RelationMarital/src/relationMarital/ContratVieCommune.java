package relationMarital;

import java.util.Calendar;

public class ContratVieCommune {
	private int dateDebut;
	private int dateFin = -1;
	private Personne personne1;
	private Personne personne2;
	
	public ContratVieCommune(int dateDebut, Personne personne1, Personne personne2) {
		this.dateDebut = dateDebut;
		this.personne1 = personne1;
		this.personne2 = personne2;
	}

	// ------ GETTER AND SEEDERS ------ //
	public Personne getPersonne1() {
		return personne1;
	}

	public Personne getPersonne2() {
		return personne2;
	}
	
	public int getDateDeb() {
		return dateDebut;
	}

	public int getDateFin() {
		return dateFin;
	}
	// -------------------------------- //
	
	public void add(){
		personne1.ajoutContrat(this);
		personne2.ajoutContrat(this);
	}
	
	public void resiliation(){
		if (personne1.estAvec() == personne2 && personne2.estAvec() == personne1){
			dateFin = Calendar.getInstance().getWeekYear();	
		}
		else{
			System.out.print("Impossible de résilier le contrat");
		}
	}

	@Override
	public String toString() {
		return "Contrat : [ " + dateDebut + " : " + ((dateFin == -1)? "En cours" : dateFin) + " ] \npersonne1 [ " + personne1 + " ]"
				+ "\npersonne2 [ " + personne2 + " ]";
	}


}
