package game.res;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

// Resource class to contain the graphics of the game such as the X and O images
public class Resources {
	
	public static BufferedImage[] letters;
	
	// Initializing the images
	static {
		letters = new BufferedImage[2];
		letters[0] = loadImage("D:/Documents/Rino School Work/School Work/University/Eclipse/OnlineTicTacToe V2/res/x.png");
		letters[1] = loadImage("D:/Documents/Rino School Work/School Work/University/Eclipse/OnlineTicTacToe V2/res/o.png");
	}
	
	// Method to load the image
	private static BufferedImage loadImage (String path) {
		try {
			return ImageIO.read(new File(path));
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(-1);
		}
		return null;
	}
	
}
