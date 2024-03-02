#pragma once
#include <stdio.h>
#include <string>  
#include <iostream>
#include <vector>
#include <fstream>
#include "curl/curl.h"
#include "json.hpp"
using namespace std;
using json = nlohmann::json;
enum requestType { GET, POST};

class gameSelector
{
private:
	static void printMenu();
	static void printPotentialGames();
	static void joinGame(int gameID);
	static void createGame(string userName);
	static string HTTPRequest(requestType type, string endpoint, vector<string> headers, vector<string> params);
	static string createAccount(string username, string password);
	static string login(string username, string password);
	static void printLoginMenu();
	static string loginLoop();

public:
	static void menuLoop();
};

