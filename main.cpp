#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cassert>
#include <math.h>
#include <chrono>

using namespace std;
// hONNESTY ?
// Fonction d'affichage.
// Lgg
int nbChoice = 10;
string file = "";
string choiced = "";
string lgg = "eng";
string QI42 = " ";
int DemiLargeur = 42;
string Ag = "";
bool Error_Opening_File = true;
string Error_Opening_File1 = "Error Opening File ";
string Error_Opening_File2 = "!";
string NAME_date = "NAME_date.txt";
string ascChoice = "1 or 2? ";
string Patient = "Patient ";
string Intelligence = "Intelligence = ";
string intellig = "";
string Genre = "Genre = ";
string Comorbidity = "Comorbidity = ";
string Fanatism = "Fanatism = ";
string Utility = "Utility = ";
string Age = "Age = ";
string file1 = "What is the name of the file, please?\nFor exemple, :";
string file2 = ".";
string intro = "";

string noSpace(string input = "") {    // Ok.
    string result = "";
    for(unsigned int i = 0; i < input.length(); i++) {
        if(input[i] != ' ') {
            result = result + input[i];
            }
        }
    return result;
    }


void init() {
    string tempo = "";
    string file = "MedicalTriage.cfg";
    ifstream fichier(file.c_str(), ios::in);
    if(!fichier) {
        if(Error_Opening_File) { // Not in file: good.
            cerr << Error_Opening_File1 << file << Error_Opening_File2 << endl;
            }
        }
    else {
        string line = "";
        while(getline(fichier, line)) {
            line = noSpace(line); // Easier, less mistakes.
            if(line == "Error_Opening_File=false") { // True before.
                Error_Opening_File = false;
                }
            if(line.substr(0, 4) == "lgg=") {
                lgg = line.substr(line.size() - 2);
                }
            if(line.substr(0, 9) == "nbChoice=") {
                nbChoice = stoi(line.substr(line.size() - 7)); // ?
                }
            if(line.substr(0, 12) == "DemiLargeur=") {
                DemiLargeur = stoi(line.substr(line.size() - 2));
                }
            // cout << line << endl;
            }
        fichier.close();
        }
    assert((DemiLargeur > 20) && "Small largeur!");
    assert((nbChoice > 9) && "nbChoice too low!");
    }

init_lgg(string lgg = "eng") {
    intro = "Sometimes, the doctors do NOT have enough material or drugs to help everybody...\nYou play a doctor, and you must choose who deserves to be helped...\nDo you want to take care of patient 1, and let patient 2 die (choice 1), \nor do you want to take care of patient 2, and let patient 1 die (choice 2)?\nChoose the human to help and save, and the other patient, sacrificed, will die...\nFor your choice, just type 1 or 2, and ENTER.";
    NAME_date = "NAME_date.txt";
    file1 = "What is the name of the file, please?\nFor exemple, :";
    file2 = ".";
    file = file1 + "\"" + NAME_date + "\"" + file2;
    Error_Opening_File1 = "Error Opening File ";
    Error_Opening_File2 = "!";
    ascChoice = "1 or 2? ";
    Patient = "Patient ";
    Intelligence = "Intelligence = ";
    Genre = "Genre = ";
    Comorbidity = "Comorbidity = ";
    Fanatism = "Fanatism = ";
    }

/*
int coutAppendFunctionFileString(string file, int data = 0){
return coutAppendFunctionFileString( file, to_string(data) );  // ?
   }
*/


int coutAppendFunctionFileString(string file, string data = "", bool display = true) { // And create new file if does not exist.
    if(display) {
        cout << data;
        }
    ofstream outfile(file.c_str(), ios_base::app);
    if(!outfile) {
        if(Error_Opening_File) {
            cerr << Error_Opening_File1 << file << Error_Opening_File2 << endl;
            }
        return -1;
        }
    else {
        outfile << data;
        outfile.close();
        }
    return 0; // Ok.
    }

