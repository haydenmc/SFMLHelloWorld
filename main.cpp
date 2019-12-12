#include <SFML/Graphics.hpp>

static const unsigned int FRAME_RATE = 60u;

int main()
{
    // Set up our rendering window
    sf::RenderWindow window(
        sf::VideoMode(1920, 1080),
        "Hello World",
        sf::Style::Titlebar | sf::Style::Close
    );
    window.setFramerateLimit(FRAME_RATE);

    // Init font + text
    sf::Font segoeFont;
    segoeFont.loadFromFile("C:\\Windows\\Fonts\\seguibl.ttf");
    sf::Text helloWorldText;
    helloWorldText.setFont(segoeFont);
    helloWorldText.setCharacterSize(64);
    helloWorldText.setFillColor(sf::Color::White);
    helloWorldText.setString("HELLO WORLD!");

    // Physics (if you can call it that)
    int velocityX = 2;
    int velocityY = 2;
    float posX = 0.0f;
    float posY = 0.0f;
    auto bounds = helloWorldText.getLocalBounds();
    auto windowSize = window.getSize();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Update positions
        posX += velocityX;
        posY += velocityY;
        if (posX < 0)
        {
            posX = 0;
            velocityX *= -1;
        }
        else if (posY < 0)
        {
            posY = 0;
            velocityY *= -1;
        }
        else if (posX > windowSize.x - bounds.width)
        {
            velocityX *= -1;
            posX = windowSize.x - bounds.width;
        }
        else if (posY > windowSize.y - bounds.height)
        {
            velocityY *= -1;
            posY = windowSize.y - bounds.height;
        }
        helloWorldText.setPosition(posX, posY);

        // Draw
        window.clear();
        window.draw(helloWorldText);
        window.display();
    }

    return 0;
}