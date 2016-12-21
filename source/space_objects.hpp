#ifndef SPACE_OBJECTS
#define SPACE_OBJECTS

#include <SFML/Graphics.hpp>

#include <string>

class SpaceObject : public sf::Drawable
{
public:
  SpaceObject(const sf::Vector2f &, const std::string &);
  virtual void draw(sf::RenderTarget &, sf::RenderStates) const = 0;
  virtual void update() = 0;
protected:
  sf::Vector2f position_;

  sf::Texture image_;
  sf::Sprite  item_;
};

class Sun : public SpaceObject
{
public:
  Sun(const sf::Vector2f &, const sf::Vector2f &, const std::string &);
  void draw(sf::RenderTarget &, sf::RenderStates) const override;
  void update() override;

  sf::Vector2f getSunFocus()    const { return position_; }
  sf::Vector2f getSecondFocus() const { return secondFocus_.getPosition(); };

  void setFocuses(const sf::Vector2f &, const sf::Vector2f &);

private:
  sf::CircleShape secondFocus_;
};

class Satellite : public SpaceObject
{
public:
  Satellite(const sf::Vector2f &, const std::string &);
  void draw(sf::RenderTarget &, sf::RenderStates) const override;
  void update() override;

  void setPoint(const sf::Vector2f &);
};

#endif // SPACE_OBJECTS
