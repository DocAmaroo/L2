package tp6;

import java.util.ArrayList;

public class Contributeur extends Personne {
	private ArrayList<Contribution> contributeur = new ArrayList<> ();
	
	
	public Contributeur(String m, String p, int a) {
		super(m, p, a);
		contributeur = null;
		// TODO Auto-generated constructor stub
	}
	
	public Contribution getContributeur(int i){
		return contributeur.get(i);
	}
	
	public void contribue(Notice a, ArrayList<Role> wow){
		Contribution nouveau = null;
		nouveau.setNotice(a);
		nouveau.setListRole(wow);
		contributeur.add(nouveau);
	}

}
