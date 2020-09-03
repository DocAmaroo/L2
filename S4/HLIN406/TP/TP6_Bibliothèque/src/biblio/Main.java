package biblio;

public class Main {

	public static void main(String[] args) {
		Contributeur Daniel = new Contributeur("Daniel","Pennac");
		Notice numero1 = new Notice("AAA","La fée carabine","Le sous-titre",Public.enfant);
		Contribution numero1daniel = new Contribution(Role.Auteur,numero1,Daniel);
		numero1daniel.add();
		System.out.println("Daniel :" + Daniel + "\n");
		System.out.println("numero1 :" + numero1 + "\n");
		System.out.println("numero1daniel :" + numero1daniel + "\n");
	}

}
