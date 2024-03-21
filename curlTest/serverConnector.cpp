#include "serverConnector.h"

static size_t my_write(void* buffer, size_t size, size_t nmemb, void* param)
{
	std::string& text = *static_cast<std::string*>(param);
	size_t totalsize = size * nmemb;
	text.append(static_cast<char*>(buffer), totalsize);
	return totalsize;
}

string serverConnector::HTTPRequest(requestType type, string endpoint, vector<string> headers, vector<string> params, const char* data)
{
	string url = "https://jeremy-chess-server-aa4e4177c88e.herokuapp.com/" + endpoint;
	string testURL = "localhost:8080/" + endpoint;
	

	for (auto param : params)
		url += param;

	//cout << testURL << endl;
	std::string result;
	CURL* curl;
	CURLcode res;
	curl_global_init(CURL_GLOBAL_DEFAULT);

	curl = curl_easy_init();
	if (curl) {
		struct curl_slist* chunk = NULL;

		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, (type == 0) ? "GET" : "POST");
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_write);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
		struct curl_slist* curlHeaders = NULL;
		for (auto header : headers)
			curlHeaders = curl_slist_append(curlHeaders, header.c_str());
		curlHeaders = curl_slist_append(curlHeaders, "Content-Type: application/json");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, curlHeaders);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);




		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);


		if (CURLE_OK != res) {
			std::cerr << "CURL error: " << res << '\n';
		}
	}
	curl_global_cleanup();
	return result;
}


void serverConnector::ping()
{
	vector<string> params = vector<string>();
	vector<string> headers = vector<string>();
	requestType type = GET;

	char* data = nullptr;
	string response = HTTPRequest(type, "ping", headers, params, data);

	json responseJSON = nlohmann::json::parse(response);


	cout << response << endl;
}

string serverConnector::makeMove(Move move, int gameID)
{
	requestType type = POST;
	vector<string> params = vector<string>();
	vector<string> headers = vector<string>();
	params.push_back("?gameID=" + std::to_string(gameID));


	string moveJSON = move.toJSONString();


	string response = HTTPRequest(type, "makeMove", headers, params, moveJSON.c_str());

	//json responseJSON = nlohmann::json::parse(response);


	//cout << response << endl;

	return response;
}

json serverConnector::getOpponentMove(string userName, int gameID)
{
	requestType type = GET;
	vector<string> params = vector<string>();
	vector<string> headers = vector<string>();
	params.push_back("?gameID=" + std::to_string(gameID));
	headers.push_back("?userName=" + userName);



	string response = HTTPRequest(type, "getOpponentMove", headers, params, nullptr);

	if (response != "\"opponent hasn't moved yet\"") {
		json responseJSON = nlohmann::json::parse(response);
		return responseJSON;
	}


	return json::object();
}


