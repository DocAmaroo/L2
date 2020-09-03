package laponie;

import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
	
		ArrayList<ObjetPostaux> object = new ArrayList<>();
		
		object.add(new Lettre("Paris","20 rue des amandier",34980,3,0.02,TauxR.un,true));
		object.add(new ColisExpress("Bruxelle", "10 avenue des cacahuete", 34270, 32.1, 2.3, TauxR.deux, 10.0, "Un nain de jardin", true));
		object.add(new Lettre("Niger","connait pas d'adresse",12000,4,1.2,TauxR.zero,true));
		object.add(new Colis("France","Somewhere",34980,3.0,0.02,TauxR.deux,10.0,"UnRasoirAQt"));
		object.add(new ColisExpress("France", "Jesaispasou", 34271, 32.1, 2.3, TauxR.deux, 10.0, "ToujoursUnRasoirBizarre", true));
		object.add(new Colis("France","Somewhere",34980,3.0,0.02,TauxR.deux,10.0,"UnRasoirPasBeau"));
		object.add(new ColisExpress("France", "Jesaispasou", 34272, 2, 2.3, TauxR.deux, 10.0, "UnRasoirLunette", true));
		
//		for (int i = 0; i < object.size(); i++) {
//			System.out.println(object.get(i).toString());
//		}
		
		SacPostal sac = new SacPostal();
		
		for (int i = 0; i < 7; i++) {
			if (!sac.Ajout(object.get(i))){
				System.out.println("L'objet " + object.get(i).toString() + " ne rentre pas");
				System.out.println("Le volume restant est de : " + sac.getCapaciteRestante());
			}
			sac.Ajout(object.get(i));
		}
		
	}

}