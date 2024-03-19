#include <string>

struct coordinates {
    int size;
    std::string * items;
};

coordinates get_coordinates(std::string &);
std::string compile_coordinate(std::string &coordinate);
void save_coordinate(std::string &compiled_coordinate, std::string &label, std::string &output_folder, int &index);
