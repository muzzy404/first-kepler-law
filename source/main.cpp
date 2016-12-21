#include "back_ground.hpp"
#include "space_objects.hpp"
#include "graph.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <exception>

#define FRAMERATE_LIMIT 10
#define B_RADIUS        300

int main()
{
  // ellipse (orbit) radii
  const int a = 200;      // constant first radius
        int b = B_RADIUS; // second radius

  try
  {
    BackGround backGround("images/background.png", a, b);

    sf::RenderWindow window(sf::VideoMode(backGround.getWindowWidth(),
                                          backGround.getWindowHeight()),
                            "Kepler's laws of planetary motion");

    Sun sun(sf::Vector2f(300, 400 - backGround.c()),
            sf::Vector2f(300, 400 + backGround.c()),
            "images/sun.png");

    std::vector<sf::Vector2f> trajectory = backGround.CalculateCoordinates();
    KeplerGraph graph("images/1st_law.png");
    graph.calculate(sun.getSunFocus(), sun.getSecondFocus(), trajectory);

    Satellite satellite(trajectory[0], "images/satellite.png");

    window.setFramerateLimit(FRAMERATE_LIMIT);
    std::size_t iteration = 0;

    window.clear();
    window.draw(backGround);

    while (window.isOpen())
    {
      if (b <= a) // start again for first radius
      {
        b = B_RADIUS;
      }

      sf::Event event;
      while (window.pollEvent(event))
      {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
    }

      window.clear();
      window.draw(backGround);
      // draw first line of graphic at the beginning
      if (iteration == 0)
      {
        window.draw(graph);
        graph.update();
      }
      window.draw(graph);

      // lines from satellite to orbit focuses
      sf::Vertex line1[] =
      {
      sf::Vertex(sun.getSunFocus(),     sf::Color::Yellow),
      sf::Vertex(trajectory[iteration], sf::Color::Magenta),
      };
      sf::Vertex line2[] =
      {
      sf::Vertex(sun.getSecondFocus(),  sf::Color::Red),
      sf::Vertex(trajectory[iteration], sf::Color::Cyan),
      };
      window.draw(line1, 2, sf::Lines);
      window.draw(line2, 2, sf::Lines);

      window.draw(sun);
      window.draw(satellite);

      window.display();

      ++iteration; // satellite motion

      // end of orbital flight, next orbit required
      if (iteration >= trajectory.size())
      {
        iteration = 0;

        b -= 20;
        backGround.setOrbit(a, b);

        // new trajectory of satellite
        trajectory = backGround.CalculateCoordinates();

        sun.setFocuses(sf::Vector2f(300, 400 - backGround.c()),
                       sf::Vector2f(300, 400 + backGround.c()));
        sun.update();

        graph.calculate(sun.getSunFocus(), sun.getSecondFocus(), trajectory);

      }

      satellite.setPoint(trajectory[iteration]);
      satellite.update();
      graph.update();

    } // end of drawing cycle
  }
  catch(std::exception & e) // errors of images uploading
  {
    std::cerr << e.what() << "\n";
    return 1;
  }

  return 0;
}

