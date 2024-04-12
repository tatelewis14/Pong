#include"Global.hpp"
#include<iostream>
#include<SFML/Graphics.hpp>
#include<array>
#include"Paddle.hpp"
#include"Ball.hpp"
#include"Text.hpp"
#include<random>

int main()
{
    Paddle paddle = Paddle();
    Paddle ai_paddle = Paddle();
    Ball ball = Ball();

    ai_paddle.getShape().setFillColor(sf::Color::Red);
    ai_paddle.getShape().setPosition(sf::Vector2f(10, 0));

    ball.setInitialSpeed(sf::Vector2f(1, 1));

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong");
    window.setFramerateLimit(120);

    sf::Vertex center_line[] = {
        sf::Vertex(sf::Vector2f(SCREEN_WIDTH/2.f, 0.f)),
        sf::Vertex(sf::Vector2f(SCREEN_WIDTH/2.f, SCREEN_HEIGHT))
    };
    for (int i = 0; i < 2; ++i) {
        center_line[i].color = sf::Color::White;
    }
    /*
    sf::Font font;
    if (!font.loadFromFile("./rushford/Rushfordclean - rgz89.otf")) {
        std::cout << "Font couldn't be loaded\n";
        return EXIT_FAILURE;
    */

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    paddle.movePaddleDest(sf::Vector2f(0, -PADDLE_SPEED));
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    paddle.movePaddleDest(sf::Vector2f(0, PADDLE_SPEED));
                }
            }
            
        }
    
        ai_paddle.setPaddleDest(sf::Vector2f(0, ball.getPosition().y - ai_paddle.getSize().y/2));
        ai_paddle.interpolatePosition(0.1f);


    window.clear();
    //write(window, font, "Hello world!", 300, 400);
    paddle.interpolatePosition(0.1f);
    
    ball.update();
    
    ball.checkCollision(paddle.getShape());
    ball.checkCollision(ai_paddle.getShape());

    paddle.draw(window);
    ai_paddle.draw(window);
    ball.draw(window);
    window.draw(center_line, 2, sf::Lines);
    
    window.display();
    }   

    return 0;
}
