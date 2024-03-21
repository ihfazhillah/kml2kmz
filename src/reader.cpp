#include <iostream>
#include <vector>
#include <string>
#include "archive.h"
#include <filesystem>

#include "archive_entry.h"
#include "../lib/pugixml/pugixml.hpp"
#include "reader.h"

// #define SOURCE_URL "/home/ihf/AOI GABUNGAN.kml"
#define TEMPLATE ("<?xml version='1.0' encoding='UTF-8'?>\n<kml xmlns='http://www.opengis.net/kml/2.2' xmlns:wpml='http://www.dji.com/wpmz/1.0.4'>\n  <Document>\n    <wpml:createTime>1695820913752</wpml:createTime>\n    <wpml:updateTime>1695820942241</wpml:updateTime>\n    <wpml:missionConfig>\n      <wpml:flyToWaylineMode>safely</wpml:flyToWaylineMode>\n      <wpml:finishAction>goHome</wpml:finishAction>\n      <wpml:exitOnRCLost>executeLostAction</wpml:exitOnRCLost>\n      <wpml:executeRCLostAction>goBack</wpml:executeRCLostAction>\n      <wpml:takeOffSecurityHeight>20</wpml:takeOffSecurityHeight>\n      <wpml:globalTransitionalSpeed>15</wpml:globalTransitionalSpeed>\n      <wpml:droneInfo>\n        <wpml:droneEnumValue>77</wpml:droneEnumValue>\n        <wpml:droneSubEnumValue>0</wpml:droneSubEnumValue>\n      </wpml:droneInfo>\n      <wpml:payloadInfo>\n        <wpml:payloadEnumValue>66</wpml:payloadEnumValue>\n        <wpml:payloadSubEnumValue>0</wpml:payloadSubEnumValue>\n        <wpml:payloadPositionIndex>0</wpml:payloadPositionIndex>\n      </wpml:payloadInfo>\n    </wpml:missionConfig>\n    <Folder>\n      <wpml:templateType>mapping2d</wpml:templateType>\n      <wpml:templateId>0</wpml:templateId>\n      <wpml:waylineCoordinateSysParam>\n        <wpml:coordinateMode>WGS84</wpml:coordinateMode>\n        <wpml:heightMode>relativeToStartPoint</wpml:heightMode>\n        <wpml:globalShootHeight>186.137969970703</wpml:globalShootHeight>\n      </wpml:waylineCoordinateSysParam>\n      <wpml:autoFlightSpeed>15</wpml:autoFlightSpeed>\n      <Placemark>\n        <wpml:caliFlightEnable>0</wpml:caliFlightEnable>\n        <wpml:elevationOptimizeEnable>1</wpml:elevationOptimizeEnable>\n        <wpml:smartObliqueEnable>0</wpml:smartObliqueEnable>\n        <wpml:smartObliqueGimbalPitch>-90</wpml:smartObliqueGimbalPitch>\n        <wpml:shootType>time</wpml:shootType>\n        <wpml:direction>173</wpml:direction>\n        <wpml:margin>0</wpml:margin>\n        <wpml:overlap>\n          <wpml:orthoLidarOverlapH>80</wpml:orthoLidarOverlapH>\n          <wpml:orthoLidarOverlapW>70</wpml:orthoLidarOverlapW>\n          <wpml:orthoCameraOverlapH>80</wpml:orthoCameraOverlapH>\n          <wpml:orthoCameraOverlapW>70</wpml:orthoCameraOverlapW>\n        </wpml:overlap>\n        <Polygon>\n          <outerBoundaryIs>\n            <LinearRing>\n              <coordinates>\n              103.7684750091,-1.1169782295,0\n              103.7652449098,-1.1182736207,0\n              103.7620960300,-1.1194326989,0\n              103.7660884955,-1.1301023163,0\n              103.7665519753,-1.1304016415,0\n              103.7680587040,-1.1326063040,0\n              103.7735446864,-1.1305265400,0\n              103.7684750091,-1.1169782295,0\n            </coordinates>\n            </LinearRing>\n          </outerBoundaryIs>\n        </Polygon>\n        <wpml:ellipsoidHeight>186.137969970703</wpml:ellipsoidHeight>\n        <wpml:height>186.137969970703</wpml:height>\n      </Placemark>\n      <wpml:payloadParam>\n        <wpml:payloadPositionIndex>0</wpml:payloadPositionIndex>\n        <wpml:dewarpingEnable>0</wpml:dewarpingEnable>\n        <wpml:returnMode>singleReturnFirst</wpml:returnMode>\n        <wpml:samplingRate>240000</wpml:samplingRate>\n        <wpml:scanningMode>nonRepetitive</wpml:scanningMode>\n        <wpml:modelColoringEnable>0</wpml:modelColoringEnable>\n        <wpml:imageFormat>wide</wpml:imageFormat>\n      </wpml:payloadParam>\n    </Folder>\n  </Document>\n</kml>")

