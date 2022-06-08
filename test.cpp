#include "src/GameConfig.hpp"

int main() {
	GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("chunk-size").as_uint64();
}
