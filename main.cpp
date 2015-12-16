#include <stdexcept>
#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

//#include "matrix.h"

int matrix[59][31] = {
        1,4,4,-1,-1,7,9,11,13,5,29,21,-1,24,25,40,-1,26,27,16,18,15,28,52,30,23,4,31,43,48,-1,
        1,-1,-1,-1,-1,-1,-1,-1,-1,2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,49,-1,
        3,-1,-1,-1,-1,-1,-1,-1,-1,45,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,49,-1,
        4,4,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,-1,-1,4,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,6,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,8,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,10,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,36,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,12,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,14,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,20,-1,-1,-1,-1,17,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,19,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,22,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,38,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        32,32,32,32,47,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,56,32,32,-1,
        34,34,34,34,47,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,33,34,34,46,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        34,34,34,34,47,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,35,34,34,46,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        36,36,36,36,-1,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,-1,
        37,37,37,37,37,37,37,37,38,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,46,
        37,37,37,37,37,37,37,37,38,37,37,37,37,37,37,37,37,37,39,37,37,37,37,37,37,37,37,37,37,37,46,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,42,41,41,41,41,41,41,41,41,41,41,41,41,41,46,
        41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,42,41,41,41,41,41,41,41,41,41,41,41,41,41,46,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        44,44,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,44,-1,
        44,44,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,44,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        4,4,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,-1,-1,4,-1,
        50,-1,-1,-1,-1,51,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        53,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,54,-1,-1,
        53,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        55,55,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,-1,
        55,55,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,57,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,58,-1,-1,46,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
};



using namespace std;

enum identType {IDENT= 0, KEYWORDS, OP, ERROR};
enum symbolType { NUMBER=0, CHARACTER_A_F, CHARACTER_G_Z, TAB, NEXT_LINE, PLUS, MINUS, DIVISION, MULTIPLICATION, POINT, SEMICOLON, COLON, SPACE, LEFT_BRACKET, RIGHT_BRACKET, LEFT_BRACES, RIGHT_BRACES, LEFT_PARENTHESES, RIGHT_PARENTHESES, LEFT_CHEVRONS, RIGHT_CHEVRONS, CARET, AT_SIGN, HASH, COMMA, EQUALS, UNDERSCORE, PRIME, DOLLAR, CHARACTER_E, TILDE };
map<string, int> ident_type;
map<char, int> symbol_type;
void initmap()
{
    symbol_type['\t'] = TAB;
    symbol_type['\n'] = NEXT_LINE;
    symbol_type['+'] = PLUS;
    symbol_type['-'] = MINUS;
    symbol_type['/'] = DIVISION;
    symbol_type['*'] = MULTIPLICATION;
    symbol_type['.'] = POINT;
    symbol_type[';'] = SEMICOLON;
    symbol_type[':'] = COLON;
    symbol_type[' '] = SPACE;
    symbol_type['['] = LEFT_BRACKET;
    symbol_type[']'] = RIGHT_BRACKET;
    symbol_type['{'] = LEFT_BRACES;
    symbol_type['}'] = RIGHT_BRACES;
    symbol_type['('] = LEFT_PARENTHESES;
    symbol_type[')'] = RIGHT_PARENTHESES;
    symbol_type['<'] = LEFT_CHEVRONS;
    symbol_type['>'] = RIGHT_CHEVRONS;
    symbol_type['^'] = CARET;
    symbol_type['@'] = AT_SIGN;
    symbol_type['#'] = HASH;
    symbol_type[','] = COMMA;
    symbol_type['='] = EQUALS;
    symbol_type['_'] = UNDERSCORE;
    symbol_type['\''] = PRIME;
    symbol_type['$'] = DOLLAR;
    symbol_type['~'] = TILDE;

    ident_type["BadNL"] = ERROR;
    ident_type["BadEOF"] = ERROR;
    ident_type["BadChar"] = ERROR;
    ident_type["NoExp"] = ERROR;
    ident_type["NoFract"] = ERROR;
    ident_type["NoHex"] = ERROR;
    ident_type["NoCC"] = ERROR;
    ident_type["BadC"] = ERROR;

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
        return NUMBER;
    if ((s == 'E') || (s == 'e'))
        return CHARACTER_E;
    if ((s >= 'A' && s <= 'F') || (s >= 'a' && s <= 'f'))
        return CHARACTER_A_F;
    if ((s >= 'G' && s <= 'Z') || (s >= 'g' && s <= 'z'))
        return CHARACTER_G_Z;
    else
        return symbol_type[s];
}

string toke[59] = {"0","integer","NoFract","real","ident","op","sep","op","op","op","op","op","op","op","op","op","op","op","op","op","op","sep","op","op","sep","sep","sep","sep","op","sep","sep","0","0","char","0","string","comment","0","0","comment","0","0","comment","NoHex","hex","n2","BadEOF","BadNL","ident","NoExp","real","NoExp","NoCC","char#","NoCC","char#","string","0","char"};
char currentSymbol;
int q = 0;
int line = 1;
int column = 0;
ifstream fin("input.txt");
ofstream fout("output.txt");
int columnError = 0;


