#include <json.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include "config.h"

using namespace std;
using json = nlohmann::json;

int main() {
	// std::string file_name = "/Users/BobbyCai/Documents/cmaketest/json_test/test.json";
	std::string file_name = std::string(FILE_ROOT_PATH) + "/test.json";
	std::ifstream file_stream(file_name);
	std::string file_string(std::istreambuf_iterator<char>{file_stream}, std::istreambuf_iterator<char>{});
	std::cout << file_string << std::endl;
	json j = json::parse(file_string);
	std::cout << j << std::endl;
	return 0;
}