package fileAttente;

import java.util.Comparator;

public class ComparateurParAge<T extends Personne> implements Comparator<T>{

	@Override
	public int compare(T p1, T p2) {
		int ageP1 = p1.getAge();
		int ageP2 = p2.getAge();
		if( ageP1 > ageP2 ) return 1;
		else if ( ageP1 < ageP2 ) return -1;
		else return 0;
	}	
}
