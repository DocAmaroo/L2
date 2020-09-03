package tp6;

public class Exemplaire {
	private Notice livre;
	private boolean disponible;
	private Abonne emprunteur;
	
	
	public Exemplaire(Notice liv) {
		livre = liv;
		disponible = true;
		emprunteur = null;
	}
	
	public Notice getLivre(){
		return livre;
	}
	public boolean getDisponible(){
		return disponible;
	}
	public void emprunte(Abonne a){
		disponible = false;
		emprunteur = a;
	}
	public void rendre(){
		disponible = true;
	}
	public Abonne getAbonne(){
		return emprunteur;
	}

}
