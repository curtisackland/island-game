/**
 * @file GameConfig.hpp
 * @author Evan Goldrick (goldrickevan@gmail.com)
 * @brief Singleton class to read json files
 * @version 0.1
 * @date 2022-05-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <boost/json.hpp>
#include <unordered_map>
#include <fstream>
#include <string>
#include <error.h>
//#include <boost/json/src.hpp> // research what this does more

/**
 * @class GameConfig
 * @brief Json file reader singleton class.
 * Loads json files into memory so that they can be quickly accessed by the program. Call GameConfig::getInstance() to get the instance of the class.
 * Use .getJson(fileName) to get a boost::json::object, from here use .at(keyName) to get values from the json which was read.
 * 
 */
class GameConfig {
    private:
        /**
         * @brief Construct a new Game Config object
         * Private singleton constructor
         */
        GameConfig();

        /**
         * @brief Destroy the Game Config object
         * Private singleton destructor
         */
        ~GameConfig();

        /**
         * @brief Singleton instance
         * This variable stores the actual single instance of the class
         */
        static GameConfig *self;

        /**
         * @brief Map that stores all the json files
         * 
         */
        std::unordered_map<boost::json::string, boost::json::object> *configFiles;

    public:
        /**
         * @brief Get the Instance object
         * 
         * @return GameConfig& 
         */
        static GameConfig& getInstance();

        /**
         * @brief Get the Json object.
         * @param fileName Name of file to be read from.
         * 
         * @return boost::json::object const& 
         */
        boost::json::object const & getJson(boost::json::string const fileName);

        /**
         * @brief Add a file to the list of open files.
         * Adding a file allows for it to be accessed using getJson. 
         * @param fileName Name of file to be read from
         */
        void addFile(boost::json::string fileName);

        /**
         * @brief Force all open files to be re-read from disk.
         * Each file will be read, and will overwrite any changes stored in memory.
         */
        void forceRead();

        // WIP ***************************************************************************
        /**
         * @brief Force all open files to be written to disk.
         * NOT YET IMPLEMENTED
         */
        void forceWrite();

        static void destroy();

};
