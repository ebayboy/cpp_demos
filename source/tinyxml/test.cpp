/****************************************************************************
@file:test.cpp
@author:ebayboy@163.com
@date:2019-11-05 10:50
@version: 1.0
@description: cpp file
@Copyright (c)  all right reserved
**************************************************************************/

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
#include "tinyxml.h"

using namespace std;

#define DEBUG

enum SuccessEnum
{
    FAILURE, SUCCESS
};

SuccessEnum loadXML()
{

    TiXmlDocument doc;
    if(!doc.LoadFile("a.xml"))
    {

        cerr << doc.ErrorDesc() << endl;
        return FAILURE;
    }

    TiXmlElement* root = doc.FirstChildElement();
    if(root == NULL)
    {

        cerr << "Failed to load file: No root element." << endl;
        doc.Clear();
        return FAILURE;
    }

    for(TiXmlElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
    {

        string elemName = elem->Value();
        const char* attr;
        attr = elem->Attribute("priority");
        if(strcmp(attr,"1")==0)
        {

            TiXmlElement* e1 = elem->FirstChildElement("bold");
            TiXmlNode* e2=e1->FirstChild();
            cout<<"priority=1\t"<<e2->ToText()->Value()<<endl;

        }
        else if(strcmp(attr,"2")==0)
        {

            TiXmlNode* e1 = elem->FirstChild();
            cout<<"priority=2\t"<<e1->ToText()->Value()<<endl;
        }
    }
    doc.Clear();
    return SUCCESS;
}

int main(int argc, char* argv[])
{

    if(loadXML() == FAILURE)
	{
		cout << "Error: load xml failed!" << endl;
        return -1;
	}

    return 0;
}

