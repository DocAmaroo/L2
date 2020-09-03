package biblio;

public class Contribution {
	private Role roles;
	private Notice notices;
	private Contributeur contributeurs;
	
	public Contribution(Role roles, Notice notices, Contributeur contributeurs) {
		this.roles = roles;
		this.notices = notices;
		this.contributeurs = contributeurs;
	}

	public void add(){
		notices.addContributions(this);
		contributeurs.addContribution(this);
	}
	
	public String toString(){
		return "Contributeur: " + contributeurs.getName() + " |Role :" + roles.name() + " |Notice: " + notices;
	}
}