string repeatStringInt(string pattern = "", int n = 0, bool errorDisplay = false) {  // As the name says: string first, int after. // https://github.com/RedGuff/repeatStringInt
    if(n < 0) {
        if(errorDisplay == true) {
            cerr << "Error: repeat(" << pattern << ", " << n << " < 0)" << endl;
            }
        // return "-1";
        return "";
        }
    else if(n == 0) {
        return "";
        }
    else {
        return pattern + repeatStringInt(pattern, n - 1);
        }
    }

int main() {
    srand(time(NULL));       // No need for better init.
    init();
    init_lgg(lgg);
    cout << intro << endl;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    end = std::chrono::system_clock::now();
    int elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
                          (end - start).count();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    cout << file << endl;
    getline(cin, file);
    if(NAME_date == file) {
        cerr << QI42 << endl;
        }
    auto beginChrono = chrono::high_resolution_clock::now();
    coutAppendFunctionFileString(file, ctime(&end_time)); // Format d'affichage mauvais.
    for(int choice = 1; choice < nbChoice + 1; choice++) {
        coutAppendFunctionFileString(file, repeatStringInt("#", 5 + (2 * DemiLargeur)));
        coutAppendFunctionFileString(file, "\n");
        coutAppendFunctionFileString(file, "#");
        coutAppendFunctionFileString(file, repeatStringInt(" ", 1 + DemiLargeur - log10(choice + 1)));
        coutAppendFunctionFileString(file, to_string(choice) + "/" + to_string(nbChoice));
        coutAppendFunctionFileString(file, repeatStringInt(" ", 1 + DemiLargeur - log10(nbChoice + 1)));
        coutAppendFunctionFileString(file, "#\n");
        coutAppendFunctionFileString(file, repeatStringInt("#", 5 + (2 * DemiLargeur)));
        coutAppendFunctionFileString(file, "\n");
        coutAppendFunctionFileString(file, "#");
        coutAppendFunctionFileString(file, repeatStringInt(" ", 4 + (DemiLargeur / 2) - Patient.size()));
        coutAppendFunctionFileString(file, Patient + "1");
        coutAppendFunctionFileString(file, repeatStringInt(" ", 4 + (DemiLargeur / 2) - Patient.size()));
        coutAppendFunctionFileString(file, "#");
        coutAppendFunctionFileString(file, repeatStringInt(" ", 4 + (DemiLargeur / 2) - Patient.size()));
        coutAppendFunctionFileString(file, Patient + "2");
        coutAppendFunctionFileString(file, repeatStringInt(" ", 4 + (DemiLargeur / 2) - Patient.size()));
        coutAppendFunctionFileString(file, "#");
        coutAppendFunctionFileString(file, "\n");
        coutAppendFunctionFileString(file, repeatStringInt("#", 5 + (2 * DemiLargeur)));
        coutAppendFunctionFileString(file, "\n");
        coutAppendFunctionFileString(file, "# ");
        coutAppendFunctionFileString(file, Intelligence);
        intellig = to_string(rand() % 190 + 10);
        coutAppendFunctionFileString(file, intellig);
        coutAppendFunctionFileString(file, repeatStringInt(" ", 0 - intellig.size() + DemiLargeur - Intelligence.size()));
        coutAppendFunctionFileString(file, "# ");
        coutAppendFunctionFileString(file, Intelligence);
        intellig = to_string(rand() % 190 + 10);
        coutAppendFunctionFileString(file, intellig);
        coutAppendFunctionFileString(file, repeatStringInt(" ", 0 - intellig.size() + DemiLargeur - Intelligence.size()));
        coutAppendFunctionFileString(file, "#");
        coutAppendFunctionFileString(file, "\n");
        coutAppendFunctionFileString(file, "# ");
        coutAppendFunctionFileString(file, Genre);
        if(rand() % 2 == 0) {
            coutAppendFunctionFileString(file, "f");
            }
        else {
            coutAppendFunctionFileString(file, "m");
            }
        coutAppendFunctionFileString(file, repeatStringInt(" ", DemiLargeur - Genre.size() - 1));
        coutAppendFunctionFileString(file, "# ");
        coutAppendFunctionFileString(file, Genre);
        if(rand() % 2 == 0) {
            coutAppendFunctionFileString(file, "f");
            }
        else {
            coutAppendFunctionFileString(file, "m");
            }
        coutAppendFunctionFileString(file, repeatStringInt(" ", DemiLargeur - Genre.size() - 1));
        coutAppendFunctionFileString(file, "#\n");
        coutAppendFunctionFileString(file, "# ");
        coutAppendFunctionFileString(file, Comorbidity);
        coutAppendFunctionFileString(file, to_string(rand() % 9)); // Easier!
        coutAppendFunctionFileString(file, repeatStringInt(" ", DemiLargeur - Comorbidity.size() - 1));
        coutAppendFunctionFileString(file, "# ");
        coutAppendFunctionFileString(file, Comorbidity);
        coutAppendFunctionFileString(file, to_string(rand() % 9)); // Easier!
        coutAppendFunctionFileString(file, repeatStringInt(" ", DemiLargeur - Comorbidity.size() - 1));
        coutAppendFunctionFileString(file, "#\n");
        coutAppendFunctionFileString(file, "# ");
        coutAppendFunctionFileString(file, Fanatism);
        coutAppendFunctionFileString(file, to_string(rand() % 9)); // Easier!
        coutAppendFunctionFileString(file, repeatStringInt(" ", DemiLargeur - Fanatism.size() - 1));
        coutAppendFunctionFileString(file, "# ");
        coutAppendFunctionFileString(file, Fanatism);
        coutAppendFunctionFileString(file, to_string(rand() % 9)); // Easier!
        coutAppendFunctionFileString(file, repeatStringInt(" ", DemiLargeur - Fanatism.size() - 1));
        coutAppendFunctionFileString(file, "#\n");
        coutAppendFunctionFileString(file, "# ");
        coutAppendFunctionFileString(file, Utility);
        coutAppendFunctionFileString(file, to_string(rand() % 9)); // Easier!
        coutAppendFunctionFileString(file, repeatStringInt(" ", DemiLargeur - Utility.size() - 1));
        coutAppendFunctionFileString(file, "# ");
        coutAppendFunctionFileString(file, Utility);
        coutAppendFunctionFileString(file, to_string(rand() % 9)); // Easier!
        coutAppendFunctionFileString(file, repeatStringInt(" ", DemiLargeur - Utility.size() - 1));
        coutAppendFunctionFileString(file, "#\n");
        coutAppendFunctionFileString(file, "# ");
        coutAppendFunctionFileString(file, Age);
        Ag = to_string(rand() % 110 + 1);
        coutAppendFunctionFileString(file, Ag);
        coutAppendFunctionFileString(file, repeatStringInt(" ", 0 - Ag.size() + DemiLargeur - Age.size()));
        coutAppendFunctionFileString(file, "# ");
        coutAppendFunctionFileString(file, Age);
        Ag = to_string(rand() % 110 + 1);
        coutAppendFunctionFileString(file, Ag);
        coutAppendFunctionFileString(file, repeatStringInt(" ", 0 - Ag.size() + DemiLargeur - Age.size()));
        coutAppendFunctionFileString(file, "#");
        coutAppendFunctionFileString(file, "\n");
        coutAppendFunctionFileString(file, repeatStringInt("#", 5 + (2 * DemiLargeur)));
        coutAppendFunctionFileString(file, "\n");
        cout << ascChoice ;
        getline(cin, choiced);
        coutAppendFunctionFileString(file, choiced);
        auto endChrono = chrono::high_resolution_clock::now();
        auto dur = endChrono - beginChrono;
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
        coutAppendFunctionFileString(file, "\n");
        coutAppendFunctionFileString(file, to_string(ms), false); // ?
        coutAppendFunctionFileString(file, " ms", false); // ?
        coutAppendFunctionFileString(file, "\n");
        }
    return 0;
    }
