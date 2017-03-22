// compiling -lcurl
#include <stdio.h>
#include <curl/curl.h>

int main(void){
	CURL *curl;
	CURLcode res;
	char uname[40], email[40], postdata[100];

	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);

	/* get a curl handle */
	curl = curl_easy_init();
	if(curl) {
		/* First set the URL that is about to receive our POST. This URL can
		just as well be a https:// URL if that is what should receive the
		data. */
		curl_easy_setopt(curl, CURLOPT_URL, "http://www.cc.puv.fi/~e1301126/test.php");
		/* Now specify the POST data */
		while(1){
		printf("User name: "); scanf("%s", uname);
		printf("Email: "); scanf("%s", email);
		sprintf(postdata, "name=%s&email=%s", uname, email);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postdata);

		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl);
		/* Check for errors */
		if(res != CURLE_OK)
		fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

		/* always cleanup */
		}
		curl_easy_cleanup(curl);
 		}
	curl_global_cleanup();
return 0;
}
