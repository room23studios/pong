#include "menu.hpp"

Menu::Menu() {
	font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeSans.ttf");
	pongText.setFont(font);
	pongText.setString("PONG");
	pongText.setCharacterSize(50);
	pongText.setPosition(280, 180);
	pongText.setColor(sf::Color::White);
}
void Menu::refresh(){

}
