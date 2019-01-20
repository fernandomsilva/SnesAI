#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>

#define WIDTH 516//256
#define HEIGHT 239//224

void paint_pixel(sf::Uint8* pixel_array, int x, int y, sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 a)
{
	pixel_array[((x + (y * WIDTH)) * 4)] = r;
	pixel_array[((x + (y * WIDTH)) * 4) + 1] = g;
	pixel_array[((x + (y * WIDTH)) * 4) + 2] = b;
	pixel_array[((x + (y * WIDTH)) * 4) + 3] = a;
}

void load_file_image(const char *filepath, sf::Uint8* pixel_array)
{
	std::ifstream image_file;
	std::string line;
	
	int x = 0;
	int y = 0;
	int counter = 0;
	sf::Uint8 color, r, g;
	
	image_file.open(filepath);
	while (getline(image_file, line))
	{
		color = std::stoul(line);
		
		if (color < 32) 
		{
			color =  (color * 255) / 31;
			counter = (counter + 1) % 3;
			
			if (counter == 0)
			{
				paint_pixel(pixel_array, x, y, g, color, r, 255); //Looks like it is GBR for some reason
				
				x = (x + 1) % WIDTH;
				if (x == 0) { y = y + 1; }
			}
			else if (counter == 1)
			{
				r = color;
			}
			else
			{
				g = color;
			}
		}
	}
	image_file.close();
}

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML window");
	
	sf::Uint8 pixel_buffer[WIDTH * HEIGHT * 4];
	int current = 0;
	
    // Load a sprite to display
    sf::Texture texture;
	sf::Sprite sprite;
	
	for (int i=0; i < WIDTH; i++)
	{
		for (int j=0; j < HEIGHT; j++)
		{
			paint_pixel(pixel_buffer, i, j, current, current, current, 255);
		}
	}
	
	load_file_image("framebuffer.txt", pixel_buffer);

	texture.create(WIDTH, HEIGHT);
	texture.update(pixel_buffer);
	sprite.setTexture(texture);
	
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
		
		current = (current + 1) % 256;
		/*for (int i=0; i < WIDTH; i++)
		{
			for (int j=0; j < HEIGHT; j++)
			{
				paint_pixel(pixel_buffer, i, j, current, current, current, 255);
			}
		}
		texture.update(pixel_buffer);*/
		
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
}