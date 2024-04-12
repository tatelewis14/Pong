#include"SFML/Graphics.hpp"
#include<string>
#include<iostream>

void write(sf::RenderWindow& window, sf::Font font, std::string message, float x, float y) {
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Font couldn't be loaded!\n";
        return;
    }

    sf::Text text;
    text.setString(message);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(x, y);
    window.draw(text);
}