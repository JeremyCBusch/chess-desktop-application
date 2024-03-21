#include <iostream>;
#include <stdio.h>
#include <string>  
#include <vector>
#include <fstream>
#include "curl/curl.h"
#include "json.hpp"
#include "move.h"
using namespace std;
using json = nlohmann::json;
enum requestType { GET, POST };

#pragma once
static class serverConnector
{
private:
	static string HTTPRequest(requestType type, string endpoint, vector<string> headers, vector<string> params, const char* data);

	

public:
	static void ping();
	static string makeMove(Move move, int gameID);
	static json getOpponentMove(string userName, int gameID);
};

