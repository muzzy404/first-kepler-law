# Kepler's laws of planetary motion

In astronomy, Kepler's laws of planetary motion are three scientific laws describing the motion of planets around the Sun.
1. The orbit of a planet is an ellipse with the Sun at one of the two foci.
2. A line segment joining a planet and the Sun sweeps out equal areas during equal intervals of time.
3. The square of the orbital period of a planet is proportional to the cube of the semi-major axis of its orbit.


The project uses Simple and Fast Multimedia Library.
>SFML is a cross-platform software development library designed to provide a simple application programming interface (API) to various multimedia components in computers.

P.S. This project was created in 2 days and visualizes only the first law

***

# Законы Кеплера

Законы Кеплера — три эмпирических соотношения, интуитивно подобранных Иоганном Кеплером на основе анализа астрономических наблюдений Тихо Браге. Описывают идеализированную гелиоцентрическую орбиту планеты.

**Основная концепция:**
Концепция приложения основывается на свойстве эллипса, являющегося траекторией движения спутника. Эллипс — геометрическое место точек M евклидовой плоскости, для которых сумма расстояний до двух данных точек F1 и F2 (называемых фокусами) постоянна. Таким образом, если провести две прямые от месторасположения спутника к предполагаемым фокусам орбиты (в одном из них по закону Кеплера располагается Солнце) и найти сумму длин этих прямых, эта сумма будет одинакова во все моменты времени (т.е. постоянна для любой точки орбиты).
Чтобы продемонстрировать данное свойство, в левой части приложения происходит отрисовка перемещения спутника по орбите, а в правой отображаются прямые, равные тем, которые соединяют спутник с фокусами орбиты. Эти прямые рисуются последовательно, представляя в целом одну прямую. Данная процедура будет проделывается для определенного количества точек орбиты (точнее для 16-ти). Таким образом, пользователь может убедиться в том, что орбита является эллипсом. Так как если это действительно так, все прямые в правой части окажутся равными друг другу, что будет видно и без линейки.
