package tp6;

import java.util.ArrayList;

public class Abonne extends Personne{
	private boolean mineur;
	private ArrayList<Exemplaire> emprunte = new ArrayList<>();
	private Public model;
	

	public Abonne(String m, String p, int a) {
		super(m, p, a);
		mineur = mineur(a);
		emprunte = null;
		model = modele(a);
		
}
	private Public modele(int age){
		if (age<8){
			return Public.Enfant;
		}
		if(age<16){
			return Public.Junior;
		}
		else{
			return Public.Adulte;
		}
	}
	
	public boolean mineur(int age){
		if(age<18){
			return true;
		}
		else{
			return false;
		}
	}
	
	public void emprunte(Exemplaire livre){
		if( !emprunte.contains(livre) && (emprunte.size()<5) && livre.getDisponible())
		{
			if(model == Public.Enfant)
			{
				if(livre.getLivre().getPegi() != model)
				{
					System.out.println("Vous êtes trop jeune");
				}
			}
			if(model == Public.Junior)
			{
				if(livre.getLivre().getPegi() == Public.Adulte)
				{
					System.out.println("Vous êtes trop jeune");
				}
			}
			else{
				emprunte.add(livre);
				livre.emprunte(this);
			}
		}
	}
	
	public void rendre(Exemplaire livre){
		if(emprunte.contains(livre))
		{
			emprunte.remove(livre);
			livre.rendre();
		}
	}
	
}