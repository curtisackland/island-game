#define BOOST_TEST_MODULE MainTests
#include <boost/test/included/unit_test.hpp>
#include "mainTest.hpp"
#define SKIP_SFML_TESTS true
#define SAVE_NOISE_IMAGES false
// Docs: https://www.boost.org/doc/libs/1_71_0/libs/test/doc/html/index.html

BOOST_AUTO_TEST_SUITE(GameConfigTestSuite)

BOOST_AUTO_TEST_CASE(GetInstanceTest) {
    BOOST_REQUIRE_NE(&GameConfig::getInstance(), nullptr);
}

BOOST_AUTO_TEST_CASE(FileNotAdded, * boost::unit_test::depends_on("GameConfigTestSuite/GetInstanceTest")) {
    BOOST_CHECK_THROW(GameConfig::getInstance().getJson("nofile"), std::ifstream::failure);
}

BOOST_AUTO_TEST_CASE(BadJsonForm, * boost::unit_test::depends_on("GameConfigTestSuite/GetInstanceTest")) {
    BOOST_CHECK_THROW(GameConfig::getInstance().getJson("tests/testConfigBad.json"), boost::wrapexcept<boost::system::system_error>);
}

BOOST_AUTO_TEST_CASE(BadJsonForm2, * boost::unit_test::depends_on("GameConfigTestSuite/GetInstanceTest")) {
    BOOST_CHECK_THROW(GameConfig::getInstance().getJson("tests/testConfigBad2.json"), std::domain_error);
}

BOOST_AUTO_TEST_CASE(FileNotFound, * boost::unit_test::depends_on("GameConfigTestSuite/GetInstanceTest")) {
    BOOST_CHECK_THROW(GameConfig::getInstance().addFile("tests/notFound.json"), std::ifstream::failure);
}

BOOST_AUTO_TEST_CASE(AddFile, * boost::unit_test::depends_on("GameConfigTestSuite/GetInstanceTest")) {
    GameConfig::getInstance().addFile("tests/testConfig.json");
}

BOOST_AUTO_TEST_CASE(AddFileTwice, * boost::unit_test::depends_on("GameConfigTestSuite/AddFile")) {
    GameConfig::getInstance().addFile("tests/testConfig.json");
}

BOOST_AUTO_TEST_CASE(ReadConfig, * boost::unit_test::depends_on("GameConfigTestSuite/AddFileTwice")) {
    GameConfig::getInstance().forceRead();
}

BOOST_AUTO_TEST_CASE(ReadPropertyInteger, * boost::unit_test::depends_on("GameConfigTestSuite/AddFile")) {
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/testConfig.json").at("testInteger"), 1);
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/testConfig.json").at("testInteger").as_int64(), 1);
}

BOOST_AUTO_TEST_CASE(ReadPropertyDouble, * boost::unit_test::depends_on("GameConfigTestSuite/AddFile")) {
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/testConfig.json").at("testDouble"), 1.5);
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/testConfig.json").at("testDouble").as_double(), 1.5);
}

BOOST_AUTO_TEST_CASE(ReadPropertyString, * boost::unit_test::depends_on("GameConfigTestSuite/AddFile")) {
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/testConfig.json").at("testString"), "Hello");
}

BOOST_AUTO_TEST_CASE(ReadPropertyObject, * boost::unit_test::depends_on("GameConfigTestSuite/AddFile")) {
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/testConfig.json").at("testObject").at("objectInteger"), 1);
}

BOOST_AUTO_TEST_CASE(AddFile2, * boost::unit_test::depends_on("GameConfigTestSuite/GetInstanceTest")) {
    GameConfig::getInstance().addFile("tests/testConfig2.json");
}

BOOST_AUTO_TEST_CASE(ReadPropertyInteger2, * boost::unit_test::depends_on("GameConfigTestSuite/AddFile2")) {
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/testConfig2.json").at("testInteger2"), 1);
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/testConfig2.json").at("testInteger2").as_int64(), 1);
}

BOOST_AUTO_TEST_CASE(ReadPropertyDouble2, * boost::unit_test::depends_on("GameConfigTestSuite/AddFile2")) {
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/testConfig2.json").at("testDouble2"), 1.5);
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/testConfig2.json").at("testDouble2").as_double(), 1.5);
}

BOOST_AUTO_TEST_CASE(ReadPropertyString2, * boost::unit_test::depends_on("GameConfigTestSuite/AddFile2")) {
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/testConfig2.json").at("testString2"), "Hello");
}

