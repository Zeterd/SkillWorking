import java.io.Console;
import java.util.Scanner;
//package pack;
public class Main {
	public static void menu(){
		System.out.println("------------MENU------------");
		System.out.println("----------------------------");
		System.out.println("	   	1 - Registar		");
		System.out.println("	   	2 - Login 			");
		System.out.println("	   	3 - Ajuda			");
		System.out.println("	   	4 - Contactos		");
	}

	public static void main(String []args){
		Scanner input = new Scanner(System.in);
		Console cons = System.console();
		Utilizador[] users = new Utilizador[10];
		 
		int n_res = 0; //numero de users registados

		menu();

		while(true){
			int op = input.nextInt();

			if(op == 1){
				System.out.println("------- REGISTO -------");

				System.out.print("Primeiro Nome: ");
				String firstName = input.next();


				System.out.print("Idade: ");
				int idade = input.nextInt();
				
				System.out.print("Ultimo Nome: ");
				String lastName = input.next();

				System.out.print("NIF: ");
				int nif = input.nextInt();
				
				System.out.print("Sexo(M/F): ");
				String sexo = input.next();

				System.out.print("Contacto telefonico: ");
				int  cont_tel = input.nextInt();

				char[] password = new char[20];
				
				try {
					password = cons.readPassword("Password:");
				}
				finally {
					if(password != null)
						java.util.Arrays.fill(password, ' ');
				}

				users[n_res] = new Utilizador(firstName, lastName, idade, sexo, nif, cont_tel, password);
				users[n_res].setID(n_res);
				n_res++;

				System.out.println("Registado com sucesso!!");
				System.out.println("Bem-vindo ID: " + n_res-1);

			}
			else if(op == 2){
				System.out.println("------- LOGIN -------");


			}
			else{
				break;
			}
			System.out.println("\n\n");
			menu();

		}

	}
}

class Utilizador {
	String p_nome;
	String u_nome;
	String sexo;
	char[] password = new char[20];
	int idade;
	int nif;
	int cont_tel;
	
	int id;
	int carteira;
	int pontos;

	public Utilizador(String p_nome, String u_nome, int idade, String sexo, int nif, int cont_tel, char[] password){
		this.p_nome = p_nome;
		this.u_nome = u_nome;
		this.sexo = sexo;
		this.idade = idade;
		this.nif = nif;
		this.cont_tel = cont_tel;
		this.password = password;
		this.pontos = 0;
		this.carteira = 0;
		this.id= 0;

	}

	public String getName(){
		return p_nome + " " + u_nome;
	}

 	public int getAge(){
 		return idade;
 	}

 	public String getSex(){
 		if(sexo.equals("M"))
 			return "Masculino";
 		else if(sexo.equals("F"))
 			return "Femenino";
 		else
 			return "Nao especificado"; 
 	}

 	public int getNif(){
 		return nif;
 	}

 	public int getContTel(){
 		return cont_tel;
 	}
 	public int getID(){
 		return id;
 	}

 	private void setPassword(char[] password){
 		this.password = password;
 	}

 	public void setID(int id){
 		this.id = id;
 	}

 	public void setPoints(int pontos){
 		this.pontos = pontos;
 	}

 	public void setWallet(int carteira){
 		this.carteira = carteira;
 	}
}