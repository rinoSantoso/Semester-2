package game;

import javax.swing.JOptionPane;

import game.gui.GameWindow;

public class Main {
	//Asks the user if they want to create a server or connect as a client
	public static void main(String[] args) {
		int choice = Integer.parseInt(JOptionPane.showInputDialog("1 for server | 2 for client"));
		
		if (choice == 1) {
			new ServerGame();
		}
		else if (choice == 2) {
			new ClientGame();
		}
	}
}
