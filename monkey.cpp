#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>

std::string phrase = "wildfire";
std::string chars = "abcdefghijklmnopqrstuvwxyz ";
int closeLen = 6;

int main() {
	time_t start = time(NULL);
	srand(start);
	// modulo for indexing chars with rand()
	int m = strlen(chars.c_str())+1;
	int phraseIndex = 0;
	
	bool quit = false;
	while(!quit) {
		char randomChar = chars[rand() % m];
		//std::cout << randomChar;
		// random char matches with our phrase
		if(randomChar == phrase[phraseIndex]) {
			phraseIndex++;
			// Print if we get more than 5 letters to match
			if(phraseIndex > closeLen) {
				std::cout << "\"";
				for(int i=0;i<phraseIndex;i++) {
					std::cout << phrase[i];
				}
				std::cout << "\" (" << time(NULL) - start << " seconds)" << std::endl;
			}
			// Full match found
			if(phraseIndex == strlen(phrase.c_str())) {
				time_t end = time(NULL);
				std::cout << "\nFound phrase: " << phrase << " in " << end - start << " seconds" << std::endl;
				quit = true;
			}
		// Failed match
		} else {
			phraseIndex = 0;
		}
	}
}
