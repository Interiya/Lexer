#include <stdexcept>
#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

int matrix[61][32] = {
        1,4,4,42,42,7,9,11,13,5,29,21,42,24,25,40,59,26,27,16,18,15,28,52,30,23,4,31,43,48,59,59,
        1,-1,-1,-1,-1,-1,-1,-1,-1,2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,49,-1,-1,
        3,-1,-1,-1,-1,-1,-1,-1,-1,45,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,49,-1,-1,
        4,4,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,-1,-1,4,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,6,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,8,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,10,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,36,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,12,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,14,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,20,-1,-1,-1,-1,17,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,19,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,22,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,38,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        32,32,32,32,47,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,56,32,32,32,32,
        34,34,34,34,47,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,33,34,34,46,34,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        34,34,34,34,47,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,35,34,34,46,34,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,60,-1,-1,-1,-1,
        36,36,36,36,-1,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,-1,-1,
        37,37,37,37,37,37,37,37,38,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,46,-1,
        37,37,37,37,37,37,37,37,38,37,37,37,37,37,37,37,37,37,39,37,37,37,37,37,37,37,37,37,37,37,46,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,42,41,41,41,41,41,41,41,41,41,41,41,41,41,46,-1,
        41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,42,41,41,41,41,41,41,41,41,41,41,41,41,41,46,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        44,44,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,44,-1,-1,
        44,44,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,44,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        4,4,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,-1,-1,4,-1,-1,
        50,-1,-1,-1,-1,51,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        53,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,54,-1,-1,-1,
        53,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        55,55,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,-1,-1,
        55,55,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,57,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,58,-1,-1,46,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        34,34,34,34,47,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,35,34,34,46,34,
};
using namespace std;

enum identType {NO_TOKEN=0, INTEGER, NO_FRACT, REAL, IDENT,
    KEYWORD, OP, SEP, CHAR, STRING, COMMENT, NO_HEX, HEX,
    N2, BAD_EOF, BAD_NL, NO_EXP, NO_CC, CHAR$, CHAR$$, BAD_CHAR, ERROR};
string tokenTypeName[] = {"","integer","NoFract","real","ident","keyword","op","sep","char",
                        "string","comment","NoHex","hex","n2",
                        "BadEOF","BadNL","NoExp","NoCC",
                        "char#","char#$","BadChar"};
enum symbolType { NUMBER=0, CHARACTER_A_F, CHARACTER_G_Z, TAB,
    NEXT_LINE, PLUS, MINUS, DIVISION, MULTIPLICATION, POINT,
    SEMICOLON, COLON, SPACE, LEFT_BRACKET, RIGHT_BRACKET,
    LEFT_BRACES, RIGHT_BRACES, LEFT_PARENTHESES,
    RIGHT_PARENTHESES, LEFT_CHEVRONS, RIGHT_CHEVRONS, CARET,
    AT_SIGN, HASH, COMMA, EQUALS, UNDERSCORE, PRIME, DOLLAR,
    CHARACTER_E, TILDE, OTHER_CHARACTER };
map<string, identType> ident_type;
map<char, symbolType> symbol_type;
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

    ident_type["begin"] = KEYWORD;
    ident_type["forward"] = KEYWORD;
    ident_type["do"] = KEYWORD;
    ident_type["else"] = KEYWORD;
    ident_type["end"] = KEYWORD;
    ident_type["for"] = KEYWORD;
    ident_type["function"] = KEYWORD;
    ident_type["if"] = KEYWORD;
    ident_type["array"] = KEYWORD;
    ident_type["of"] = KEYWORD;
    ident_type["procedure"] = KEYWORD;
    ident_type["program"] = KEYWORD;
    ident_type["record"] = KEYWORD;
    ident_type["then"] = KEYWORD;
    ident_type["to"] = KEYWORD;
    ident_type["type"] = KEYWORD;
    ident_type["var"] = KEYWORD;
    ident_type["while"] = KEYWORD;
    ident_type["break"] = KEYWORD;
    ident_type["continue"] = KEYWORD;
    ident_type["downto"] = KEYWORD;
    ident_type["exit"] = KEYWORD;
    ident_type["repeat"] = KEYWORD;
    ident_type["until"] = KEYWORD;

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
    else if (symbol_type[s] != 0)
        return symbol_type[s];
    else
        return OTHER_CHARACTER;
}

