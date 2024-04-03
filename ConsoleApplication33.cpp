#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
int main(){
	RenderWindow window(VideoMode(800, 600), "google dinasaur");
	Style::Close|Style::Titlebar;
	Texture backgroundtexture;
	backgroundtexture.loadFromFile("C://Users//sohas//source//repos//ConsoleApplication33//image//image.png");
	Sprite background;
	background.setTexture(backgroundtexture);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

	}
	
	

	window.clear();
	window.draw(background);
	window.display();
	return 0;
}