#include "TextureFactory.hpp"

std::unordered_map<std::string, sf::Texture*> TextureFactory::textures;

sf::Texture * TextureFactory::getTexture(std::string key) {
    auto result = TextureFactory::textures.find(key);
    if (result != TextureFactory::textures.end()) {
        return result->second;
    } else  {
        sf::Texture *texture = new sf::Texture;
        if(texture->loadFromFile(key)){
            TextureFactory::textures.insert(std::pair<std::string, sf::Texture*>(key, texture));
        } else {
            printf("Error loading sprite.\n");
            throw std::ifstream::failure("Error loading sprite");
        }
        return texture;
    }
}
