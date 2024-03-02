#define CURL_STATICLIB
#include <iostream>
#include <string>

#include "curl/curl.h"
using namespace std;

static size_t my_write(void* buffer, size_t size, size_t nmemb, void* param)
{
	std::string& text = *static_cast<std::string*>(param);
	size_t totalsize = size * nmemb;
	text.append(static_cast<char*>(buffer), totalsize);
	return totalsize;
}

int dumb()
{
	std::string result;
	CURL* curl;
	CURLcode res;
	curl_global_init(CURL_GLOBAL_DEFAULT);

	string url = "https://jeremy-chess-server-aa4e4177c88e.herokuapp.com"; 
	string testURL = "localhost:8080";



	//create game


	//curl = curl_easy_init();
	//if (curl) {
	//	struct curl_slist* chunk = NULL;
	//	struct curl_header* type;

	//	curl_easy_setopt(curl, CURLOPT_URL, "localhost:8080/createGame");
	//	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_write);
	//	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
	//	curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
	//	CURLHcode h = curl_easy_header(curl, "userID", 0, CURLH_HEADER, -1, &type);
	//	curl_easy_setopt(curl, CURLOPT_POST, 1L);
	//	res = curl_easy_perform(curl);
	//	curl_easy_cleanup(curl);
	//	if (CURLE_OK != res) {
	//		std::cerr << "CURL error: " << res << '\n';
	//	}
	//}
	//curl_global_cleanup();
	//std::cout << result << "\n\n";


	//join game


	//curl = curl_easy_init();
	//if (curl) {
	//	struct curl_slist* chunk = NULL;
	//	struct curl_header* type;

	//	curl_easy_setopt(curl, CURLOPT_URL, "localhost:8080/joinGame?gameID=3925");
	//	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_write);
	//	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
	//	curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
	//	CURLHcode h = curl_easy_header(curl, "userID", 0, CURLH_HEADER, -1, &type);
	//	curl_easy_setopt(curl, CURLOPT_POST, 1L);
	//	res = curl_easy_perform(curl);
	//	curl_easy_cleanup(curl);
	//	if (CURLE_OK != res) {
	//		std::cerr << "CURL error: " << res << '\n';
	//	}
	//}
	//curl_global_cleanup();
	//std::cout << result << "\n\n";



	// get potenial games


	curl = curl_easy_init();
	if (curl) {
		struct curl_slist* chunk = NULL;
		/* Add a custom header */
		chunk = curl_slist_append(chunk, "userID: asdfg");

		curl_easy_setopt(curl, CURLOPT_URL, "localhost:8080/getPotentialGames");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_write);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
		//curl_easy_setopt(curl, CURLOPT_POST, 1L);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		if (CURLE_OK != res) {
			std::cerr << "CURL error: " << res << '\n';
		}
	}
	curl_global_cleanup();
	std::cout << res << "\n\n";







	//curl = curl_easy_init();
	//if (curl) {
	//	curl_easy_setopt(curl, CURLOPT_POST, 1L);
	//	//curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
	//	curl_easy_setopt(curl, CURLOPT_URL, "localhost:8080/makeMove?gameID=1234");
	//	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_write);
	//	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
	//	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
	//	//curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
	//	struct curl_slist* headers = NULL;
	//	headers = curl_slist_append(headers, "Content-Type: application/json");
	//	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	//	const char* data = "{\r\n    \"isEnPassant\": true,\r\n	\"isKingSideCastle\": false,\r\n	\"isQueenSideCastle\": false,\r\n	\"isPromotion\": false,\r\n	\"isStandardCapture\": false,\r\n	\"isCheck\": false,\r\n	\"positionFrom\": 0,\r\n	\"positionTo\": 8\r\n}";
	//	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
	//	res = curl_easy_perform(curl);
	//}
	//curl_easy_cleanup(curl);
	//std::cout << result << "\n\n";




	//curl = curl_easy_init();
	//if (curl) {
	//	curl_easy_setopt(curl, CURLOPT_POST, 1L);
	//	//curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
	//	curl_easy_setopt(curl, CURLOPT_URL, "localhost:8080/getOpponentMove?gameID=1234");
	//	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_write);
	//	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
	//	curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
	//	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
	//	struct curl_slist* headers = NULL;
	//	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	//	res = curl_easy_perform(curl);
	//}
	//curl_easy_cleanup(curl);
	//std::cout << res << "\n\n";
	return 1;
}
