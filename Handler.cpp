#include "Handler.h"

using namespace std;

void getLineStream(basic_istream<char> &istream, string &target){
  char cbuf;
  istream.read(&cbuf, 1);
  while(!istream.eof() && cbuf != '\n'){
    target += cbuf;
    istream.read(&cbuf, 1);
  }
}


/**
 * option parameters:
 *  -i    Path file to input file
 *  -o    Path file to output file (output file to check, output test cases)
 */

int entrypoint(int argi, char *argcs[]){
  string inputPathfile = DEFAULT_INPUTFILE;
  string outputPathfile = DEFAULT_OUTPUTFILE;
  string outputCheckfile;

  for(int i = 0; i < argi; i++){
    if(argcs[i][0] == '-'){
      switch(argcs[i][1]){
        break; case 'i':
          if(strlen(argcs[i]) > 2)
            inputPathfile = (argcs[i] + 2);
          else
            throw invalid_argument("Option doesn't have the value.");

        break; case 'o':
          if(strlen(argcs[i]) > 2)
            outputCheckfile = (argcs[i] + 2);
          else
            throw invalid_argument("Option doesn't have the value.");
      }
    }
  }

  streambuf *defaultStreamI = cin.rdbuf();
  ifstream inputFile(inputPathfile, ios::in);
  cin.rdbuf(inputFile.rdbuf());

  streambuf *defaultStreamO = cout.rdbuf();
  ofstream outputfile(outputPathfile, ios::out);
  cout.rdbuf(outputfile.rdbuf());

  auto begin_time = chrono::steady_clock::now();
  main();
  auto end_time = chrono::steady_clock::now();

  chrono::duration<double> exec_time = end_time - begin_time;

  cout.rdbuf(defaultStreamO);
  outputfile.close();
  ifstream outputFile1(outputPathfile), outputFile2(outputCheckfile);
  int currentline = 1;
  bool gotErrors = false;
  while(!outputFile1.eof() || !outputFile2.eof()){
    string file1, file2;
    getLineStream(outputFile1, file1);
    getLineStream(outputFile2, file2);
    //outputFile1.getline(buf, 255);
    //outputFile2.getline(buf2, 255);
    if(file1 != file2){
      cout << "Output difference in line: " << currentline << endl;
      gotErrors = true;
    }
    
    currentline++;
  }

  cout << endl;
  if(!gotErrors)
    cout << "No errors found." << endl;
  cout << "Time executed: " << exec_time.count() << "s" << endl;

  return 0;
}


int startprog(){
  LPSTR argsstr = GetCommandLineA();
  int argsstrlen = strlen(argsstr);

  int argsi = 0;
  char **argcs = (char**)malloc(0);

  int i = 0;
  while(i < argsstrlen){
    argsi++;
    argcs = (char**)realloc(argcs, sizeof(char*)*argsi);
    
    string str;
    while(i < argsstrlen && argsstr[i] != ' '){
      str += argsstr[i];
      i++;
    }
    i++;

    argcs[argsi-1] = (char*)malloc(str.length()+1);
    str.copy(argcs[argsi-1], str.length());
    argcs[argsi-1][str.length()] = '\0';
  }

  entrypoint(argsi, argcs);
  exit(0);
}

static int tmp = startprog();