#include <SFML/Graphics.hpp>

class Menu{
public:
	Menu();
	void show();
	void refresh();
	sf::String inputString;
	sf::Text pongText;
private:
	sf::Font font;
};
