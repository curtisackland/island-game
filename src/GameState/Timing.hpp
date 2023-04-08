#include <SFML/Graphics.hpp>


class Timing {
private:
    float deltaTime;
    sf::Clock clock; // Game clock
public:
    Timing() = default;
    ~Timing() = default;
    const float getDeltaTime() const;
    void resetTimer();
};
