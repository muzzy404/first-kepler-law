#include "space_objects.hpp"

SpaceObject::SpaceObject(const sf::Vector2f & point,
                         const std::string & image):
  position_(point)
{
  if (!image_.loadFromFile(image))
  {
    throw std::invalid_argument("can not find image \"" + image + "\"");
  }
  image_.setSmooth(true);
  item_.setTexture(image_);
}

/* --- Sun --- */

Sun::Sun(const sf::Vector2f & sunPoint,
         const sf::Vector2f & focusPoint,
         const std::string & image):
  SpaceObject(sunPoint, image)
{
  item_.setPosition(position_);
  item_.setOrigin((45 / 2), (45 / 2));

  secondFocus_.setPosition(focusPoint);
  secondFocus_.setRadius(6);
  secondFocus_.setFillColor(sf::Color::Red);
  secondFocus_.setOrigin(6, 6);
}

void Sun::setFocuses(const sf::Vector2f & sunPoint,
                     const sf::Vector2f & focusPoint)
{
  position_    = sunPoint;
  secondFocus_.setPosition(focusPoint);
}

void Sun::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
  target.draw(item_);
  target.draw(secondFocus_);
}

void Sun::update()
{
  item_.setPosition(position_);
}

/* --- Satellite --- */

Satellite::Satellite(const sf::Vector2f & satellitePoint,
                     const std::string & image):
  SpaceObject(satellitePoint, image)
{
  item_.setOrigin((30 / 2), (30 / 2));
  update();
}

void Satellite::setPoint(const sf::Vector2f & newPoint)
{
  position_ = newPoint;
}

void Satellite::update()
{
  item_.setPosition(position_);
}

void Satellite::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
  target.draw(item_);
}
