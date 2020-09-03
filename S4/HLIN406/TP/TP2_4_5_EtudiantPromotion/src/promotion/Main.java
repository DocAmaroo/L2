package promotion;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;

public class Main {
	
	private static LocalDate randomLocalDate() {
		long minDay = LocalDate.of(1990, 1, 1).toEpochDay();
	    long maxDay = LocalDate.of(2000, 12, 31).toEpochDay();
	    long randomDay = ThreadLocalRandom.current().nextLong(minDay, maxDay);
	    
	    return LocalDate.ofEpochDay(randomDay);
	}

	public static void main(String[] args) {
		
		String prenoms[] = {"Michel", "Robert", "Charles", "Enzo", "Maxime", "Thomas", "Jean", "Uther", "Jacques", "Baudouin", "Bilal",
				"Camille", "Lucie", "Kassandra", "Christelle", "Illona", "Sabrina", "Veronica", "Marie", "Ludivine"};
		
		String noms[] = {"VICENTINI", "DESGENETEZ", "CANTA", "REITER", "DESCHAMPS", "KANTE", "ALHABAR", "BUTTERFIELD", "POIKOV", "POIDS", "ROUX", "DUMOULIN"};
		
		Promotion promo = new Promotion(2019);
		
		ArrayList<Etudiant> listeEtudiant = new ArrayList<Etudiant>();
		
		Random rand = new Random();
		for (int i = 0; i < 50; i++) {
			Etudiant etu = new Etudiant(prenoms[rand.nextInt(prenoms.length)], noms[rand.nextInt(noms.length)], 
					randomLocalDate(), i, 33, new double[] {(double)rand.nextInt(21), (double)rand.nextInt(21), (double)rand.nextInt(21)});
			promo.inscrire(etu);
			
			
			listeEtudiant.add(etu);
		}
		
//		promo.afficheResultats();
//		
//		System.out.println("Il y a "+promo.inf().size()+" étudiants non francophones.");
//		for (Etudiant e : promo.getMajors()) {
//			System.out.println(e.getPrenom() + " " + e.getNom());
//		}
		
		
		int moyenne[][] = {{10,0},{11,0},{12,0},{13,0},{14,0},{15,0},{16,0},{17,0},{18,0},{19,0},{20,0}};
		
		for (int i = 0; i < listeEtudiant.size() ; i++) {
			double lamoyenne = listeEtudiant.get(i).getMoyenne();
			if (lamoyenne < 10){}
			else if (lamoyenne < 11){ moyenne[0][1]++; }
			else if (lamoyenne < 12){ moyenne[1][1]++; }
			else if (lamoyenne < 13){ moyenne[2][1]++; }
			else if (lamoyenne < 14){ moyenne[3][1]++; }
			else if (lamoyenne < 15){ moyenne[4][1]++; }
			else if (lamoyenne < 16){ moyenne[5][1]++; }
			else if (lamoyenne < 17){ moyenne[6][1]++; }
			else if (lamoyenne < 18){ moyenne[7][1]++; }
			else if (lamoyenne < 19){ moyenne[8][1]++; }
			else if (lamoyenne <= 20){ moyenne[9][1]++; }
		}
		for (int i = 0; i < moyenne.length; i++) {
			if (i < 9){
				System.out.print("[ " + moyenne[i][0] + " : " + moyenne[i+1][0] + " [");
			}
			else 
				System.out.print("[ " + moyenne[i-1][0] + " : " + moyenne[i][0] + " ]");
			for (int j = 0; j < moyenne[i][1]; j++) {
				System.out.print("*");
			}
			System.out.println("");
		}
	}


}