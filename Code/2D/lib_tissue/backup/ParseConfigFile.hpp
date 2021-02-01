#ifndef PARSECONFIGFILE_HPP
#define PARSECONFIGFILE_HPP


#include <iostream>
#include <fstream>
#include <string>


void parseSettingsFile(string fname)
{
	std::string::size_type posBeginIdx, posEndIdx;    	
	std::string            sLine, sValue;    
	std::string            sKeyWord;    
	const std::string      sDelim( "=" );    
	int numcommands = 0;

	std::ifstream myInputFile(fname.c_str(), std::ios::in);    
	
	if( !myInputFile )    
	{       
		cout << "File " << fname << " could not be opened\n";       
		return; 
	}
	else
	{
		cout << "File " << fname << " successfully opened\n";       
	}    
	
	while( getline(myInputFile,sLine) )    
	{       
		if( sLine.empty() );   // Ignore empty lines       
		else       
		{	
			//cout << "Line = [" << sLine << "]" << endl;
			string scomment = sLine.substr(0, 2);
			GenPurpose::trim(scomment);

			if(scomment != "//")
			{
				if(sLine.substr(0,8) == "#include")
				{
					parseSettingsFile(argc, argv, sLine.substr(9, sLine.length() - 9));
				}
				else
				{
					posEndIdx = sLine.find_first_of( sDelim );          
					sKeyWord  = sLine.substr( 0, posEndIdx ); // Extract word
					GenPurpose::trim(sKeyWord);
					posBeginIdx = posEndIdx + 1;  // Beginning of next word (after ':')       
					sValue    = sLine.substr( posBeginIdx, sLine.length() - posBeginIdx );						
					GenPurpose::trim(sValue);			

					if(sValue == "#ASK")
					{
						cout << "User input value for key [" << sKeyWord << "] = ";
						cin >> sValue;
					}
					else if(sValue.substr(0,1) == "#")
					{				
						string temp = sValue.substr(1,sValue.length()-1);				
						int nr = (int)atof(temp.c_str());				
						sValue = argv[nr+3];
					}

					parseKeyValuePair(sKeyWord, sValue);
					numcommands++;
				}
			}
			else
			{
				if(!hideOutput) cout << "Ignoring: [" << sLine << "]" << endl;
			}
		}    
	}

	if(!hideOutput) cout << "Processed " << numcommands << " commands" << endl;    	
}

#endif