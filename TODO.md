# Tasks
- [ ] Screen size (fullscreen/scaling)
    - [ ] Put all settings into one singleton class
- [ ] Make a config file 
    - [x] Singleton class that opens a config file to hold game settings
    - [x] Decide which library/file format to use for the file
    - [ ] (optional) Make properties writable
- [x] Tile system
    - [x] Generation
- [ ] Entities
    - [ ] Enemy attack system
    - [X] Pathfinding
- [ ] Player Attack system
- [ ] Level/Map system
    - [ ] Surface
    - [ ] Caves
    - [ ] Cave entrance 
- [ ] Sleeping to re-generate caves
- [ ] Add a logging system for debug information


# Notes
## Config file
the latest version of boost on WSL is 1.71, which does not have boost.json yet. I have included boost_1_79_0 under libs so that the json library is included


# Resources
[Boost library latest is 1.71 for WSL](https://www.boost.org/doc/libs/1_71_0/)

[Potential optimization techniques for SFML (vertex arrays)](https://en.sfml-dev.org/forums/index.php?topic=13885.0)
