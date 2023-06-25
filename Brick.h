#include <SFML/Graphics.hpp>

#ifndef TETRIS_BRICK_H
#define TETRIS_BRICK_H

/// Class representing one brick
class Brick : public sf::Drawable {
public:
    /// Constructor
    Brick();

    /**Set position of the brick
     *
     * @param x - x position
     * @param y - y position
     */
    void setPosition(float x, float y);

    /**Set color of the brick
     *
     * @param color - color of the brick
     */

    void setFillColor(sf::Color color);


private:
    sf::RectangleShape shape; ///< Shape of the brick

    /**Draw the brick
     *
     * @param target - target to draw
     * @param states - states of the brick
     */
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};

#endif
