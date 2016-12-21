#ifndef BACK_GROUND
#define BACK_GROUND

#include "orbit.hpp"

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <utility>

class BackGround : public sf::Drawable
{
public:
  BackGround(const std::string &, int, int);

  void draw(sf::RenderTarget &, sf::RenderStates) const override;
  void setOrbit(int a, int b) { orbit_.setRadius(sf::Vector2f(a, b));
                                orbit_.setPosition((300 - a), (400 - b)); }
  std::vector<sf::Vector2f> CalculateCoordinates() const;

  unsigned int getWindowHeight() const { return window_.y; };
  unsigned int getWindowWidth()  const { return window_.x; };

  float c() const; // c - distance between focuses

private:
  sf::Sprite   background_;
  sf::Texture  image_;

  sf::Vector2i window_;

  Orbit orbit_;
};


#endif // BACK_GROUND
