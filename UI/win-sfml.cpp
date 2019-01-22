#include "sfml-gui.h"
#include <fstream>
#include <iostream>

typedef unsigned char		uint8;

/*
FIRST NUMBER: Number of elements (including 3 RGBs)
SECOND NUMBER: Number of pixels per row (no including 3 RGBs)
*/
int main() {

	// Reading framebuffer
	std::fstream buffer_file;
	buffer_file.open("framebuffer.txt");

	int pixelPerRow = 0, screenSize = 0;
	buffer_file >> screenSize >> pixelPerRow;
	std::cout << screenSize << "---" << pixelPerRow;

	sf::Uint8* framebuffer = new sf::Uint8[screenSize];
	sf::Uint8* fb_pointer = framebuffer;

	int r, g, b;
	while (buffer_file >> r >> g >> b) {
		*(fb_pointer++) = (sf::Uint8)(r * 255 / 31);
		*(fb_pointer++) = (sf::Uint8)(g * 255 / 31);
		*(fb_pointer++) = (sf::Uint8)(b * 255 / 31);
	}

	// Create window 
	int windowheight = screenSize / (3 * pixelPerRow);
	int windowwidth = pixelPerRow / 2;
	SFMLGUI sfml_gui(windowwidth, windowheight);

	while (sfml_gui.mainLoop(framebuffer));
}

/*
int main()
{
    // Create the main window
 //   sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML window");
	//
 //   sf::Uint8 pixel_buffer[WIDTH * HEIGHT * 4];
 //   int current = 0;
	//
 //   // Load a sprite to display
 //   sf::Texture texture;
	//sf::Sprite sprite;
	//
	//for (int i=0; i < WIDTH; i++)
	//{
 //         for (int j=0; j < HEIGHT; j++)
 //           {
 //             paint_pixel(pixel_buffer, i, j, current, current, current, 255);
 //           }
	//}

	//texture.create(WIDTH, HEIGHT);
	//texture.update(pixel_buffer);
	//sprite.setTexture(texture);
	
    // Start the game loop
    while (window.isOpen())
      {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
		
	//current = (current + 1) % 256;
	for (int i=0; i < WIDTH; i++)
          {
            for (int j=0; j < HEIGHT; j++)
              {
                paint_pixel(pixel_buffer, i, j, (int)(i * 256 / WIDTH), (int)(i * 256 / WIDTH), (int)(i * 256 / WIDTH), 255);
              }
          }
        texture.update(pixel_buffer);
		
        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(sprite);

        // Draw the string
        //window.draw(text);

        // Update the window
        window.display();
      }
    return EXIT_SUCCESS;
}*/
