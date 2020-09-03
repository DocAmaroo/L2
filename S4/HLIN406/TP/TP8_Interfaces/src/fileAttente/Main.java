package fileAttente;

import java.util.ArrayList;
import java.util.Collections;

public class Main {

	public static void main(String[] args){
		FileAttenteStat file = new FileAttenteStat();
		Personne p1 = new Personne("Bobby", "lapointe",3);
		Personne p2 = new Personne("Jacquie", "Michel", 65);
		Personne p3 = new Personne("Bob", "l'Eponge", 14);
		file.entre(p1);
		file.entre(p2);
		file.entre(p3);
		//file.sort()
		//System.out.println("Nombre d'entrée : " + file.nbEntrees());
		//System.out.println("Nombre de sortie : " + file.nbSorties());

		//System.out.println(file.max());

		ArrayList<Personne> list = new ArrayList<Personne>();
		list.add(p1); list.add(p2); list.add(p3);
		
		System.out.println(list);
		Collections.sort(list);
		System.out.println(list);
		Collections.sort(list, new ComparateurParAge<>());
		System.out.println(list);
	}
	
	
}
