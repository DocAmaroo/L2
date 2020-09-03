package laponie;

import java.util.ArrayList;

public class SacPostal {

	private ArrayList<ObjetPostaux> obj;
	private double capaciteMax = 0.5;
	private double capacite;
	
	// CONSTRUCTEUR PAR DEFAULT
	public SacPostal(){
		this.obj = new ArrayList<ObjetPostaux>();
	}
	
	public SacPostal(double _capacite){
		this.obj = new ArrayList<ObjetPostaux>();
		this.capaciteMax = _capacite;
	}
	
	// ACCESSEURS EN LECTURE
	public double getCapaciteRestante(){
		return capaciteMax - capacite;
	}
	
	public double getCapacite(){
		return this.capacite;
	}
	
	// AJOUTER UN OBJET
	public boolean Ajout(ObjetPostaux objet){
		if( this.capaciteMax < (this.capacite + objet.getVolume()) ){
			return false;
		}
		
		obj.add(objet);
		this.capacite += objet.getVolume();
		return true;
	}
	
	public double tarifRemboursement(){
		double som = 0;
		for (int i = 0; i < obj.size(); i++) {
			som += obj.get(i).tarifRemboursement();
		}
		return som;
	}
	
}