int tokenTypeCode[] = {NO_TOKEN,INTEGER,NO_FRACT,REAL ,IDENT ,OP,
                 SEP,OP,OP,OP,OP,OP,OP,OP,OP,OP,OP,OP,OP,OP,
                 OP,SEP,OP,OP,SEP,SEP,SEP,SEP,OP,SEP,SEP,
                 NO_TOKEN,NO_TOKEN,CHAR,NO_TOKEN,STRING,
                 COMMENT,NO_TOKEN,NO_TOKEN,COMMENT,NO_TOKEN,
                 NO_TOKEN,COMMENT,NO_HEX,HEX,N2,BAD_EOF,BAD_NL,
                 IDENT,NO_EXP,REAL,NO_EXP,NO_CC,CHAR$,NO_CC,CHAR$$,
                 STRING,NO_TOKEN,CHAR,BAD_CHAR,NO_TOKEN};

char currentSymbol = '\0';
int q = 0;
int line = 1;
int column = 1;
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

    if (currentSymbol != '\0')
    {
        int currentSymbolType = symbolType(currentSymbol);
        if (currentSymbolType == NEXT_LINE) {
            line++;
            columnError = column;
            column = 1;
        } else if (currentSymbolType == TAB) {
            column = ((column - 1) / 4 + 1) * 4 + 1;
        }
        else column++;
    }

    fin >> currentSymbol;
    if (fin.eof()) currentSymbol = '~';
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
    int lineCur = line;
    int columnCur = column;
    int currentState = 0;
    int currentTokenTypeCode;
    q = 0;
    while(true)
    {
        currentState = q;
        q = matrix[q][symbolType(currentSymbol)];
        if (q < 0) break;
        leksema += currentSymbol;
        next_char();
    }
    currentTokenTypeCode = tokenTypeCode[currentState];
    tokenType = tokenTypeName[currentTokenTypeCode];

    if (currentTokenTypeCode == N2)
    {
        leksema = leksema.substr(0, leksema.size()-2);
        bufer = new Token(lineCur, column - 2, tokenTypeName[SEP], "..");
        tokenType = tokenTypeName[INTEGER];
        currentTokenTypeCode = INTEGER;
    }
    if ( currentTokenTypeCode == INTEGER || currentTokenTypeCode == HEX)
    {
        string s = leksema.substr(currentTokenTypeCode == HEX ? 1 : 0, leksema.size());
        int a = strtol (s.c_str(), NULL, currentTokenTypeCode == HEX ? 16 : 10);
        return new TokenVal<int>(lineCur, columnCur, tokenType, leksema, a);
    }
    if (currentTokenTypeCode == REAL)
    {
        double a = atof(leksema.c_str());
        return new TokenVal<double>(lineCur, columnCur, tokenTypeName[REAL], leksema, a);
    }
    if (currentTokenTypeCode == IDENT && (ident_type[leksema] == KEYWORD)) tokenType = tokenTypeName[KEYWORD];
    if (currentTokenTypeCode == IDENT && (ident_type[leksema] == OP)) tokenType = tokenTypeName[OP];
    if (currentTokenTypeCode == CHAR)
    {
        char d = leksema[1];
        return new TokenVal<char>(lineCur, columnCur, tokenType, leksema, d);
    }
    if (currentTokenTypeCode == CHAR$ || currentTokenTypeCode == CHAR$$)
    {
        string s = leksema.substr(currentTokenTypeCode == CHAR$$ ? 2 : 1, leksema.size());
        int a = strtol (s.c_str(), NULL, currentTokenTypeCode == CHAR$$ ? 16 : 10);
        tokenType = tokenTypeName[CHAR];
        if (a > 127) throw new LexerError(lineCur,column,"BadCC");
        return new TokenVal<char>(lineCur, columnCur, tokenType, leksema, (char)a);
    }
    if (currentTokenTypeCode == STRING)
    {
        string s = leksema.substr(1,leksema.size()-2);
        int index = 0;
        while (true)
        {
            index = s.find("''",index);
            if (index == string::npos) break;
            s.replace (index, 2, "'");
            index ++;
        }
        return new TokenVal<string>(lineCur, columnCur, tokenType, leksema, s);
    }

    if (ident_type[tokenType] == ERROR)
    {
        if (currentTokenTypeCode == BAD_NL)
            columnCur = columnError;
        else if (currentTokenTypeCode == BAD_EOF)
        {
            lineCur = line;
            columnCur = column - 1;
        }
        else if (currentTokenTypeCode == BAD_CHAR)
            columnCur = column - 1;
        else
            columnCur = column;
        throw new LexerError(lineCur,columnCur,tokenType);
    }
    if (currentTokenTypeCode == COMMENT)
    {
        return get_token();
    }
    return new Token(lineCur, columnCur, tokenType, leksema);
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