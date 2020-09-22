import java.io.Console;

class Main {
	public static void interfMENU(){
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

		interfMENU();

		while(true){
			String op = input.nextInt();

			if(op == 1){
				System.out.println("------- REGISTO -------");

				System.out.print("Primeiro Nome: ");
				String firstName = input.nextLine();

				System.out.print("Ultimo Nome: ");
				String lastName = input.nextLine();

				System.out.print("Idade: ");
				int idade = input.nextInt();

				System.out.print("Sexo(M/F): ");
				String sexo = input.nextLine();

				System.out.print("NIF: ");
				String nif = input.nextLine();

				System.out.print("Contacto telefonico: ");
				String cont_tel = input.nextLine();

				try {
					String password = cons.readPassword("Password:");
				}
				finally {
					if(password != null)
						java.util.Arrays.fill(password, ' ');
				}
				
			}

		}

	}
}