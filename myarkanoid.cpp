#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

int main()
{
    srand(time(0));
    bool menu = false;

    RenderWindow app(VideoMode(520, 480), "Arkanoid!");
    app.setFramerateLimit(70);

    Texture t1,t2,t3,t4;
    Texture g;
    g.loadFromFile(("images/gameover.png"));
    t1.loadFromFile("images/block05.png");
    t2.loadFromFile("images/background.jpg");
    t3.loadFromFile("images/ball.png");
    t4.loadFromFile("images/paddle.png");

    Sprite sBackground(t2), sBall(t3), sPaddle(t4),background;

    sPaddle.setPosition(300,440);
    Sprite gs;
    gs.setTexture(g);
    background.setTexture(t2);
    background.setScale(0.13f,0.16f);

    Sprite block[1000];

    int n=0;
    for (int i=1;i<=10;i++)
    for (int j=1;j<=10;j++)
      {
         block[n].setTexture(t1);
         block[n].setPosition(i*43,j*20);
         n++;
      }

    float dx=6, dy=5;
	float x=300, y=220;

    while (app.isOpen())
    {
       Event e;
       while (app.pollEvent(e))
       {
         if (e.type == Event::Closed)
             app.close();

       }

       if(Keyboard::isKeyPressed(Keyboard::Tab))
        menu=true;

    x+=dx;
    for (int i=0;i<n;i++)
		if ( FloatRect(x+3,y+3,6,6).intersects(block[i].getGlobalBounds()) )
		     {block[i].setPosition(-100,0); dx=-dx;}

    y+=dy;
    for (int i=0;i<n;i++)
		if ( FloatRect(x+3,y+3,6,6).intersects(block[i].getGlobalBounds()) )
		     {block[i].setPosition(-100,0); dy=-dy;}

    if (x<0 || x>520)  dx=-dx;
    if (y<0)  dy=-dy;



    if (Keyboard::isKeyPressed(Keyboard::L) && sPaddle.getPosition().x + 90 < 520 ) sPaddle.move(12,0);
    if (Keyboard::isKeyPressed(Keyboard::A) && sPaddle.getPosition().x > 0 ) sPaddle.move(-12,0);

	if ( FloatRect(x,y,12,12).intersects(sPaddle.getGlobalBounds()) ) dy=-(rand()%5+2);



	sBall.setPosition(x,y);

    app.clear();
    app.draw(background);

    app.draw(sBall);
    app.draw(sPaddle);

    for (int i=0;i<n;i++)
     app.draw(block[i]);
    if(y>450){ app.draw(gs);
    //app.draw(background);
    }

    app.display();
    }

  return 0;
}
