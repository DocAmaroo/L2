package tp1;

import java.util.Scanner;

public class ProgrammePersonne {
	
	public static void maint(String args){
		Scanner clavier = new Scanner(System.in);
		Personne p = new Personne();
		p.setNom("Jules");
		p.setNom(clavier.next());
		System.out.println(p);
	}
}
