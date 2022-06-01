#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <string.h>
#include <fstream>

class TextureFactory {
private:
    static std::unordered_map<std::string, sf::Texture*> textures;

public:
    static sf::Texture * getTexture(std::string key);
};