package tp6;

import java.util.ArrayList;

public class Contribution {
	private Notice livre;
	private ArrayList<Role> metier = new ArrayList<> ();
	
	public Contribution() {
		livre = null;
		metier = null;
		// TODO Auto-generated constructor stub
	}
	
	public Notice getNotice(){
		return livre;
	}
	public void setNotice(Notice a){
		livre = a;
	}
	public void setRole(Role a){
		metier.add(a);
	}
	public Role getRole(int i){
		return metier.get(i);
	}
	
	public void setListRole(ArrayList<Role> wow){
		metier = wow;
	}
	
	
}
