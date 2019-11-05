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

int loadXML(const char *fname)
{
    TiXmlDocument doc;
    if(!doc.LoadFile(fname))
    {
        cerr << doc.ErrorDesc() << endl;
        return -1;
    }

    TiXmlElement* root = doc.FirstChildElement();
    if(root == NULL)
    {
        cerr << "Failed to load file: No root element." << endl;
        doc.Clear();
        return -1;
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

    return 0;
}

int saveXML(char *fname)
{

    TiXmlDocument doc;

    TiXmlElement* root = new TiXmlElement("root");
    doc.LinkEndChild(root);

    TiXmlElement* element1 = new TiXmlElement("Element1");
    root->LinkEndChild(element1);

    element1->SetAttribute("attribute1", "some value");


    TiXmlElement* element2 = new TiXmlElement("Element2");  ///元素
    root->LinkEndChild(element2);

    element2->SetAttribute("attribute2", "2");
    element2->SetAttribute("attribute3", "3");


    TiXmlElement* element3 = new TiXmlElement("Element3");
    element2->LinkEndChild(element3);

    element3->SetAttribute("attribute4", "4");

    TiXmlText* text = new TiXmlText("Some text.");  ///文本
    element2->LinkEndChild(text);

    int success = doc.SaveFile(fname);
    doc.Clear();

    if(success) 
	{
        return 0;
	}
    else
	{
        return -1;
	}

	return 0;
}

int main(int argc, char* argv[])
{
	
    if(loadXML((char *)"a.xml") == -1)
    {
        cout << "Error: loadXML failed!" << endl;
        return -1;
    } 
	else 
	{
		cout << "loadXML a.xml ok!" << endl;
	}

	if (saveXML((char *)"b.xml") == -1)
	{
		cout << "Error: saveXML failed!" << endl;
	} 
	else
	{
		cout << "saveXML b.xml ok!" << endl;
	}

    return 0;
}