BOOST_AUTO_TEST_CASE(ReadPropertyObject2, * boost::unit_test::depends_on("GameConfigTestSuite/AddFile2")) {
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/testConfig2.json").at("testObject2").at("objectInteger2"), 1);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(GameEntityTestSuite)

BOOST_AUTO_TEST_CASE(ConstructorDestructor) {
    GameEntityTest entity(0);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(GameEventsTestSuite)

BOOST_AUTO_TEST_CASE(CreateGameEventsWithEntity) {
    GameEvents events;
    GameEntityTest entity(0);
    events.addUpdateEntity(&entity);
    BOOST_CHECK(events.updateListContains(&entity));
    events.removeUpdateEntity(&entity);
}

BOOST_AUTO_TEST_CASE(CheckNoNotify) {
    GameEvents events;
    GameEntityTest entity(0);
    events.addUpdateEntity(&entity);
    BOOST_CHECK(!entity.getInternalVariable());
    events.removeUpdateEntity(&entity);
}

BOOST_AUTO_TEST_CASE(CheckNotify) {
    GameEvents events;
    GameEntityTest entity(0);
    events.addUpdateEntity(&entity);
    events.notifyAll();
    BOOST_CHECK(entity.getInternalVariable());
    events.removeUpdateEntity(&entity);
}

BOOST_AUTO_TEST_CASE(CheckNoDrawNotify) {
    GameEvents events;
    GameEntityTest entity(0);
    events.addUpdateEntity(&entity);
    BOOST_CHECK(!entity.getInternalVariable2());
    events.removeUpdateEntity(&entity);
}

BOOST_AUTO_TEST_CASE(CheckDrawNotify) {
    GameEvents events;
    GameEntityTest entity(0);
    events.addDrawEntity(&entity, 0);
    events.notifyAll();
    BOOST_CHECK(entity.getInternalVariable2());
    events.removeDrawEntity(&entity);
}

BOOST_AUTO_TEST_CASE(CheckDestroyEntity) {
    GameEvents events;
    GameEntityTest* entity = new GameEntityTest(0);
    events.addUpdateEntity(entity);
    BOOST_CHECK(events.updateListContains(entity));

    events.notifyUpdateEntities();
    BOOST_CHECK(entity->getInternalVariable());

    events.removeUpdateEntity(entity);
    BOOST_CHECK(!events.updateListContains(entity));
}

BOOST_AUTO_TEST_CASE(CheckDestroyEntities) {
    GameEvents events;
    std::vector<GameEntityTest*> *entityVector = new std::vector<GameEntityTest*>();
    int const testSize = 1000;
    for (int i = 0; i < testSize; ++i) {
        entityVector->push_back(new GameEntityTest(0));
        events.addUpdateEntity(entityVector->back());
    }

    events.notifyUpdateEntities();
    for (int i = 0; i < testSize; ++i) {
        BOOST_CHECK(entityVector->at(i)->getInternalVariable());
    }

    GameEntityTest* e = entityVector->at(0);
    for (int i = 0; i < testSize; ++i) {
        delete entityVector->at(i);
        entityVector->at(i) = nullptr;
    }
    delete entityVector;
    e->getId();
    BOOST_CHECK_NO_THROW(events.notifyUpdateEntities());
}


BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TextureFactoryTestSuite, * boost::unit_test::enable_if<!SKIP_SFML_TESTS>())

BOOST_AUTO_TEST_CASE(LoadTexture) {
    TextureFactory::getTexture("tests/grass.png");
}

BOOST_AUTO_TEST_CASE(LoadTextureTwice, * boost::unit_test::depends_on("TextureFactoryTestSuite/LoadTexture")) {
    TextureFactory::getTexture("tests/grass.png");
}

BOOST_AUTO_TEST_CASE(LoadSecondTexture, * boost::unit_test::depends_on("TextureFactoryTestSuite/LoadTexture")) {
    TextureFactory::getTexture("tests/master.png");
}

BOOST_AUTO_TEST_SUITE_END()

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
    noise->addLayer(new NoiseBuilder2DPerlin(0, 0.01, 127.5, 127.5));

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
    noise->addLayer(new NoiseBuilder2DHighCenter(0.02, 50, 0, 0, 0));
    noise->addLayer(new NoiseBuilder2DPerlin(86747272, 0.002, 20, 20));
    noise->addLayer(new NoiseBuilder2DPerlin(27074768, 0.004, 10, 10));

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

/*
Generic test suite template:
Put the class name + "Test" as the name of the suite
BOOST_AUTO_TEST_SUITE(OtherClassTest)

BOOST_AUTO_TEST_CASE(test1) {
    BOOST_WARN_EQUAL(101, 101); // Tests pass when not working
    BOOST_CHECK_EQUAL(101, 101); // Tests fail when not working
    BOOST_REQUIRE_EQUAL(101, 101); // Testing stops when not working
}

BOOST_AUTO_TEST_SUITE_END()
*/
