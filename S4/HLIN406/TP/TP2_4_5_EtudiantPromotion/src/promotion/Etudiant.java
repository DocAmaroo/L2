package promotion;

import java.time.LocalDate;

public class Etudiant {

	private String prenom, nom;
	private LocalDate dateNaissance;
	private int codeIns;
	private int codePays;
	private double notes[] = new double[3]; 

	public Etudiant(String prenom, String nom, LocalDate date, int codeIns, int codePays, double[] notes) {
		this.setPrenom(prenom);
		this.setNom(nom);
		dateNaissance = date;
		this.codeIns = codeIns;
		this.codePays = codePays;
		this.notes = notes;
	}
	
	public Etudiant() {
		this("", "", LocalDate.now(), -1, -1, new double[] {-1D, -1D, -1D});
	}

	public int getAge() {
		return dateNaissance.until(LocalDate.now()).getYears();
	}

	public LocalDate getDateNaissance() { return dateNaissance; }
	public void setDateNaissance(LocalDate date) { dateNaissance = date; }

	public int getCodeIns() { return codeIns; }
	public boolean isInscris() { return codeIns != 0; }
	public void setCodeIns(int codeIns) { this.codeIns = codeIns; }

	public int getCodePays() { return codePays; } 
	public void setCodePays(int codePays) { this.codePays = codePays; }

	public double[] getNotes() { return notes; }
	public void setNotes(double[] notes) { this.notes = notes; }

	public double getMoyenne() {
		return (notes[0]+notes[1]+notes[2])/3;
	}

	public String ligneResultat() {
		double moy = getMoyenne();
		Mention m = Mention.calculerMention(moy);

		return prenom+" "+nom+" a obtenue une moyenne de "+moy+"/20. Mention : "+m+". Phrase du directeur : "+m.getPhrase()+".";
	}

	public Mention getMention() { return Mention.calculerMention(getMoyenne()); }

	public String toString() { return "Etudiant de "+getAge()+" ans. "+(isInscris() ? "Inscris avec le code : "+codeIns+"." : "Non-inscris.")+" Code Pays : "+codePays+"."; }

	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public String getPrenom() {
		return prenom;
	}

	public void setPrenom(String prenom) {
		this.prenom = prenom;
	}
}