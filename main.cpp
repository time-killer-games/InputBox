#include <string>
#include <iostream>
#include "inputbox.h"

using std::string;

string FilenameName(string FileName) {
  size_t FilePos = FileName.find_last_of("\\/");
  return FileName.substr(FilePos + 1);
}

void PrintError(string argv) {
  std::cout << "Please rename \"" << FilenameName(argv) << "\" to the desired action, ";
  std::cout << "\"InputBox.exe\" or \"PasswordBox.exe\", and use at least 1 additional argument, with up to 2 optional arguments" << std::endl;
}

int main(int argc, char** argv) {
  if (argc > 1) { 
	if (FilenameName(argv[0]) == "InputBox.exe") {
      std::cout << InputBox(argv[1], (argc > 2) ? argv[2] : (char*)"", (argc > 3) ? argv[3] : (char*)"") << std::endl;
    } else if (FilenameName(argv[0]) == "PasswordBox.exe") {
	  std::cout << PasswordBox(argv[1], (argc > 2) ? argv[2] : (char*)"", (argc > 3) ? argv[3] : (char*)"") << std::endl;
    } else {
	  PrintError(argv[0]);
      return 1;
    }
  } else {
    PrintError(argv[0]);
	return 1;
  }
  return 0;
}
