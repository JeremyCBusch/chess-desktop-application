#pragma once
#include <stdio.h>
#include <string>  
#include <iostream>
#include <vector>
#include <fstream>
#include<tuple>
#include "curl/curl.h"
#include "json.hpp"
#include "serverConnector.h"
using namespace std;
using json = nlohmann::json;
//enum requestType { GET, POST};
enum gameSelectorReturnType { JOIN, CREATE, QUIT };

class gameSelector
{
private:
	static void printMenu();
	static void printPotentialGames();
	static void joinGame(int gameID);
	static string createGame(string userName);
	static string HTTPRequest(requestType type, string endpoint, vector<string> headers, vector<string> params);
	static string createAccount(string username, string password);
	static string login(string username, string password);
	static void printLoginMenu();
	static string loginLoop();

public:
	static tuple<int, string, gameSelectorReturnType> menuLoop();
};

