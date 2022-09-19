//
//  Project 1 Starter Code - DNA Profiling
//  TODO:  Put your header info here.  Update line above.
//
//
#include <stdio.h>
#include <fstream>
#include "ourvector.h"
#include <string.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//struct definition
struct textfile
{
    string name;
    ourvector<int> str_count;
};

void display(ourvector<textfile> &text, ourvector<char> &dna, ourvector<ourvector<char>> &str_header, ourvector<int> &counter) // add ourvector<textfile> &dna,
{
//    cout << text.size();
//    cout << text[i].str_count.size();
    if (text.size() > 0) {
        cout << "Database loaded:" << endl;
        for (int i = 1; i < text.size(); i++) {
            cout << text[i].name << "";
            for (int j = 0; j < text[i].str_count.size(); j++)
            {
                cout << " " << text[i].str_count[j];
            }
            cout << endl;
        }
    }
    else {
        cout << "No database loaded." << endl;
    }
    if (dna.size() > 0) {
        cout << "\n";
        cout << "DNA loaded:" << endl;
        // add loop for printing out all of DNAs
        for (int i = 0; i < dna.size(); i++) {
            cout << dna[i] << "";
        }
        cout << endl;
    }
    else {
        cout << "\n";
        cout << "No DNA loaded." << endl;
    }
    //DNA processed or not:: if-else
    if (counter.size() == 0) {
        cout << "\n";
        cout << "No DNA has been processed." << endl;
    }
    else {
        cout << "\n";
        cout << "DNA processed, STR counts:" << endl;
        for (int i = 0; i < str_header.size(); i++) {
            for (int j = 0; j < str_header[i].size(); j++) {
                cout << str_header[i][j] << "";
            }
            cout << ": " << counter[i] << endl;
        }
        cout << endl;
    }
}

void search(ourvector<ourvector<char>> &str_header, ourvector<char> &dna, ourvector<int> &counter, ourvector<textfile> &text) {

    if (!text.size() > 0) {
        cout << "No database loaded." << endl;
    }
    else if (!dna.size() > 0) {
        cout << "No DNA loaded." << endl;
    }
    else if (!counter.size() > 0) {
        cout << "No DNA processed." << endl;
    }
    else {
        int count = 0;
        int iter;
//        for (int i = 0; i < counter.size(); i++){
////        cout << counter[i] << endl;
//        }
        for (int i = 0; i < text.size(); i++) {
            for (int j = 0; j < text[i].str_count.size(); j++) {
//                cout << "Line 92" << text[i].name << " " << text[i].str_count[j] << " ";
                if (text[i].str_count[j] == counter[j]) {
//                cout << i << " " << j << "  " << text[i].str_count[j] <<  " " << counter[j] << endl;
                    count++;
//                cout << "Line 85 iter" << i << endl;
//                iter = i;
                }
//            cout << "Count is: " << count << endl;

            }
            if (count == counter.size()) {

                iter  = i;
//                cout << "Line 101 " << text[iter].name << endl;
                break;
            }

        }
//    cout << "Line 98 iter" << iter << endl;
        if (iter > 0 && iter < text.size()) {
            cout << "Searching database..." << endl;
            cout << "Found in database! DNA matches: " << text[iter].name << endl;
        }
        else {
            cout << "Not found in database" << endl;
        }
    }
}

void process(ourvector<char> &dna, ourvector<textfile> &text, ourvector<ourvector<char>> &str_header, ourvector<int> &counter) {

    if (!text.size() > 0) {
        cout << "No database loaded." << endl;
    }
    else if (!dna.size() > 0) {
        cout << "No DNA loaded." << endl;
    }
    else {
        ourvector<char> temp;
        int result;
        for (int str = 0; str < str_header.size(); str++) {
//            for (int j = 0; j < str_header[str].size(); j++) {
//                cout << str_header[str][j] << "";
//            }
//        cout << "Line 184" << " " << str << endl;
            int localMax = 0;
            int globalMax = 0;
            for (int i = 0; i < str_header[str].size(); i++) {
//            cout << "Line 186" << endl;
                for (int j = 0; j < (dna.size() - str_header[str].size()); j++ ) {
//                cout << "Line 190" << endl;
                    result = 1;
                    for( int k = 0; k < str_header[str].size(); k++) {
//                    cout << "Line 193" << endl;
                        if (dna[j+k] != str_header[str][k]) {
                            result = 0;
                            localMax = 0;
                            break;
                        }
                    }

                    if(result) {
                        j += str_header[str].size() - 1;
                        localMax++;
                    }

                    if(localMax > globalMax) {
                        globalMax = localMax;
                    }
                }
            }
            counter.push_back(globalMax);
//            cout << counter[str];
        }
        cout << "Processing DNA..." << endl;
    }
}


