#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class DirectoryManager {
private:
    map<string, vector<string>> directory;  // folder -> list of files

public:
    void addFolder(const string &folderName) {
        directory[folderName];  // creates empty folder if not exist
    }

    void addFileToFolder(const string &folderName, const string &fileName) {
        directory[folderName].push_back(fileName);  // adds file to folder
    }

    void displayDirectory() {
        cout << "Directory Structure:" << endl;
        for (auto it = directory.begin(); it != directory.end(); ++it) {
            cout << "Folder: " << it->first << endl;
            vector<string> files = it->second;
            sort(files.begin(), files.end());  // optional: sort files alphabetically
            for (const string &file : files) {
                cout << "  - " << file << endl;
            }
        }
    }
};

int main() {
    DirectoryManager dm;

    dm.addFolder("src");
    dm.addFolder("docs");
    dm.addFolder("tests");

    dm.addFileToFolder("src", "main.cpp");
    dm.addFileToFolder("src", "utils.cpp");
    dm.addFileToFolder("docs", "readme.md");
    dm.addFileToFolder("tests", "test_main.cpp");

    dm.displayDirectory();

    cout<<"HARSH_HIRPARA_24CE040";

    return 0;
}