// CONTOH CARA PENGGUNAAN
// int main(){
//     std::string source = SOURCE_URL;
//     coordinates items = get_coordinates(source);

//     // std::cout << "Coordinates: " << coordinates[0] << std::endl;

//     //std::cout << std::endl << "File baru: " << std::endl;

//     //save_coordinate(coordinates[0]);

//     std::cout << "Size of coordinates: " << items.size << std::endl;

//     // loop coordinate, buat file dengan label
//     std::string label = "SABAK";
//     std::string curdir = std::filesystem::current_path().string();
//     mkdir(label.c_str(), 0777);
//     for (int i; i < items.size; i++)
//     {
//         std::string compiled_coordinate = compile_coordinate(items.items[i]); 
//         save_coordinate(
//             compiled_coordinate,
//             label,
//             curdir,
//             i

//         );


//     }
    

    

//     // jgn lupa delete coordinates
//     // karena kita buat array dengan new
//     delete[] items.items;

    
//     return 0;
// }



coordinates get_coordinates(std::string &filename){
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(filename.c_str());
    pugi::xpath_node_set nodes = doc.select_nodes("//Placemark//coordinates");

    int size = nodes.size();

    std::string * items = new std::string[size];

    
    for (size_t i = 0; i < size; i++)
    {
        // kita perlu reverse ini
        std::cout << "jalan ke: " << i << std::endl;
        items[size - i - 1] = nodes[i].node().text().get();
    }

    coordinates coords {size, items};

    return coords;

}

struct xml_string_writer: pugi::xml_writer
{
    std::string result;

    virtual void write(const void* data, size_t size)
    {
        result.append(static_cast<const char*>(data), size);
    }
};

std::string node_to_string(pugi::xml_node node)
{
    xml_string_writer writer;
    node.print(writer);

    return writer.result;
}

std::string compile_coordinate(std::string &coordinate){
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(TEMPLATE);

    pugi::xpath_node coordinates_node = doc.select_node("//coordinates");

    if (coordinates_node)
    {
        coordinates_node.node().text() = coordinate.c_str();
    }
    
    return node_to_string(doc.root());
    

}

void save_coordinate(std::string &compiled_coordinate, std::string &label, std::string &output_folder, int &index){
    std::string zip_name = label + "/" + label + "_" + std::to_string(index + 1) + ".kmz";
    std::cout << "Writing to " << zip_name << std::endl;
    struct archive *archivePtr;
    struct archive_entry *entryPtr;

    // creating archive
    archivePtr = archive_write_new();
    archive_write_set_format_zip(archivePtr);
    archive_write_add_filter_none(archivePtr);
    archive_write_set_options(archivePtr, "zip:experimental");
    archive_write_open_filename(archivePtr, zip_name.c_str());

    // creating entry
    entryPtr = archive_entry_new();
    archive_entry_set_pathname(entryPtr, "template.kml");
    archive_entry_set_filetype(entryPtr, AE_IFREG | 0777); // Note 1
    archive_entry_set_perm(entryPtr, 0777);

    archive_write_header(archivePtr, entryPtr);
    archive_write_data(archivePtr, compiled_coordinate.data(), compiled_coordinate.size()); // Note 3
    
    // freeing entry
    archive_entry_free(entryPtr);

    // freeing archive
    archive_write_close(archivePtr);
    archive_write_free(archivePtr);
}
