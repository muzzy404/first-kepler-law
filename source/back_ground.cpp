#include "back_ground.hpp"

#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <cmath>

BackGround::BackGround(const std::string & fileName, int r1, int r2)
{
  if (!image_.loadFromFile(fileName))
  {
    throw std::invalid_argument("can not find background image");
  }
  background_.setTexture(image_);

  if (r1 > 200)
  {
    std::cerr << "invalid radius 1\ndefault radius 1 = 200\n";
    r1 = 200;
  }
  if (r2 > 310)
  {
    std::cerr << "invalid radius 2\ndefault radius 2 = 300\n";
    r2 = 310;
  }
  // window size
  window_.x = 1000;
  window_.y = 800;
  // orbit - red ellipse
  orbit_.setPosition((300 - r1), (400 - r2));
  orbit_.setRadius(sf::Vector2f(r1, r2));
  orbit_.setFillColor(sf::Color::Transparent);
  orbit_.setOutlineColor(sf::Color::Red);
  orbit_.setOutlineThickness(2);
}

void BackGround::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
  target.draw(background_);
  target.draw(orbit_);
}

std::vector<sf::Vector2f> BackGround::CalculateCoordinates() const
{
  std::vector<sf::Vector2f> coordinates;

  const float a = (orbit_.getRadius()).x;
  const float b = (orbit_.getRadius()).y;
  // right bottom part of points
  for(std::size_t i = 0; i < 5; ++i)
  {
    float y = b - (i * (b / 4));
    float x = std::sqrt( (a*a - (a*a)*(y*y)/(b*b)) );
    coordinates.push_back(sf::Vector2f(x + 300, y + 400));
  }
  // right upper part of points
  for(std::size_t i = 0; i < 4; ++i)
  {
    float y = 400 - b + (i * (b / 4));
    coordinates.push_back(sf::Vector2f(coordinates[i].x, y));
  }
  // sort from top points to bottom points
  std::sort(coordinates.begin(), coordinates.end(),
            [](sf::Vector2f & a, sf::Vector2f & b)
            {
              return (a.y < b.y);
            });
  // the rest part of points - all left points
  for(std::size_t i = 7; i > 0; --i)
  {
    coordinates.push_back(sf::Vector2f(600.f - coordinates[i].x, coordinates[i].y));
  }

  // debug information
  /*for(std::size_t i = 0; i < coordinates.size(); ++i)
  {
    std::cout << "point " << (i+1) << " : y = " << coordinates[i].y << "  x = " << coordinates[i].x << "\n";
  }*/

  return coordinates;
}

float BackGround::c() const
{
  float a = (orbit_.getRadius()).x;
  float b = (orbit_.getRadius()).y;
  return std::sqrt(std::abs(a * a - b * b)); // mathematical formula
}
