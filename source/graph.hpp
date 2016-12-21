#ifndef KEPLER_GRAPH
#define KEPLER_GRAPH

#include <SFML/Graphics.hpp>

class KeplerGraph : public sf::Drawable
{
public:
  KeplerGraph(const std::string &);
  typedef std::vector<std::pair<float, float>> LinesVect;
  void calculate(const sf::Vector2f &,
                 const sf::Vector2f &,
                 std::vector<sf::Vector2f> &);
  void draw(sf::RenderTarget &, sf::RenderStates) const override;
  void update();
private:
  LinesVect   lines_;
  std::size_t linesDraw_;

  sf::RectangleShape background_;
  sf::CircleShape    dot_;

  sf::Texture image_;
  sf::Sprite  law_;
};

#endif // KEPLER_GRAPH
