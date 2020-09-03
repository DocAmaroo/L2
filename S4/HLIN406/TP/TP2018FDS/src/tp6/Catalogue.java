package tp6;

import java.util.Hashtable;

public class Catalogue {
	private Hashtable<String,Notice> listnotice = new Hashtable<>();

	public Catalogue() {
	}
	
	public void ajouter(Notice e){
		listnotice.put(e.getIden(), e);
	}
	
	public Notice chercher(String isbn){
		if(listnotice.containsKey(isbn)){
			return listnotice.get(isbn); 
		}
		return null;
	}
	
	public void retirer(Notice e){
		if(listnotice.contains(e)){
		listnotice.remove(e);	
		}
	}
	
	
	

}
