#include "TextureFactory.hpp"

TextureFactory::TextureFactory() {
    this->throwOnMissingImage = false;
}

TextureFactory::~TextureFactory() {
    for (auto tex : this->textures) {
        delete tex.second;
    }
}

sf::Texture* TextureFactory::getTexture(std::string key) {
    auto result = TextureFactory::textures.find(key);
    if (result != TextureFactory::textures.end()) {
        return result->second;
    } else  {
        sf::Texture* texture = new sf::Texture();
        if(texture->loadFromFile(key)) {
            TextureFactory::textures.insert(std::pair<std::string, sf::Texture*>(key, texture));
        } else {
            fprintf(stderr, "\x1B[33mWarning: Error loading sprite \"%s\".\n\x1B[0m", key.c_str());
            delete texture;
            texture = new sf::Texture();
            if (this->throwOnMissingImage || !texture->loadFromFile(noTextureImagePath)) {
                delete texture;
                throw std::ifstream::failure("Error loading sprite");
            }
        }
        return texture;
    }
}
