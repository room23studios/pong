#include "button.hpp"

Button::Button(std::string textString,
			   	sf::RenderWindow & win,
			   	sf::Color backgroundColor = sf::Color::White,
			   	sf::Color textColor = sf::Color::Black,
 		   	   	std::string fontAddress = "/usr/share/fonts/truetype/freefont/FreeSans.ttf",
			   	int characterSize = 10) : window(win) {
	font.loadFromFile(fontAddress);
	text.setFont(font);
	text.setColor(textColor);
	text.setString(textString);
	text.setCharacterSize(characterSize);

}
void Button::draw() {
	window.draw(background);
	window.draw(text);

}
void Button::setPosition (float x, float y, float width, float height){
	background.setPosition(x, y);
	background.setSize( sf::Vector2f(width , height));
	text.setPosition( x + width / 2 - text.getLocalBounds().width / 2, y + height / 2 - text.getLocalBounds().height / 2);
}
bool Button::isClicked(sf::Event event){
	if(event.mouseButton.x > background.getPosition().x
		&& event.mouseButton.x < background.getPosition().x + background.getSize().x
		&& event.mouseButton.y > background.getPosition().y
		&& event.mouseButton.y < background.getPosition().y + background.getSize().y)
	return true;
	return false;
}
