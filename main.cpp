/**
 *  Created by Kamil Dzierzanowski and
 *  published under GNU GPL v.3.0 license.
 *
 *  Claiming authorship to this project
 *  is forbidden for the duration of
 *  the course it is made for.
 **/

#include <iostream>
#include <string>
#include <fstream>

#include "include/Element.hpp"
#include "include/Object.hpp"
#include "include/Property.hpp"
#include "include/json_in.h"
#include "include/json_out.h"

using namespace std;

int main()
{
    ifstream ifile;
    ofstream ofile;
    ifile.open("test_json.json", fstream::in);
    if (!ifile.is_open()){
        cout << "[ERROR] Cannot open input file!" << endl;
        return 0;
    }
    ofile.open("out_xml.xml", fstream::out);
    if (!ofile.is_open()){
        cout << "[ERROR] Cannot open output file!" << endl;
        return 0;
    }

    Object document;
    cout << loadJSON(ifile, document) << endl;
    printElement(ofile, document, 0);

    ifile.close();
    ofile.close();

    return 0;
}
