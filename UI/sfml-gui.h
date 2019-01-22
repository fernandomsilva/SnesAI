#include <SFML/Graphics.hpp>
#include <iostream>

typedef unsigned char		uint8;
typedef unsigned short		uint16;
typedef unsigned int		uint32;

#define GUI_MAINLOOP_SUCCESS 1
#define GUI_MAINLOOP_WINDOW_CLOSED 0

class SFMLGUI {
private:
	int windows_width;
	int windows_height;
	sf::RenderWindow* window;
	sf::Texture* frame_texture;
	sf::Sprite* frame_sprite;
	sf::Uint8* pixel_buffer;

public:
	SFMLGUI(int width = 256, int height = 224);

	int mainLoop(sf::Uint8* framebuffer);

	void paintPixel(sf::Uint8* pixel_array, int x, int y, sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 a);
};