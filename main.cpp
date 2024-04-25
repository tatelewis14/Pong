#include"Global.hpp"
#include<iostream>
#include<SFML/Graphics.hpp>
#include<array>
#include"Paddle.hpp"
#include"Ball.hpp"
#include"Text.hpp"
#include"BulletManager.hpp"
#include<vector>

int main()
{
    BulletManager bullet_manager;

    Paddle paddle = Paddle();
    Paddle ai_paddle = Paddle();
    Ball ball = Ball(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 1,1,15);

    paddle.setPaddleDest(sf::Vector2f(0, (SCREEN_HEIGHT / 2) - paddle.getSize().y / 2));

    ai_paddle.getShape().setFillColor(sf::Color::Red);
    ai_paddle.getShape().setPosition(sf::Vector2f(10, 0));


    float key_hold_time = 1.f;

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
                if (event.key.code == sf::Keyboard::W) {
                    paddle.movePaddleDest(sf::Vector2f(0, -PADDLE_SPEED * key_hold_time));
                    key_hold_time++;
                }
                else if (event.key.code == sf::Keyboard::S) {
                    paddle.movePaddleDest(sf::Vector2f(0, PADDLE_SPEED * key_hold_time));
                    key_hold_time++;
                }
            }
                if (event.type = sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::S) key_hold_time = 1;
                }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            float angle = atan2(sf::Mouse::getPosition(window).y - paddle.getPosition().y, sf::Mouse::getPosition(window).x - paddle.getPosition().x);
            float vx = cos(angle) * BULLET_SPEED;
            float vy = sin(angle) * BULLET_SPEED;
            bullet_manager.shoot(paddle.getPosition().x, paddle.getPosition().y + paddle.getSize().y/2, vx, vy);
        }

        if (ball.getPosition().x < SCREEN_WIDTH / 2) ai_paddle.setPaddleDest(sf::Vector2f(0, ball.getPosition().y - ai_paddle.getSize().y / 2));
        else ai_paddle.setPaddleDest(sf::Vector2f(0, (SCREEN_HEIGHT / 2) - ai_paddle.getSize().y/2));
        ai_paddle.interpolatePosition(0.05f);


    window.clear();

    //write(window, font, "Hello world!", 300, 400);
    paddle.interpolatePosition(0.1);
    
    ball.update();
    ball.check_rect_collision(paddle.getShape());
    ball.check_rect_collision(ai_paddle.getShape());

    paddle.draw(window);
    ai_paddle.draw(window);

    ball.draw(window);
    ball.check_bullet_collision(bullet_manager.getBullets());

    bullet_manager.render(window);
    bullet_manager.detect_collision(ball.getShape());
    bullet_manager.update();

    window.draw(center_line, 2, sf::Lines);
    window.display();
    }   

    return 0;
}