class LexerError
{
protected:
    int l;
    int c;
    string msg;
public:
    LexerError (int L, int C, string MSG)
    {
        l = L;
        c = C;
        msg = MSG;
    }
    void print (){
        cout << l << "\t" << c << "\t" << msg << endl;
        fout << l << "\t" << c << "\t" << msg << endl;
    }
    ~LexerError(){}
};

class Token
{
protected:
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
    }
    virtual void print(){
        cout << l << "\t" << c << "\t" << tok << "\t" << leks << endl;
        fout << l << "\t" << c << "\t" << tok << "\t" << leks << endl;
    }
    ~Token(){}
};
template<class V>
class TokenVal: public Token
{
    V val;
public:
    TokenVal(int L, int C, string TOK, string LEKS, V val):
            val(val),
            Token(L, C, TOK, LEKS){}
    void print(){
        cout << l << "\t" << c << "\t" << tok << "\t" << leks << "\t" << val << endl;
        fout << l << "\t" << c << "\t" << tok << "\t" << leks << "\t" << val << endl;
    }
};
template<>
void TokenVal<double>::print() {
    char buf[11];
    sprintf(buf, "%.4E", val);
    buf[8] = buf[9]; buf[9] = buf[10]; buf[10] = 0;
    cout << l << "\t" << c << "\t" << tok <<"\t" << leks << "\t" << buf << endl;
    fout << l << "\t" << c << "\t" << tok <<"\t" << leks << "\t" << buf << endl;
}

void next_char()
{
    fin >> currentSymbol;

    if (fin.eof()) currentSymbol = '~';
    if (symbolType(currentSymbol) == NEXT_LINE)
    {
        line++;
        columnError = column;
        column = 0;
    } else
    if (symbolType(currentSymbol) == TAB)
    {
        column = column/4 * 4 +4;
    }
    else column++;
}

Token *bufer = NULL;
Token *get_token ()
{
    if (bufer != NULL)
    {
        Token *temp = bufer;
        bufer = NULL;
        return temp;
    }
    if (fin.eof()) return 0;
    string leksema = "";
    string tokenType = "";
    int lineCur;
    int columnCur;
    int st = 0;
    q = 0;
    lineCur = line;
    columnCur = column;

    if ((symbolType(currentSymbol) != SPACE) && (symbolType(currentSymbol) != NEXT_LINE) && (symbolType(currentSymbol) != TAB))
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
        if (tokenType == "n2")
        {
            leksema = leksema.substr(0, leksema.size()-2);
            bufer = new Token(lineCur, column - 2, "sep", "..");
            tokenType = "integer";
        }
        if ( tokenType == "integer")
        {
            int a;
            a = atoi(leksema.c_str());
            TokenVal<int> *tokenVal = new TokenVal<int>(lineCur, columnCur, tokenType, leksema, a);
            return tokenVal;
        }
        if (tokenType == "real")
        {
            double a;
            a = atof(leksema.c_str());
            TokenVal<double> *tokenVal = new TokenVal<double>(lineCur, columnCur, "real", leksema, a);
            return tokenVal;
        }
        if (tokenType == "ident" && (ident_type[leksema] == KEYWORDS)) tokenType = "keyword";
        if (tokenType == "ident" && (ident_type[leksema] == OP)) tokenType = "op";
        if (tokenType == "char")
        {
            char d;
            d = leksema[1];
            TokenVal<char> *tokenVal = new TokenVal<char>(lineCur, columnCur, tokenType, leksema, d);
            return tokenVal;
        }
        if (tokenType == "char#")
        {
            string s;
            int a;
            char d;
            tokenType = "char";
            if (leksema[1] == '$')
            {
                s = leksema.substr(2, leksema.size());
                a = strtol (s.c_str(), NULL, 16);
            } else {
                s = leksema.substr(1, leksema.size());
                a = atoi(s.c_str());
            }
            cout << a << endl;
            if (a > 127) throw new LexerError(lineCur,column,"BadCC");
            d = (char)a;
            TokenVal<char> *tokenVal = new TokenVal<char>(lineCur, columnCur, tokenType, leksema, d);
            return tokenVal;
        }
        if (tokenType == "string")
        {
            string s;
            if (leksema.size() != 2) s = leksema.substr(1,leksema.size()-2);
            TokenVal<string> *tokenVal = new TokenVal<string>(lineCur, columnCur, tokenType, leksema, s);
            return tokenVal;
        }
        if (tokenType == "hex")
        {
            long int a;
            string s;
            s = leksema.substr(1, leksema.size());
            a = strtol (s.c_str(), NULL, 16);
            TokenVal<int> *tokenVal = new TokenVal<int>(lineCur, columnCur, tokenType, leksema, a);
            return tokenVal;
        }
        if (ident_type[tokenType] == ERROR)
        {
            if (tokenType == "BadNL")
            {
                columnCur = columnError +1;
            } else
            if (tokenType == "BadEOF")
            {
                lineCur = line;
                columnCur = column - 1;
            }
            else columnCur = column;
            throw new LexerError(lineCur,columnCur,tokenType);
        }
        if (tokenType == "comment")
        {
            return get_token();
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
    try {
        while (cur = get_token()) {
            cur->print();
            delete cur;
        }
    }catch (LexerError *e) { e->print(); }
}
