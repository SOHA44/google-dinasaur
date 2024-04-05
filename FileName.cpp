#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
using namespace sf;
int score = 0;
//function of game 
void game(RenderWindow& window) {
    Font font;
    font.loadFromFile("B://PixCon.ttf");
    Text scoretext("Score: ", font, 20);
    scoretext.setFillColor(Color::White);
    scoretext.setPosition(100, 100);
    Texture backgroundtexture;
    backgroundtexture.loadFromFile("B://project//image.png");
    Sprite background;
    background.setTexture(backgroundtexture);
    background.setScale(2, 2);
    //load photo of dinasaur 
    Texture dinasaurtexture;
    dinasaurtexture.loadFromFile("B://project//diansaur-removebg-preview.png");
    Sprite dinasaur;
    dinasaur.setTexture(dinasaurtexture);
    //information about position of dinasaur
    dinasaur.setScale(.3, .3);
    dinasaur.setTextureRect(IntRect(0, 0, 400, 400));
    dinasaur.setPosition(500, 600);
    while (window.isOpen()) {
        Event event;  while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            dinasaur.move(.5, 0);
            score++;
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            dinasaur.move(-.5, 0);
            score++;
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            dinasaur.move(0, -.5);
            score++;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            dinasaur.move(0, .5);
            score++;
        }
        //this section takes current score value and convert it into string and combines it , then it update the text displayed 
        scoretext.setString("Score: " + to_string(score));
        window.clear();
        window.draw(background);
        window.draw(dinasaur);
        window.draw(scoretext);
        window.display();
    }
}
int main()
{
    RenderWindow window(VideoMode(1000, 800), "Google Dinasaur");

    //load background from file and set scale of background
    Texture backgroundtexture;
    backgroundtexture.loadFromFile("B://project//background.png");
    Sprite background;
    background.setTexture(backgroundtexture);
    background.setScale(2, 1.5);
    //load photo of main menu and set its podsition and scale 
    Texture mainmenutexture;
    mainmenutexture.loadFromFile("B://project//main menu.png");
    Sprite mainmenu;
    mainmenu.setTexture(mainmenutexture);
    mainmenu.setScale(.9, .9);
    mainmenu.setPosition(330, 400);
    Texture mainmenu2;
    mainmenu2.loadFromFile("B://project//menu2-removebg-preview.png");
    Sprite mainmenusprite;
    mainmenusprite.setTexture(mainmenu2);
    mainmenusprite.setScale(.7, .8);
    mainmenusprite.setPosition(700, 450);

    //load font for name and buttons of game and set thier positions , colors and size of font
    Font font;
    font.loadFromFile("B://PixCon.ttf");
    Text title("Google Dinasaur", font, 40);
    title.setPosition(320, 360);
    title.setFillColor(Color::White);
    Text start("Start ", font, 40);
    start.setPosition(470, 520);
    start.setFillColor(Color::White);
    Text exit("Exit", font, 40);
    exit.setPosition(470, 600);
    exit.setFillColor(Color::White);
    Text mute("Mute", font, 30);
    mute.setPosition(790, 600);
    mute.setFillColor(Color::White);
    bool startgame = false;
    //load music
    Music  menumusic;
    menumusic.openFromFile("C://Users//sohas//Downloads//Music//b.mp3");
    menumusic.play();
    //this sectin starts aloop that runs as long as the window is open 
    while (window.isOpen()) {
        Event event;
        //inner loop control of polls event 
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::MouseButtonPressed) {
                //two dimensional vector retrieves the positin of mouse and store it in variable mousepos (x ,y)
                Vector2i mousePos = Mouse::getPosition(window);
                if (start.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    start.setFillColor(Color::Black);
                    startgame = true;
                }
                if (exit.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    exit.setFillColor(Color::Black);
                    window.close(); // Close the window
                }
                if (mute.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    mute.setFillColor(Color::Red);
                    menumusic.setVolume(0);
                }



            }
        }
        window.clear();
        window.draw(background);
        window.draw(mainmenu);
        window.draw(mainmenusprite);
        window.draw(title);
        window.draw(start);
        window.draw(exit);
        window.draw(mute);
        window.display();
        //check if the game should start 
        if (startgame == true) {
            game(window);//call function gameloop
            startgame = false;//after game loop ends 
        }


    }



    return 0;
}


