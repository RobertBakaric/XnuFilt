/*
 * SegFilt.cpp
 * 
 * Copyright 2015 Robert Bakaric <rbakaric@irb.hr>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */




#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <ConvertString.hpp>
#include <XNU.hpp>
#include <boost/program_options.hpp>
 
 namespace po = boost::program_options;
 using namespace std;
 using namespace xnu;
 
void PrintLogo(){
  
   cout <<"\n\
\n\
 __   __            ______ _ _ _   \n\
 \\ \\ / /           |  ____(_) | |  \n\
  \\ V / _ __  _   _| |__   _| | |_ \n\
   > < | '_ \\| | | |  __| | | | __|\n\
  / . \\| | | | |_| | |    | | | |_ \n\
 /_/ \\_\\_| |_|\\__,_|_|    |_|_|\\__|\n\
                                  \n\
                                           \n\
                            by Robert Bakaric \n\
\n\
_________________________________________________________________v0.01\n\
**********************************************************************\n\
\n\
CONTACT:\n\
   This program has been written and is maintained by Robert Bakaric,\n\
   email: rbakaric@irb.hr , bakaric@evolbio.mpg.de                    \n\
                                                                      \n\
\n\
\n\
LICENSE:\n\
   The program is distributed under the GNU General Public License.   \n\
   You should have received a copy of the licence together  with this \n\
   software. If not, see http://www.gnu.org/licenses/                 \n\
______________________________________________________________________\n\
**********************************************************************\n\
" << endl;

                                                           
}



template <typename INT, typename CHARA>
po::variables_map SetOptions(INT& argc, CHARA& argv){

    try {
        int opt;
        string version = "0.01";
        po::options_description desc("Options");
        desc.add_options()
            ("help,h", "produce help message")
            ("version,v", "print version information")
            ("input-file,i", po::value< string >(), "input file")
            ("output-file,o", po::value< string >(), "output file")
            ("pam,P", po::value< string >(), "PAM  matrix to use: 60/120/250.")
            ("score,S", po::value< string >(), "Score cutoff.")
            ("probability,p", po::value< string >(), "Probability cutoff.")
            ("min_search_offset,m", po::value< string >(), "Minimum search offset.")
            ("max_search_offset,M", po::value< string >(), "Maximum search offset.")  
        ;

        po::positional_options_description p;
        p.add("input-file,i", -1);
        
        po::variables_map vm;
        po::store(po::command_line_parser(argc, argv).
                  options(desc).positional(p).run(), vm);
        po::notify(vm);
    
        if (vm.count("help")) {
            cout << "Usage: ./program [options]\n\n";
            PrintLogo();
            cout << desc;
            exit(0);
        }else if (vm.count("version")) {
            cout << "Program version:  " << version << "\n";
            exit(0);
        }
        if (!vm.count("input-file")){
            cout << "Input file is not defined \n";
            exit(0);
        }

        return vm;    
    }
    catch(std::exception& e)
    {
        cout << e.what() << "\n";
        exit(0);
    }    
}



template <typename TXnu>
void FilterFile(const string file, TXnu& Xnu, const string& out){
  
   fstream fs;
   ofstream os;
   streambuf *backup;
   
   if(out.size()>0){
      backup = cout.rdbuf();
      os.open (out.c_str());
      if ( !os.is_open())
         throw runtime_error ("Cannot open file: " + out );
      cout.rdbuf(os.rdbuf()); 
   }
   
   
   fs.open (file.c_str(), ios::in);
   if ( !fs.is_open())
      throw  runtime_error ("Cannot open file: " + file );

  string str;
  char c;
  int i=0, f=0;
  
  while( fs.good()) {
    c = fs.get();
    if(fs.eof())
       break;
    if (c == '>'){
		if (str.size()> 0){
            str.resize(i);
            string s = Xnu.Filter(str);
            cout << s << endl;
            str.resize(0);
            i=0;
		}
        f=1;
        cout<<c;
     }else if( f == 1 && c == '\n'){
        f=0;
        cout<<c;
     }else if( f == 1 ){
        cout<<c;
     }else if (f == 0 && c !='\n'){
		 if(i == str.size() )
		     str.resize((str.size()+1)*2);
		 str[i++] = c;
	 }
  }

/* Flush */
str.resize(i);
string s = Xnu.Filter(str);
cout << s << endl;
fs.close();

   if ( os.is_open()){
      cout.rdbuf(backup);
      os.close();
   }
}



int main (int argc, char** argv){

   po::variables_map arg;
   arg = SetOptions(argc,argv);
   unordered_map<string,string> Arg;
try{

  string output = arg.count("output-file") ? arg["output-file"].as<string>() : "";  

   if(arg.count("score"))
      Arg["scut"]    = arg["score"].as<string>();
   if(arg.count("probability"))
      Arg["pcut"]    = arg["probability"].as<string>();
   if(arg.count("min_search_offset"))
      Arg["ncut"]    = arg["min_search_offset"].as<string>();
   if(arg.count("max_search_offset"))
      Arg["mcut"]    = arg["max_search_offset"].as<string>();
   if(arg.count("pam"))
      Arg["pam"]  = arg["pam"].as<string>();
      
/* Make object */
   XNU<int> XnuFilt(Arg);
   
   
   
/* Filter Sequences */  
    FilterFile(arg["input-file"].as<string>(), XnuFilt, output);
    
    
    
  }catch(runtime_error& e){
    cerr << e.what() << "\n";
  }
  
  return 0;
}
