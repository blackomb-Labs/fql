        #include <iostream>
        #include <string>
        #include <filesystem>
        #include <fstream>
        #include <vector>
        #include "../../include/lexer/lexer.h"
        using namespace std;

        int parser(string fileName) {
            ifstream file(fileName);

            if (!file.is_open()) {
                cerr << "Error opening file!\n";
                return 1;
            }

            string line;

            while (getline(file, line)) {
                vector<string> tokens = lexer(line);

                if (tokens.size() < 3)
                    continue;

                // NAME OPERATORS -------------------------------

                if (tokens[0] == "NM") {

                    if (tokens[1] == "=") {
                        cout << "NM = " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == "!=") {
                        cout << "NM != " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == "*=") {
                        cout << "NM *= " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == ":=") {
                        cout << "NM := " << tokens[2] << "\n";
                    }
                    else{
                        cout<<"ERROR: '"+tokens[1]+"' IS NOT VALID.\n";
                    }

                }

                // CONTENT OPERATORS ----------------------------

                else if (tokens[0] == "CNT") {

                    if (tokens[1] == ":=") {
                        cout << "CNT := " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == "=") {
                        cout << "CNT = " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == "!=") {
                        cout << "CNT != " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == "*=") {
                        cout << "CNT *= " << tokens[2] << "\n";
                    }   else{
                        cout<<"ERROR: '"+tokens[1]+"' IS NOT VALID.\n";
                    }

                }

                // SIZE OPERATORS --------------------------------

                else if (tokens[0] == "SZB"){

                    if (tokens[1] == "=") {
                        cout << tokens[0] << " = " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == "!=") {
                        cout << tokens[0] << " != " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == ">") {
                        cout << tokens[0] << " > " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == "<") {
                        cout << tokens[0] << " < " << tokens[2] << "\n";
                    }   else{
                        cout<<"ERROR: '"+tokens[1]+"' IS NOT VALID.\n";
                    }
                    }
                else if (tokens[0] == "SZK"){

                    if (tokens[1] == "=") {
                        cout << tokens[0] << " = " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == "!=") {
                        cout << tokens[0] << " != " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == ">") {
                        cout << tokens[0] << " > " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == "<") {
                        cout << tokens[0] << " < " << tokens[2] << "\n";
                    }   else{
                        cout<<"ERROR: '"+tokens[1]+"' IS NOT VALID.\n";
                    }
                }
                else if(tokens[0] == "SZM"){

                    if (tokens[1] == "=") {
                        cout << tokens[0] << " = " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == "!=") {
                        cout << tokens[0] << " != " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == ">") {
                        cout << tokens[0] << " > " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == "<") {
                        cout << tokens[0] << " < " << tokens[2] << "\n";
                    }   else{
                        cout<<"ERROR: '"+tokens[1]+"' IS NOT VALID.\n";
                    }
                }
                else if(tokens[0] == "SZG") {

                    if (tokens[1] == "=") {
                        cout << tokens[0] << " = " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == "!=") {
                        cout << tokens[0] << " != " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == ">") {
                        cout << tokens[0] << " > " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == "<") {
                        cout << tokens[0] << " < " << tokens[2] << "\n";
                    }   else{
                        cout<<"ERROR: '"+tokens[1]+"' IS NOT VALID.\n";
                    }

                }

                // EXTENSION OPERATORS ---------------------------

                else if (tokens[0] == "EXT") {

                    if (tokens[1] == "=") {
                        cout << "EXT = " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == "!=") {
                        cout << "EXT != " << tokens[2] << "\n";
                    }   else{
                        cout<<"ERROR: '"+tokens[1]+"' IS NOT VALID.\n";
                    }

                }

                // EXTENDED ATTRIBUTE OPERATORS ------------------

                else if (tokens[0] == "ATR") {

                    if (tokens.size() < 4)
                        continue;

                    if (tokens[2] == "=") {
                        cout << "ATR " << tokens[1]
                             << " = " << tokens[3] << "\n";
                    }
                    else if (tokens[2] == "!=") {
                        cout << "ATR " << tokens[1]
                             << " != " << tokens[3] << "\n";
                    }
                    else if (tokens[2] == "<") {
                        cout << "ATR " << tokens[1]
                             << " < " << tokens[3] << "\n";
                    }
                    else if (tokens[2] == ">") {
                        cout << "ATR " << tokens[1]
                             << " > " << tokens[3] << "\n";
                    }   else{
                        cout<<"ERROR: '"+tokens[1]+"' IS NOT VALID.\n";
                    }

                }

                // PARENT OPERATORS ------------------------------

                else if (tokens[0] == "PAR") {

                    if (tokens[1] == "=") {
                        cout << "PAR = " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == "!=") {
                        cout << "PAR != " << tokens[2] << "\n";
                    }   else{
                        cout<<"ERROR: '"+tokens[1]+"' IS NOT VALID.\n";
                    }

                }

                // LINE COUNT OPERATORS --------------------------

                else if (tokens[0] == "LCT") {

                    if (tokens[1] == "=") {
                        cout << "LCT = " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == "!=") {
                        cout << "LCT != " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == ">") {
                        cout << "LCT > " << tokens[2] << "\n";
                    }
                    else if (tokens[1] == "<") {
                        cout << "LCT < " << tokens[2] << "\n";
                    }   else{
                        cout<<"ERROR: '"+tokens[1]+"' IS NOT VALID.\n";
                    }

                }

                // BOOLEAN OPERATORS -----------------------------

                else if (tokens[0] == "BIN") {

                    if (tokens[1] == "=") {
                        if (tokens[2] == "TRUE") {
                            cout << "BIN = TRUE\n";
                        }
                        else if (tokens[2] == "FALSE") {
                            cout << "BIN = FALSE\n";
                        }
                        else{
                            cout<<"ERROR: '"+tokens[2]+"' IS NOT VALID.\n";
                        }
                    }
                    else{
                        cout<<"ERROR: '"+tokens[1]+"' IS NOT VALID.\n";
                    }

                }

                // DIRECTORY OPERATORS ---------------------------

                else if (tokens[0] == "DIR") {

                    if (tokens[1] == "=") {
                        if (tokens[2] == "TRUE") {
                            cout << "DIR = TRUE\n";
                        }
                        else if (tokens[2] == "FALSE") {
                            cout << "DIR = FALSE\n";
                        }
                        else{
                            cout<<"ERROR: '"+tokens[2]+"' IS NOT VALID.\n";
                        }
                    }
                    else{
                        cout<<"ERROR: '"+tokens[1]+"' IS NOT VALID.\n";
                    }

                }
                else{
                    cout<<"ERROR: '"+tokens[0]+"' IS NOT VALID.\n";
                }

    }
    file.close();
    filesystem::remove("CODE");
    return 0;
}
