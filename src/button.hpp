#include <SFML/Graphics.hpp>

class Button {
public:
	Button(std::string textString,
		   	sf::RenderWindow & win,
		   	sf::Color backgroundColor,
		   	sf::Color textColor,
		   	std::string fontAddress,
		   	int characterSize );
	void draw();
	void setPosition(float x, float y, float width, float height);
	void setPosition(sf::Vector2f vector);
	bool isClicked(sf::Event event);

	sf::RenderWindow & window;
	int width, height;
	sf::Color backgroundColor;
	sf::Color textColor;
 	std::string fontAddress;
	std::string textString;
	int characterSize;
private:
	sf::Text text;
	sf::Font font;
	sf::RectangleShape background;
	sf::Event event;
};
