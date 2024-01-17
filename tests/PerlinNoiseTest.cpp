#include "common/boost_test.hpp"

#include <SFML/Graphics.hpp>

#include "Noise/LayeredNoise2D.hpp"
#include "Noise/Perlin/Noise2DPerlin.hpp"
#include "Noise/HighCenter/Noise2DHighCenter.hpp"

BOOST_AUTO_TEST_SUITE(PerlinNoiseTest)

BOOST_AUTO_TEST_CASE(Noise2DPerlinTest) {
    sf::Image i;
    i.create(1920, 1080);
    Noise2DPerlin *noise = new Noise2DPerlin(0, 0.01, 127.5, 127.5, 0, 0);

    for (unsigned int x = 0; x < i.getSize().x; ++x) {
        for (unsigned int y = 0; y < i.getSize().y; ++y) {
            int val = noise->noise(((double) x), ((double) y));
            i.setPixel(x, y, sf::Color(val, val, val, 255));
        }
    }
    if (SAVE_NOISE_IMAGES) {
        int fileNumber = -1;
        std::string fileName;
        {
            bool haveNotFoundNextNumber = true;
            sf::Image testImage;
            do {
                ++fileNumber;
                fileName = "tests/outputs/noise_perlin2D" + std::to_string(fileNumber) + ".png";
                haveNotFoundNextNumber = testImage.loadFromFile(fileName);
            } while (haveNotFoundNextNumber);
        }

        i.saveToFile(fileName);
    }
}

BOOST_AUTO_TEST_CASE(LayeredNoise2DOneLayerTest) {
    sf::Image i;
    i.create(1920, 1080);
    LayeredNoise2D *noise = new LayeredNoise2D();
    noise->addLayer(std::make_unique<Noise2DPerlin>(0, 0.01, 127.5, 127.5, 0, 0));

    for (unsigned int x = 0; x < i.getSize().x; ++x) {
        for (unsigned int y = 0; y < i.getSize().y; ++y) {
            int val = noise->noise(((double) x), ((double) y));
            i.setPixel(x, y, sf::Color(val, val, val, 255));
        }
    }
    if (SAVE_NOISE_IMAGES) {
        int fileNumber = -1;
        std::string fileName;
        {
            bool haveNotFoundNextNumber = true;
            sf::Image testImage;
            do {
                ++fileNumber;
                fileName = "tests/outputs/noise_single_layered2D" + std::to_string(fileNumber) + ".png";
                haveNotFoundNextNumber = testImage.loadFromFile(fileName);
            } while (haveNotFoundNextNumber);
        }

        i.saveToFile(fileName);
    }
}

BOOST_AUTO_TEST_CASE(LayeredNoise2DManyLayerTest) {
    sf::Image i;
    i.create(1000, 1000);
    LayeredNoise2D *noise = new LayeredNoise2D();
    noise->addLayer(std::make_unique<Noise2DHighCenter>(0.02, 50, 0, 0, 0));
    noise->addLayer(std::make_unique<Noise2DPerlin>(86747272, 0.002, 20, 20, 0, 0));
    noise->addLayer(std::make_unique<Noise2DPerlin>(27074768, 0.004, 10, 10, 0, 0));

    for (unsigned int x = 0; x < i.getSize().x; ++x) {
        for (unsigned int y = 0; y < i.getSize().y; ++y) {
            double val = noise->noise(((double) x), ((double) y)) * 2;
            i.setPixel(x, y, sf::Color(val, val, val));
        }
    }
    if (SAVE_NOISE_IMAGES) {
        int fileNumber = -1;
        std::string fileName;
        {
            bool haveNotFoundNextNumber = true;
            sf::Image testImage;
            do {
                ++fileNumber;
                fileName = "tests/outputs/noise_many_layered2D" + std::to_string(fileNumber) + ".png";
                haveNotFoundNextNumber = testImage.loadFromFile(fileName);
            } while (haveNotFoundNextNumber);
        }
        
        i.saveToFile(fileName);
    }
}

BOOST_AUTO_TEST_SUITE_END()
