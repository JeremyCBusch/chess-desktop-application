#include <iostream>;
#include <stdio.h>
#include <string>  
#include <vector>
#include <fstream>
#include "curl/curl.h"
#include "json.hpp"
using namespace std;
using json = nlohmann::json;
enum requestType { GET, POST };

#pragma once
static class serverConnector
{
private:
	static string HTTPRequest(requestType type, string endpoint, vector<string> headers, vector<string> params);

	

public:
	static void ping();
};

