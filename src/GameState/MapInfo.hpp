class MapInfo {
private:
    double tileSize;
public:
    MapInfo(double tileSize);
    ~MapInfo() = default;

    double getTileSize();
    void setTileSize(double tileSize);
};
