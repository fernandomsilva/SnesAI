#include "sfml-gui.h"

SFMLGUI::SFMLGUI(int width, int height) : windows_width(width), windows_height(height)
{
	window = new sf::RenderWindow(sf::VideoMode(windows_width, windows_height), "Snes9x Deux Ex Machina");

	// Create Sprite with texture that fills the entire screen
	frame_texture = new sf::Texture();
	frame_sprite = new sf::Sprite();

	frame_texture->create(windows_width, windows_height);
	pixel_buffer = new sf::Uint8[windows_width * windows_height * 4];
	//texture.update(pixel_buffer);													<-delete this if nothing goes wrong
	frame_sprite->setTexture(*frame_texture);
}

void SFMLGUI::changeWindowSize(int width, int height) {
	windows_width = width;
	windows_height = height;
	window->setSize(sf::Vector2u(windows_width, windows_height));
	
	delete frame_texture;
	delete frame_sprite;
	delete[] pixel_buffer;

	// Create Sprite with texture that fills the entire screen
	frame_texture = new sf::Texture();
	frame_sprite = new sf::Sprite();

	frame_texture->create(windows_width, windows_height);
	pixel_buffer = new sf::Uint8[windows_width * windows_height * 4];
	//texture.update(pixel_buffer);													<-delete this if nothing goes wrong
	frame_sprite->setTexture(*frame_texture);
}

/*
	Input:	framebuffer in the format of sf::Uint8

			The implementation assumes that windows height and windows width equals to that of the framebuffer.

			The framebuffer will contain two screens with one screen being completely black, 
				so after reading a *windowwidth* number of pixels, the method skips another *windowwidth* number of pixels.
*/
int SFMLGUI::mainLoop(sf::Uint8* framebuffer)
{
	if (!window->isOpen())
		return GUI_MAINLOOP_WINDOW_CLOSED;

	// Process events
	sf::Event event;
	while (window->pollEvent(event))
	{
		// Close window: exit
		if (event.type == sf::Event::Closed) {
			window->close();
			return GUI_MAINLOOP_WINDOW_CLOSED;
		}
	}

	// Update screen
	int counter = 0, fb_index = 0, x, y;
	sf::Uint8 r, g, b;
	while (counter < windows_width * windows_height)
	{
		r = framebuffer[fb_index];
		g = framebuffer[fb_index + 1];
		b = framebuffer[fb_index + 2];
		x = counter % windows_width;
		y = counter / windows_width;

		paintPixel(pixel_buffer, x, y, r, g, b, 255);

		counter++;
		fb_index += 3;

		if (counter % windows_width == 0)  fb_index += windows_width * 3; // Skip the second buffer pixels.
	}
	frame_texture->update(pixel_buffer);

	// Clear screen
	window->clear();

	// Draw the sprite
	window->draw(*frame_sprite);

	// Draw the string
	//window.draw(text);

	// Update the window
	window->display();
	
	return GUI_MAINLOOP_SUCCESS;
}

void SFMLGUI::paintPixel(sf::Uint8* pixel_array, int x, int y, sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 a)
{
	pixel_array[((x + (y * windows_width)) * 4)] = r;
	pixel_array[((x + (y * windows_width)) * 4) + 1] = g;
	pixel_array[((x + (y * windows_width)) * 4) + 2] = b;
	pixel_array[((x + (y * windows_width)) * 4) + 3] = a;

}