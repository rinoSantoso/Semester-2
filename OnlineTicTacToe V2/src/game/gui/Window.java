package game.gui;

import java.awt.Dimension;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JFrame;

import game.Game;

// Base display window, the frame for the game
public class Window extends JFrame{

	private static final long serialVersionUID = 1L;
	
	private Game game;
	
	// Constructor for the window, includes the title, and size
	public Window(Game game, String title, int width, int height) {
		super(title);
		this.game = game;
		setResizable(false);
		getContentPane().setPreferredSize(new Dimension(width, height));
		pack();
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLocationRelativeTo(null);
		addWindowListener(new Listener());
	}
	
	// Listener class, detects if the window is closed
	class Listener extends WindowAdapter{
		@Override
		public void windowClosing(WindowEvent e) {
			game.close();
		}
	}
}
