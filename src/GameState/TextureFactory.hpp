/**
 * @file TextureFactory.hpp
 * @brief Load shared reference to textures from disk
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <string.h>
#include <fstream>

/**
 * @class TextureFactory
 * @brief Load shared reference to textures from disk
 * Use the getTexture method to get a shared pointer to a texture, if the texture is not already loaded, it will be read from disk.
 */
class TextureFactory {
private:
    /**
     * @brief Map of textures to be cached.
     * 
     */
    std::unordered_map<std::string, sf::Texture*> textures;
    std::string noTextureImagePath = std::string("resources/images/no-texture.png");
    bool throwOnMissingImage;

public:
    TextureFactory();
    ~TextureFactory();
    /**
     * @brief Get a Texture pointer.
     * Get a shared pointer to a texture, if the texture is not already loaded, it will be read from disk.
     * @param key File name of the texture.
     * @return sf::Texture* Pointer to texture.
     */
    sf::Texture* getTexture(std::string key);
    bool getThrowOnMissingImage() {return throwOnMissingImage;}
    void setThrowOnMissingImage(bool set) {throwOnMissingImage = set;}
    std::string getNoTextureImagePath() {return noTextureImagePath;}
    void setNoTextureImagePath(const std::string& noTextureImagePath) {this->noTextureImagePath = noTextureImagePath;}
};