void load_dna(string &filename, ourvector<char> &dna) {
    //get first and only line, char by char, till end of line

    ifstream infile(filename);
//    ourvector<char> temp_dna;
    string letter;
    while(getline(infile,letter, '\n')) {
        for (int i = 0; i < letter.size(); i++) {
            dna.push_back(letter.at(i));
//                cout << temp_dna <<
        }
    }
    cout << "Loading DNA..."  << endl;
    if (filename != "1.txt" && filename != "2.txt" && filename != "3.txt" &&
        filename != "4.txt" && filename != "5.txt" &&
        filename != "6.txt" && filename != "7.txt" && filename != "8.txt" &&
        filename != "9.txt" && filename != "10.txt" &&
        filename != "11.txt" && filename != "12.txt" && filename != "13.txt" &&
        filename != "14.txt" && filename != "15.txt" &&
        filename != "16.txt" && filename != "17.txt" && filename != "18.txt" &&
        filename != "19.txt" && filename != "20.txt" ) {
        cout << "Error: unable to open '" << filename << "'" << endl;
    }

}

void load_db(string &filename, ourvector<textfile> &text, ourvector<ourvector<char>> &str_header) {
//    cout << "Line 25 reached." << endl;

    ourvector<char> temp_dna;
    string tempStr;
    int str_value;
    ifstream infile(filename);
    string line;
    text.push_back(textfile());
    getline(infile,line, '\n'); // gets first line of headers:: name,AGATC,AATG,TATC

    //processing header here//
//    cout << "Line 100 " << line << endl;
    stringstream header(line);
    getline(header,line, ','); //removes "name" from header
    while(getline(header, line, ',')) { // AGATC
//        cout << "Line 104 " << line << endl;
        for (int i = 0; i < line.size(); i++) {
            temp_dna.push_back(line.at(i)); //char by char storing:: A, G, A, T, C
//            cout << temp_dna.at(i);
        } // temp_dna has AGATC
//        cout<< temp_dna.size();
        str_header.push_back(temp_dna);
        temp_dna.clear();// now str_header has AGAT
//        cout << "\nLine 112" << endl;
    }
//    cout << str_header.size() << endl;
    //processing lines 1 to n with name values and str_count values//
    while(getline(infile,line, '\n')) { // gets all the lines after first header line:: for eg:: Alice,2,8,3
        textfile tempObj;
//        cout << line << endl;
        stringstream info(line);

        getline(info, line, ','); // gets first string until ',' :: Alice // do we have to store names char by char also?
//        cout << "Line 127 " << line << endl;
        for (int j = 0; j < line.size(); j++) {
            tempStr += line.at(j);
//            cout << "Line 133 " << line.at(j) << endl;
        }
        tempObj.name = tempStr;
        tempStr = "";
//        cout << "Line 136 " << tempObj.name << endl;

        while(getline(info, line, ',')) { // 2, 8, 3
            str_value = stoi(line);
            tempObj.str_count.push_back(str_value);
//            cout << "Line 161 " << str_value << endl;
        }
        text.push_back(tempObj);
//        cout << text.size();
    }
    cout << "Loading database..." << endl;
    if (filename != "small.txt" && filename != "large.txt") {
        cout << "Error: unable to open '" << filename << "'" << endl;
        text.clear();
    }

}

void evaluate_command(string command, char *switch_value) {
    if(command.compare("load_db") == 0) {
        *switch_value = '1';
    }
    if(command.compare("display") == 0) {
        *switch_value = '2';
    }
    if(command.compare("load_dna") == 0) {
        *switch_value = '3';
    }
    if(command.compare("process") == 0) {
        *switch_value = '4';
    }
    if(command.compare("search") == 0) {
        *switch_value = '5';
    }
} //end of evaluate_command

int main() {
    ourvector<textfile> text;
    ourvector<char> dna;
    ourvector<ourvector<char>> str_header;
    string filename, command;
    ourvector<char> longestSTR;
    ourvector<int> counter;
    //the menu//
    cout << "Welcome to the DNA Profiling Application." << endl;
    cout << "Enter command or # to exit:";
    cin >>  command;
//    cout << command;
    while (command.compare("#") != 0) {
//        cout << "Line 136" << endl;
        if (command.compare( "load_db") == 0 || command.compare( "load_dna") == 0) {
            cin >> filename;
        }
        char switch_val;
        int db_counter, dna_counter;
        evaluate_command(command,&switch_val);
        switch(switch_val) {
            case '1':
                if (++db_counter > 1) {
                    text.clear();
                    str_header.clear();
                    load_db(filename, text, str_header);
                }
                else {
                    load_db(filename, text, str_header);
                }

//                display(text);
                break;
            case '2':
                display(text, dna, str_header, counter);
                break;
            case '3':
//                load_dna(filename,dna);
                if (++dna_counter > 1) {
                    dna.clear();
                    load_dna(filename, dna);
                }
                else {
                    load_dna(filename, dna);
                }
                break;
            case '4':
                process(dna, text, str_header, counter);
                break;
            case '5':
                search(str_header, dna, counter, text);
                break;
        }
        cout << "Enter command or # to exit:";
        cin >> command;
    }
    return 0;
} // end of program






