//#include "gameSelector.h"
//using namespace std;
//
//static size_t my_write(void* buffer, size_t size, size_t nmemb, void* param)
//{
//	std::string& text = *static_cast<std::string*>(param);
//	size_t totalsize = size * nmemb;
//	text.append(static_cast<char*>(buffer), totalsize);
//	return totalsize;
//}
//
//void gameSelector::printMenu()
//{
//	cout << "1. List Potential Games\n";
//	cout << "2. Create Game\n";
//	cout << "3. Join Potential Game\n";
//	cout << ">: ";
//}
//
//
//void gameSelector::printLoginMenu()
//{
//	cout << "Welcome to the Online Chess Menu\n";
//	cout << "Please Login or Register\n";
//	cout << "1. Create Account\n";
//	cout << "2. Login\n";
//	cout << ">: ";
//}
//
//
//
//void gameSelector::menuLoop()
//{
//	string userInput;
//	bool *stillInLoop = new bool(true);
//
//	string userName = loginLoop();
//
//	int intUserInput;
//
//	
//
//	while (*stillInLoop == true)
//	{
//		printMenu();
//		cin >> userInput;
//		intUserInput = stoi(userInput);
//		
//		switch (intUserInput)
//		{
//		case(1):
//			printPotentialGames();
//			break;
//		case(2):
//			cout << "creating game" << endl;
//			createGame(userName);
//			stillInLoop = new bool(false);
//			break;
//		case(3):
//			int gameID;
//			cout << "Enter Game ID\n>: ";
//			cin >> gameID;
//			joinGame(gameID);
//			stillInLoop = new bool(false);
//			break;
//		default:
//			cout << "Invalid Input\n";
//			break;
//		}
//	}
//}
//
//
//
//string gameSelector::loginLoop()
//{
//	string userInput;
//	int intUserInput;
//	string userName;
//	string password;
//	string result;
//
//
//	while (true)
//	{
//		printLoginMenu();
//		cin >> userInput;
//		intUserInput = stoi(userInput);
//
//		switch (intUserInput)
//		{
//		case(1):
//
//			cout << "Enter a username\n>: ";
//			cin >> userName;
//			cout << "Enter a passowrd\n>: ";
//			cin >> password;
//			result = createAccount(userName, password);
//			cout << "\n" << result << endl;
//			if (result == "\"created\"")
//				cout << "Account created.\n";
//			else
//				cout << "Account Creation Failed\n";
//			break;
//
//		case(2):
//			cout << "Enter a username\n>: ";
//			cin >> userName;
//			cout << "Enter a passowrd\n>: ";
//			cin >> password;
//			result = login(userName, password);
//			cout << "\n" << result << endl;
//			if (result == "\"authenticated\"")
//			{
//				cout << "Authenticated\n";
//				return userName;
//			}
//			else
//				cout << "Authenticated Failed\n";
//			break;
//
//		default:
//			cout << "Invalid Input\n";
//			break;
//		}
//	}
//	return nullptr;
//}
//
//
//
//
////  *******************
////	**** ENDPOINTS ****
////	*******************
//
//string gameSelector::createAccount(string username, string password)
//{
//	vector<string> params = vector<string>();
//	vector<string> headers{ "username:" + username, "password:" + password };
//	requestType type = POST;
//
//
//	return HTTPRequest(type, "registerAccount", headers, params);
//}
//
//string gameSelector::login(string username, string password)
//{
//	vector<string> params = vector<string>();
//	vector<string> headers{ "username:" + username, "password:" + password };
//	requestType type = POST;
//
//
//	string result = HTTPRequest(type, "login", headers, params);
//
//	return result;
//}
//
//void gameSelector::joinGame(int gameID)
//{
//	vector<string> params{ "?gameID=" + std::to_string(gameID) };
//	vector<string> headers{ "userID:qwerty" };
//	requestType type = POST;
//
//
//	HTTPRequest(type, "joinGame", headers, params);
//
//}
//
//void gameSelector::createGame(string userName)
//{
//	vector<string> params = vector<string>();
//	vector<string> headers{ "userName:" + userName };
//	requestType type = POST;
//
//
//	string result = HTTPRequest(type, "createGame", headers, params);
//	cout << result << endl;
//}
//
//
//void gameSelector::printPotentialGames()
//{
//	vector<string> params = vector<string>();
//	vector<string> headers = vector<string>();
//	requestType type = GET;
//
//
//	string games = HTTPRequest(type, "getPotentialGames", headers, params);
//
//	json gameIDS = nlohmann::json::parse(games);
//
//
//	for (auto& el : gameIDS.items())
//	{
//		std::cout << "Game: " << el.value().at("ID") << '\n';
//	}
//}
//
//
////  *******************
////	** HTTP REQUEST ***
////	*******************
//
//
//string gameSelector::HTTPRequest(requestType type, string endpoint, vector<string> headers, vector<string> params)
//{
//	string url = "https://jeremy-chess-server-aa4e4177c88e.herokuapp.com/";
//	string testURL = "localhost:8080/" + endpoint;
//
//	for (auto param : params)
//		testURL += param;
//
//	std::string result;
//	CURL* curl;
//	CURLcode res;
//	curl_global_init(CURL_GLOBAL_DEFAULT);
//
//	curl = curl_easy_init();
//	if (curl) {
//		struct curl_slist* chunk = NULL;
//
//		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, (type == 0) ? "GET" : "POST");
//		curl_easy_setopt(curl, CURLOPT_URL, testURL.c_str());
//		curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
//		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_write);
//		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
//		struct curl_slist* curlHeaders = NULL;
//		for (auto header : headers)
//			curlHeaders = curl_slist_append(curlHeaders, header.c_str());
//		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, curlHeaders);
//		res = curl_easy_perform(curl);
//		curl_easy_cleanup(curl);
//
//
//		if (CURLE_OK != res) {
//			std::cerr << "CURL error: " << res << '\n';
//		}
//	}
//	curl_global_cleanup();
//	return result;
//}