/*//load background from file and set scale of background
Texture backgroundtexture;
backgroundtexture.loadFromFile("B://project//background.png");
Sprite background;
background.setTexture(backgroundtexture);
background.setScale(2, 1.5);
//load photo of main menu and set its podsition and scale 
Texture mainmenutexture;
mainmenutexture.loadFromFile("B://project//main menu.png");
Sprite mainmenu;
mainmenu.setTexture(mainmenutexture);
mainmenu.setScale(.9, .9);
mainmenu.setPosition(330, 400);
Texture mainmenu2;
mainmenu2.loadFromFile("B://project//menu2-removebg-preview.png");
Sprite mainmenusprite;
mainmenusprite.setTexture(mainmenu2);
mainmenusprite.setScale(.7, .8);
mainmenusprite.setPosition(700, 450);

//load font for name and buttons of game and set thier positions , colors and size of font
Font font;
font.loadFromFile("B://PixCon.ttf");
Text title("Google Dinasaur", font, 40);
title.setPosition(320, 360);
title.setFillColor(Color::White);
Text start("Start ", font, 40);
start.setPosition(470, 520);
start.setFillColor(Color::White);
Text exit("Exit", font, 40);
exit.setPosition(470, 600);
exit.setFillColor(Color::White);
Text mute("Mute", font, 30);
mute.setPosition(790, 600);
mute.setFillColor(Color::White);
bool startgame = false;
//load music
Music  menumusic;
menumusic.openFromFile("C://Users//sohas//Downloads//Music//b.mp3");
menumusic.play();
//this sectin starts aloop that runs as long as the window is open 
while (window.isOpen()) {
    Event event;
    //inner loop control of polls event 
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed)
            window.close();
        if (event.type == Event::MouseButtonPressed) {
            //two dimensional vector retrieves the positin of mouse and store it in variable mousepos (x ,y)
            Vector2i mousePos = Mouse::getPosition(window);
            if (start.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                start.setFillColor(Color::Black);
                startgame = true;
            }
            if (exit.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                exit.setFillColor(Color::Black);
                window.close(); // Close the window
            }
            if (mute.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                mute.setFillColor(Color::Red);
                menumusic.setVolume(0);
            }
            /* if (mute.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                 mute.setFillColor(Color::White);
                 menumusic.play();
             }

        }
    }
    window.clear();
    window.draw(background);
    window.draw(mainmenu);
    window.draw(mainmenusprite);
    window.draw(title);
    window.draw(start);
    window.draw(exit);
    window.draw(mute);
    window.display();
    //check if the game should start 
    if (startgame == true) {
        game(window);//call function gameloop
        startgame = false;//after game loop ends 
    }


}*//*void game(RenderWindow& window) {
    Font font;
    font.loadFromFile("B://PixCon.ttf");
    Text scoretext("Score: ", font, 20);
    scoretext.setFillColor(Color::White);
    scoretext.setPosition(100, 100);
    Texture backgroundtexture;
    backgroundtexture.loadFromFile("B://project//image.png");
    Sprite background;
    background.setTexture(backgroundtexture);
    background.setScale(2, 2);
    //load photo of dinasaur 
    Texture dinasaurtexture;
    dinasaurtexture.loadFromFile("B://project//diansaur-removebg-preview.png");
    Sprite dinasaur;
    dinasaur.setTexture(dinasaurtexture);
    //information about position of dinasaur
    dinasaur.setScale(.3, .3);
    dinasaur.setTextureRect(IntRect(0, 0, 400, 400));
    dinasaur.setPosition(500, 600);
    while (window.isOpen()) {
        Event event;  while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            dinasaur.move(.12, 0);
            score++;
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            dinasaur.move(-.12, 0);
            score++;
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            dinasaur.move(0, -.12);
            score++;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            dinasaur.move(0, .12);
            score++;
        }
        //this section takes current score value and convert it into string and combines it , then it update the text displayed 
        scoretext.setString("Score: " + to_string(score));
        window.clear();
        window.draw(background);
        window.draw(dinasaur);
        window.draw(scoretext);
        window.display();
    }
}*/