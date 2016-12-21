#include "graph.hpp"

#include <iostream>
#include <iterator>

KeplerGraph::KeplerGraph(const std::string & law):
  linesDraw_(0u)
{
  background_.setSize(sf::Vector2f(350, 700));
  background_.setPosition(sf::Vector2f(620, 50));
  background_.setFillColor(sf::Color::Black);
  background_.setOutlineColor(sf::Color::Yellow);
  background_.setOutlineThickness(5);

  // point on the line connection
  dot_.setRadius(4);
  dot_.setOrigin(4, 4);
  dot_.setFillColor(sf::Color::Red);

  // the text of first Kepler law
  if (!image_.loadFromFile(law))
  {
    throw std::invalid_argument("can not find law image");
  }
  image_.setSmooth(true);
  law_.setTexture(image_);
  law_.setPosition(650, 640);
}

void KeplerGraph::calculate(const sf::Vector2f & focus1,
                            const sf::Vector2f & focus2,
                            std::vector<sf::Vector2f> & points)
{
  lines_.clear();
  for(std::size_t i = 0; i < points.size(); ++i)
  {
    float line1 = std::sqrt((focus1.x - points[i].x) * (focus1.x - points[i].x) +
                            (focus1.y - points[i].y) * (focus1.y - points[i].y));
    float line2 = std::sqrt((focus2.x - points[i].x) * (focus2.x - points[i].x) +
                            (focus2.y - points[i].y) * (focus2.y - points[i].y));
    lines_.push_back(std::make_pair(line1, line2));
  }

  // check lines - debugging
  /*for(std::size_t i = 0; i < lines_.size(); ++i)
  {
    std::cout << "line " << (i + 1) << " = " << (lines_[i].first + lines_[i].second) << "\n";
  }*/
}

void KeplerGraph::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
  target.draw(background_);

  const int gapLf = 650;
  const int gapUp = 60;
  // draw all old lines and one new
  for(std::size_t i = 0; i < linesDraw_; ++i)
  {
    sf::Vertex line1[] =
    {
      sf::Vertex(sf::Vector2f(gapLf + (20 * i), gapUp),
                 sf::Color::Yellow),
      sf::Vertex(sf::Vector2f(gapLf + (20 * i), gapUp + lines_[i].first),
                 sf::Color::Magenta),
    };
    sf::Vertex line2[] =
    {
      sf::Vertex(sf::Vector2f(gapLf + (20 * i), gapUp + lines_[i].first),
                 sf::Color::Cyan),
      sf::Vertex(sf::Vector2f(gapLf + (20 * i), gapUp + lines_[i].first + lines_[i].second),
                 sf::Color::Red),
    };
    target.draw(line1, 2, sf::Lines);
    target.draw(line2, 2, sf::Lines);
  }
  target.draw(dot_);
  target.draw(law_);
}

void KeplerGraph::update()
{
  dot_.setPosition(sf::Vector2f(650 + (20 * linesDraw_),
                                60 + lines_[linesDraw_].first));
  ++linesDraw_;
  if (linesDraw_ > lines_.size())
  {
    linesDraw_ = 0;
  }
}
