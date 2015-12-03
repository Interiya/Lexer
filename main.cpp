#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

#include "matrix.h"

using namespace std;




enum identType {IDENT= 0, KEYWORDS, OP};
map<string, int> ident_type;
map<char, int> symbol_type;
void initmap()
{
    symbol_type['\t'] = 3;
    symbol_type['\n'] = 4;
    symbol_type['+'] = 5;
    symbol_type['-'] = 6;
    symbol_type['/'] = 7;
    symbol_type['*'] = 8;
    symbol_type['.'] = 9;
    symbol_type[';'] = 10;
    symbol_type[':'] = 11;
    symbol_type[' '] = 12;
    symbol_type['['] = 13;
    symbol_type[']'] = 14;
    symbol_type['{'] = 15;
    symbol_type['}'] = 16;
    symbol_type['('] = 17;
    symbol_type[')'] = 18;
    symbol_type['<'] = 19;
    symbol_type['>'] = 20;
    symbol_type['^'] = 21;
    symbol_type['@'] = 22;
    symbol_type['#'] = 23;
    symbol_type[','] = 24;
    symbol_type['='] = 25;
    symbol_type['_'] = 26;
    symbol_type['~'] = 27;

    ident_type["begin"] = KEYWORDS;
    ident_type["forward"] = KEYWORDS;
    ident_type["do"] = KEYWORDS;
    ident_type["else"] = KEYWORDS;
    ident_type["end"] = KEYWORDS;
    ident_type["for"] = KEYWORDS;
    ident_type["function"] = KEYWORDS;
    ident_type["if"] = KEYWORDS;
    ident_type["array"] = KEYWORDS;
    ident_type["of"] = KEYWORDS;
    ident_type["procedure"] = KEYWORDS;
    ident_type["program"] = KEYWORDS;
    ident_type["record"] = KEYWORDS;
    ident_type["then"] = KEYWORDS;
    ident_type["to"] = KEYWORDS;
    ident_type["type"] = KEYWORDS;
    ident_type["var"] = KEYWORDS;
    ident_type["while"] = KEYWORDS;
    ident_type["break"] = KEYWORDS;
    ident_type["continue"] = KEYWORDS;
    ident_type["downto"] = KEYWORDS;
    ident_type["exit"] = KEYWORDS;
    ident_type["repeat"] = KEYWORDS;
    ident_type["until"] = KEYWORDS;

    ident_type["and"] = OP;
    ident_type["div"]= OP;
    ident_type["mod"] = OP;
    ident_type["not"] = OP;
    ident_type["or"] = OP;
    ident_type["xor"] = OP;
}

int symbolType(char s)
{
    if (s >= '0' && s <= '9')
        return 0;
    if ((s >= 'A' && s <= 'F') || (s >= 'a' && s <= 'f'))
        return 1;
    if ((s >= 'G' && s <= 'Z') || (s >= 'g' && s <= 'z'))
        return 2;
    else
        return symbol_type[s];
}

string toke[33] = {"0", "integer", "0", "real", "ident", "op", "sep", "op", "op", "op", "op", "op", "op", "op", "op", "op", "op", "op", "op", "op", "op", "sep", "op", "op", "sep", "sep", "sep", "sep", "sep", "sep", "@", "sep", "sep"};

char currentSymbol;
int q = 0;
int line = 1;
int column = 0;
ifstream fin("input.txt");
ofstream fout("output.txt");

class Token
{
    int l;
    int c;
    string tok;
    string leks;
public:
    Token (int L, int C, string TOK, string LEKS)
    {
        l = L;
        c = C;
        tok = TOK;
        leks = LEKS;
        cout << l << "\t" << c << "\t" << tok << "\t" << leks << endl;
        fout << l << "\t" << c << "\t" << tok << "\t" << leks << endl;
    }
//    void Print(){
//
//    }
    ~Token(){}
};

template<class V>
class TokenVal: public Token
{
    V val;
public:
    TokenVal(int L, int C, string TOK, string LEKS, V val):
            val(val),
//            this->tok = tok;
            Token(L, C, TOK, LEKS){ }
};

//template<class V> class TokenVal
//{
//    V val;
//public:
//    TokenVal(int L, int C, string TOK, string LEKS, V val){
//        Token(L, C, TOK, LEKS);
//        val(val);
//    }
//};

void next_char()
{
    fin >> currentSymbol;
    if (fin.eof()) currentSymbol = '~';
    if ( symbolType(currentSymbol) == 4)
    {
        line++;
        column = 0;
    } else column++;
}

Token *get_token ()
{
    if (fin.eof())
        return 0;
    string leksema = "";
    string tokenType = "";
    int lineCur;
    int columnCur;
    int st = 0;
    q = 0;
    lineCur = line;
    columnCur = column;

    if ((symbolType(currentSymbol) != 12) && (symbolType(currentSymbol) != 4) && (symbolType(currentSymbol) != 3))
    {
        do
        {
            st = q;
            q = matrix[q][symbolType(currentSymbol)];
            if (q < 0) break;
            leksema += currentSymbol;
            next_char();
        } while(1);
        tokenType = toke[st];
        if (tokenType == "ident" && (ident_type[leksema] == KEYWORDS)) {
            tokenType = "keyword";
        }
        if (tokenType == "ident" && (ident_type[leksema] == OP)) {
            tokenType = "op";
        }
        if ( tokenType == "integer") {
            int a;
            string s = leksema;
            istringstream iss(s);
            iss >> a;
            TokenVal<int> *tokenVal = new TokenVal<int>(lineCur, columnCur, tokenType, leksema, a);
            return tokenVal;
        }



        Token *token = new Token(lineCur, columnCur, tokenType, leksema);
        return token;
    }
    else
    {
        next_char();
        return get_token();
    }
}

int main()
{
    initmap();
    fin >> noskipws;
    next_char();
    Token *cur;
    while (cur = get_token())
    {
        delete cur;
    }

}
