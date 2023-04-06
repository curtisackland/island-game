#include "TextureFactory.hpp"

std::unordered_map<std::string, sf::Texture*> TextureFactory::textures;

sf::Texture* TextureFactory::getTexture(std::string key) {
    auto result = TextureFactory::textures.find(key);
    if (result != TextureFactory::textures.end()) {
        return result->second;
    } else  {
        sf::Texture* texture = new sf::Texture;
        if(texture->loadFromFile(key)) {
            TextureFactory::textures.insert(std::pair<std::string, sf::Texture*>(key, texture));
        } else {
            fprintf(stderr, "\x1B[33mWarning: Error loading sprite \"%s\".\n\x1B[0m", key.c_str());
            if (!texture->loadFromFile("resources/images/no-texture.png")) {
                throw std::ifstream::failure("Error loading sprite");
            }
        }
        return texture;
    }
}

void TextureFactory::destroy() {
    for (auto tex : TextureFactory::textures) {
        delete tex.second;
        tex.second = nullptr;
    }
}
