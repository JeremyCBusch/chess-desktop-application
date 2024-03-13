#include "serverConnector.h"

static size_t my_write(void* buffer, size_t size, size_t nmemb, void* param)
{
	std::string& text = *static_cast<std::string*>(param);
	size_t totalsize = size * nmemb;
	text.append(static_cast<char*>(buffer), totalsize);
	return totalsize;
}

string serverConnector::HTTPRequest(requestType type, string endpoint, vector<string> headers, vector<string> params)
{
	string url = "https://jeremy-chess-server-aa4e4177c88e.herokuapp.com/";
	string testURL = "localhost:8080/" + endpoint;

	for (auto param : params)
		testURL += param;

	std::string result;
	CURL* curl;
	CURLcode res;
	curl_global_init(CURL_GLOBAL_DEFAULT);

	curl = curl_easy_init();
	if (curl) {
		struct curl_slist* chunk = NULL;

		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, (type == 0) ? "GET" : "POST");
		curl_easy_setopt(curl, CURLOPT_URL, testURL.c_str());
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_write);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
		struct curl_slist* curlHeaders = NULL;
		for (auto header : headers)
			curlHeaders = curl_slist_append(curlHeaders, header.c_str());
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, curlHeaders);
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


	string response = HTTPRequest(type, "ping", headers, params);

	json responseJSON = nlohmann::json::parse(response);


	cout << response << endl;
}